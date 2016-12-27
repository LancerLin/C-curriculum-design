#pragma once
#include"Person.h"
#include"Member.h"
#include"Manager.h"
class Operator {
public:
	friend class Person;
//	void setpassword(Person &p, int x) { p.password = x; }
	void createMember(char *inputname, int inputid, int inputpassword);
	void createManager(char *inputname, int inputid, int inputpassword);
};
