#pragma once

#include "Model.h"
#include "WorldTransform.h"

/// <summary>
/// ステージのキューブ描画するやつ
/// </summary>
class Stage {
public:
	void Initialize(Model* model);

	void Update();

	void Draw(ViewProjection& viewProjection_);

private:
	// ワールド変換データ
	WorldTransform worldtransform_; 
	// ビュープロジェクション
	ViewProjection viewProjection_;
	// モデル
	Model* model_ = nullptr;
};
