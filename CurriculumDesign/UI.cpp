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
	cout << "��ӭʹ�û�Ա��¼ϵͳ" << endl;

	do //�ж��û���������
	{
		cout << "�������û�ID:" << endl;
		cin >> id;
		if (Operator::Certid(id) == true) break;  //������ھ�����ѭ��
		cout << "�û���������������" << endl;
		getchar();
	} while (Operator::Certid(id) == false);//certid()�ǲ����� ����true��˵������

	do //�ж������Ƿ���ȷ
	{
		cout << "����������:" << endl;
		cin >> pw;
		if (Operator::Certid(id) == true) break;  //������ھ�����ѭ��
		cout << "�����������������" << endl;
		getchar();
	} while (Operator::Certid(id) == false);//certpw()�ǲ����� ����true��˵������
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


void UI::MemberUI(const int inputid)   //���뵱ǰid �������Ƶ�ǰ����
{

	int fg;
	while (1) {

		Clean();
		cout << "****************************" << endl;
		cout << "*     ��ӭ�����Ա����      *" << endl;
		cout << "*   1.��ѯ������Ϣ         *" << endl;
		cout << "*   2.��ѯ�˻�����          *" << endl;
		cout << "*   3.�޸�����             *" << endl;
		cout << "*   4.ע����½             *" << endl;
		cout << "***************************" << endl;
		cout << "��������Ž��в�����" << endl;
		//�����ǲ������ݣ�����ȫ
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
		cout << "*     ��ӭ���뾭�����      *" << endl;
		cout << "*   1.��ѯ��Ա��Ϣ          *" << endl;
		cout << "*   2.�»�Աע��            *" << endl;
		cout << "*   3.��Ա�����޸�          *" << endl;
		cout << "*   4.ע����½             *" << endl;
		cout << "***************************" << endl;
		cout << "��������Ž��в�����" << endl;
		//�����ǲ������ݣ�����ȫ
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
		cout << "*     ��ӭ���볬���������   *" << endl;
		cout << "*   1.��ѯ�˻���Ϣ          *" << endl;
		cout << "*   2.�»�Աע��            *" << endl;
		cout << "*   3.��ѯ�˻�״̬          *" << endl;
		cout << "*   4.��Ա�����޸�          *" << endl;
		cout << "*   5.��ʾ�û�����          *" << endl;
		cout << "*   6.ע����½              *" << endl;
		cout << "***************************" << endl;
		cout << "��������Ž��в�����" << endl;
		//�����ǲ������ݣ�����ȫ
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
	cout << "�Ƿ�ȷ��ע����Y/N��?" << endl;
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
	cout << "��������������" << endl;
	cin >> p->name;
	cout << "����������" << endl;
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
		cout << "��ԱID��" << m->getid() << endl;
		cout << "������" << m->getname() << endl;
		cout << "��Ա����"<< m->getcredit;//����û���Ϣ
		cout << "�˻�״̬";
		if (m->isued == true) {
			cout << "����" << endl;
		}
		else if (m->isued == false) {
			cout << "����" << endl;
		}
		cout << "*****************" << endl;
	}
	delete m;
	Manager *m = new Manager();
	for (int i = 0; i < LOGT.L.NManager; i++) {
		m->read(ManagerStartNumber + i);
		cout << "*****************" << endl;
		cout << "����ԱID��" << m->getid() << endl;
		cout << "������" << m->getname() << endl;
		cout << "�˻�״̬";
		if (m->isued == true) {
			cout << "����" << endl;
		}
		else if (m->isued == false) {
			cout << "����" << endl;
		}
		cout << "*****************" << endl;
	}
}
