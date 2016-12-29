#include "Operator.h"
#include<iostream>

using namespace std;
/*
void Operator::CreateMember(char *inputname, int inputid, int inputpassword)
{
	//Member::Member(inputname, inputid, inputpassword);
	//文件操作:会员数量++
}
*/


void Operator::CreateManager(D * d)
{
	Manager *p = new Manager(Person(d));
	p->Manager::Write();
}

bool Operator::Certid(int inputid)
{
	if (SuperID == inputid) {
		return true;
	}
	Person *_p = new Person();
	char filename[20] = { 0 };
	int StartNumber = 0;
	if (inputid >= MemberStartNumber) {
		strcpy_s(filename, memberpath);
		StartNumber = MemberStartNumber;
	}
	else if (inputid >= ManagerStartNumber) {
		strcpy_s(filename, managerpath);
		StartNumber = ManagerStartNumber;
	}
	std::fstream inFile;
	inFile.open(filename, std::ios::in | std::ios::out | std::ios::binary);
	inFile.seekg((inputid - StartNumber) * sizeof(D), std::ios::beg);
	inFile.read((char*)_p, sizeof(D));
	inFile.close();
	return _p->isued();
}

bool Operator::Certpw(Person &p, int inputpw)
{
	if (p.getpass() == inputpw) {
		return true;
	}
	Person *_p = new Person();
	char filename[20] = { 0 };
	int StartNumber = 0;
	if (p.getid() >= MemberStartNumber) {
		strcpy_s(filename, memberpath);
		StartNumber = MemberStartNumber;
	}
	else if (p.getid() >= ManagerStartNumber) {
		strcpy_s(filename, managerpath);
		StartNumber = ManagerStartNumber;
	}
	std::fstream inFile;
	inFile.open(filename, std::ios::in | std::ios::out | std::ios::binary);
	inFile.seekg((p.getid() - StartNumber) * sizeof(D), std::ios::beg);
	inFile.read((char*)_p, sizeof(D));
	inFile.close();
	return _p->getpass() == inputpw;
}

void Operator::Checkinfo()
{
	int inputid;
	system("Cls");
	cout << "***************" << endl;
	cout << "请输入查询的账户ID" << endl;

	cin >> inputid;
	if (Operator::Certid(inputid) == false) {
		cout << "你输入的ID不存在，按回车返回操作界面" << endl;
		getchar(); getchar();
		return;
	}
	else if (Operator::Certid(inputid) == true) {
		Member *m = new Member();  //下面两句用于获取id的位置以便输出
		m->Read(inputid);
		system("Cls");
		cout << "*******************" << endl;
		cout << "用户姓名：" << m->getname() << endl;
		cout << "用户ID：" << m->getid() << endl;
		cout << "用户积分：" << m->getcredit() << endl;
		cout << "使用情况：" << m->isued() << endl;
		cout << "*******************" << endl;
		cout << "按回车返回界面" << endl;
	}
	getchar(); getchar();
}

void Operator::Checkinfo(int inputid)
{
	Member *m = new Member();  //下面两句用于获取id的位置以便输出
	m->Read(inputid);
	system("Cls");
	cout << "*******************" << endl;
	cout << "用户姓名：" << m->getname() << endl;
	cout << "用户ID：" << m->getid() << endl;
	cout << "用户积分：" << m->getcredit() << endl;
	cout << "使用情况：" << m->isued() << endl;
	cout << "*******************" << endl;
	cout << "按回车返回界面" << endl;
	getchar(); getchar();
}

void Operator::ChangePw()
{
	int inputid, NewPw, tp;
	cout << "***************" << endl;
	cout << "请输入需要修改密码的ID" << endl;

	cin >> inputid;
	if (Operator::Certid(inputid) == false) {
		cout << "你输入的ID不存在，将返回操作界面" << endl;
		getchar();
		return;
	}
	else if (Operator::Certid(inputid) == true) {
		Member *m = new Member();
		m->Read(inputid);
		cout << "*****************" << endl;
		cout << "请输入新密码:";
		cin >> NewPw;
		cout << "请再次输入新密码：";
		cin >> tp;
		if (NewPw == tp) {
			cout << "新密码为" << NewPw << endl;
			if (IsYes() == true) {
				m->setpassword(NewPw);
				cout << "新密码设置成功" << endl;
				getchar();
				return;
			}
		}


	}
}

void Operator::ChangePw(int inputid)
{
	int NewPw, tp;
	Member *m = new Member();
	m->Read(inputid);
	system("Cls");
	cout << "*****************" << endl;
	cout << "请输入新密码:";
	cin >> NewPw;
	cout << "请再次输入新密码：";
	cin >> tp;
	if (NewPw == tp) {
		if (IsYes() == true) {
			m->setpassword(NewPw);
			cout << "新密码设置成功" << endl;
			cout << "新密码为" << m->getpass() << endl;
			m->Write();
			getchar(); getchar();
			return;
		}
	}
}

void Operator::ChangeIsused()
{
	int inputid;
	cout << "***************" << endl;
	cout << "请输入需要查询的用户状态" << endl;
	cin >> inputid;
	if (Operator::Certid(inputid) == false) {
		cout << "你输入的ID不存在，将返回操作界面" << endl;
		getchar();
		return;
	}
	else if (Operator::Certid(inputid) == true) {
		Member *m = new Member();
		m->Read(inputid);
		cout << "用户ID为：" << m->getid() << endl;
		cout << "账户当前状态为" ;
		if (m->isued() == true) {
			cout << "正常" << endl;
		}
		else if (m->isued() == false) {
			cout << "禁用" << endl;
		}
		cout << "是否要修改用户状态" << endl;
		if (IsYes() == true) {
			Member *m = new Member();
			m->Read(inputid);
			D *d = new D();
			d->credit = m->getcredit();
			d->id = !m->getid();
			d->IsUsed =  m->isued();
			d->password = m->getpass();
			delete m;
			m = new Member(Person(d));
			m->Write();
			cout << "****************" << endl;
			cout << "用户ID:" << m->getid() << endl;
			cout << "账户当前状态为";
			if (m->isued() == true) {
				cout << "正常" << endl;
			}
			else if (m->isued() == false) {
				cout << "禁用" << endl;
			}
			cout << "*******************" << endl;
		}
		getchar();
		return;
	}
}

void Operator::ChangeCredit()
{
	int inputid, credit;
	cout << "***************" << endl;
	cout << "请输入需要修改密码的ID" << endl;

	cin >> inputid;
	if (Operator::Certid(inputid) == false) {
		cout << "你输入的ID不存在，将返回操作界面" << endl;
		getchar();
		return;
	}
	else if (Operator::Certid(inputid) == true) {
		cout << "请输入要增加的积分" << endl;
		cin >> credit;
		if (IsYes() == true) {

			Member *m = new Member();
			m->Read(inputid);
			D *d = new D();
			d->credit = credit;
			d->id = m->getid();
			d->IsUsed = m->isued();
			d->password = m->getpass();
			delete m;
			m = new Member(Person(d));
			m->Write();
			cout << "****************" << endl;
			cout << "用户ID:" << m->getid() << endl;
			cout << "用户积分:" << m->getcredit() << endl;
			cout << "*******************" << endl;
		}
			return;
	}

}




bool Operator::IsYes()
{
	char fg;
	cout << "******************" << endl;
	cout << "是否确定（y/n）?" << endl;
	cin >> fg;
	switch (fg)
	{
	case 'y':return true; break;
	case'n':return false; break;
	default:
		cout << "ERROR" << endl;
		getchar();
		return IsYes();
		break;
	}

}
