#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<thread>
#include<mutex>
using namespace std;
class ordinary{
public:
	ordinary()
	{
		cout << "ordinary" << endl;
	}
};
//int main(){
//	ordinary hp1;				// 栈
//	static ordinary hp2;		// 数据段(静态区)
//	ordinary* p = new ordinary; // 堆
//	system("pause");
//	return 0;
//}
// 只能在堆上
class HeapOnly
{
public:
	static HeapOnly* GetHeapObj()
	{
		HeapOnly* p = new HeapOnly;
		return p;
	}

private:
	HeapOnly()
	{
		cout << "HeapOnly()" << endl;
	}
	//拷贝构造私有化
	//C++98：只声明，不定义
	//HeapOnly(const HeapOnly&);
	//C++11
	HeapOnly(const HeapOnly&) = delete;//删掉拷贝构造
};
class StackOnly
{
public:
	static StackOnly CreateObject()
	{
		return StackOnly();
	}
private:
	StackOnly()
	{}
	/*void* operator new(size_t size);
	void operator delete(void* p);*/
};
//class NonInherit final
//{
//public:
//	NonInherit()
//	{}
//};
//
//class Inherit : public NonInherit  // 借助子类构造函数来设定
//{};
//int main()
//{
////	//HeapOnly hp1;				// 栈
////	//static HeapOnly hp2;		// 数据段(静态区)
////	HeapOnly* p = HeapOnly::GetHeapObj(); // 堆
////	//HeapOnly copy1(*p); //栈拷贝构造
////	//static HeapOnly copy(*p); //数据段拷贝构造
//
//	//StackOnly so = StackOnly::CreateObject();
//	////static StackOnly so1(so);
//	////StackOnly* p2 = new StackOnly; // operator new + 构造函数
//
//	/*Inherit p1;*/
//	system("pause");
//	return 0;
//}

//单例:
//饿汉 --> 一上来就初始化，main函数开始之间就实例化对象
class Singleton
{
public:
	static Singleton& GetInstance()
	{ 
		//双重检查提高效率
		if (_sInst == nullptr)
		{
		    _stx.lock();
			if (_sInst == nullptr)
			{
				_sInst = new Singleton;
			}
			_stx.unlock();
			
		}
		return *_sInst;
	}
private:
	//构造函数私有化
	Singleton()
	{}
	//拷贝构造函数私有化
	Singleton(const Singleton&) = delete;
	static Singleton* _sInst;//声明 
	static mutex _stx;
};
Singleton* Singleton::_sInst = nullptr;
mutex Singleton::_stx;
int main()
{
	/*cout << &Singleton::GetInstance() << endl;
	cout << &Singleton::GetInstance() << endl;
	cout << &Singleton::GetInstance() << endl;
	cout << &Singleton::GetInstance() << endl;*/

	// 多线程来调用Singleton::GetInstance()，有没有线程安全的问题？
	// 
	vector<thread> vthreads;
	for (size_t i = 0; i < 100; ++i)
	{
		vthreads.push_back(thread([]()
		{
			this_thread::sleep_for(std::chrono::seconds(1));
			for (size_t i = 0; i < 10; ++i)
			{
				cout << &Singleton::GetInstance() << endl;
			}
		}));
	}
	for (auto& e : vthreads)
	{
		e.join();
	}
	system("pause");
	return 0;
}
