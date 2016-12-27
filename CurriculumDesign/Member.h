#pragma once
#include"Person.h"
#include"FileSys.h"
#include <fstream>
const int originID = 10000000;
//会员等级制度暂且保留
//会员类 
class Member :virtual public Person, public FileSys {

public:
	Member();
	Member(Person &p);
	void read(int ID);
	void write();
	void createMember(char *inputname, int inputid, int inputpassword);
};