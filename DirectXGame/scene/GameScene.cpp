#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>
#include "AxisIndicator.h"

GameScene::GameScene() {}

GameScene::~GameScene() {}

void GameScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();

	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();

	viewProjection_.Initialize();
	viewProjection_.farZ = 1600.0f;
	viewProjection_.UpdateMatrix();

	modelGround_.reset(Model::CreateFromOBJ("ground", true));

	ground_ = std::make_unique<Ground>();
	ground_->Initialize(modelGround_.get());

	//プレイヤー
	model_.reset(Model::CreateFromOBJ("float", true));
	player_ = std::make_unique<Player>();
	player_->Initialize(model_.get());

	// Enemy
	/*model_.reset(Model::CreateFromOBJ("needle_Body", true));
	enemy_ = std::make_unique<Enemy>();
	enemy_->Initialize(model_.get());*/


	followCamera_ = std::make_unique<FollowCamera>();
	followCamera_->Initialize();
	followCamera_->SetTarget(&player_->GetWorldTransform());

	player_->SetViewProjection(&followCamera_->GetViewProjection());
}

void GameScene::Update() {

	player_->Update();
	//enemy_->Update();

	followCamera_->Update();

	viewProjection_.matView = followCamera_->GetViewProjection().matView;
	viewProjection_.matProjection = followCamera_->GetViewProjection().matProjection;

	viewProjection_.TransferMatrix();

	//四隅の処理 右
	if (worldTransform_.translation_.z >= 0 && worldTransform_.translation_.y >= 0) {

	}

	if (worldTransform_.translation_.z >= 0 && worldTransform_.translation_.y >= 100) {

	}

	if (worldTransform_.translation_.z >= 100 && worldTransform_.translation_.y == 100) {

	}

	if (worldTransform_.translation_.z >= 100 && worldTransform_.translation_.y == 0) {

	}

	//四隅の処理 左

}

void GameScene::CheckAllCollision() {

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

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	player_->Draw(viewProjection_);
	//enemy_->Draw(viewProjection_);
	ground_->Draw(viewProjection_);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>

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


