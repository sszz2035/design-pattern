#ifndef _PROPERTIES_H_
#define _PROPERTIES_H_
#include<iostream>
#include<fstream>
#include<map>
#include<string>
#include<algorithm>
#include<sstream>
#include<vector>
#include<set>
#include "util_export.h"
using namespace std;

/**
 * properties�����ļ�����������
 */
class UTIL_API Properties final
{
private:
	map<string, string>* props = nullptr;
	set<string>* keys = nullptr;
	void trim(string& s);
	vector<string> split(const string& str, char pattern);
	void loadKeys();
public:
	Properties();
	~Properties();
	map<string, string>* getProps() const;
	set<string>* getKeys() const;
	//����ָ��λ������
	bool load(const string& path);
	//ͨ��key��ȡ����ֵ
	string getProperty(const string& key);
	//��������ֵ
	void setProperty(const string& key, const string& value);
	//�Ƴ�����
	void remProperty(const string& key);
	//�������õ�ָ��λ��
	bool save(const string& path);
};

/**
 * ����Properties����
 * @param varName Properties����ʵ����Ӧ�ı�����
 * @param fileName configĿ¼����������ļ�����
 */
#define CREATE_PROPERTIES(varName, fileName) \
Properties varName; \
varName.load("config/"#fileName".properties")

#endif // _PROPERTIES_H_