#pragma once
#include"Person.h"
#include"FileSys.h"
#include <fstream>

const int OriginID = 10000000;
//��Ա�ȼ��ƶ����ұ���
//��Ա�� 
class Member :virtual public Person,virtual public FileSys {

public:
	Member();
//	Member(D &d);
	Member(Person &p);
	void read(int ID);
	void write();
//	void createMember(); �����ҵĹ���
};