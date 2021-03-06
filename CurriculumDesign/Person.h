#pragma once
//基类 Person.h
//不能设置姓名 不能查看密码
typedef struct DATA {
	char name[20];
	int id; //长度决定等级
	int password;
	int credit;
	bool IsUsed;
}D;

class Person{
private:
	D data;
public:
	Person(char *inputname, int inputid, int inputpassword, int inputcredit=0);
	Person();
	Person(D *d);
	Person(Person &p);
	D* getdata() { return &data; }
	int getpass() { return data.password; }
	int getid() { return data.id; }
	int getcredit() { return data.credit; }
	char *getname() { return data.name; }
	bool isued() { return data.IsUsed; }
	void setpassword(int x) { data.password = x; }
	void show();//显示姓名和id和credit
//	friend class Operator;
};
