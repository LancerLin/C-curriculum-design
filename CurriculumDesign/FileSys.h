#pragma once
class FileSys
{
public:
	FileSys();
	~FileSys();
	virtual void read(int ID) = 0;
	virtual void write() = 0;

//	virtual void check() = 0;
};

