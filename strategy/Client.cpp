#include"Adventurer.h"
#include"Behaviour/AggressiveBehaviour.h"
#include"Behaviour/DefensiveBehaviour.h"
#include"Behaviour/NormalBehaviour.h"
#include<iostream>
int main()
{
	std::shared_ptr<stra::IBehaviour>aggresiveBhv = std::make_shared<stra::AggressiveBehaviour>();
	std::shared_ptr<stra::IBehaviour>defensiveBhv = std::make_shared<stra::DefensiveBeahviour>();
	std::shared_ptr<stra::IBehaviour>normalBhv = std::make_shared<stra::NormalBehaviour>();
	std::shared_ptr<stra::Adventurer>adventurer = std::make_shared<stra::Adventurer>(normalBhv);
	bool isOver = false;
	do
	{
		switch (adventurer->explore())
		{
		case stra::ResultType::NORMAL:
			adventurer->setBehaviour(normalBhv);
			adventurer->addScore(1);
			break;
		case stra::ResultType::STRONG_ENEMY:
			adventurer->setBehaviour(defensiveBhv);
			adventurer->addScore(3);
			break;
		case stra::ResultType::WEAK_ENEMY:
			adventurer->setBehaviour(aggresiveBhv);
			break;
		case stra::ResultType::CLEAR:
			adventurer->setBehaviour(normalBhv);
			adventurer->addScore(3);
			break;
		case stra::ResultType::MISTAKE:
			adventurer->setBehaviour(defensiveBhv);
			break;
		case stra::ResultType::DEAD:
			isOver = true;
			break;
		}
	} while (!isOver);
	std::cout << "==========================================" << std::endl;
	std::cout << "            探险结束,开始结算" << std::endl;
	std::cout << "          您获得的分数是:" << adventurer->getScore()<<std::endl;
	std::cout << "==========================================" << std::endl;

	return 0;
}