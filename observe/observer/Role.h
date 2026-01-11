#ifndef ROLE_H
#define ROLE_H
#include<memory>
#include<string>
#include "observe/target/RoleSkill.h"

namespace observer
{
	class Role
	{
	public:
		virtual ~Role()=default;
		virtual void useSkill()=0;
		virtual void evaluate(int hp)=0;
		int getHp() { return hp; }
		void setHp(const int& new_hp) { hp = new_hp; }
		std::shared_ptr<target::RoleSkill> getSkill() { return skill; }
		void setSkill(std::shared_ptr<target::RoleSkill>& new_skill) { skill = new_skill; }
		std::string getName() { return name; }
		void setName(const std::string& new_name) { name = new_name; }

	private:
		int hp;
		int camp;
		std::string name;
		std::shared_ptr<target::RoleSkill>skill;
	};
}

#endif