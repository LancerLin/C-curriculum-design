#pragma once
#include "FileSys.h"
/*
��־ȫ�ֻ�����Ϣ
�����棺
number of member
number of manager
������Ϣ�б�
��/ɾ/��+ID
���˲�����ࣩ

��չ���ܶ�member��Ϣ����

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

