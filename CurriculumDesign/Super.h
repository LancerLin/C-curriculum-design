#pragma once
#include"Person.h"
#include"Operator.h"
class Super : virtual public Person,virtual public Operator {
public:
	Super();
	friend class Operator;
};
