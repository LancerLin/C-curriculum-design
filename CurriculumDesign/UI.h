#pragma once
//UI.h ����
#include <stdlib.h>
#include"Operator.h"
class UI:public Operator
{
public:
	UI();
	void LoginUI();  //��½����
	void Clean();  //������Ļ
	void Loginid();  //id��½����
	void MemberUI(); //��Ա��½����
	void ManagerUI();//����Ա����
	void SuperUI();  //�����
private:

};
