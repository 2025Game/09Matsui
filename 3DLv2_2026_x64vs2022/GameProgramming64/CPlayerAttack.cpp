#include "CPlayerAttack.h"
#include "CXPlayer.h"

void CPlayerAttack::Start(CXCharacter* parent)
{
	//親?ポインタを保存
	mpParent = parent;
	//アニメーション?変更
	mpParent->ChangeAnimation(3, false, 30);
	mState = EState::EATTACK; //状態?種類を歩???る
}
void CPlayerAttack::Update()
{
	//アニメーション?終了??いる?
	if (mpParent->IsAnimationFinished())
	{
		//アニメーション?終了??ら待機状態??る
		mState = EState::EIDLE;
	}
}