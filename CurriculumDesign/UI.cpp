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
	Clean();
	cout << "********************" << endl;
	cout << "*��ӭʹ�û�Ա��¼ϵͳ*" << endl;

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
		if (id > 100000){
			MemberUI();
		}
		else if(id<1000){
			SuperUI();
		}
		else {
			ManagerUI();
		}
}

void UI::Clean()
{
	system("Cls");
}


void UI::MemberUI()
{
	int fg;
	Clean();
	cout << "****************************" << endl;
	cout << "*     ��ӭ�����Ա����      *" << endl;
	cout << "*   1.��ѯ������Ϣ         *" << endl;
	cout << "*   2.���ѻ���             *" << endl;
	cout << "*   3.��ѯ�˻�����          *" << endl;
	cout << "*   4.�޸�����             *" << endl;
	cout << "*   5.ע����½             *" << endl;
	cout << "***************************" << endl;
	cout << "��������Ž��в�����" << endl;
	//�����ǲ������ݣ�����ȫ
	cin >> fg;
	switch (fg)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5: Logout(); break;
	default:
		break;
	}
}

void UI::ManagerUI()
{
	int fg;
	Clean();
	cout << "****************************" << endl;
	cout << "*     ��ӭ���뾭�����      *" << endl;
	cout << "*   1.��ѯ��Ա��Ϣ          *" << endl;
	cout << "*   2.�»�Աע��            *" << endl;
	cout << "*   3.��ֵ��Ա����          *" << endl;
	cout << "*   4.ע����½             *" << endl;
	cout << "***************************" << endl;
	cout << "��������Ž��в�����" << endl;
	//�����ǲ������ݣ�����ȫ
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

void UI::SuperUI()
{
	int fg;
	Clean();
	cout << "****************************" << endl;
	cout << "*     ��ӭ���볬���������   *" << endl;
	cout << "*   1.��ѯ�˻���Ϣ          *" << endl;
	cout << "*   2.�»�Աע��            *" << endl;
	cout << "*   3.ɾ����Ա�˻�          *" << endl;
	cout << "*   4.ɾ��������            *" << endl;
	cout << "*   4.��Ա���ֲ���          *" << endl;
	cout << "*   5.���������˻���Ϣ       *" << endl;
	cout << "*   6.ע����½              *" << endl;
	cout << "***************************" << endl;
	cout << "��������Ž��в�����" << endl;
	//�����ǲ������ݣ�����ȫ
	cin >> fg;
	switch (fg)
	{
	case 1:
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
	cout << "�Ƿ�ȷ��ע����Y\N��?" << endl;
	cin >> fg;
	if (fg == 'Y') {
		cout << "********************" << endl;
		cout << "* Log out succeed  *" << endl;
		cout << "********************" << endl;
		getchar();
		LoginUI();
	}
}
