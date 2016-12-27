#include "FileSys.h"
#include <fstream>
#include <iostream>
const int originID = 10000000;

FileSys::FileSys()
{
}


FileSys::~FileSys()
{
} 

void FileSys::readMember(Person &p,int ID) {
	std::ifstream inFile;
	inFile.open("member.txt", std::ios::in | std::ios::binary);
	inFile.seekg((ID - originID)*(sizeof(Person)), std::ios::beg);
	inFile.read((char*)&p,sizeof(Person));
	inFile.close();
	std::cout << p.getid() << p.getname() << std::endl;

}
void FileSys::writeMember(Person &p) {
	std::ofstream outFile;
	outFile.open("member.txt", std::ios::out | std::ios::binary);
	outFile.seekp((p.getid() - originID) * sizeof(Person));
	outFile.write((char*)&p, sizeof(Person));
	outFile.close();
}