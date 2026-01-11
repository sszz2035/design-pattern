#ifndef _ADVENTURE_H_
#define _ADVENTURE_H_
#include<memory>
#include"IBehaviour.h"
namespace stra
{
	class Adventurer
	{
	public:
		Adventurer() {}
		explicit Adventurer(std::shared_ptr<IBehaviour>behavior):behaviour(behavior),score(0){}
		ResultType explore()
		{
			return behaviour->execute();
		}
		void setBehaviour(std::shared_ptr<IBehaviour>& behavior) { behaviour = behavior; }
		void addScore(const int& score) { this->score += score; }
		int getScore() { return score; }
	private:
		std::shared_ptr<IBehaviour>behaviour;
		int score;
	};
}

#endif