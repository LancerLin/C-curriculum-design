#include "UI.h"

#include<iostream>
using namespace std;
UI::UI()
{
}

void UI::LoginUI()
{
	int id, pw;
	int tp, cls;
	CleanUI();
	cout << "/t欢迎使用会员登录系统/t" << endl;

	do //判断用户名存在性
	{
		cout << "请输入用户ID:" << endl;
		cin >> id;
		if (certid(id) == true) break;  //如果存在就跳出循环
		cout << "用户名，请重新输入" << endl;
		getchar();
	} while (certid(id) == false);//certid()是布尔型 返回true就说明存在

		do //判断密码是否正确
		{
			cout << "请输入密码:" << endl;
			cin >> pw;
			if (certpw(id) == true) break;  //如果存在就跳出循环
			cout << "密码错误，请重新输入" << endl;
			getchar();
		} while (certpw(id) == false);//certpw()是布尔型 返回true就说明存在
		if (id > 100000)
		{

		}
}

void UI::CleanUI()
{
	system("Cls");
}

void UI::Loginid()
{

}

void UI::MemberUI()
{
}
