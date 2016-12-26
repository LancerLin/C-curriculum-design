#pragma once
#define Person_h
//基类 Person.h
//不能设置姓名 不能查看密码
class Person{
	char name[20];
	int id;
	int password;
public:
	Person(char *name, int id, int password);
	Person();
	int getid() { return id; }
	char *getname() { return name; }
	void setpassword(int x) { password = x; }
	void show();//显示姓名和id
};
