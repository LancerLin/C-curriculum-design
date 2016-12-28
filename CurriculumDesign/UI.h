#pragma once
//UI.h 界面
#include <stdlib.h>
#include "Person.h"
#include"Operator.h"
class UI:public Operator
{
public:
	UI();
	void LoginUI();  //登陆界面
	void Clean();    //清理屏幕
	void MemberUI(); //会员登陆界面
	void ManagerUI();//管理员界面
	void SuperUI();  //脏界面
	void Logout();   //注销
	D * CreatMemberUI();
	//D * CreatManagerUI();
private:

};
