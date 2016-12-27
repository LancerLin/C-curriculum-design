#pragma once
//基类 Person.h
//不能设置姓名 不能查看密码
class Person{
private:
	char name[20];
	int id; //长度决定等级
	int password;
	int credit;
	bool IsUsed;
public:
	Person(char *inputname, int inputid, int inputpassword, int inputcredit);
	Person();
	Person(Person &p);
	int getpass() { return password; }
	int getid() { return id; }
	int getcredit() { return credit; }
	char *getname() { return name; }
	//friend void setpassword(int x) { password = x; }
	void show();//显示姓名和id
	friend class Operator;
};
