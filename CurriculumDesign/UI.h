#pragma once
//UI.h 界面
/*
1.登录界面改返回ID switch放在主函数里
2.UI只显示界面
3.操作都放在operator
4.
*/
#include <stdlib.h>
#include "Person.h"
#include "Member.h"
#include "Manager.h"
#include"Operator.h"
#include"Log.h"
class UI:virtual public Operator
{
public:
	UI();
	Log LOGT;
	Member member;
	Manager manager;
	void LoginUI();  //登陆界面
	void Clean();    //清理屏幕
	void MemberUI(const int inputid); //会员登陆界面
	void ManagerUI(const int inputid);//管理员界面
	void SuperUI(const int inputid);  //脏界面
	void Logout();					  //注销登录
	//查询用户信息
	void CreatMemberUI();  //返回D类型用于文件操作
	//D * CreatManagerUI();
private:

};
