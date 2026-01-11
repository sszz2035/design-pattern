#ifndef GAMECORE_H
#define GAMECORE_H
#include<unordered_set>
#include<memory>
#include"observe/observer/RoleObserver.h"
class GameCore{

public:
	explicit GameCore();
	void fight();
private:
	void init();
	void initCamp(int idx);
	void removeDead(int idx);
private:
	std::unordered_set<std::shared_ptr<observer::RoleObserver>>camp1;
	std::unordered_set<std::shared_ptr<observer::RoleObserver>>camp2;
};

#endif