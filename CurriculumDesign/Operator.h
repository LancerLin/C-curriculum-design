#pragma once
#include"Person.h"
#include"Member.h"
#include"Manager.h"

class Operator:virtual public Member,virtual public Manager {
public:
	//void setpassword(Person &p, int x) { p.password = x; }
	void createMember(char *inputname, int inputid, int inputpassword);
	void createManager(char *inputname, int inputid, int inputpassword);
	bool certid(int inputid);   //判断id或密码存在性 返回ture存在
	bool certpw(Person &p,int inputpw);
};
