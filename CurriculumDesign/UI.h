#pragma once
//UI.h ����
/*
1.��¼����ķ���ID switch������������
2.UIֻ��ʾ����
3.����������operator
4.
*/
#include <stdlib.h>
#include "Person.h"
#include "Member.h"
#include "Manager.h"
#include "Super.h"
#include "Operator.h"
#include "Log.h"
class UI:virtual public Operator
{
public:
	UI();
	Log LOGT;
	Member member;
	Manager manager;
	Super admin;
	void LoginUI();  //��½����
	void Clean();    //������Ļ
	void MemberUI(const int inputid); //��Ա��½����
	void ManagerUI(const int inputid);//����Ա����
	void SuperUI(const int inputid);  //�����
	void Logout(int inputid);					  //ע����¼
	void CreatMemberUI();  //����D���������ļ�����
	void CreatManagerUI();
	void ShowAllCount();
private:

};
