#include "RailCamera.h"

void RailCamera::Initialize()
{
	// ワールドトランスフォームの初期化、設定
	worldtransform_.Initialize();
	worldtransform_.translation_.z = -10;

	// ビュープロジェクションの初期化
	viewprojection_.Initialize();
}

void RailCamera::Update()
{
	worldtransform_.translation_.z += 0.05f;
	worldtransform_.UpdateMatrix();
}
