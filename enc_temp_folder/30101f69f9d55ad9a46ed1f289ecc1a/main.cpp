#include <iostream>
using namespace std;
#include"Person.h"
#include"FileSys.h"
#include"Member.h"
int main() {
	cout << sizeof(Member)<<endl;
	cout << "person show" << endl;
	Person p1("zhang", 10000001, 123, 0),
		p2("li",10000002,123,0);
	p1.show();
	p2.show();
	cout <<"member show" <<endl;
	Member m1(p1),m2(p2),m;
	m1.show();
	m2.show();
	m.show();
	//FileSys f;
	cout << "filesys write member" << endl;
	m1.writeMember();
	m2.writeMember();
	cout << "filesys read member" << endl;
	
	m1.readMember(10000002);
	m1.show();
	m2.readMember(10000001);
	m2.show();
	
	
//	m.readMember(10000001);
//	m.show();
//	m.readMember(10000002);
//	m.show();
	system("pause");
	return 0;
}