#pragma once
#include"Person.h"
#include"Member.h"
#include"Manager.h"
#include"baseinfo.h"
class Operator:virtual public Member,virtual public Manager{
public:
	//void setpassword(Person &p, int x) { p.password = x; }
	void CreateManager(char *inputname, int inputid, int inputpassword);
	bool Certid(int inputid);   //�ж�id����������� ����ture����
	bool Certpw(Person &p,int inputpw);
	void Checkinfo();				  //
	void Checkinfo(int inputid);
	void ChangePw();				  //to change the password 
};
