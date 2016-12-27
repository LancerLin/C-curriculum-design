#pragma once
#include "Person.h"
class FileSys:virtual public Person
{
public:
	FileSys();
	~FileSys();
	virtual void read(int ID) = 0;
	virtual void write() = 0;
};

