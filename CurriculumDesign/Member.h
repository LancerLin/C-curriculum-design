#pragma once
#define Member_h
#include"Person.h"
//会员等级制度暂且保留
//会员类 
class Member:public Person {
	int credit; //积分
public:
	Member(char *inputname, int inputid, int inputpassword);
	int getcredit() { return credit; }
	void show();
	friend class Operator;
};