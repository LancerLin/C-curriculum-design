#pragma once
#include"Person.h"
#include"FileSys.h"
#include <fstream>
#include"UI.h"
const int originID = 10000000;
//会员等级制度暂且保留
//会员类 
class Member :virtual public Person, public FileSys,public UI {

public:
	Member();
	Member(D &d);
	Member(Person &p);
	void read(int ID);
	void write();
	void createMember();
};