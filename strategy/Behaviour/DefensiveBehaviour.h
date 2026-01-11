#ifndef _DEFENSIVEBEHAVIOUR_H_
#define _DEFENSIVEBEHAVIOUR_H_
#include "IBehaviour.h"
#include<iostream>
#include"RandomUtil.h"
namespace stra {
	class DefensiveBeahviour :public IBehaviour
	{
		ResultType execute()override
		{
			std::cout << "·ÀÓùÄ£Ê½Æô¶¯£¡ " ;
			int Probability = RandomUtil().nextInt(100);
			if (Probability > 30)
			{
				std::cout << "·ÀÓù³É¹¦À²!" << std::endl;
				return ResultType::NORMAL;
			}
			else
			{
				std::cout << "·ÀÓùÊ§°Ü£¬°¢Î°ËÀÁË" << std::endl;
				return ResultType::DEAD;
			}
		}
	};
}


#endif