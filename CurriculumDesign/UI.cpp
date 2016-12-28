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
	cout << "��ӭʹ�û�Ա��¼ϵͳ" << endl;

	do //�ж��û���������
	{
		cout << "�������û�ID:" << endl;
		cin >> id;
		if (Operator::certid(id) == true) break;  //������ھ�����ѭ��
		cout << "�û���������������" << endl;
		getchar();
	} while (Operator::certid(id) == false);//certid()�ǲ����� ����true��˵������

	do //�ж������Ƿ���ȷ
	{
		cout << "����������:" << endl;
		cin >> pw;
		if (Operator::certid(id) == true) break;  //������ھ�����ѭ��
		cout << "�����������������" << endl;
		getchar();
	} while (Operator::certid(id) == false);//certpw()�ǲ����� ����true��˵������
	if (id > 100000) {
		MemberUI(id);
	}
	else if (id < 1000) {
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


void UI::MemberUI(int inputid)   //���뵱ǰid �������Ƶ�ǰ����
{
	int id = inputid;
	int fg;
	Clean();
	cout << "****************************" << endl;
	cout << "*     ��ӭ�����Ա����      *" << endl;
	cout << "*   1.��ѯ������Ϣ         *" << endl;
	cout << "*   3.��ѯ�˻�����          *" << endl;
	cout << "*   4.�޸�����             *" << endl;
	cout << "*   5.ע����½             *" << endl;
	cout << "***************************" << endl;
	cout << "��������Ž��в�����" << endl;
	//�����ǲ������ݣ�����ȫ
	cin >> fg;
	switch (fg)
	{
	case 1:Checkinfo(id);
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
	cout << "*   3.ע�� �ָ��˻�          *" << endl;
	cout << "*   4.��Ա���ֲ���          *" << endl;
	cout << "*   5.���������˻���Ϣ       *" << endl;
	cout << "*   6.ע����½              *" << endl;
	cout << "***************************" << endl;
	cout << "��������Ž��в�����" << endl;
	//�����ǲ������ݣ�����ȫ
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

void UI::Checkinfo()
{
	int inputid;
	cout << "***************" << endl;
	cout << "�������ѯ���˻�ID" << endl;

	cin >> inputid;
	if (Operator::certid(inputid) == false) {
		cout << "�������ID�����ڣ������ز�������" << endl;
		getchar();
	}
	else if (Operator::certid(inputid) == true) {
		Member *m = new Member();  //�����������ڻ�ȡid��λ���Ա����
		m->read(inputid);
		cout << "*******************" << endl;
		cout << "�û�������" << m->getname << endl;
		cout << "�û�ID��" << m->getid << endl;
		cout << "�û����֣�" << m->getcredit << endl;
		cout << "ʹ�������" << m->isued << endl;
		cout << "*******************" << endl;
	}
}

void UI::Checkinfo(int inputid)
{
	Member *m = new Member();  //�����������ڻ�ȡid��λ���Ա����
	m->read(inputid);
	cout << "*******************" << endl;
	cout << "�û�������" << m->getname << endl;
	cout << "�û�ID��" << m->getid << endl;
	cout << "�û����֣�" << m->getcredit << endl;
	cout << "ʹ�������" << m->isued << endl;
	cout << "*******************" << endl;

}
D* UI::CreatMemberUI()
{

	D *p = new D;
	cout << "********************" << endl;
	cout << "��������������" << endl;
	cin >> p->name;
	cout << "����������" << endl;
	cin >> p->password;
	//	p->id = 0;        ��ȡID
	p->IsUsed = true;
	p->credit = 0;
	return p;
	// TODO: �ڴ˴����� return ���
}
