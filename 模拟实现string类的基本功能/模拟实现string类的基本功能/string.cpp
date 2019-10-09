#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
#include<string>
using namespace std;
class String
{
public:
	typedef char* Iterator;
	String(const char* str = "")//构造函数
	{
		if (nullptr == str)
		{
			assert(false);
			return;
		}
		_size = strlen(str);
		_capacity = _size;
		_str = new char[_capacity + 1];
		strcpy(_str, str);
	}
	String(const String& s)//拷贝构造
		:_str(new char[s._capacity + 1])
		, _size(s._size)
		, _capacity(s._capacity)
	{
		strcpy(_str, s._str);
	}
	String& operator=(const String& s)//赋值运算符重载
	{
		if (this != &s)
		{
			char* pstr = new char[strlen(s._str) + 1];
			strcpy(pstr, s._str);
			delete[] _str;
			_str = pstr;
			_size = s._size;
			_capacity = s._capacity;
		}
		return *this;
	}
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
	void Reserve(size_t newCapacity)
	{
		if (newCapacity > _capacity)
		{
			char* str = new char[newCapacity + 1];
			strcpy(str, _str);
			delete[] _str;
			_str = str;
			_capacity = newCapacity;
		}	
	}
	void Resize(size_t newSize, char c = char())
	{
		if (newSize > _size)
		{
			if (newSize > _capacity)
			{
				Reserve(newSize);
			}
			memset(_str + _size, c, newSize - _size);
		}
		
		_size = newSize;
		_str[newSize] = '\0';
	}
	void pushback(char c)
	{
		if (_size == _capacity)
		{
			Reserve(_capacity * 2);
		}
		_str[_size++] = c;
		_str[_size] = '\0';
	}
	void Append(size_t n, char c)
	{
		for (size_t i = 0; i < n; ++i)
		{
			pushback(c);
		}
	}
	void Append(const char* str)
	{
		int str_size = strlen(str);
		if ((_size + str_size)>=_capacity)
		{
			Reserve(_capacity * 2);
		}
		int pos = _size;
		str_size = 0;
		while (str[str_size] != '\0')
		{
			_str[pos] = str[str_size];
			pos++;
			str_size++;
		}
		_size = pos;
		_str[_size] = '\0';
	}
	String& operator+=(char c)
	{
		pushback(c);
		return *this;
	}
	String& operator+=(const char* str)
	{
		Append(str);
		return *this;
	}
	Iterator Begin()
	{
		return _str;
	}
	Iterator endl()
	{
		return _str + _size;
	}
private:
	char* _str;
	size_t _size;
	size_t _capacity;
};
void test1()
{
	String s1("hello world");
	String s2(s1);
	String s3 = s1;
}
void test2()
{
	String s1("hello world");
	s1.pushback('z');
	s1.pushback('h');
	s1.Append(5, 'z');
	s1.Append("zhou");
	s1 += 'L';
	s1 += "ijie";
	auto it = s1.Begin();
	while (it != s1.endl())
	{
		cout << *it++;
	}
}
int main()
{
	test1();
	test2();
	system("pause");
	return 0;
}