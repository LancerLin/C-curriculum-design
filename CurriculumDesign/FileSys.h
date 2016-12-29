#pragma once
#include "baseinfo.h"
class FileSys
{
public:
	FileSys();
	~FileSys();
	virtual void Read(int ID) = 0;
	virtual void Write() = 0;

//	virtual void check() = 0;
};

