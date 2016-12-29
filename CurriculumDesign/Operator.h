#pragma once
#include"Person.h"
#include"Member.h"
#include"Manager.h"
#include"baseinfo.h"
class Operator:virtual public Member,virtual public Manager{
public:
	//void setpassword(Person &p, int x) { p.password = x; }
	void CreateManager(char *inputname, int inputid, int inputpassword);
	bool Certid(int inputid);   //判断id或密码存在性 返回ture存在
	bool Certpw(Person &p,int inputpw);
	void Checkinfo();			//查询用户信息
	void Checkinfo(int inputid);
	void ChangePw();	//to change the password 
	void ChangePw(int inputid);
	void ChangeIsused();  //to log off or recover user
	void ChangeCredit();
	bool IsYes();			//to return yes or no
private:

};
