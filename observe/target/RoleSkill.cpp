#include "RoleSkill.h"
#include "observe/observer/RoleObserver.h"

void target::RoleSkill::addTargets(observer::RoleObserver* obs)
{
	observers.insert(obs);
}

void target::RoleSkill::removeTargets(observer::RoleObserver* obs)
{
	observers.erase(obs);
}

void target::RoleSkill::notify()
{
	for (auto obs : observers)
	{
		obs->evaluate(getHp());
	}
}

int target::RoleSkill::getHp()
{
	return hp;
}

void target::RoleSkill::setHp(const int& new_hp)
{
	this->hp = new_hp;
}

std::string target::RoleSkill::getName()
{
	return name;
}

void target::RoleSkill::setName(const std::string& new_name)
{
	this->name = new_name;
}

