#pragma once
#include"Person.h"
#include"FileSys.h"
//会员等级制度暂且保留
//会员类 
class Member:virtual public Person,public FileSys {
//	int credit; //积分
public:
	Member();
	Member(Person &p);

};