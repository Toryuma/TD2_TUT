#pragma once

#include "WorldTransform.h"
#include "Model.h"

class RailCamera
{
public:
	// 初期化
	void Initialize();

	// 更新
	void Update();

private:
	// ワールド変換データ
	WorldTransform worldtransform_;
	// ビュープロジェクション
	ViewProjection viewprojection_;
};

