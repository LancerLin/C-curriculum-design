#pragma once
#include"Person.h"
#include"FileSys.h"
#include <fstream>

const int OriginID = 10000000;
//会员等级制度暂且保留
//会员类 
class Member :virtual public Person,virtual public FileSys {

public:
	Member();
//	Member(D &d);
	Member(Person &p);
	void read(int ID);
	void write();
//	void createMember(); 不是我的功能
};