#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<assert.h>
using namespace std;

template<class T>
class Vector{
public:
	typedef T* iterator;
	//构造函数
	Vector()
		:_start(nullptr)
		, _finish(nullptr)
		, _end_of_storage(nullptr)
	{

	}
	//拷贝构造函数
	Vector(const Vector<T>& v)
	{
		_start = new T[v.size()];
		memcpy(_start, v._start, sizeof(T)*v.size());
		_finish = _start + v.size();
		_end_of_storage = _start + v.size();
	}
	//赋值运算符重载
	const Vector<T>& operator=(Vector<T> v)
	{
		//this->swap(v);
		Swap(v);
		return *this;
	}
	//析构函数
	~Vector()
	{
		if (_start)
		{
			delete[]_start;
			_start = _finish = _end_of_storage = nullptr;
		}
	}
	void Swap(Vector<T>& v)
	{
		swap(_start, v._start);
		swap(_finish, v._finish);
		swap(_end_of_storage, v._end_of_storage);
	}
	//迭代器指针的开始结束
	iterator begin()
	{
		return _start;
	}
	iterator end()
	{
		return _finish;
	}
	size_t size() const
	{
		return _finish - _start;
	}
	size_t capacity() const
	{
		return _end_of_storage - _start;
	}
	T& operator[](size_t pos)const
	{
		return _start[pos];
	}

	//增容函数reserve
	void reserve(size_t n)
	{
		if (n > capacity())
		{
			size_t sz = size();
			T* tmp = new T[n];
			if (_start)
			{
				memcpy(tmp, _start, sizeof(T)*sz);
				delete[] _start;
			}
			_start = tmp;
			_finish = _start + sz;
			_end_of_storage = _start + n;
		}
	}
	//判断是否需要增容并初始化resize
	void resize(size_t n, const T& val = T())
	{
		if (n < size())
		{
			_finish = _start + n;
		}
		if (n > size())
		{
			reserve(n);
		}
		while (_finish != _start + n)
		{
			*_finish = val;
			++_finish;
		}
	}
	//尾插尾删  任意位置插入删除
	void push_back(const T& x)
	{
		//判满
		if (_finish == _end_of_storage)
		{
			size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
			reserve(newcapacity);
		}
		*_finish = x;
		_finish++;
	}
	void pop_back()
	{
		assert(_finish > _start);
		--_finish;
	}
	void insert(iterator& pos, const T& x)
	{
		assert(pos >= _start && pos < _finish);
		if (_finish == _end_of_storage)
		{
			size_t n = pos - _start;//在_start改变之前，记录其与POS的相对位置
			size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
			reserve(newcapacity);
			pos = _start + n;
		}
		iterator end = _finish - 1;
		while (end >= pos)
		{
			*(end + 1) = *end;
			--end;
		}
		*pos = x;
		++_finish;
	}
	void erase(iterator& pos)
	{
		assert(pos >= _start && pos < _finish);
		iterator begin = pos + 1;
		while (begin < _finish)
		{
			*(begin - 1) = *begin;
			++begin;
		}
		--_finish;
	}
private:
	iterator _start;//数据开始
	iterator _finish;//有效数据个数
	iterator _end_of_storage;//存储容量
};
void test()
{
	Vector<int> v1;
	v1.push_back(1);
	v1.push_back(3); 
	v1.push_back(5);
	v1.push_back(7); 
	v1.push_back(9);
	
	auto it = v1.begin();
	v1.insert(it, 2);
	for (size_t i = 0; i < v1.size(); ++i)
	{
		cout << v1[i] << " ";
	}
	cout << endl;
    
	v1.pop_back();
	v1.erase(it);
	for (size_t i = 0; i < v1.size(); ++i)
	{
		cout << v1[i] << " ";
	}
	Vector<int> v2(v1);
	Vector<int> v3 = v1;
}
int main()
{
	test();
	system("pause");
	return 0;
}
