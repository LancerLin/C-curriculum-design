#pragma once
#include"Person.h"
#include"FileSys.h"
//��Ա�ȼ��ƶ����ұ���
//��Ա�� 
class Member:virtual public Person,public FileSys {
//	int credit; //����
public:
	Member();
	Member(Person &p);

};