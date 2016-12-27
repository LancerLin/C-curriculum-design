#pragma once
//此类用来保存所有计数的变量
//所有的操作都由函数进行
//操作太少 顾暂时没由建立cpp文件
class Count
{
public:
	Count(){};
	void Cntone() { Cnt++; }
private:
	static int Cnt;
};
