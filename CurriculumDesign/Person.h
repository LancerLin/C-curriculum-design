#pragma once
#define Person_h
//���� Person.h
//������������ ���ܲ鿴����
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
	void show();//��ʾ������id
};
