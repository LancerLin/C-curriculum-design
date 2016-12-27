#include <iostream>
using namespace std;
#include"Person.h"
//#include"FileSys.h"
#include"Member.h"
int main() {
	cout << sizeof(D)<<endl;
	cout << "person show" << endl;
	Person p1("zhang", 10000000, 123, 0),
		p2("li",10000001,123,0),
		p3("chen",10000002,123,0);
	p1.show();
	p2.show();
	p3.show();
	cout <<"member show" <<endl;
	Member m1(p1),m2(p2),m3(p3),*m;
	m1.show();
	m2.show();
	m3.show();
//	m->show();
	//FileSys f;
	cout << "filesys write member" << endl;

	m1.writeMember();
	m2.writeMember();
	m3.writeMember();

	cout << "filesys read member" << endl;
	
	m1.readMember(10000001);
	m1.show();
	m2.readMember(10000002);
	m2.show();
	m3.readMember(10000000);
	m3.show();
	
	m = new Member();
	m->readMember(10000001);
	m->show();

	system("pause");
	return 0;
}