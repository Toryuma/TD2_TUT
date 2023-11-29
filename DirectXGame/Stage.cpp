#include "Stage.h"
#include <cassert>

void Stage::Initialize(Model* model) { 
	assert(model);

	model_ = model;
	// ワールドトランスフォームの初期化とスケール
	worldtransform_.Initialize();
	
	worldtransform_.scale_ = {1.0f, 1.0f, 1.0f};
}

void Stage::Update() { 
	worldtransform_.UpdateMatrix();
}

void Stage::Draw(ViewProjection& viewProjection_) {
	// 3Dモデル描画
	model_->Draw(worldtransform_, viewProjection_);
}
