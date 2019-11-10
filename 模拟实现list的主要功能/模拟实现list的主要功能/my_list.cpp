#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
using namespace std;
namespace zlj
{
	template<class T>
	struct list_node//�Զ������ͱ����ʼ�����������Ϳ��Բ���
	{
		list_node<T>* _next;
		list_node<T>* _prev;
		T _data;
		list_node<T>(const T& x = T())
			:_data(x)
			, _next(nullptr)
			, _prev(nullptr)
		{
		}
	};
	//List�е�������ʹ������������ʹ�÷���������ͬ��ʵ�����Ӧ����
	template<class T,class Ref,class ptr>//ʵ����ǰ��ָ��Ļ�������
	//���������ܵ�ʵ��
	struct list_iterator
	{
		typedef list_node<T> node;//����������
		typedef list_iterator<T, Ref, ptr> self;//ָ����
		node* _node;
		list_iterator(node* node)
			:_node(node)
		{}
		Ref operator*()//��������
		{
			return _node->_data;
		}
		ptr operator->()//�Զ�������
		{
			return &_node->_data;
		}
		self& operator++()//ǰ��++
		{
			_node = _node->_next;
			return *this;
		}
		self operator++(int)
		{
			list_iterator<T> tmp(*this);
			_node = _node->_next;
			return tmp;
		}
		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		self operator--(int)
		{
			list_iterator<T> tmp(*this);
			_node = _node->_prev;
			return *this;
		}
		bool operator!=(const self& it)
		{
			return _node != it._node;
		}
		bool operator==(const self& it)
		{
			return _node == it._node;
		}
	};
	template<class T>
	//��ͷ˫��ѭ��
	class list
	{
		typedef list_node<T> node;
	public:
		typedef list_iterator<T, T&, T*> iterator;
		typedef list_iterator<T, const T&,const T*> const_iterator;
		const_iterator begin()const
		{
			return const_iterator(_head->_next);
		}
		const_iterator end()const
		{
			return const_iterator(_head);
		}
		iterator begin()
		{
			return iterator(_head->_next);
		}
		iterator end()
		{
			return iterator(_head);
		}
		//copy
		list(const list<T>& l)
		{
			_head = new node;
			_head->_next = head;
			_head->_prev = head;
			//const_iterator it = l.begin();
			auto it = l.begin();
			while (it != l.end())
			{
				push_back(*it);
				++it;
			}
		}
		//��ֵ���������
		list<T>& operator=(list<T> l)
		{
			swap(_head, l._head);
			return *this;
		}
		list()
		{
			_head = new node(T());
			_head->_next = _head;
			_head->_prev = _head;
		}
		~list()
		{
			//clear();
			delete _head;
			_head = nullptr;
		}
		//β��
		void push_back(const T& x)
		{
			node* tail = _head->_prev;
			node* newnode = new node(x);
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;
		}
		//����λ�ò���
		void insert(iterator pos, const T& x)
		{
			node* cur = pos._node;
			node* prev = cur->_prev;
			node* newnode = new node(x);
			//prev newnode cur
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
		}
		//����λ��ɾ��
		void erase(iterator pos)
		{
			node* cur = pos._node;
			assert(cur != _head);
			node* prev = cur->_prev;
			node* next = cur->_next;
			prev->_next = next;
			next->_prev = prev;
			delete cur;
			//return iterator(next);
		}
		void pop_back()
		{
			erase(--end());
		}
		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_front()
		{
			erase(begin());
		}
		void print_list(const list<int>& l)
		{
			auto it = l.begin();
			while (it != l.end())
			{
				cout << *it << " ";
				++it;
			}
			cout << endl;
		}
	private:
		node* _head;
	};
	
	
	void test1()
	{
		list<int> l;
		l.push_back(1);
		l.push_back(2);
		l.push_back(3);
		l.push_back(4);
		l.print_list(l);

		l.pop_back();
		l.print_list(l);

		l.push_front(0);
		l.print_list(l);

		l.pop_front();
		l.print_list(l);
	}
}
int main()
{
	zlj::test1();
	system("pause");
	return 0;
}
	
