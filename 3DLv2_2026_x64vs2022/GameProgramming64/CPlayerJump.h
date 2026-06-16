
#include "CState.h"
#include "CCollider.h"
#include "CInput.h"
class CPlayerJump : public CState
{
public:
	void Start(CXCharacter* parent) override;
	void Update() override;
	//衝突処理
//Collision(コライダ1, コライダ2)
	void Collision(CCollider* m, CCollider* o) override;



private:
	CInput mInput;
	CVector mJumpV; //ジャンプ䛾速度
};
