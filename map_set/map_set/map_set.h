#include <map>
#include <set>
#include<string>
void test_map_set1()
{
	set<int> s;
	s.insert(1);
	s.insert(5);
	s.insert(3);
	s.insert(9);
	s.insert(7);
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	set<int>::reverse_iterator rit = s.rbegin();
	while (rit != s.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
	//删除
	auto pos = s.find(5);
	if (pos != s.end())
	{
		s.erase(pos);
	}
	else
	{
		cout << "找不到" << endl;
	}
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

}
void test_map_set2()
{
	map<string, string> dict;
	dict.insert(pair<string,string>("insert", "插入"));
	dict.insert(pair<string, string>("left", "左边"));
	dict.insert(pair<string, string>("right", "右边"));
	dict.insert(pair<string, string>("node", "节点"));
	dict.insert(pair<string, string>("tree", "树"));
	string str;
	while (cin >> str)
	{
		auto ret = dict.find(str);
		if (ret != dict.end())
		{
			cout << str << ":" << (*ret).second << endl;
		}
		else
		{
			cout << str << ":" << "非法词汇" << endl;
		}
	}
	
}
void test_map_set3()
{
	//统计出现次数
	string str[] = { "草莓", "苹果", "香蕉", "苹果", "苹果", "香蕉" };
	map<string, int> countMap;
	for (auto& e : str)
	{
		auto ret = countMap.find(e);
		if (ret != countMap.end())
		{
			//(*ret).second++;
			ret->second++;
		}
		else
		{
			//调用构造函数创建匿名对象
			//countMap.insert(pair<string, int>(e, 1));
			//template<class K,class V>函数模板
			countMap.insert(make_pair(e, 1));
		}
	}
	for (auto e : countMap)
	{
		cout << e.first << ":" << e .second << endl;
	}
}
void test_map_set4()
{
	string str[] = { "草莓", "苹果", "香蕉", "苹果", "苹果", "香蕉" };
	map<string, int> countMap;
	for (auto& e : str)
	{
		countMap[e]++;
	}
	//operator[]可以用来插入和修改
	countMap["菠萝"];
	countMap["菠萝"] = 5;
	for (auto e : countMap)
	{
		cout << e.first << ":" << e.second << endl;
	}
}