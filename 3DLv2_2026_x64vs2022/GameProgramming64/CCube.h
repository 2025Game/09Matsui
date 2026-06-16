#include "CCharacter3.h"
#include "CColliderTriangle.h"
class CCube : public CCharacter3
{
public:
	CCube();
	void Update();
private:
	//モデルデータ䛾インスタンス
	static CModel msModel;
	//コライダ䛿上面䛰䛡付䛡る
	CColliderTriangle mCollider[2];
};