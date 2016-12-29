#include "UI.h"
#include<iostream>
#include"Operator.h"
using namespace std;
UI::UI()
{
	//日志初始化
	LOGT.Read_log();
	if (LOGT.L.NManager + LOGT.L.NMember == 0) {
		LOGT.Write_log();
		LOGT.CreatConduct_log();
	}
}

void UI::LoginUI()
{
	int id, pw;
	D *d = NULL;
	//	int tp, cls;

	do //判断用户名存在性
	{
		Clean();
		cout << "***********************" << endl;
		cout << "欢迎使用会员登录系统" << endl;
		cout << "*********************" << endl;
		cout << "请输入用户ID:" << endl;
		cin >> id;
		if (Operator::Certid(id)) break;  //如果存在就跳出循环
		system("Cls");
		cout << "用户名不存在，请按回车重新输入" << endl;
		getchar(); getchar();
	} while (!Operator::Certid(id));//certid()是布尔型 返回true就说明存在
	if (id >= MemberStartNumber) {
		Member *mb_p = new Member();
		mb_p->Member::Read(id);
		d = mb_p->getdata();
	}
	else if (id >= ManagerStartNumber) {
		Manager *mg_p = new Manager();
		mg_p->Manager::Read(id);
		d = mg_p->getdata();
	}
	else if (SuperID == id) {
		d = new D();
		strcpy_s(d->name, SuperName);
		d->id = SuperID;
		d->password = SuperPass;
	}

	do //判断密码是否正确
	{
		cout << "请输入密码:" << endl;
		cin >> pw;
		if (Operator::Certpw(Person(d), pw) == true) break;  //如果存在就跳出循环
		cout << "密码错误，请重新输入" << endl;
		getchar();
	} while (Operator::Certpw(Person(d), pw) == false);//certpw()是布尔型 返回true就说明存在
	if (id >= MemberStartNumber) {
		MemberUI(id);
	}
	else if (id >= ManagerStartNumber) {
		ManagerUI(id);
	}
	else if (SuperPass == pw) {
		SuperUI(id);
	}
}

void UI::Clean()
{
	system("Cls");
}


void UI::MemberUI(const int inputid)   //传入当前id 用作限制当前操作
{
	LOGT.AddConduct(inputid, "login", "system");
	int fg;
	while (1) {

		Clean();
		cout << "****************************" << endl;
		cout << "*     欢迎进入会员界面    " << endl;
		cout << "*   当前ID:" << inputid << endl;
		cout << "*   1.查询个人信息        " << endl;
		cout << "*   2.查询账户操作          " << endl;
		cout << "*   3.修改密码             " << endl;
		cout << "*   4.注销登陆             " << endl;
		cout << "***************************" << endl;
		cout << "请输入序号进行操作：" << endl;
		//下面是操作内容，待补全
		cin >> fg;
		switch (fg)
		{
		case 1:Checkinfo(inputid); continue;
		case 2:continue;//log op
		case 3:if(ChangePw(inputid)) LOGT.AddConduct(inputid, "edit", "password"); continue;
		case 4:Logout(inputid);  break; continue;
		}
	}
}

void UI::ManagerUI(const int inputid)
{
	LOGT.AddConduct(inputid, "login", "system");
	int fg;
	while (1)
	{
		Clean();
		cout << "****************************" << endl;
		cout << "*     欢迎进入经理界面      " << endl;
		cout << "*   1.查询会员信息          " << endl;
		cout << "*   2.新会员注册            " << endl;
		cout << "*   3.会员积分修改          " << endl;
		cout << "*   4.注销登陆             " << endl;
		cout << "***************************" << endl;
		cout << "请输入序号进行操作：" << endl;
		//下面是操作内容，待补全
		cin >> fg;
		switch (fg)
		{
		case 1:Checkinfo(); continue;
		case 2:CreatMemberUI(); continue;
		case 3:if(ChangeCredit())LOGT.AddConduct(inputid, "edit", "credit");  continue;
		case 4:Logout(inputid);  continue;
		}
	}
}

void UI::SuperUI(const int inputid)
{
	LOGT.AddConduct(inputid, "login", "system");
	int fg;
	while (1)
	{

		Clean();
		cout << "****************************" << endl;
		cout << "*     欢迎进入超级经理界面   " << endl;
		cout << "*   1.查询账户信息          " << endl;
		cout << "*   2.新会员注册            " << endl;
		cout << "*   3.新管理员注册            " << endl;
		cout << "*   4.查询账户状态          " << endl;
		cout << "*   5.会员积分修改          " << endl;
		cout << "*   6.显示用户数量          " << endl;
		cout << "*   7.注销登陆              " << endl;
		cout << "***************************" << endl;
		cout << "请输入序号进行操作：" << endl;
		//下面是操作内容，待补全
		cin >> fg;
		switch (fg)
		{
		case 1:Checkinfo(); continue;
		case 2:CreatMemberUI(); continue;
		case 3:CreatManagerUI(); continue;
		case 4:if(ChangeIsused())LOGT.AddConduct(inputid, "edit", "isused"); continue;
		case 5:if(ChangeCredit())LOGT.AddConduct(inputid, "edit", "credit");  continue;
		case 6:ShowAllCount(); continue;
		case 7:Logout(inputid);  continue;
		}
	}
}

void UI::Logout(int inputid)
{
	char fg;
	cout << "是否确定注销（Y/N）?" << endl;
	cin >> fg;
	if (fg == 'Y' || fg == 'y') {
		LOGT.AddConduct(inputid, "logout", "system");
		system("Cls");
		cout << "********************" << endl;
		cout << "* Log out succeed  *" << endl;
		cout << "********************" << endl;
		getchar(); getchar();
		LoginUI();
	}
}

void UI::CreatMemberUI()
{

	D *p = new D;
	system("Cls");

	cout << "********************" << endl;
	cout << "请输入新姓名：" << endl;
	cin >> p->name;
	cout << "请设置密码" << endl;
	cin >> p->password;
	cout << "确认信息" << endl;
	if (IsYes() == true) {
		p->id = LOGT.MemberCount() + MemberStartNumber;
		p->IsUsed = true;
		p->credit = 0;
		manager.CreateMember(p);
		
		system("Cls");
		cout << "****************" << endl;
		cout << "新用户ID：" << p->id << endl;
		cout << "用户姓名：" << p->name << endl;
		cout << "密码：" << p->password << endl;
		cout << "*******************" << endl;
		cout << "按回车返回界面" << endl;
		getchar(); getchar();
		LOGT.AddConduct(p->id, "add member",p->name);
	}
	
}

void UI::CreatManagerUI()
{
	D *p = new D;
	system("Cls");

	cout << "********************" << endl;
	cout << "请输入新姓名：" << endl;
	cin >> p->name;
	cout << "请设置密码" << endl;
	cin >> p->password;
	cout << "确认信息" << endl;
	if (IsYes() == true) {
		p->id = LOGT.ManagerCount() + ManagerStartNumber;
		p->IsUsed = true;
		p->credit = 0;
		CreateManager(p);
		system("Cls");
		cout << "****************" << endl;
		cout << "新管理员ID：" << p->id << endl;
		cout << "管理员姓名：" << p->name << endl;
		cout << "密码：" << p->password << endl;
		cout << "*******************" << endl;
		cout << "按回车返回界面" << endl;
		getchar(); getchar();
		LOGT.AddConduct(p->id, "add manager", p->name);
	}
}

void UI::ShowAllCount()
{
	Member *mb = new Member();
	for (int i = 1; i <= LOGT.L.NMember; i++) {
		mb->Read(MemberStartNumber + i);
		cout << "用户ID：" << mb->getid() << endl;
		cout << "用户姓名：" << mb->getname() << endl;//输出用户信息

	}
	cout << "会员显示完毕" << endl;
	getchar(); getchar();
	delete mb;
	Manager *mg = new Manager();
	for (int i = 1; i <= LOGT.L.NManager; i++) {
		mg->Read(ManagerStartNumber + i);
		cout << "管理员ID：" << mg->getid() << endl;
		cout << "管理员姓名：" << mg->getname() << endl;//输出用户信息
		//
		cout << mg->getpass() << endl;
		//
	}
	cout << "管理员显示完毕" << endl;
	getchar(); getchar();
}
