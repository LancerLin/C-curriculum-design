#pragma once
//���� Person.h
//������������ ���ܲ鿴����
typedef struct DATA {
	char name[20];
	int id; //���Ⱦ����ȼ�
	int password;
	int credit;
	bool IsUsed;
}D;

class Person{
private:
	D data;
public:
	Person(char *inputname, int inputid, int inputpassword, int inputcredit);
	Person();
	Person(D *d);
	Person(Person &p);
	D* getdata() { return &data; }
	int getpass() { return data.password; }
	int getid() { return data.id; }
	int getcredit() { return data.credit; }
	char *getname() { return data.name; }
//	friend void setpassword(int x) { password = x; }
	void show();//��ʾ������id
//	friend class Operator;
};
