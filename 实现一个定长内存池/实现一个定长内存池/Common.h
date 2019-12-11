#pragma once

#include <iostream>
using namespace std;

const size_t MAX_SIZE = 64 * 1024;
const size_t NFREE_LIST = MAX_SIZE / 8;

inline void*& NextObj(void* obj)
{
	return *((void**)obj);
}

class FreeList
{
public:
	void Push(void* obj)
	{
		//头插
		NextObj(obj) = _freelist;
		_freelist = obj;
	}
	void PushRange(void* head, void* tail)
	{
		//循环插入
		NextObj(tail) = _freelist;
		_freelist = head;
	}

	void* Pop()
	{
		//头删
		void* obj = _freelist;
		_freelist = NextObj(obj);

		return obj;
	}

	bool Empty()
	{
		return _freelist == nullptr;
	}

private:
	void* _freelist = nullptr;
};

class SizeClass
{
public:
	static size_t ListIndex(size_t size)
	{
		if (size % 8 == 0)
		{
			return size / 8 - 1;
		}
		else
		{
			return size / 8;
		}
	}
};