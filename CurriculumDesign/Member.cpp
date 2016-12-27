#include "Member.h"
#include"Person.h"
Member::Member():Person(){
}

Member::Member(Person &p):Person(p) {
}