#pragma once
#define Member_h
#include"Person.h"
//��Ա�ȼ��ƶ����ұ���
//��Ա�� 
class Member:public Person {
	int credit; //����
public:
	Member(char *inputname, int inputid, int inputpassword);
	int getcredit() { return credit; }
	void show();
	friend class Operator;
};