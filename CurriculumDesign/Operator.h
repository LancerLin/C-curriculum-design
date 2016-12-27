#pragma once
#include"Person.h"
#include"Member.h"
#include"Manager.h"
class Operator {
public:
	void setpassword(Person &p, int x) { p.password = x; }
	void createMember(char *inputname, int inputid, int inputpassword);
	void createManager(char *inputname, int inputid, int inputpassword);
	bool certid(int inputid);   //判断id或密码存在性 返回ture存在
	bool certpw(int inputpw);
	virtual void checkid() = 0;  //查询id信息，此为纯虚函数 需要重新定义


};
