#include "FileSys.h"
#include"Member.h"
#include"Person.h"
#include <fstream>
#include <iostream>
const int originID = 10000000;

FileSys::FileSys()
{
}


FileSys::~FileSys()
{
}

void FileSys::readMember(int ID) {

	std::fstream inFile;
	inFile.open("member.txt", std::ios::in | std::ios::binary);
	inFile.seekg((ID - originID)*sizeof(Member), std::ios::beg);
	inFile.read((char*)this,sizeof(Member));
	inFile.close();
//	std::cout << getid() << getname() << std::endl;

}
void FileSys::writeMember() {
	std::fstream outFile;
	outFile.open("member.txt", std::ios::out | std::ios::binary);
	outFile.seekp((this->getid() - originID) * sizeof(Member),std::ios::beg);
	outFile.write((char*)this, sizeof(Member));
	outFile.close();
//	std::cout << getid() << getname() << std::endl;
}