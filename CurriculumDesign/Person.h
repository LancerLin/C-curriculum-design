#pragma once
//���� Person.h
//������������ ���ܲ鿴����
#include"Count.h"
class Person:public Count{
	char name[20];
	int id; //���Ⱦ����ȼ�
	double password;
	bool IsUsed;
public:
	Person(char *inputname, int inputid, int inputpassword);
	Person();
	int getid() { return id; }
	char *getname() { return name; }
	//friend void setpassword(int x) { password = x; }
	void show();//��ʾ������id
	friend class Operator;
};
