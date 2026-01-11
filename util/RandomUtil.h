//�ο���https://www.cnblogs.com/jiading/p/11653911.html
#ifndef _RANDOMUTIL_H_
#define _RANDOMUTIL_H_
#include <random>
#include <iostream>
#include "util_export.h"
class UTIL_API RandomUtil
{
private:
	//�������������
	std::random_device sd;
	//linear_congruential_engine����
	std::minstd_rand linearRan;
	//�޸��������
	void changeSeed();
public:
	//�����ʼ���������
	RandomUtil();
	
	//************************************
	// Method:    randInt
	// FullName:  RandomUtil::randInt
	// Access:    public 
	// Returns:   int �����
	// Qualifier: ����min-max֮�������������������[min,max]
	// Parameter: int min ��Сֵ
	// Parameter: int max ���ֵ
	// Parameter: bool chSeed �Ƿ��޸����ӣ�Ĭ�ϲ��޸�
	//************************************
	int randInt(int min, int max, bool chSeed = false);

	//************************************
	// Method:    nextInt
	// FullName:  RandomUtil::nextInt
	// Access:    public 
	// Returns:   int �����
	// Qualifier: ����0-max֮�������������������[0,max]
	// Parameter: int max ���ֵ
	// Parameter: bool chSeed �Ƿ��޸����ӣ�Ĭ�ϲ��޸�
	//************************************
	int nextInt(int max, bool chSeed = false);
	
	//************************************
	// Method:    randFloat
	// FullName:  RandomUtil::randFloat
	// Access:    public 
	// Returns:   float �����
	// Qualifier: ����min-max֮�������������������[min,max)
	// Parameter: float min ��Сֵ
	// Parameter: float max ���ֵ
	// Parameter: bool chSeed �Ƿ��޸����ӣ�Ĭ�ϲ��޸�
	//************************************
	float randFloat(float min, float max, bool chSeed = false);
	
	//************************************
	// Method:    nexFloat
	// FullName:  RandomUtil::nexFloat
	// Access:    public 
	// Returns:   float �����
	// Qualifier: ����0-max֮�������������������[0,max)
	// Parameter: float max ���ֵ
	// Parameter: bool chSeed �Ƿ��޸����ӣ�Ĭ�ϲ��޸�
	//************************************
	float nexFloat(float max, bool chSeed = false);
	
	//************************************
	// Method:    nextBool
	// FullName:  RandomUtil::nextBool
	// Access:    public 
	// Returns:   bool ture or false
	// Qualifier: �������һ������ֵ
	// Parameter: bool chSeed �Ƿ��޸����ӣ�Ĭ�ϲ��޸�
	//************************************
	bool nextBool(bool chSeed = false);
};
#endif // _RANDOMUTIL_H_