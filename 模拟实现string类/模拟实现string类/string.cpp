#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
//#include<string>
using namespace std;
//初识模板类
//template<class T1,class T2>
//T1 Add(const T1& left, const T2& right)
//{
//	return left + right;
//}
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double b1 = 10.0, b2 = 20.0;
//	Add(a1, a2);
//	Add(b1, b2);
//	system("pause");
//	return 0;
//}
//string类对象的容量操作
//void test()
//{
//	string s("hello world");//string类支持使用cin和cout
//	cout << s.length() << endl;
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;
//}
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}
//模拟实现一个string类
class String
{
public:
	String(const char* str = "")
	{
		// 构造string类对象时，如果传递nullptr指针，认为程序非法，此处断言下
		if (nullptr == str)
		{ 
			assert(str);
			return;
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& s)//拷贝构造
		: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}
	String& operator=(const String& s)//赋值运算符重载
	{
		if (this != &s)
		{
			char* ptr = new char[strlen(s._str) + 1];
			strcpy(ptr, s._str);
			delete[] _str;
			_str = ptr;
		}
		return *this;
	}
	//现代写法
	//String& operator=(const String& s)
	//{
	//	swap(_str, s._str);
	//	return *this;
	//}
	~String()//析构函数
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};
int main()
{
	String s1("you are my pretty sunshine");
	String s2(s1);
	String s3 = s1;
	system("pause");
	return 0;
}