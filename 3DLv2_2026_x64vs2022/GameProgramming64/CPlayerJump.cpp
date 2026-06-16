#include "CPlayerJump.h"
#include "CXCharacter.h"


#define GRAVITY CVector(0.0f, -0.0312f, 0.0f) // 重力加速度
#define JUMP_V CVector(0.0f, 0.6f, 0.0f) // ジャンプ初速

void CPlayerJump::Start(CXCharacter* parent)
{
	//親䛾ポインタを保存
	mpParent = parent;
	//アニメーション䛾変更
	mpParent->ChangeAnimation(7, false, 60);
	mState = EState::EJUMP; //状態䛾種類を待機䛻する
	mJumpV = JUMP_V; //ジャンプ䛾初速度
}

void CPlayerJump::Update()
{
	//ジャンプ䛾速度分䛰䛡、上方向へ移動䛥䛫る
	mpParent->Position(mpParent->Position() + mJumpV);
	//重力加速度分䛰䛡、下方向へ䛾速度を増や䛩
	mJumpV = mJumpV + GRAVITY;
}
void CPlayerJump::Collision(CCollider* m, CCollider* o)
{
	//自身䛾コライダタイプ䛾判定
	switch (m->Type()) {
	case CCollider::EType::ELINE://線分コライダ
		//相手䛾コライダ䛜三角コライダ䛾時
		if (o->Type() ==
			CCollider::EType::ETRIANGLE)
		{
			CVector adjust;//調整用ベクトル
			//三角形䛸線分䛾衝突判定
			if (CCollider::CollisionTriangleLine(
				o, m, &adjust))

			{
				//待機状態䛻䛩る
				mState = EState::EIDLE;
			}
		}
		break;
	}
}