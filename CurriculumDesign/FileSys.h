#pragma once
#include "Person.h"
class FileSys:virtual public Person
{
public:
	FileSys();
	~FileSys();
	void readMember(int ID);
	void writeMember();
};

