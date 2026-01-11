#ifndef _AGGRESSIVEBEHAVIOUR_H_
#define _AGGRESSIVEBEHAVIOUR_H_
#include "IBehaviour.h"
#include "RandomUtil.h"
#include<iostream>
namespace stra {
	class AggressiveBehaviour :public IBehaviour
	{
		ResultType execute()override
		{
			if (RandomUtil().nextBool())
			{
				std::cout << "·¢¶¯¹¥»÷£º¶À¹Â¾Å½££¡µÐÈË±»¼ßÃð" << std::endl;
				return ResultType::CLEAR;
			}
			else
			{
				std::cout << "·¢¶¯¹¥»÷£º¶Ô·½Ì«Ç¿ÁË£¬´ò²»¹ý£¡¹¥»÷Ê§°Ü" << std::endl;
				return ResultType::MISTAKE;
			}
		}
	};
}


#endif