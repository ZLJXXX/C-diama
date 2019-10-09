#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
//#include<string>
using namespace std;
//��ʶģ����
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
//string��������������
//void test()
//{
//	string s("hello world");//string��֧��ʹ��cin��cout
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
//ģ��ʵ��һ��string��
class String
{
public:
	String(const char* str = "")
	{
		// ����string�����ʱ���������nullptrָ�룬��Ϊ����Ƿ����˴�������
		if (nullptr == str)
		{ 
			assert(str);
			return;
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& s)//��������
		: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}
	String& operator=(const String& s)//��ֵ���������
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
	//�ִ�д��
	//String& operator=(const String& s)
	//{
	//	swap(_str, s._str);
	//	return *this;
	//}
	~String()//��������
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