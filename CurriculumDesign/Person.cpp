#include<iostream>
#include<string>
#include "Person.h"
Person::Person(char * inputname, int inputid, int inputpassword)
{
	id = inputid;
	password = inputpassword;
	strcpy_s(name, inputname);
}

Person::Person()
{
}

void Person::show()
{
	std::cout << "������" << getname() << std::endl;
	std::cout << "ID��" << getid() << std::endl;
}
