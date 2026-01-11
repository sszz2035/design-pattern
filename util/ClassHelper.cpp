#include "ClassHelper.h"

ClassFactory::ClassFactory()
{

}

ClassFactory::~ClassFactory()
{
	while (!prt_dyinstaces.empty())
	{
		delete prt_dyinstaces.top();
		prt_dyinstaces.pop();
	}
}

void* ClassFactory::getClassInstanceByName(string name)
{
	auto iter = prt_createFunMap.find(name);
	if (iter != prt_createFunMap.end())
	{
		return iter->second();
	}
	return NULL;
}

void ClassFactory::registClass(string name, createFun method, void* dyinstance)
{
	prt_createFunMap.insert(make_pair(name, method));
	prt_dyinstaces.push(dyinstance);
}

ClassFactory& ClassFactory::getInstance()
{
	static ClassFactory instance;
	return instance;
}

DynamicClass::DynamicClass(string name, createFun method)
{
	ClassFactory::getInstance().registClass(name, method, this);
}
