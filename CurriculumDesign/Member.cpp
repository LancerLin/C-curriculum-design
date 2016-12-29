#include "Member.h"

Member::Member():Person(){
}

Member::Member(Person &p):Person(p) {
}

void Member::read(int ID)
{
	std::fstream inFile;
	inFile.open(memberpath, std::ios::in | std::ios::out | std::ios::binary);
	inFile.seekg((ID - MemberStartNumber) * sizeof(D), std::ios::beg);
	inFile.read((char*)getdata(), sizeof(D));
	inFile.close();
}

void Member::write()
{
	std::fstream outFile;
	outFile.open(memberpath, std::ios::in | std::ios::out | std::ios::binary);
	outFile.seekp((getid() - MemberStartNumber) * sizeof(D), std::ios::beg);
	outFile.write((char*)getdata(), sizeof(D));
	outFile.close();
}
/*operator 功能
void Member::check()
{
	Person  *p = new Person();
	read(getid());
}
*/
/*  manager 功能
void Member::createMember()
{
	
	Person *p;
	p = new Person(CreatMemberUI());
	p->
	Member *m = new Member(*p);
	m->write();
	
}*/
