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
//member����ID��ȡ�ļ���Ϣ
//P.S.�Ḳ���ڴ�������Ϣ
//==============================�Ѿ�ת�Ƶ�member read/write��
/*
void FileSys::readMember(int ID) {
	std::fstream inFile;
	inFile.open("member.txt", std::ios::in |std::ios::out| std::ios::binary);
	inFile.seekg((ID - originID)*sizeof(D), std::ios::beg);
	inFile.read((char*)getdata(),sizeof(D));
	inFile.close();
}
//memberֱ��д���ļ�
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
//Manager����ID��ȡ�ļ���Ϣ
//P.S.�Ḳ���ڴ�������Ϣ
void FileSys::readManager(int ID) {
	std::fstream inFile;
	inFile.open("manager.txt", std::ios::in | std::ios::out | std::ios::binary);
	inFile.seekg((ID - originID) * sizeof(D), std::ios::beg);
	inFile.read((char*)getdata(), sizeof(D));
	inFile.close();
}
//Managerֱ��д���ļ�
void FileSys::writeManager() {
	std::fstream outFile;
	outFile.open("manager.txt", std::ios::in | std::ios::out | std::ios::binary);
	outFile.seekp((getid() - originID) * sizeof(D), std::ios::beg);
	outFile.write((char*)getdata(), sizeof(D));
	outFile.close();
}
*/

//��־��Ϣ��������Ϣ
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
//��־д���ڸ��ֻ���
void FileSys::writeMember() {
	std::fstream outFile;
	outFile.open("member.txt", std::ios::in | std::ios::out | std::ios::binary);
	outFile.seekp((getid() - originID) * sizeof(D), std::ios::beg);
	outFile.write((char*)getdata(), sizeof(D));
	outFile.close();
}
*/