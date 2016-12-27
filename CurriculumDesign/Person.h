#pragma once
//基类 Person.h
//不能设置姓名 不能查看密码
#include"Count.h"
class Person:public Count{
	char name[20];
	int id; //长度决定等级
	double password;
	bool IsUsed;
public:
	Person(char *inputname, int inputid, int inputpassword);
	Person();
	int getid() { return id; }
	char *getname() { return name; }
	//friend void setpassword(int x) { password = x; }
	void show();//显示姓名和id
	friend class Operator;
};
