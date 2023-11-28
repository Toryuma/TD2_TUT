#pragma once

#include "Audio.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "SafeDelete.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"

#include "Player.h"
#include "Enemy.h"
#include "Skydome.h"
#include "Ground.h"
#include "FollowCamera.h"

/// <summary>
/// ゲームシーン
/// </summary>
class GameScene {

public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	void CheckAllCollision();

private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	/// <summary>
	/// ゲームシーン用
	/// </summary>

	//プレイヤー
	std::unique_ptr<Player> player_;

	std::unique_ptr<FollowCamera> followCamera_;

	std::unique_ptr<Ground> ground_;

	std::unique_ptr<Skydome> skydome_;

	std::unique_ptr<Enemy> enemy_;

	//std::unique_ptr<Wall> wall_;

	std::unique_ptr<Model> model_;

	std::unique_ptr<Model> modelEnemy_;

	std::unique_ptr<Model> modelGround_;

	std::unique_ptr<Model> modelSkydome_;

	//Model* model_ = nullptr;	// モデルクラステスト用

	WorldTransform worldTransform_;

	ViewProjection viewProjection_;
};
