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

	std::ifstream inFile;
	inFile.open("member.txt", std::ios::in | std::ios::binary);
	inFile.seekg((ID - originID + 1)*(sizeof(Member)), std::ios::beg);
	inFile.read((char*)this,sizeof(Member));
	inFile.close();
//	std::cout << getid() << getname() << std::endl;

}
void FileSys::writeMember() {
	std::ofstream outFile;
	outFile.open("member.txt", std::ios::out | std::ios::binary);
	outFile.seekp((this->getid() - originID + 1) * sizeof(Member));
	outFile.write((char*)this, sizeof(Member));
	outFile.close();
//	std::cout << getid() << getname() << std::endl;
}