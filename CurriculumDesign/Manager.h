#pragma once
#include"Person.h"
#include"Member.h"
#include"FileSys.h"
#include<fstream>
#include"baseinfo.h"
class Manager :virtual public Person,virtual public Member,virtual public FileSys{
public:
	Manager();
	Manager(Person &p);
	void Read(int ID);
	void Write();
	void CreateMember(D* d);
	
};