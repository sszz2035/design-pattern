#ifndef ROLEOBSERVER_H
#define ROLEOBSERVER_H

#include "Role.h"
namespace observer
{
	class RoleObserver :public Role
	{
	public:
		RoleObserver();
		~RoleObserver()override;
		void useSkill()override;
		void evaluate(int hp)override;

	};
}

#endif