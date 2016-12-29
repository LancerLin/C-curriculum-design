#include <iostream>
using namespace std;
#include "UI.h"

#include "Operator.h"
#include"baseinfo.h"
int main() {
	D *d=new D;
	d->id = ManagerStartNumber;
	strcpy_s(d->name, "guanli_1");
	d->IsUsed = true;
	d->password = 11;
	d->credit = 0;

	D *d1 = new D;
	d1->id = MemberStartNumber;
	strcpy_s(d1->name, "member_1");
	d1->IsUsed = true;
	d1->password = 1;
	d1->credit = 0;

	Manager *p=new Manager();
	p->CreateMember(d1);
	Operator o;
	o.CreateManager(d);
	//UI u;
	//u.LoginUI();
	system("pause");
	return 0;
}