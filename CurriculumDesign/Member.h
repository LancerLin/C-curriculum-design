#pragma once
#include"Person.h"
#include"FileSys.h"
#include <fstream>
#include"baseinfo.h"
//��Ա�ȼ��ƶ����ұ���
//��Ա�� 
class Member :virtual public Person,virtual public FileSys {

public:
	Member();
//	Member(D &d);
	Member(Person &p);
	void Read(int ID);
	void Write();
//	void createMember(); �����ҵĹ���
};