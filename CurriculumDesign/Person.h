#pragma once
//���� Person.h
//������������ ���ܲ鿴����
class Person{
private:
	char name[20];
	int id; //���Ⱦ����ȼ�
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
	void show();//��ʾ������id
	friend class Operator;
};
