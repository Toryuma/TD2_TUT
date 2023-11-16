#pragma once
#include "Input.h"
#include "Model.h"
#include "WorldTransform.h"

//class Enemy {
//public:
//
//	//初期化
//	void Initialize(Model* model);
//	
//	//更新
//	void Update();
//	
//	//描画
//	void Draw(ViewProjection& viewProjection);
//	
//	//当たり判定
//	void OnCollision();
//	
//	//死亡フラグ
//	bool IsDead() const { return isDead_; }
//
//private:
//
//	WorldTransform worldTransform_;
//
//	ViewProjection viewProjection_;
//
//	Model* model_ = nullptr;
//
//	// 速度
//	Vector3 velocity_;
//
//	int EnemyMoveCount_;
//
//    float EnemySpeed_ = 0.5f;
//
//	bool enemyMove_ = true;
//
//	bool isDead_ = false;
//};
