#pragma once
#include"Person.h"
#include"Member.h"
#include"Manager.h"
#include"baseinfo.h"
class Operator:virtual public Manager{
public:
	//void setpassword(Person &p, int x) { p.password = x; }
	void CreateManager(D *d);
	bool Certid(int inputid);  //判断id或密码存在性 返回ture存在
	bool Certpw(Person &p,int inputpw);
	void Checkinfo();			//查询用户信息
	void Checkinfo(int inputid);
	bool ChangePw();	//to change the password 
	bool ChangePw(int inputid);
	bool ChangeIsused();  //to log off or recover user
	bool ChangeCredit();
	//void Pause();  // pause to show screen and return preUI
	bool IsYes();			//to return yes or no
private:

};
