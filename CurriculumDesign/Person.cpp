#include<iostream>
#include "Person.h"
#include<string>
const int default_member =-1;
Person::Person(char * inputname, int inputid, int inputpassword,int intputcredit)
{
	id = inputid;
	password = inputpassword;
	strcpy_s(name, inputname);
	IsUsed = true;
	credit = intputcredit;
}

Person::Person()
{
	id = default_member;
	password = default_member;
	strcpy_s(name,"NULL");
	IsUsed = false;
	credit = default_member;
}

Person::Person(Person & p)
{
	strcpy_s(name, p.getname());
	id = p.getid();
	password = p.getpass();
	credit = p.getcredit();
	IsUsed = true;
}


void Person::show()
{
	std::cout << "ÐÕÃû£º" << getname() << std::endl;
	std::cout << "ID£º" << getid() << std::endl;
}
