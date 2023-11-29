#pragma once
#include "Input.h"
#include "Model.h"
#include "WorldTransform.h"
#include <list>

class Player {
public:
	// デリート
	~Player();
	
	Vector3 GetWorldPosition();

	const WorldTransform& GetWorldTransform() { return worldTransform_; }

	void SetViewProjection(const ViewProjection* viewprojection) {
		viewprojection_ = viewprojection;
	}

	// 初期化
	void Initialize(Model* model,uint32_t texturehandle);
	// 更新
	void Update();
	// 描画
	void Draw(ViewProjection& viewProjection);
	// 当たり判定
	void OnCollision();
	// 死亡フラグ
	bool IsDead() const { return isDead_; }

private:
	// ワールド変換データ
	WorldTransform worldTransform_;
	// カメラのビュープロジェクション
	const ViewProjection* viewprojection_ = nullptr;
	// モデル
	Model* model_ = nullptr;
	// テクスチャハンドル
	uint32_t texturehandle_ = 0u;
	// 速度
	Vector3 velocity_;

	bool isDead_ = false;
};
