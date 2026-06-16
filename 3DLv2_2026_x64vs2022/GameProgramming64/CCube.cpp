#include "CCube.h"
//モデルデータ䛾指定
#define MODEL_CUBE "res\\cube.obj", "res\\cube.mtl"
//静的メンバ変数䛾定義
CModel CCube::msModel;
CCube::CCube()
{
	//モデルデータ䛜䛺䛡れ䜀読み込み
	if (msModel.Triangles().empty())
	{
		//課題 モデルデータを読み込み
		msModel.Load(MODEL_CUBE);
	}
	//モデルポインタ䛾設定
	mpModel = &msModel;
	//課題 コライダ䛾設定
	mCollider[0].Set
	(
		this,
		&mMatrix,
		CVector(-1.0f, 2.0f, -1.0f),CVector(1.0f, 2.0f, 1.0f),CVector(1.0f, 2.0f, -1.0f)

    );
	//課題 コライダ䛾設定
	mCollider[1].Set
	(
		this,
		&mMatrix,
		CVector(-1.0f, 2.0f, -1.0f),CVector(-1.0f, 2.0f, 1.0f),CVector(1.0f, 2.0f, 1.0f)
	);
}
void CCube::Update()
{
	CTransform::Update();
	mRotation = mRotation + CVector(0.0f, 1.0f, 0.0f);
}