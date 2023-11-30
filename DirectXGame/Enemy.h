#pragma once

#include "Model.h"
#include "WorldTransform.h"
#include "ViewProjection.h"

class Enemy {
public:

	//初期化
	void Initialize(Model* model);
	
	//更新
	void Update();
	
	//描画
	void Draw(ViewProjection& viewProjection);
	
	//当たり判定
	//void OnCollision();

private:

	WorldTransform worldTransform_;

	ViewProjection viewProjection_;

	Model* model_ = nullptr;

	Vector3 velocity_ = {};

	// 速度
    float EnemySpeed_ = 0.1f;

	bool isDead_ = true;
};
