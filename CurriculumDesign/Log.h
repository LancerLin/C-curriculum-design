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

