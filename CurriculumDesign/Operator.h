#pragma once
#include"Person.h"
#include"Member.h"
#include"Manager.h"
class Operator {
public:
	void setpassword(Person &p, int x) { p.password = x; }
	void createMember(char *inputname, int inputid, int inputpassword);
	void createManager(char *inputname, int inputid, int inputpassword);
	bool certid(int inputid);   //�ж�id����������� ����ture����
	bool certpw(int inputpw);
	virtual void checkid() = 0;  //��ѯid��Ϣ����Ϊ���麯�� ��Ҫ���¶���


};
