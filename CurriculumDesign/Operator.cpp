#include "Operator.h"
#include<iostream>
const int MemberStartNumber = 10000000;
const int ManagerStartNumber = 10000;
#define memberpath "member.txt"
#define managerpath "manager.txt"
using namespace std;
void Operator::CreateMember(char *inputname, int inputid, int inputpassword)
{
	//Member::Member(inputname, inputid, inputpassword);
	//�ļ�����:��Ա����++
}

void Operator::CreateManager(char * inputname, int inputid, int inputpassword)
{
	//Manager::Manager(inputname, inputid, inputpassword);
	//�ļ�����:��Ա����++
}

bool Operator::Certid(int inputid)
{
	Person *_p = new Person();
	char filename[20] = { 0 };
	if (inputid >= MemberStartNumber) {
		strcpy_s(filename, memberpath);
	}
	else if (inputid >= ManagerStartNumber) {
		strcpy_s(filename, managerpath);
	}
	std::fstream inFile;
	inFile.open(filename, std::ios::in | std::ios::out | std::ios::binary);
	inFile.seekg((inputid - OriginID) * sizeof(D), std::ios::beg);
	inFile.read((char*)_p, sizeof(D));
	inFile.close();
	return _p->isued();
}

bool Operator::Certpw(Person &p, int inputpw)
{
	Person *_p = new Person();
	char filename[20] = { 0 };
	if (p.getid() >= MemberStartNumber) {
		strcpy_s(filename, memberpath);
	}
	else if (p.getid() >= ManagerStartNumber) {
		strcpy_s(filename, managerpath);
	}
	std::fstream inFile;
	inFile.open(filename, std::ios::in | std::ios::out | std::ios::binary);
	inFile.seekg((p.getid() - OriginID) * sizeof(D), std::ios::beg);
	inFile.read((char*)_p, sizeof(D));
	inFile.close();
	return _p->getpass()==inputpw;
}

void Operator::Checkinfo()
{
	int inputid;
	cout << "***************" << endl;
	cout << "�������ѯ���˻�ID" << endl;

	cin >> inputid;
	if (Operator::Certid(inputid) == false) {
		cout << "�������ID�����ڣ������ز�������" << endl;
		getchar();
	}
	else if (Operator::Certid(inputid) == true) {
		Member *m = new Member();  //�����������ڻ�ȡid��λ���Ա����
		m->read(inputid);
		cout << "*******************" << endl;
		cout << "�û�������" << m->getname() << endl;
		cout << "�û�ID��" << m->getid() << endl;
		cout << "�û����֣�" << m->getcredit() << endl;
		cout << "ʹ�������" << m->isued() << endl;
		cout << "*******************" << endl;
	}
}

void Operator::Checkinfo(int inputid)
{
	Member *m = new Member();  //�����������ڻ�ȡid��λ���Ա����
	m->read(inputid);
	cout << "*******************" << endl;
	cout << "�û�������" << m->getname() << endl;
	cout << "�û�ID��" << m->getid() << endl;
	cout << "�û����֣�" << m->getcredit() << endl;
	cout << "ʹ�������" << m->isued() << endl;
	cout << "*******************" << endl;

}

void Operator::ChangePw()
{
	int inputid;
	cout << "***************" << endl;
	cout << "��������Ҫ�޸������ID" << endl;

	cin >> inputid;
	if (Operator::Certid(inputid) == false) {
		cout << "�������ID�����ڣ������ز�������" << endl;
		getchar();
	}
	else if (Operator::Certid(inputid) == true) {
		Member *m = new Member();
		m->read(inputid);
		cout
	}
}
