#include<iostream>
#include "Person.h"
#include<string>
Person::Person(char * inputname, int inputid, int inputpassword)
{
	id = inputid;
	password = inputpassword;
	strcpy_s(name, inputname);
	IsUsed = true;
}

Person::Person()
{
}

void Person::show()
{
	std::cout << "������" << getname() << std::endl;
	std::cout << "ID��" << getid() << std::endl;
}
