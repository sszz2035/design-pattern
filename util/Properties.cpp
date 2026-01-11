#include "Properties.h"

void Properties::trim(string& s)
{
	if (!s.empty())
	{
		s.erase(0, s.find_first_not_of(" "));
		s.erase(s.find_last_not_of(" ") + 1);
	}
}

std::vector<std::string> Properties::split(const string& str, char pattern)
{
	vector<string> res;
	stringstream input(str);
	string temp;
	while (getline(input, temp, pattern))
	{
		res.push_back(temp);
	}
	return res;
}

void Properties::loadKeys()
{
	for (auto i : *props) {
		keys->insert(i.first);
	}
}

Properties::Properties()
{
	this->props = new map<string, string>();
	this->keys = new set<string>();
}

Properties::~Properties()
{
	delete props;
	delete keys;
}

std::map<std::string, std::string>* Properties::getProps() const
{
	return props;
}

std::set<std::string>* Properties::getKeys() const
{
	return keys;
}

bool Properties::load(const string& path)
{
	//加载配置文件内容
	vector<string> paths = split(path, '.');
	if (paths.size() == 0 || paths[paths.size() - 1] != "properties") {
		throw runtime_error(path + " is not a properties file!");
	}
	ifstream input(path);
	if (!input) {
		throw runtime_error("can't load " + path);
	}
	string line;
	while (getline(input, line))
	{
		trim(line);
		if (line.empty() || line == "\r" || line[0] == '#')
		{
			continue;
		}
		vector<string> res = split(line, '=');
		if (res.size() < 2)
		{
			cerr << "Properties format error!" << endl;
			throw exception("Properties format error!");
		}
		//去除value后面的注释内容
		size_t t = res[1].find("#");
		if (t != string::npos) {
			res[1].erase(t);
		}
		//去除key和value的空格
		for_each(res.begin(), res.end(),
			[=](string& s) mutable {
				trim(s);
			});
		props->insert(make_pair(res[0], res[1]));
	}
	input.close();
	//填充keys内容
	loadKeys();
	return true;
}

std::string Properties::getProperty(const string& key)
{
	if (props->find(key) == props->end())
	{
		cerr << "can't find value with " << key << endl;
		return "";
	}
	string value = this->props->at(key);
	return value;
}

void Properties::setProperty(const string& key, const string& value)
{
	this->props->insert(make_pair(key, value));
}

void Properties::remProperty(const string& key)
{
	auto iter = props->find(key);
	if (iter != props->end())
	{
		props->erase(iter);
	}
}

bool Properties::save(const string& path)
{
	ofstream output(path);
	if (!output) {
		throw exception("can 't construct the output file!");
	}
	for (auto item : *props) {
		output << item.first << "=" << item.second << endl;
	}
	output.close();
	return true;
}