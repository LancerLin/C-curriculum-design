#pragma once
//���� Person.h
//������������ ���ܲ鿴����
class Person{
	char name[20];
	int id; //���Ⱦ����ȼ�
	int password;
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
