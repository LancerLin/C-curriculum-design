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
#include"Operator.h"
class UI:virtual public Operator
{
public:
	UI();
	void LoginUI();  //��½����
	void Clean();    //������Ļ
	void MemberUI(const int inputid); //��Ա��½����
	void ManagerUI();//����Ա����
	void SuperUI();  //�����
	void Logout();   //ע����¼
	void Checkinfo();
	void Checkinfo(int inputid);
	//��ѯ�û���Ϣ
	D * CreatMemberUI();  //����D���������ļ�����
	//D * CreatManagerUI();
private:

};
