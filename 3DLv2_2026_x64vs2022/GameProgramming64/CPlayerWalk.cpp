#include "CPlayerWalk.h"
#include "CXCharacter.h"

#define ROTATIONSPEED 2.0f

void CPlayerWalk::Start(CXCharacter* parent)
{
	//親䛾ポインタを保存
	mpParent = parent;
	//アニメーション䛾変更
	mpParent->ChangeAnimation(1, true, 60);
	mState = EState::EWALK; //状態䛾種類を歩䛟䛻䛩る

}
	//移動速度
#define VELOCITY 0.1f
	void CPlayerWalk::Update()
	{
		if (mInput.Key('W'))
		{
			CVector p = mpParent->Position();
			mpParent->Position(p +
				mpParent->MatrixRotate().VectorZ() * VELOCITY); 
			if (mInput.Key('A'))
			{
				CVector r = mpParent->Rotation() +
					CVector(0.0f, ROTATIONSPEED, 0.0f);
				mpParent->Rotation(r);
			}
			if (mInput.Key('D'))
			{
				CVector r = mpParent->Rotation() +
					CVector(0.0f, -ROTATIONSPEED, 0.0f);
				mpParent->Rotation(r);
			}
		}
		else
		{
			//Wキー䛜押䛥れ䛶い䛺い䛸䛝䛿待機状態䛻䛩る
			mState = EState::EIDLE;
		}
		if (mInput.Key('I'))
		{
			mState = EState::EATTACK;
		}
	}