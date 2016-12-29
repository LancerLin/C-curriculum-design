#include "Log.h"

Log::Log()
{
	L.NManager = 0;
	L.NMember = 0;
}

Log::~Log()
{
}

int Log::MemberCount()
{
	L.NMember++;
	Write_log();
	return L.NMember;
}

int Log::ManagerCout()
{
	L.NManager++;
	Write_log();
	return L.NManager;
}

void Log::Read_log()
{
	char buff[255];
	int A, B;
	List *p = &L.list;
	std::ifstream fin("log.txt");
	fin.getline(buff, 100);//"number of member\n"
	fin >> L.NMember;
	fin.getline(buff, 100);//"\n"
	fin.getline(buff, 100);//"number of manager\n"
	fin >> L.NManager;
	fin.getline(buff, 100);//"\n"
	fin.getline(buff, 100);//"id + add/edit/cancle + name/password/credit\n"
/*读日志条目 暂时不启用
	
	for (int i = 0; i < L.listlength; i++) {
		fin >> p->ID >> A >> B;
		switch (A) {
		case 0:p->A = add;
		case 1:p->A = edit;
		case 2:p->A = cancle;
		}
		switch (B) {
		case 0:p->B = name;
		case 1:p->B = password;
		case 2:p->B = credit;
		}
		fin.getline(buff, 100);//"\n"
		p = p->next;
	}
*/
	fin.close();
}

void Log::Write_log()
{
	//char buff[20];
	List *p =&L.list;
	std::ofstream fout("log.txt");
	fout << "number of member\n";
	fout << L.NMember << "\n";
	fout << "number of manager\n";
	fout << L.NManager << "\n";
	fout << "id + add/edit/cancle + name/password/credit\n";
/*写日志条目 暂不启用
	
	for (int i = 0; i < L.listlength; i++) {
		fout << p->ID << p->A << p->B << "\n";
		p = p->next;
	}
*/
	fout.close();
}

void Log::Creatlist()
{
}
