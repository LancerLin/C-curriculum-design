#include <iostream>
using namespace std;
#include"Person.h"
#include"FileSys.h"
#include"UI.h"
int main() {

	//Person p("zhang", 1000000, 123, 0);
	//p.show();
	//FileSys f(p);
	UI windows;
	windows.LoginUI();
	system("pause");
	return 0;
}