#include <iostream>
using namespace std;
#include"Person.h"
#include"FileSys.h"
int main() {
	Person p("zhang", 1000000, 123, 0);
	p.show();
	//FileSys f(p);
	system("pause");
	return 0;
}