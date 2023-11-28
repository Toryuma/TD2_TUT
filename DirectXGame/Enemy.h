#pragma once

#include "Model.h"
#include "WorldTransform.h"

class Enemy {
public:

	//初期化
	void Initialize(Model* model);
	
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

	ViewProjection viewProjection_;

	Model* model_ = nullptr;

	Vector3 velocity_ = {};

	// 速度
    float EnemySpeed_ = 0.3f;

	bool isDead_ = true;
};
