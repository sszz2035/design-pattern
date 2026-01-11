#ifndef _STRINGUTIL_H_
#define _STRINGUTIL_H_
#include <vector>
#include <string>
#include "util_export.h"
using namespace std;

/**
 * �ַ�������������
 * @param varName Properties����ʵ����Ӧ�ı�����
 * @param fileName configĿ¼����������ļ�����
 */
class UTIL_API StringUtil
{
public:
	/**
	 * �ַ������
	 * @param const string& str ������ַ���
	 * @param const string& delim ������ַ���
	 * @return ��ֺ���ַ�������
	 */
	static vector<string> split(const string& str,const string& delim);
	/**
	 * ȥ���ַ���ǰ��ո�
	 * @param string& str �������ַ���
	 */
	static void trim(string& str);
};

#endif // _STRINGUTIL_H_
