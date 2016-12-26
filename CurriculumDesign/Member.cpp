#include"Member.h"
#include<iostream>
Member::Member(char * inputname, int inputid, int inputpassword):Person(inputname,inputid,inputpassword)
{
}

void Member::show()
{
	Person::show();
	std::cout << "»ı·Ö:" << getcredit() << std::endl;
}
