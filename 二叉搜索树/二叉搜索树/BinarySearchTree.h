//����������
//�ڵ�
template<class k>
struct BSTreeNode
{
	BSTreeNode<k>* _left;
	BSTreeNode<k>* _right;
	k _key;
	BSTreeNode(const k& key)
		:_key(key)
		, _left(nullptr)
		, _right(nullptr)
	{
	}
};
template<class k>
class BSTree
{
	typedef BSTreeNode<k> Node;
public:
	//���캯��
	BSTree()
		:_root(nullptr)
	{
	}
	~BSTree()
	{
	}
	//��������
	bool insert(const k& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}
		Node* parents = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key > key)
			{
				parents = cur;
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				parents = cur;
				cur = cur->_right;
			}
			else
			{
				return false;//���������������ݲ������
			}
		}
		cur = new Node(key);
		if (parents->_key > key)
		{
			parents->_left = cur;
		}
		if (parents->_key < key)
		{
			parents->_right = cur;
		}
		return true;
	}
	//����
	Node* find(const k& key)
	{
		if (_root == nullptr)
		{
			return nullptr;
		}
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else{
				cout << "�ҵ���" << endl;
				return cur;
			}
		}
		cout << "������Ч" << endl;
		return nullptr;
	}
	//ɾ��
	bool Erase(const k& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				// ɾ��
				// 1.��Ϊ��
				// 2.��Ϊ��
				// 3.���Ҷ���Ϊ��
				Node* del = cur;
				if (cur->_left == nullptr)
				{
					if (parent == nullptr)
					{
						_root = cur->_right;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_right;
						}
						else
						{
							parent->_right = cur->_right;
						}
					}
				}
				else if (cur->_right == nullptr)
				{
					if (parent == nullptr)
					{
						_root = cur->_left;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_left;
						}
						else
						{
							parent->_right = cur->_left;
						}
					}
				}
				else
				{
					Node* lessParent = cur;
					Node* lessRight = cur->_right;
					while (lessRight->_left)
					{
						lessParent = lessRight;
						lessRight = lessRight->_left;
					}

					cur->_key = lessRight->_key;
					del = lessRight;
					if (lessParent->_left == lessRight)
					{
						lessParent->_left = lessRight->_right;
					}
					else
					{
						lessParent->_right = lessRight->_right;
					}
				}

				delete del;
				return true;
			}
		}

		return false;
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
private:
	Node* _root;
};

void TestBSTtree()
{
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	BSTree<int> t;
	for (auto e : a)
	{
		t.insert(e);
	}
	t.InOrder();
	t.find(10);
	t.Erase(2);
	t.Erase(8);
	t.Erase(1);
	t.Erase(7);
	t.Erase(5);

	t.InOrder();
}