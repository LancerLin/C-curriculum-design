#pragma once
#include "FileSys.h"
#include <fstream>
/*
日志全局基本信息
基本面：
number of member
number of manager
操作信息列表：
ID + 增/删/改 + 名/密码/信用
（此部分最多）

拓展功能对member信息检索

*/
enum conduct_ {
	add,
	edit,
	cancle
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
	LIST *next;
}List;
typedef struct LOGtable {
	int NMember;//number of Member
	int NManager;//number of Manager
	List list;
	int listlength;
}LOG;
class Log//:virtual public FileSys
{
public:
	LOG L;
	Log();
	~Log();
	int MemberCount();//Member计数
	int ManagerCout();//Manager计数
	void read_log();//log全读
	void write_log();//log全写 P.S.日志条目追加 暂未启用
	void creatlist();//P.S.日志条目 暂不启用
};

