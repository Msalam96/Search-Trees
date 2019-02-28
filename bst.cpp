//Mohammed Salam
#ifdef BST_H

/*
template<typename T>
Node<T>& Node<T>::operator=(Node rhs) {
	rhs.swap(*this);
	return *this;
}
*/
template<typename T>
BST<T>::BST() {
	root = NULL;
}

template<typename T>
BST<T>::~BST() {
	delete(root);
}

template<typename T>
int BST<T>::heightHelper(Node<T>* root) {
	if (!root) {
		return 0;
	} else {
		return 1 + std::max(heightHelper(root->left), heightHelper(root->right));
	}
}

template<typename T>
int BST<T>::height() {
	return heightHelper(this->root);
}

template<typename T>
int BST<T>::sizeHelper(Node<T>* root) {
	if (!root) {
		return 0;
	} else {
		return 1 + sizeHelper(root->left) + sizeHelper(root->right);
	}
}

template<typename T>
int BST<T>::size() {
	return sizeHelper(this->root);
}

template<typename T>
void BST<T>::printHelper(Node<T>* root) {
	if (!root) {
		return;
	} else {
		printHelper(root->left);
		std::cout << root->data << " ";
		printHelper(root->right);
	}
}

template<typename T>
void BST<T>::print() {
	printHelper(this->root);
}

template<typename T>
Node<T>* BST<T>::insertHelper(Node<T>* root, T data) {
	if (root == NULL) {
		root = new Node<T>;
		root->data = data;
		root->left = root->right = NULL;
	} else if (data < root->data) {
		root->left = insertHelper(root->left, data);
	} else if (data > root->data) {
		root->right = insertHelper(root->right, data);
	} else {
		return NULL;
	}
	return root;
}

template<typename T>
void BST<T>::insert(const T& data) {
	root = insertHelper(root, data);
}

template<typename T>
Node<T>* BST<T>::removeHelper(Node<T>* root, T data) {
	Node<T>* traverse = root;
	if (traverse == NULL) {
		return NULL;
	} else if (data < traverse->data) {
		traverse->left = removeHelper(traverse->left, data);
	} else if (data > traverse->data) {
		traverse->right = removeHelper(traverse->right, data);
	} else if(traverse->left && traverse->right) {
		Node<T>* temp = findMin(traverse->right);
		traverse->data = temp->data;
		traverse->right = removeHelper(traverse->right, traverse->data);
	} else {
		Node<T>* temp = traverse;
		if (traverse->left == NULL) {
			traverse = traverse->right;
		} else if (traverse->right == NULL) {
			traverse = traverse->left;
		}
		delete(temp);
	}
	return traverse;
}

template<typename T>
Node<T>* BST<T>::findMin(Node<T>* node) {
	if (node == NULL) {
		return NULL;
	} else if (node->left == NULL) {
		return node;
	} else {
		return findMin(node->left);
	}

}

template<typename T>
void BST<T>::remove(const T& data) {
	root = removeHelper(root, data);
}

template<typename T>
void BST<T>::removeNode(Node<T>* node) {
	if (node) {
		removeNode(node->left);
		removeNode(node->right);
		delete(node);
	}
}

template<typename T>
void BST<T>::copy(Node<T>* node) {
	if (node) {
		insert(node->data);
		copy(node->left);
		copy(node->right);
	}
}

template<typename T>
T& BST<T>::operator[](const int index) {
	if (index >= size()) {
		exit(0);
	} else {
		return root[index].data;
	}
}

template<typename T>
BST<T>& BST<T>::operator=(const BST& rhs) {
	if(this != &rhs) {
          removeNode(this->root);
          root = NULL;
          copy(rhs.root);
     }
     return *this;
}
#endif