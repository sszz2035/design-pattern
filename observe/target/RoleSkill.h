#include<unordered_set>
#include <string>
#ifndef ROLESKILL_H
#define ROLESKILL_H

namespace observer { class RoleObserver; };

namespace target {
	class RoleSkill
	{
	public:
		//virtual ~RoleSkill();
	public:
		virtual void addTargets(observer::RoleObserver* obs);
		virtual void removeTargets(observer::RoleObserver* obs);
		virtual void notify();
		int getHp();
		void setHp(const int &new_hp);
		std::string getName();
		void setName(const std::string& new_name);

	private:
		int hp;
		std::unordered_set<observer::RoleObserver*>observers;
		std::string name;
	};
}

#endif