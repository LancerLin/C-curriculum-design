#pragma once
#include"Person.h"
#include"Operator.h"
class Super : public Person,public Operator {
public:
	Super();
	friend class Operator;
};
