#pragma once
#include<iostream>
#include<time.h>
using namespace std;
namespace blog_RBTree
{
	enum Color
	{
		BLACK,
		RED
	};

	template<class T>
	struct TreeNode
	{
		//��Ա����
		T _data;//����
		TreeNode<T>* _left;
		TreeNode<T>* _right;
		TreeNode<T>* _parent;
		Color _col;//���������ɫ

		//���캯��
		TreeNode(const T& data)
			:_data(data)
			,_left(nullptr)
			,_right(nullptr)
			,_parent(nullptr)
			,_col(RED)//ÿ����һ���½�㣬����������ɫĬ�ϸ���ɫ������Ϊʲô����������
		{}
	};

	//������ĵ�����
	template<class T>
	struct RBTreeIterator
	{
		typedef TreeNode<T> Node;
		typedef RBTreeIterator Self;

		//���캯��
		RBTreeIterator(Node* tmp)
			:_node(tmp)
		{}

		//����*
		T operator*()
		{
			return _node->_data;
		}

		//����->
		T& operator->()
		{
			return &_node->_data;
		}

		//������++
		Self operator++()
		{
			if (_node->_right != nullptr)
			{
				Node* cur = _node->_right;
				while (cur->_left != nullptr)
				{
					cur = cur->_left;
				}
				_node = cur;
			}
			else
			{
				Node* cur = _node;
				Node* parent = cur->_parent;
				while (parent != nullptr && parent->_right == cur)
				{
					cur = parent;
					parent = cur->_parent;
				}
				_node = parent;
			}
			return *this;
		}

		bool operator!=(const Self& tmp)
		{
			if (_node != tmp._node)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		//��Ա����
		Node* _node;
	};

	template<class T, class GCV>
	class RBTree
	{
	public:
		typedef TreeNode<T> Node;
		typedef RBTreeIterator<T> iterator;
	public:
		//����begin������
		iterator begin()
		{
			Node* tmp = GetRoot();
			while (tmp->_left != nullptr)
			{
				tmp = tmp->_left;
			}
			return iterator(tmp);
		}

		//����end������
		iterator end()
		{
			return iterator(nullptr);
		}

		//���캯��
		RBTree()
			:_root(nullptr)//�������һ��nullptr
		{}

		//������
		bool insert(const T& data)
		{
			GCV gcv;//�º�������

			//�����ΪNULL����ֱ�ӽ��½�����_root
			if (_root == nullptr)
			{
				_root = new Node(data);
				_root->_col = BLACK;//���½���_root��Ҫ�ǵð���ɫ��λBLACK
				return true;
			}

			Node* cur = _root;
			Node* cur_parent = nullptr;
			while (cur != nullptr)
			{
				if (gcv(data) > gcv(cur->_data))
				{
					cur_parent = cur;
					cur = cur->_right;
				}
				else if (gcv(data) < gcv(cur->_data))
				{
					cur_parent = cur;
					cur = cur->_left;
				}
				else//˵����ֵ�Ѿ����ڣ������в���
				{
					return false;	
				}
			}

			//���½�����
			cur = new Node(data);
			if (gcv(cur_parent->_data) > gcv(data))
			{
				cur_parent->_left = cur;
				cur->_parent = cur_parent;
			}
			else
			{
				cur_parent->_right = cur;
				cur->_parent = cur_parent;
			}

			//����������
			while (cur_parent != nullptr && cur_parent->_col == RED)
			{
				Node* grandparent = cur_parent->_parent;
				if (grandparent->_left == cur_parent)//������
				{
					Node* uncle = grandparent->_right;
					if (uncle != nullptr && uncle->_col == RED)//���һ,uncle������Ϊ��
					{
						cur_parent->_col = uncle->_col = BLACK;
						grandparent->_col = RED;
						//�������ϴ���
						cur = grandparent;
						cur_parent = cur->_parent;
					}
					else//������������
					{
						//���������������һ����ת����Ա������������Կ������ж��Ƿ��������
						if (cur_parent->_right == cur)//����������������
						{
							//�Ƚ���һ������
							RotateL(cur_parent);
							swap(cur, cur_parent);
						}
						//�����ߵ������һ�����������
						RotateR(grandparent);
						cur_parent->_col = BLACK;
						grandparent->_col = RED;
						break;
					}
				}
				else if (grandparent->_right == cur_parent)//������
				{
					Node* uncle = grandparent->_left;
					if (uncle != nullptr && uncle->_col == RED)//����������һ
					{
						cur_parent->_col = uncle->_col = BLACK;
						grandparent->_col = RED;

						cur = grandparent;
						cur_parent = cur->_parent;
					}
					else//�������������������
					{
						if (cur_parent->_left == cur)
						{
							RotateR(cur_parent);
							swap(cur, cur_parent);
						}
						RotateL(grandparent);
						cur_parent->_col = BLACK;
						grandparent->_col = RED;
						break;
					}
				}
			}
			_root->_col = BLACK;
		}
		
		//��ȡ�����
		Node* GetRoot()
		{
			return _root;
		}

	private:
		//����	
		void RotateL(Node* cur_parent)
		{
			GCV gcv;
			Node* cur = cur_parent->_right;
			Node* cur_left = cur->_left;

			//�ı�ָ������ӹ�ϵ
			cur_parent->_right = cur_left;
			if (cur_left != nullptr)
			{
				cur_left->_parent = cur_parent;
			}

			cur->_left = cur_parent;
			Node* cur_parent_parent = cur_parent->_parent;
			cur_parent->_parent = cur;

			//��ת��ɺ�Ҫ�ж�cur_parent�Ƿ�Ϊ��
			if (cur_parent_parent != nullptr)//˵��cur_parent���Ǹ�
			{
				if (gcv(cur_parent_parent->_data) < gcv(cur_parent->_data))
				{
					cur_parent_parent->_right = cur;
					cur->_parent = cur_parent_parent;
				}
				else
				{
					cur_parent_parent->_left = cur;
					cur->_parent = cur_parent_parent;
				}
			}
			else//˵��cur_parent�Ǹ�
			{
				_root = cur;
				cur->_parent = nullptr;
			}

		}

		//�ҵ���
		void RotateR(Node* cur_parent)
		{
			GCV gcv;
			Node* cur = cur_parent->_left;
			Node* cur_right = cur->_right;

			cur_parent->_left = cur_right;
			if (cur_right != nullptr)
			{
				cur_right->_parent = cur_parent;
			}

			cur->_right = cur_parent;
			Node* cur_parent_parent = cur_parent->_parent;
			cur_parent->_parent = cur;

			if (cur_parent_parent != nullptr)
			{
				if (gcv(cur_parent_parent->_data) > gcv(cur_parent->_data))
				{
					cur_parent_parent->_left = cur;
					cur->_parent = cur_parent_parent;
				}
				else
				{
					cur_parent_parent->_right = cur;
					cur->_parent = cur_parent_parent;
				}
			}
			else
			{
				_root = cur;
				cur->_parent = nullptr;
			}

		}

	private:
		Node* _root;
	};



}
