#pragma once
#include"Person.h"
#include"FileSys.h"
#include <fstream>

//��Ա�ȼ��ƶ����ұ���
//��Ա�� 
class Member :virtual public Person, public FileSys {

public:
	Member();
	Member(Person &p);
	void createMember(char *inputname, int inputid, int inputpassword);
};