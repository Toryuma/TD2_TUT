#pragma once
#include "Input.h"
#include "Model.h"
#include "WorldTransform.h"
#include <list>

class Enemy {
public:
	//デリート
	~Enemy();
	//初期化
	void Initialize(Model* model, Vector3& position, const Vector3& velocity);
	//更新
	void Update();
	//描画
	void Draw(ViewProjection& viewProjection);
	//当たり判定
	void OnCollision();
	//死亡フラグ
	bool IsDead() const { return isDead_; }

private:

	WorldTransform worldTransform_;
	Model* model_ = nullptr;
	uint32_t texturehandle_ = 0u;
	// 速度
	Vector3 velocity_;

	bool isDead_ = false;
};
