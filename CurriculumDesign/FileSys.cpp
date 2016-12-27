#include "FileSys.h"
//#include"Member.h"
//#include"Person.h"
#include <fstream>
#include <iostream>
//const int originID = 10000000;

FileSys::FileSys()
{
}


FileSys::~FileSys()
{
}
//member根据ID读取文件信息
//P.S.会覆盖内存完整信息
//==============================已经转移到member read/write下
/*
void FileSys::readMember(int ID) {
	std::fstream inFile;
	inFile.open("member.txt", std::ios::in |std::ios::out| std::ios::binary);
	inFile.seekg((ID - originID)*sizeof(D), std::ios::beg);
	inFile.read((char*)getdata(),sizeof(D));
	inFile.close();
}
//member直接写入文件
void FileSys::writeMember() {
	std::fstream outFile;
	outFile.open("member.txt", std::ios::in|std::ios::out | std::ios::binary);
	outFile.seekp((getid() - originID) * sizeof(D),std::ios::beg);
	outFile.write((char*)getdata(), sizeof(D));
	outFile.close();
}
//===============================
*/

/*
//Manager根据ID读取文件信息
//P.S.会覆盖内存完整信息
void FileSys::readManager(int ID) {
	std::fstream inFile;
	inFile.open("manager.txt", std::ios::in | std::ios::out | std::ios::binary);
	inFile.seekg((ID - originID) * sizeof(D), std::ios::beg);
	inFile.read((char*)getdata(), sizeof(D));
	inFile.close();
}
//Manager直接写入文件
void FileSys::writeManager() {
	std::fstream outFile;
	outFile.open("manager.txt", std::ios::in | std::ios::out | std::ios::binary);
	outFile.seekp((getid() - originID) * sizeof(D), std::ios::beg);
	outFile.write((char*)getdata(), sizeof(D));
	outFile.close();
}
*/

//日志信息及基本信息
/*
number of member

*/
/*
void FileSys::readLog() {
	std::fstream inFile;
	inFile.open("log.txt", std::ios::in | std::ios::out | std::ios::binary);
	inFile.seekg((ID - originID) * sizeof(D), std::ios::beg);
	inFile.read((char*)getdata(), sizeof(D));
	inFile.close();
}
//日志写存在各种环节
void FileSys::writeMember() {
	std::fstream outFile;
	outFile.open("member.txt", std::ios::in | std::ios::out | std::ios::binary);
	outFile.seekp((getid() - originID) * sizeof(D), std::ios::beg);
	outFile.write((char*)getdata(), sizeof(D));
	outFile.close();
}
*/