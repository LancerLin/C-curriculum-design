#include "UI.h"
#include<iostream>
#include"Operator.h"
using namespace std;
UI::UI()
{
	LOGT.read_log();
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
	while (1) {

		Clean();
		cout << "****************************" << endl;
		cout << "*     欢迎进入会员界面      *" << endl;
		cout << "*   1.查询个人信息         *" << endl;
		cout << "*   2.查询账户操作          *" << endl;
		cout << "*   3.修改密码             *" << endl;
		cout << "*   4.注销登陆             *" << endl;
		cout << "***************************" << endl;
		cout << "请输入序号进行操作：" << endl;
		//下面是操作内容，待补全
		cin >> fg;
		switch (fg)
		{
		case 1:Checkinfo(inputid); continue;
		case 2:continue;//log op
		case 3:ChangePw(inputid); continue;
		case 4:Logout(); break; continue;
		}
	}
}

void UI::ManagerUI(const int inputid)
{
	int fg;
	while (1)
	{
		Clean();
		cout << "****************************" << endl;
		cout << "*     欢迎进入经理界面      *" << endl;
		cout << "*   1.查询会员信息          *" << endl;
		cout << "*   2.新会员注册            *" << endl;
		cout << "*   3.会员积分修改          *" << endl;
		cout << "*   4.注销登陆             *" << endl;
		cout << "***************************" << endl;
		cout << "请输入序号进行操作：" << endl;
		//下面是操作内容，待补全
		cin >> fg;
		switch (fg)
		{
		case 1:Checkinfo(); continue;
		case 2:CreatMemberUI(); continue;
		case 3:ChangeCredit(); continue;
		case 4:Logout(); continue;
		}
	}
}

void UI::SuperUI(const int inputid)
{
	int fg;
	while (1)
	{

		Clean();
		cout << "****************************" << endl;
		cout << "*     欢迎进入超级经理界面   *" << endl;
		cout << "*   1.查询账户信息          *" << endl;
		cout << "*   2.新会员注册            *" << endl;
		cout << "*   3.查询账户状态          *" << endl;
		cout << "*   4.会员积分修改          *" << endl;
		cout << "*   5.显示用户数量          *" << endl;
		cout << "*   6.注销登陆              *" << endl;
		cout << "***************************" << endl;
		cout << "请输入序号进行操作：" << endl;
		//下面是操作内容，待补全
		cin >> fg;
		switch (fg)
		{
		case 1:Checkinfo(); continue;
		case 2:CreatMemberUI();continue;
		case 3:ChangeIsused(); continue;
		case 4:ChangeCredit(); continue;
		case 5:ShowAllCount(); continue;
		case 6:Logout(); continue;
		}
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

void UI::CreatMemberUI()
{

	D *p = new D;
	cout << "********************" << endl;
	cout << "请输入新姓名：" << endl;
	cin >> p->name;
	cout << "请设置密码" << endl;
	cin >> p->password;
	p->id = LOGT.MemberCount();
	p->IsUsed = true;
	p->credit = 0;
	manager.createmamber(p);

}

void UI::ShowAllCount()
{
	Member *m=new Member();
	for (int i = 0; i < LOGT.L.NMember; i++) {
		m->read(MemberStartNumber + i);
		cout << "*****************" << endl;
		cout << "会员ID：" << m->getid() << endl;
		cout << "姓名：" << m->getname() << endl;
		cout << "会员积分"<< m->getcredit;//输出用户信息
		cout << "账户状态";
		if (m->isued == true) {
			cout << "正常" << endl;
		}
		else if (m->isued == false) {
			cout << "禁用" << endl;
		}
		cout << "*****************" << endl;
	}
	delete m;
	Manager *m = new Manager();
	for (int i = 0; i < LOGT.L.NManager; i++) {
		m->read(ManagerStartNumber + i);
		cout << "*****************" << endl;
		cout << "管理员ID：" << m->getid() << endl;
		cout << "姓名：" << m->getname() << endl;
		cout << "账户状态";
		if (m->isued == true) {
			cout << "正常" << endl;
		}
		else if (m->isued == false) {
			cout << "禁用" << endl;
		}
		cout << "*****************" << endl;
	}
}
