#include "Operator.h"
#include<iostream>

using namespace std;
/*
void Operator::CreateMember(char *inputname, int inputid, int inputpassword)
{
	//Member::Member(inputname, inputid, inputpassword);
	//�ļ�����:��Ա����++
}
*/


void Operator::CreateManager(D * d)
{
	Manager *p = new Manager(Person(d));
	p->Manager::Write();
}

bool Operator::Certid(int inputid)
{
	if (SuperID == inputid) {
		return true;
	}
	Person *_p = new Person();
	char filename[20] = { 0 };
	int StartNumber = 0;
	if (inputid >= MemberStartNumber) {
		strcpy_s(filename, memberpath);
		StartNumber = MemberStartNumber;
	}
	else if (inputid >= ManagerStartNumber) {
		strcpy_s(filename, managerpath);
		StartNumber = ManagerStartNumber;
	}
	std::fstream inFile;
	inFile.open(filename, std::ios::in | std::ios::out | std::ios::binary);
	inFile.seekg((inputid - StartNumber) * sizeof(D), std::ios::beg);
	inFile.read((char*)_p, sizeof(D));
	inFile.close();
	return _p->isued();
}

bool Operator::Certpw(Person &p, int inputpw)
{
	if (p.getpass() == inputpw) {
		return true;
	}
	Person *_p = new Person();
	char filename[20] = { 0 };
	int StartNumber = 0;
	if (p.getid() >= MemberStartNumber) {
		strcpy_s(filename, memberpath);
		StartNumber = MemberStartNumber;
	}
	else if (p.getid() >= ManagerStartNumber) {
		strcpy_s(filename, managerpath);
		StartNumber = ManagerStartNumber;
	}
	std::fstream inFile;
	inFile.open(filename, std::ios::in | std::ios::out | std::ios::binary);
	inFile.seekg((p.getid() - StartNumber) * sizeof(D), std::ios::beg);
	inFile.read((char*)_p, sizeof(D));
	inFile.close();
	return _p->getpass() == inputpw;
}

void Operator::Checkinfo()
{
	int inputid;
	system("Cls");
	cout << "***************" << endl;
	cout << "�������ѯ���˻�ID" << endl;

	cin >> inputid;
	if (Operator::Certid(inputid) == false) {
		cout << "�������ID�����ڣ����س����ز�������" << endl;
		getchar(); getchar();
		return;
	}
	else if (Operator::Certid(inputid) == true) {
		Member *m = new Member();  //�����������ڻ�ȡid��λ���Ա����
		m->Read(inputid);
		system("Cls");
		cout << "*******************" << endl;
		cout << "�û�������" << m->getname() << endl;
		cout << "�û�ID��" << m->getid() << endl;
		cout << "�û����֣�" << m->getcredit() << endl;
		cout << "ʹ�������" << m->isued() << endl;
		cout << "*******************" << endl;
		cout << "���س����ؽ���" << endl;
	}
	getchar(); getchar();
}

void Operator::Checkinfo(int inputid)
{
	Member *m = new Member();  //�����������ڻ�ȡid��λ���Ա����
	m->Read(inputid);
	system("Cls");
	cout << "*******************" << endl;
	cout << "�û�������" << m->getname() << endl;
	cout << "�û�ID��" << m->getid() << endl;
	cout << "�û����֣�" << m->getcredit() << endl;
	cout << "ʹ�������" << m->isued() << endl;
	cout << "*******************" << endl;
	cout << "���س����ؽ���" << endl;
	getchar(); getchar();
}

void Operator::ChangePw()
{
	int inputid, NewPw, tp;
	cout << "***************" << endl;
	cout << "��������Ҫ�޸������ID" << endl;

	cin >> inputid;
	if (Operator::Certid(inputid) == false) {
		cout << "�������ID�����ڣ������ز�������" << endl;
		getchar();
		return;
	}
	else if (Operator::Certid(inputid) == true) {
		Member *m = new Member();
		m->Read(inputid);
		cout << "*****************" << endl;
		cout << "������������:";
		cin >> NewPw;
		cout << "���ٴ����������룺";
		cin >> tp;
		if (NewPw == tp) {
			cout << "������Ϊ" << NewPw << endl;
			if (IsYes() == true) {
				m->setpassword(NewPw);
				cout << "���������óɹ�" << endl;
				getchar();
				return;
			}
		}


	}
}

void Operator::ChangePw(int inputid)
{
	int NewPw, tp;
	Member *m = new Member();
	m->Read(inputid);
	system("Cls");
	cout << "*****************" << endl;
	cout << "������������:";
	cin >> NewPw;
	cout << "���ٴ����������룺";
	cin >> tp;
	if (NewPw == tp) {
		if (IsYes() == true) {
			m->setpassword(NewPw);
			cout << "���������óɹ�" << endl;
			cout << "������Ϊ" << m->getpass() << endl;
			m->Write();
			getchar(); getchar();
			return;
		}
	}
}

void Operator::ChangeIsused()
{
	int inputid;
	cout << "***************" << endl;
	cout << "��������Ҫ��ѯ���û�״̬" << endl;
	cin >> inputid;
	if (Operator::Certid(inputid) == false) {
		cout << "�������ID�����ڣ������ز�������" << endl;
		getchar();
		return;
	}
	else if (Operator::Certid(inputid) == true) {
		Member *m = new Member();
		m->Read(inputid);
		cout << "�û�IDΪ��" << m->getid() << endl;
		cout << "�˻���ǰ״̬Ϊ" ;
		if (m->isued() == true) {
			cout << "����" << endl;
		}
		else if (m->isued() == false) {
			cout << "����" << endl;
		}
		cout << "�Ƿ�Ҫ�޸��û�״̬" << endl;
		if (IsYes() == true) {
			Member *m = new Member();
			m->Read(inputid);
			D *d = new D();
			d->credit = m->getcredit();
			d->id = !m->getid();
			d->IsUsed =  m->isued();
			d->password = m->getpass();
			delete m;
			m = new Member(Person(d));
			m->Write();
			cout << "****************" << endl;
			cout << "�û�ID:" << m->getid() << endl;
			cout << "�˻���ǰ״̬Ϊ";
			if (m->isued() == true) {
				cout << "����" << endl;
			}
			else if (m->isued() == false) {
				cout << "����" << endl;
			}
			cout << "*******************" << endl;
		}
		getchar();
		return;
	}
}

void Operator::ChangeCredit()
{
	int inputid, credit;
	cout << "***************" << endl;
	cout << "��������Ҫ�޸������ID" << endl;

	cin >> inputid;
	if (Operator::Certid(inputid) == false) {
		cout << "�������ID�����ڣ������ز�������" << endl;
		getchar();
		return;
	}
	else if (Operator::Certid(inputid) == true) {
		cout << "������Ҫ���ӵĻ���" << endl;
		cin >> credit;
		if (IsYes() == true) {

			Member *m = new Member();
			m->Read(inputid);
			D *d = new D();
			d->credit = credit;
			d->id = m->getid();
			d->IsUsed = m->isued();
			d->password = m->getpass();
			delete m;
			m = new Member(Person(d));
			m->Write();
			cout << "****************" << endl;
			cout << "�û�ID:" << m->getid() << endl;
			cout << "�û�����:" << m->getcredit() << endl;
			cout << "*******************" << endl;
		}
			return;
	}

}




bool Operator::IsYes()
{
	char fg;
	cout << "******************" << endl;
	cout << "�Ƿ�ȷ����y/n��?" << endl;
	cin >> fg;
	switch (fg)
	{
	case 'y':return true; break;
	case'n':return false; break;
	default:
		cout << "ERROR" << endl;
		getchar();
		return IsYes();
		break;
	}

}
