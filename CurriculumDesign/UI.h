#pragma once
//UI.h 界面
#include <stdlib.h>
#include"Operator.h"
class UI:public Operator
{
public:
	UI();
	void LoginUI();  //登陆界面
	void CleanUI();  //清理屏幕
	void Loginid();  //id登陆操作
	void MemberUI(); //会员登陆界面
private:

};
