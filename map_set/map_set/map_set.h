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
	//ɾ��
	auto pos = s.find(5);
	if (pos != s.end())
	{
		s.erase(pos);
	}
	else
	{
		cout << "�Ҳ���" << endl;
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
	dict.insert(pair<string,string>("insert", "����"));
	dict.insert(pair<string, string>("left", "���"));
	dict.insert(pair<string, string>("right", "�ұ�"));
	dict.insert(pair<string, string>("node", "�ڵ�"));
	dict.insert(pair<string, string>("tree", "��"));
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
			cout << str << ":" << "�Ƿ��ʻ�" << endl;
		}
	}
	
}
void test_map_set3()
{
	//ͳ�Ƴ��ִ���
	string str[] = { "��ݮ", "ƻ��", "�㽶", "ƻ��", "ƻ��", "�㽶" };
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
			//���ù��캯��������������
			//countMap.insert(pair<string, int>(e, 1));
			//template<class K,class V>����ģ��
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
	string str[] = { "��ݮ", "ƻ��", "�㽶", "ƻ��", "ƻ��", "�㽶" };
	map<string, int> countMap;
	for (auto& e : str)
	{
		countMap[e]++;
	}
	//operator[]��������������޸�
	countMap["����"];
	countMap["����"] = 5;
	for (auto e : countMap)
	{
		cout << e.first << ":" << e.second << endl;
	}
}