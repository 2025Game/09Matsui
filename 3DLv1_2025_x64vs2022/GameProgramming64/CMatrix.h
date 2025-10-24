#ifndef CMATRIX_H
#define CMATRIX_H
/*
マトリクスクラス
4行4列の行列データを扱います
*/
class CMatrix {
public:
	//デフォルトコンストラクタ
	CMatrix();
	//単位行列の作成
	CMatrix Identity();

	//表示確認用
	//4×4の行列を画面出力
	void Print();
private:
	//4×4の行列データを設定
	float mM[4][4];
};
#endif
#pragma once
