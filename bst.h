//Mohammed Salam
#ifndef BST_H
#define BST_H
#include <algorithm>
#include <cstdlib>
#include <iostream>

template <typename T>
struct Node {
	T data;
	Node<T>* left;
	Node<T>* right;
	int height;
	//Node<T>* parent;
	Node() {
		left = NULL;
		right = NULL; 
		height = 0;
	}

	~Node() {
		delete(left);
		delete(right);
	}
	//Node& operator=(Node rhs);
};

template <typename T>
class BST {
public:
	BST();
	~BST();
	int height();
	int size();
	void print();
	//operator[]
	void insert(const T& data);
	void remove(const T& data);
	BST& operator=(const BST& rhs);
	T& operator[](const int index);
protected:
	int heightHelper(Node<T>* root);
	int sizeHelper(Node<T>* root);
	void printHelper(Node<T>* root);
	Node<T>* findMin(Node<T>* node);
	void removeNode(Node<T>* node);
	void copy(Node<T>* node);
	virtual Node<T>* insertHelper(Node<T>* root, T data);
	virtual Node<T>* removeHelper(Node<T>* root, T data);
	//Node<T>* findMin(Node<T>* node);
private:
	Node<T>* root;
};

#include "bst.cpp"

#endif