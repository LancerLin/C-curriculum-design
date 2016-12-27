#pragma once
#include "FileSys.h"
/*
日志全局基本信息
基本面：
number of member
number of manager
操作信息列表：
增/删/改+ID
（此部分最多）

拓展功能对member信息检索

*/
enum conduct_ {
	add,
	edit,
	del
};
enum _conduct {
	name,
	password,
	credit
};
typedef struct LIST {
	conduct_ A;
	_conduct B;
	int ID;
	LIST* next;
}infoList;
typedef struct LOGtable {
	int noMember;//number of Member
	int noManager;//number of Manager
	infoList l;
}LOGtable;
class Log:public FileSys
{
private:
	LOGtable L;
public:
	Log();
	~Log();
};

