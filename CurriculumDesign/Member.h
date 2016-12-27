#pragma once
#include"Person.h"
#include"FileSys.h"
#include <fstream>

//会员等级制度暂且保留
//会员类 
class Member :virtual public Person, public FileSys {

public:
	Member();
	Member(Person &p);
	void createMember(char *inputname, int inputid, int inputpassword);
};