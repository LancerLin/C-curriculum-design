#pragma once
//UI.h ����
#include <stdlib.h>
#include"Operator.h"
class UI:public Operator
{
public:
	UI();
	void LoginUI();  //��½����
	void Clean();    //������Ļ
	void MemberUI(); //��Ա��½����
	void ManagerUI();//����Ա����
	void SuperUI();  //�����
	void Logout();   //ע��
private:

};