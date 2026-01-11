#ifndef _CLASSHELPER_H_
#define _CLASSHELPER_H_

#include <map>
#include <string>
#include <stack>
#include "util_export.h"
using std::string;
using std::map;
using std::pair;
using std::stack;

// ����һ���ഴ������ָ��
typedef void* (*createFun)(void);

/**
 * �๤��
 */
class UTIL_API ClassFactory
{
private:
	ClassFactory();
	~ClassFactory();
	map<string, createFun> prt_createFunMap;
	stack<void*> prt_dyinstaces;
	ClassFactory(const ClassFactory&) = delete; 
	ClassFactory& operator=(const ClassFactory&) = delete;
public:
	//************************************
	// Method:    getClassInstanceByName
	// FullName:  ClassFactory::getClassInstanceByName
	// Access:    public 
	// Returns:   void* ������ʵ��ָ��
	// Qualifier: ͨ��������ȡ��ʵ��
	// Parameter: string name ������(�����ռ�::����)���� sp::Cat
	//************************************
	void* getClassInstanceByName(string name);
	//************************************
	// Method:    registClass
	// FullName:  ClassFactory::registClass
	// Access:    public 
	// Returns:   void
	// Qualifier: ע��֧��ͨ������������ʵ������
	// Parameter: string name ������(�����ռ�::����)���� sp::Cat
	// Parameter: createFun method �ഴ������ָ��
	// Parameter: void * dyinstance ��̬��ʵ��
	//************************************
	void registClass(string name, createFun method, void* dyinstance);
	// ��ȡ�๤������
	static ClassFactory& getInstance();
};

/**
 * ��̬�࣬�������๤����ע��֧��ͨ��������������
 */
class UTIL_API DynamicClass
{
public:
	DynamicClass(string name, createFun method);
};

/**
 * ������̬���Լ������ഴ��������д��h��
 * @param className �������������ռ�Ҫ���������ռ�
 */
#define DECLARE_CLASS(className) \
private: \
static DynamicClass* prt_dcInstance; \
public: \
static void* createFun() {return new className();}

/**
 * ���嶯̬��ʵ����д��cpp��
 * @param className �������������ռ�Ҫ���������ռ�
 */
#define IMPLEMENT_CLASS(className) \
DynamicClass* className::prt_dcInstance = new DynamicClass(#className,&className::createFun)

/**
 * ͨ�������ƴ�����ʵ��
 * @param typeName ���ͣ����ڻ�ȡ�ɹ������ǿ������ת��
 * @param varName ��ʵ��������
 * @param className �������������ռ�Ҫ���������ռ�
 */
#define GET_INSTANCE_BY_NAME(typeName, varName, className) \
typeName varName = (typeName)ClassFactory::getInstance().getClassInstanceByName(className)

#endif // _CLASSHELPER_H_