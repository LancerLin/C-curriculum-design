#include "Member.h"

Member::Member():Person(){
}

Member::Member(Person &p):Person(p) {
}

void Member::Read(int ID)
{
	std::fstream inFile;
	inFile.open(memberpath, std::ios::in | std::ios::out | std::ios::binary);
	inFile.seekg((ID - MemberStartNumber) * sizeof(D), std::ios::beg);
	inFile.read((char*)getdata(), sizeof(D));
	inFile.close();
}

void Member::Write()
{
	std::fstream outFile;
	outFile.open(memberpath, std::ios::in | std::ios::out | std::ios::binary);
	outFile.seekp((getid() - MemberStartNumber) * sizeof(D), std::ios::beg);
	outFile.write((char*)getdata(), sizeof(D));
	outFile.close();
}
/*operator ����
void Member::check()
{
	Person  *p = new Person();
	read(getid());
}
*/
/*  manager ����
void Member::createMember()
{
	
	Person *p;
	p = new Person(CreatMemberUI());
	p->
	Member *m = new Member(*p);
	m->write();
	
}*/
