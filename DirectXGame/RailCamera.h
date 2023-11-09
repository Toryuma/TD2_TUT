#pragma once

#include "WorldTransform.h"
#include "Model.h"

class RailCamera {
public:
	// 初期化
	void Initialize();

	// 更新
	void Update();
	const ViewProjection& GetViewProjecton() { return viewprojection_; }

	// プレイヤーワールド座標を取得
	const WorldTransform& GetWorldTransform() { return worldtransform_; }

private:
	// ワールド変換データ
	WorldTransform worldtransform_;
	// ビュープロジェクション
	ViewProjection viewprojection_;
};
