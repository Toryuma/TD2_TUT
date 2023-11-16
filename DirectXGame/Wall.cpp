#include "Wall.h"
#include <cassert>

void Wall::Initialize(Model* model, uint32_t textureHandle) {

	texturehandle_ = textureHandle;

	texturehandle_ = TextureManager::Load("sen.png");

	assert(model);

	model_ = model;

	model_ = Model::Create();

	viewProjection_.translation_.y = 360;
	viewProjection_.translation_.z = 50;
}

void Wall::Update() {

}

void Wall::Draw() {

	model_->Draw(worldTransform_, viewProjection_);

}
