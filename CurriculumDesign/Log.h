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
typedef struct LIST {
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
	int ID;
	List *next;
}List;
typedef struct LOG {
	int noMember;//number of Member
	int noManager;//number of Manager
	List l;
}Log;
class Log:public FileSys
{
private:
	Log Log;
public:
	Log();
	~Log();
};

