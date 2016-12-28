#include <iostream>
using namespace std;
#include"Person.h"

#include"Member.h"
#include"Operator.h"
int main() {
	cout << sizeof(D)<<endl;
	cout << "person show" << endl;
	Person p1("zhang", 10000000, 1, 1),
		p2("li",10000001,2,2),
		p3("chen",10000002,3,3);
	p1.show();
	p2.show();
	p3.show();
	cout <<"member show" <<endl;
	Member m1(p1),m2(p2),m3(p3);
	m1.show();
	m2.show();
	m3.show();

	cout << "filesys write member" << endl;

	m1.write();
	m2.write();
	m3.write();
	cout << "filesys read member" << endl;

	m1.read(10000002);
	m1.show();

	cout << "=======" << endl;
	Operator o;
	if (o.certpw(m1, 3)) 
		cout << "y";
	else 
		cout << "N";

	system("pause");
	return 0;
}