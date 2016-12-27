#include<iostream>
#include "Person.h"

const int default_member =-1;
Person::Person(char * inputname, int inputid, int inputpassword,int intputcredit)
{
	data.id = inputid;
	data.password = inputpassword;
	strcpy_s(data.name, inputname);
	data.IsUsed = true;
	data.credit = intputcredit;
}

Person::Person()
{
	data.id = default_member;
	data.password = default_member;
	strcpy_s(data.name,"NULL");
	data.IsUsed = false;
	data.credit = default_member;
}

Person::Person(D * d)
{
	strcpy_s(data.name, d->name);
	data.id = d->id;
	data.password = d->password;
	data.credit = d->credit;
	data.IsUsed = true;
}

Person::Person(Person & p)
{
	strcpy_s(data.name, p.getname());
	data.id = p.getid();
	data.password = p.getpass();
	data.credit = p.getcredit();
	data.IsUsed = true;
}


void Person::show()
{
	std::cout << "ÐÕÃû£º" << getname() << std::endl;
	std::cout << "ID£º" << getid() << std::endl;
}
