#pragma once
#include "FileSys.h"
#include <fstream>
/*
��־ȫ�ֻ�����Ϣ
�����棺
number of member
number of manager
������Ϣ�б�
ID + ��/ɾ/�� + ��/����/����
���˲�����ࣩ

��չ���ܶ�member��Ϣ����

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
	int MemberCount(); //Member����
	int ManagerCount();//Manager����
	void Read_log();//logȫ��
	void Write_log();//logȫд P.S.��־��Ŀ׷�� ��δ����
	void Creatlist();//P.S.��־��Ŀ �ݲ�����
	void CreatConduct_log();
	void AddConduct(int id,char buff_[],char _buff[]);
};

