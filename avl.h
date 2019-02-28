//Mohammed Salam
#ifndef AVL_H
#define AVL_H

#include "bst.h"

template<typename T>
class AVL : public BST<T>{
public:
	AVL();
	~AVL();
	//int height();
	//int size();
	//void print();
	//void insert(const T& data);
	//void remove(const T& data);
	//AVL& operator=(const AVL& rhs);

private:
	Node<T>* root;
	//AVLNode<T>* root;
	//int heightHelper(AVLNode<T>* root);
	//int sizeHelper(AVLNode<T>* root);
	//void printHelper(AVLNode<T>* root);
	//void copy(Node<T>* node);
	Node<T>* insertHelper(Node<T>* node, T data);
	Node<T>* rotateRight(Node<T>* &node);
	Node<T>* rotateRightx2(Node<T>* &node);
	Node<T>* rotateLeft(Node<T>* &node);
	Node<T>* rotateLeftx2(Node<T>* &node);
	Node<T>* removeHelper(Node<T>* node, T data);
	//Node<T>* findMin(Node<T>* node);
	//void removeNode(AVLNode<T>* node);
	//void copy(AVLNode<T>* node);
};
#include "avl.cpp"

#endif