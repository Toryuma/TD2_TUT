#include "Ground.h"
#include <cassert>

void Ground::Initialize(Model* model) {

	assert(model);

	model_ = model;

	worldTransform_.Initialize();

	worldTransform_.translation_.z = 15.0f;
	worldTransform_.translation_.y = 15.0f;
	worldTransform_.translation_.x = 15.0f;
}

void Ground::Update() {

	worldTransform_.TransferMatrix();

}

void Ground::Draw(ViewProjection& viewProjection) {

	model_->Draw(worldTransform_, viewProjection);

}
