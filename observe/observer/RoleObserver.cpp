#include"RoleObserver.h"
#include<iostream>

observer::RoleObserver::RoleObserver()
{
	setHp(5000);
}

observer::RoleObserver::~RoleObserver()
{
	this->getSkill().reset();
}

void observer::RoleObserver::useSkill()
{
	auto skill = getSkill();
	std::cout << this->getName() << " use " << skill->getName()<<std::endl;
	skill->notify();
	return;
}

void observer::RoleObserver::evaluate(int hp)
{
	int new_hp = getHp() + hp;
	setHp(new_hp);
	std::cout<<this->getName()<<"'s " << "hp changed,hp:" << new_hp << std::endl;
	return;
}
