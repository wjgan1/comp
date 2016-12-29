#include <iostream>
using namespace std;

template <typename T>
class RBNode
{
public:
	T val;
	int left_sz, right_sz;
	RBNode<T> *par, *left, *right;
	bool red;
};

template <typename T>
class RBTree
{
	RBNode<T> *root;
	int sz;

	int size()
	{
		return sz;
	}

	RBNode<T>* find(T val)
	{
		return find(root, val);
	}
	
	RBNode<T>* find(RBNode<T> *&node, T val)
	{
		if (!node)
			return nullptr;
		if (T == node->val)
			return node;
		if (T < node->val)
			return find(node->left,val);
		return find(node->right,val);
	}
	/*
	RBNode<T>* select(int pos)
	{
		if (pos < 0 || pos >= sz)
			return NULL;
		return select(root, pos);
	}

	RBNode<T>* select(RBNode *node, int pos)
	{
		if (pos == node->left_sz)
			return node;
		if (pos < node->left_sz)
			return select(node->left,pos);
		return select(node->right,pos-node->left_sz-1);
	}

	RBNode<T>*
	*/
};

int main()
{
	
}