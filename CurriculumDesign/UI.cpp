#include "UI.h"
#include<iostream>
#include"Operator.h"
using namespace std;
UI::UI()
{
	//��־��ʼ��
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

	do //�ж��û���������
	{
		Clean();
		cout << "***********************" << endl;
		cout << "��ӭʹ�û�Ա��¼ϵͳ" << endl;
		cout << "*********************" << endl;
		cout << "�������û�ID:" << endl;
		cin >> id;
		if (Operator::Certid(id)) break;  //������ھ�����ѭ��
		system("Cls");
		cout << "�û��������ڣ��밴�س���������" << endl;
		getchar(); getchar();
	} while (!Operator::Certid(id));//certid()�ǲ����� ����true��˵������
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

	do //�ж������Ƿ���ȷ
	{
		cout << "����������:" << endl;
		cin >> pw;
		if (Operator::Certpw(Person(d), pw) == true) break;  //������ھ�����ѭ��
		cout << "�����������������" << endl;
		getchar();
	} while (Operator::Certpw(Person(d), pw) == false);//certpw()�ǲ����� ����true��˵������
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


void UI::MemberUI(const int inputid)   //���뵱ǰid �������Ƶ�ǰ����
{
	LOGT.AddConduct(inputid, "login", "system");
	int fg;
	while (1) {

		Clean();
		cout << "****************************" << endl;
		cout << "*     ��ӭ�����Ա����    " << endl;
		cout << "*   ��ǰID:" << inputid << endl;
		cout << "*   1.��ѯ������Ϣ        " << endl;
		cout << "*   2.��ѯ�˻�����          " << endl;
		cout << "*   3.�޸�����             " << endl;
		cout << "*   4.ע����½             " << endl;
		cout << "***************************" << endl;
		cout << "��������Ž��в�����" << endl;
		//�����ǲ������ݣ�����ȫ
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
		cout << "*     ��ӭ���뾭�����      " << endl;
		cout << "*   1.��ѯ��Ա��Ϣ          " << endl;
		cout << "*   2.�»�Աע��            " << endl;
		cout << "*   3.��Ա�����޸�          " << endl;
		cout << "*   4.ע����½             " << endl;
		cout << "***************************" << endl;
		cout << "��������Ž��в�����" << endl;
		//�����ǲ������ݣ�����ȫ
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
		cout << "*     ��ӭ���볬���������   " << endl;
		cout << "*   1.��ѯ�˻���Ϣ          " << endl;
		cout << "*   2.�»�Աע��            " << endl;
		cout << "*   3.�¹���Աע��            " << endl;
		cout << "*   4.��ѯ�˻�״̬          " << endl;
		cout << "*   5.��Ա�����޸�          " << endl;
		cout << "*   6.��ʾ�û�����          " << endl;
		cout << "*   7.ע����½              " << endl;
		cout << "***************************" << endl;
		cout << "��������Ž��в�����" << endl;
		//�����ǲ������ݣ�����ȫ
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
	cout << "�Ƿ�ȷ��ע����Y/N��?" << endl;
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
	cout << "��������������" << endl;
	cin >> p->name;
	cout << "����������" << endl;
	cin >> p->password;
	cout << "ȷ����Ϣ" << endl;
	if (IsYes() == true) {
		p->id = LOGT.MemberCount() + MemberStartNumber;
		p->IsUsed = true;
		p->credit = 0;
		manager.CreateMember(p);
		
		system("Cls");
		cout << "****************" << endl;
		cout << "���û�ID��" << p->id << endl;
		cout << "�û�������" << p->name << endl;
		cout << "���룺" << p->password << endl;
		cout << "*******************" << endl;
		cout << "���س����ؽ���" << endl;
		getchar(); getchar();
		LOGT.AddConduct(p->id, "add member",p->name);
	}
	
}

void UI::CreatManagerUI()
{
	D *p = new D;
	system("Cls");

	cout << "********************" << endl;
	cout << "��������������" << endl;
	cin >> p->name;
	cout << "����������" << endl;
	cin >> p->password;
	cout << "ȷ����Ϣ" << endl;
	if (IsYes() == true) {
		p->id = LOGT.ManagerCount() + ManagerStartNumber;
		p->IsUsed = true;
		p->credit = 0;
		CreateManager(p);
		system("Cls");
		cout << "****************" << endl;
		cout << "�¹���ԱID��" << p->id << endl;
		cout << "����Ա������" << p->name << endl;
		cout << "���룺" << p->password << endl;
		cout << "*******************" << endl;
		cout << "���س����ؽ���" << endl;
		getchar(); getchar();
		LOGT.AddConduct(p->id, "add manager", p->name);
	}
}

void UI::ShowAllCount()
{
	Member *mb = new Member();
	for (int i = 1; i <= LOGT.L.NMember; i++) {
		mb->Read(MemberStartNumber + i);
		cout << "�û�ID��" << mb->getid() << endl;
		cout << "�û�������" << mb->getname() << endl;//����û���Ϣ

	}
	cout << "��Ա��ʾ���" << endl;
	getchar(); getchar();
	delete mb;
	Manager *mg = new Manager();
	for (int i = 1; i <= LOGT.L.NManager; i++) {
		mg->Read(ManagerStartNumber + i);
		cout << "����ԱID��" << mg->getid() << endl;
		cout << "����Ա������" << mg->getname() << endl;//����û���Ϣ
		//
		cout << mg->getpass() << endl;
		//
	}
	cout << "����Ա��ʾ���" << endl;
	getchar(); getchar();
}
