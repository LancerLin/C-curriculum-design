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
	cout << "/t��ӭʹ�û�Ա��¼ϵͳ/t" << endl;

	do //�ж��û���������
	{
		cout << "�������û�ID:" << endl;
		cin >> id;
		if (certid(id) == true) break;  //������ھ�����ѭ��
		cout << "�û���������������" << endl;
		getchar();
	} while (certid(id) == false);//certid()�ǲ����� ����true��˵������

		do //�ж������Ƿ���ȷ
		{
			cout << "����������:" << endl;
			cin >> pw;
			if (certpw(id) == true) break;  //������ھ�����ѭ��
			cout << "�����������������" << endl;
			getchar();
		} while (certpw(id) == false);//certpw()�ǲ����� ����true��˵������
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
