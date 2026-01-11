#ifndef _NORMALBEHAIVOUR_H_
#define _NORMALBEHAIVOUR_H_
#include "IBehaviour.h"
#include "RandomUtil.h"
#include<iostream>
namespace stra {
	class NormalBehaviour :public IBehaviour
	{
		ResultType execute()override
		{
			if (RandomUtil().nextBool())
			{
				std::cout << "ÎÔ²Û£¬ÔâÓöÇ¿µÐ£¡" << std::endl;
				return ResultType::STRONG_ENEMY;
			}
			else {
				std::cout << "¹þ¹þ£¬Åöµ½¸öÀ±¼¦" << std::endl;
				return ResultType::WEAK_ENEMY;
				}
		}
	};
}


#endif