#pragma once
#include"Person.h"
class Manager :public Person{
public:
	//Manager(char *inputname, int inputid, int inputpassword);
	
	friend class Operator;
};