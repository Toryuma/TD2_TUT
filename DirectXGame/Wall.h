#pragma once

#include "WorldTransform.h"
#include "Model.h"

class Wall {

public:

	void Initialize(Model* model, uint32_t textureHandle);

	void Update();

	void Draw();

private:

	Model* model_ = nullptr;

	uint32_t texturehandle_ = 0u;
    
	WorldTransform worldTransform_;

	ViewProjection viewProjection_;
};
