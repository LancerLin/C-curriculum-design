#include "UI.h"
#include<iostream>
#include"Operator.h"
using namespace std;
UI::UI()
{
}

void UI::LoginUI()
{
	int id, pw;
	//	int tp, cls;
	Clean();
	cout << "欢迎使用会员登录系统" << endl;

	do //判断用户名存在性
	{
		cout << "请输入用户ID:" << endl;
		cin >> id;
		if (Operator::Certid(id) == true) break;  //如果存在就跳出循环
		cout << "用户名，请重新输入" << endl;
		getchar();
	} while (Operator::Certid(id) == false);//certid()是布尔型 返回true就说明存在

	do //判断密码是否正确
	{
		cout << "请输入密码:" << endl;
		cin >> pw;
		if (Operator::Certid(id) == true) break;  //如果存在就跳出循环
		cout << "密码错误，请重新输入" << endl;
		getchar();
	} while (Operator::Certid(id) == false);//certpw()是布尔型 返回true就说明存在
	if (id > 100000) {
		MemberUI(id);
	}
	else if (id < 1000) {
		SuperUI(id);
	}
	else {
		ManagerUI(id);
	}
}

void UI::Clean()
{
	system("Cls");
}


void UI::MemberUI(const int inputid)   //传入当前id 用作限制当前操作
{

	int fg;
	Clean();
	cout << "****************************" << endl;
	cout << "*     欢迎进入会员界面      *" << endl;
	cout << "*   1.查询个人信息         *" << endl;
	cout << "*   3.查询账户操作          *" << endl;
	cout << "*   4.修改密码             *" << endl;
	cout << "*   5.注销登陆             *" << endl;
	cout << "***************************" << endl;
	cout << "请输入序号进行操作：" << endl;
	//下面是操作内容，待补全
	cin >> fg;
	switch (fg)
	{
	case 1:Checkinfo(inputid);
	case 2://log op
	case 3:
	case 4:
	case 5: Logout(); break;
	default:
		break;
	}
}

void UI::ManagerUI(const int inputid)
{
	int fg;
	Clean();
	cout << "****************************" << endl;
	cout << "*     欢迎进入经理界面      *" << endl;
	cout << "*   1.查询会员信息          *" << endl;
	cout << "*   2.新会员注册            *" << endl;
	cout << "*   3.充值会员积分          *" << endl;
	cout << "*   4.注销登陆             *" << endl;
	cout << "***************************" << endl;
	cout << "请输入序号进行操作：" << endl;
	//下面是操作内容，待补全
	cin >> fg;
	switch (fg)
	{
	case 1:
	case 2:
	case 3:
	case 4:Logout(); break;
	default:
		break;
	}
}

void UI::SuperUI(const int inputid)
{
	int fg;
	Clean();
	cout << "****************************" << endl;
	cout << "*     欢迎进入超级经理界面   *" << endl;
	cout << "*   1.查询账户信息          *" << endl;
	cout << "*   2.新会员注册            *" << endl;
	cout << "*   3.注销 恢复账户          *" << endl;
	cout << "*   4.会员积分操作          *" << endl;
	cout << "*   5.导出所有账户信息       *" << endl;
	cout << "*   6.注销登陆              *" << endl;
	cout << "***************************" << endl;
	cout << "请输入序号进行操作：" << endl;
	//下面是操作内容，待补全
	cin >> fg;
	switch (fg)
	{
	case 1:Checkinfo();
	case 2:
	case 3:
	case 4:
	case 5:
	case 6: Logout(); break;
	default:
		break;
	}
}

void UI::Logout()
{
	char fg;
	cout << "是否确定注销（Y/N）?" << endl;
	cin >> fg;
	if (fg == 'Y') {
		cout << "********************" << endl;
		cout << "* Log out succeed  *" << endl;
		cout << "********************" << endl;
		getchar();
		LoginUI();
	}
}


D* UI::CreatMemberUI()
{

	D *p = new D;
	cout << "********************" << endl;
	cout << "请输入新姓名：" << endl;
	cin >> p->name;
	cout << "请设置密码" << endl;
	cin >> p->password;
	//	p->id = 0;        获取ID
	p->IsUsed = true;
	p->credit = 0;
	return p;
	// TODO: 在此处插入 return 语句
}
