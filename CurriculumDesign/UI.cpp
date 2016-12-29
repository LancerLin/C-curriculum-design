#include "UI.h"
#include<iostream>
#include"Operator.h"
using namespace std;
UI::UI()
{
	LOGT.Read_log();
	
}

void UI::LoginUI()
{
	int id, pw;
	D *d=NULL;
	//	int tp, cls;
	Clean();
	cout << "欢迎使用会员登录系统" << endl;

	do //判断用户名存在性
	{
		cout << "请输入用户ID:" << endl;
		cin >> id;
		if (Operator::Certid(id)) break;  //如果存在就跳出循环
		cout << "用户名，请重新输入" << endl;
		getchar();
	} while (!Operator::Certid(id));//certid()是布尔型 返回true就说明存在
	if (id > MemberStartNumber) {
		Member *mb_p = new Member();
		mb_p->Read(id);
		d = mb_p->getdata();
	}
	else if (id > ManagerStartNumber) {
		Manager *mg_p = new Manager();
		mg_p->Read(id);
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
		if (Operator::Certpw(Person(d),pw) == true) break;  //如果存在就跳出循环
		cout << "密码错误，请重新输入" << endl;
		getchar();
	} while (Operator::Certpw(Person(d),pw) == false);//certpw()是布尔型 返回true就说明存在
	if (id > MemberStartNumber) {
		MemberUI(id);
	}
	else if (id > ManagerStartNumber) {
		ManagerUI(id);
	}
	else if(SuperPass==pw){
		SuperUI(id);
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
	manager.CreateMember(p);

}

void UI::CreatManagerUI()
{
	D *p = new D;
	cout << "********************" << endl;
	cout << "请输入新姓名：" << endl;
	cin >> p->name;
	cout << "请设置密码" << endl;
	cin >> p->password;
	p->id = LOGT.ManagerCout();
	p->IsUsed = true;
	p->credit = 0;
	CreateManager(p);
}

void UI::ShowAllCount()
{
	Member *mb=new Member();
	for (int i = 0; i < LOGT.L.NMember; i++) {
		mb->Read(MemberStartNumber + i);
		cout << mb->getid() << mb->getname() ;//输出用户信息
	}
	delete mb;
	Manager *mg = new Manager();
	for (int i = 0; i < LOGT.L.NManager; i++) {
		mg->Read(ManagerStartNumber + i);
		cout << mg->getid() << mg->getname() ;//输出用户信息
	}
}
