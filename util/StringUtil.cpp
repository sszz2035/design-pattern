#include "StringUtil.h"

vector<string> StringUtil::split(const string& str, const string& delim)
{
	vector<string> res;
	//空字符处理
	if ("" == str) return res;

	//字符串从string类型转换为char*类型
	char* source = new char[str.length() + 1];
	strcpy_s(source, str.length() + 1, str.c_str());
	char* d = new char[delim.length() + 1];
	strcpy_s(d, delim.length() + 1, delim.c_str());

	//拆分字符串逻辑
	char* nextToken = NULL;
	char* strToken = strtok_s(source, d, &nextToken);
	while (strToken) {
		//分割得到的字符串转换为string类型
		string s = strToken;
		//存入结果数组
		res.push_back(s);
		//继续分隔
		strToken = strtok_s(NULL, d, &nextToken);
	}
	delete[] source;
	delete[] d;
	return res;
}

void StringUtil::trim(string& str)
{
	if (!str.empty())
	{
		str.erase(0, str.find_first_not_of(" "));
		str.erase(str.find_last_not_of(" ") + 1);
	}
}
