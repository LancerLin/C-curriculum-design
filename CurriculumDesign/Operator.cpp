#include "Operator.h"
#include<iostream>
const int MemberStartNumber = 10000000;
const int ManagerStartNumber = 10000;
#define memberpath "member.txt"
#define managerpath "manager.txt"
using namespace std;
void Operator::createMember(char *inputname, int inputid, int inputpassword)
{
	//Member::Member(inputname, inputid, inputpassword);
	//文件操作:会员数量++
}

void Operator::createManager(char * inputname, int inputid, int inputpassword)
{
	//Manager::Manager(inputname, inputid, inputpassword);
	//文件操作:会员数量++
}

bool Operator::certid(int inputid)
{
	Person *_p = new Person();
	char filename[20] = {0};
	if (inputid >= MemberStartNumber) {
		strcpy_s(filename,memberpath);
	}
	else if (inputid >= ManagerStartNumber) {
		strcpy_s(filename, managerpath);
	}
	std::fstream inFile;
	inFile.open(filename, std::ios::in | std::ios::out | std::ios::binary);
	inFile.seekg((inputid - originID) * sizeof(D), std::ios::beg);
	inFile.read((char*)_p, sizeof(D));
	inFile.close();
	return _p->isued();
}

bool Operator::certpw(Person &p, int inputpw)
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
	inFile.seekg((p.getid() - originID) * sizeof(D), std::ios::beg);
	inFile.read((char*)_p, sizeof(D));
	inFile.close();
	return _p->getpass()==inputpw;
}

D * Operator::ReID(int inputid)
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
	inFile.seekg((inputid - originID) * sizeof(D), std::ios::beg);
	inFile.read((char*)_p, sizeof(D));
	inFile.close();
	return _p;
}
