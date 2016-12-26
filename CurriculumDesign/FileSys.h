#pragma once
#include "Person.h"
class FileSys:virtual Person
{
public:
	FileSys();
	~FileSys();
	void readMember(Person &p,int ID);
	void writeMember(Person &p);

};

