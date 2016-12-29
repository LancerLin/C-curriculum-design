#include "Manager.h"

Manager::Manager():Person()
{
}

Manager::Manager(Person & p):Person(p)
{
}

void Manager::Read(int ID)
{
	std::fstream inFile;
	inFile.open(managerpath, std::ios::in | std::ios::out | std::ios::binary);
	inFile.seekg((ID - ManagerStartNumber) * sizeof(D), std::ios::beg);
	inFile.read((char*)getdata(), sizeof(D));
	inFile.close();
}

void Manager::Write()
{
	std::fstream outFile;
	outFile.open(managerpath, std::ios::in | std::ios::out | std::ios::binary);
	outFile.seekp((getid() - ManagerStartNumber) * sizeof(D), std::ios::beg);
	outFile.write((char*)getdata(), sizeof(D));
	outFile.close();
}

void Manager::CreateMember(D *d)
{
	Member *p = new Member(Person(d));
	p->Member::Write();
}
