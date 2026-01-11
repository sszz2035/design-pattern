#ifndef _IBEHAVIOUR_H_
#define _IBEHAVIOUR_H_

namespace stra {
	enum class ResultType
	{
		NORMAL,//正常
		WEAK_ENEMY,//弱敌人
		STRONG_ENEMY,//强敌人
		CLEAR,//敌人全被击败
		MISTAKE,//攻击失败
		DEAD//角色死亡
	};
	class IBehaviour
	{
	public:
		virtual ResultType execute() = 0;
	};
}

#endif