#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>

GameScene::GameScene() {}

GameScene::~GameScene() {
	delete modelSkydome_;
	delete debugcamera_;
}

void GameScene::Initialize() {

	// ゲームシーンのテクスチャハンドル
	textureHandle_ = TextureManager::Load("sen.png");

	// ビュープロジェクションの初期化
	viewProjection_.Initialize();

	// 3Dキューブと3Dキャラの生成
	model_.reset(Model::Create());
	
	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();

#pragma region デバックカメラ
	// デバックカメラの生成
	debugcamera_ = new DebugCamera(1280, 720);
	debugcamera_->SetFarZ(1400.0f);
#pragma endregion

#pragma region 天球の初期化
	// 3Dモデルの生成
	modelSkydome_ = Model::CreateFromOBJ("skydome", true);

	// 天球の生成
	skydome_ = new Skydome();
	// 天球初期化
	skydome_->Initialize(modelSkydome_);
#pragma endregion

#pragma region プレイヤーの描画
	// 自キャラの生成
	player_ = std::make_unique<Player>();
	// 3Dモデルの生成
	playerModel_.reset(Model::CreateFromOBJ("Sphere", true));

	// 自キャラの初期化
	player_->Initialize(playerModel_.get(), textureHandle_);

#pragma endregion

	// カメラ
	followCamera_ = std::make_unique<FollowCamera>();
	followCamera_->Initialize();
	followCamera_->SetTarget(&player_->GetWorldTransform());

	player_->SetViewProjection(&followCamera_->GetViewProjection());
}

void GameScene::Update() {

	// カメラの処理
	if (isDebugCameraActive_) {
		debugcamera_->Update();
		viewProjection_.matView = debugcamera_->GetViewProjection().matView;
		viewProjection_.matProjection = debugcamera_->GetViewProjection().matProjection;
		// ビュープロジェクション行列の転送
		viewProjection_.TransferMatrix();
	} else {
		// 追従カメラの更新
		followCamera_->Update();
		viewProjection_.matView = followCamera_->GetViewProjection().matView;
		viewProjection_.matProjection = followCamera_->GetViewProjection().matProjection;
		viewProjection_.TransferMatrix();
	}

	// 自キャラの更新
	player_->Update();

	// 天球
	skydome_->Update();

	// 地面
	// ground_->Update();
}

void GameScene::Draw() {

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region ここに描画処理を書く
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	// ステージの描画
	stage_->Draw(viewProjection_);

	// 自キャラの描画
	player_->Draw(viewProjection_);

	// 天球の描画
	skydome_->Draw(viewProjection_);

	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}
