#include"GameCore.h"
#include<string>
#include"util/RandomUtil.h"
#include"target/CureSkill.h"
#include "target/HurtSkill.h"
GameCore::GameCore()
{
	init();
}

void GameCore::fight()
{
	std::cout << "Fight!" << std::endl;
	int round = 1;
	do
	{
		int idx = RandomUtil().nextBool();
		std::cout << "====================================" << std::endl;
		std::cout << "Round:" << round << std::endl;
		if (idx)
		{
			for (auto role : camp1)
			{
				role->useSkill();
				removeDead(2);
				if (camp2.empty())	break;
			}
		}
		else
		{
			for (auto role : camp2)
			{
				role->useSkill();
				removeDead(1);
				if (camp1.empty())	break;
			}
		}
		std::cout << "====================================" << std::endl;
		std::cout << std::endl;
		round++;
	} while (!camp1.empty() && !camp2.empty());
	if (camp1.empty())	std::cout << "camp2 Win!" << std::endl;
	else	std::cout << "camp1 Win!" << std::endl;
}

void GameCore::init()
{
	initCamp(1);
	initCamp(2);
	bool hurtSkillSelect = false;
	bool cureSkillSelect = false;
	for (auto obs : camp1)
	{
		if (hurtSkillSelect && cureSkillSelect)	break;
		if (!hurtSkillSelect&&obs->getSkill()->getName() == "The World")
		{
			hurtSkillSelect = true;
			for (auto obs2 : camp2)
			{
				obs->getSkill()->addTargets(obs2.get());
			}
		}
		else if(obs->getSkill()->getName()=="Cure Body")
		{
			cureSkillSelect = true;
			for (auto obs1 : camp1)
			{
				obs->getSkill()->addTargets(obs1.get());
			}
		}
	}
	hurtSkillSelect = false;
	cureSkillSelect = false;
	for (auto obs : camp2)
	{
		if (hurtSkillSelect && cureSkillSelect)	break;
		if (!hurtSkillSelect && obs->getSkill()->getName() == "The World")
		{
			hurtSkillSelect = true;
			for (auto obs2 : camp1)
			{
				obs->getSkill()->addTargets(obs2.get());
			}
		}
		else if (obs->getSkill()->getName() == "Cure Body")
		{
			cureSkillSelect = true;
			for (auto obs1 : camp2)
			{
				obs->getSkill()->addTargets(obs1.get());
			}
		}
	}

}

void GameCore::initCamp(int idx)
{
	bool isCuredSelected = false;
	auto &camp = idx == 1 ? camp1 : camp2;
	std::shared_ptr <target::RoleSkill>cureSkill = std::make_shared<target::CureSkill>();
	std::shared_ptr <target::RoleSkill>hurtSkill = std::make_shared<target::HurtSkill>();
	for (int i = 0; i < 4; i++)
	{
		std::shared_ptr<observer::RoleObserver>role1 = std::make_shared<observer::RoleObserver>();
		std::string name1 = (idx==1 ? "Black":"White") + std::to_string(i);
		role1->setName(name1);
		RandomUtil random;
		if (!isCuredSelected && random.nextBool() == false)
		{
			role1->setSkill(cureSkill);
			isCuredSelected = true;
		}
		else
		{
			role1->setSkill(hurtSkill);
		}
		camp.insert(role1);
	}
}

void GameCore::removeDead(int idx)
{
	auto& camp = idx == 1 ? camp1 : camp2;
	auto& otherCamp = idx == 1 ? camp2 : camp1;
	auto it = camp.begin();
	while (it != camp.end())
	{
		auto role = *it;
		if (role->getHp() <= 0) {
			// 将死亡角色从所有技能的目标列表中清理，避免悬挂指针
			for (auto& r : camp) {
				r->getSkill()->removeTargets(role.get());
			}
			for (auto& r : otherCamp) {
				r->getSkill()->removeTargets(role.get());
			}
			it = camp.erase(it);
		}
		else it++;
	}

}


