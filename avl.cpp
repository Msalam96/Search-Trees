//Mohammed Salam
#ifdef AVL_H
using namespace std;
template<typename T>
AVL<T>::AVL() {
	root = NULL;
}

template<typename T>
AVL<T>::~AVL() {
	delete(root);
}

/*
template<typename T>
int AVL<T>::heightHelper(AVLNode<T>* root) {
	if (!root) {
		return 0;
	} else {
		return 1 + std::max(heightHelper(root->left), heightHelper(root->right));
	}
}

template<typename T>
int AVL<T>::height() {
	return heightHelper(this->root);
}

template<typename T>
int AVL<T>::sizeHelper(AVLNode<T>* root) {
	if (!root) {
		return 0;
	} else {
		return 1 + sizeHelper(root->left) + sizeHelper(root->right);
	}
}

template<typename T>
int AVL<T>::size() {
	return sizeHelper(this->root);
}

template<typename T>
void AVL<T>::printHelper(AVLNode<T>* root) {
	if (!root) {
		return;
	} else {
		printHelper(root->left);
		std::cout << root->data << " ";
		printHelper(root->right);
	}
}

template<typename T>
void AVL<T>::print() {
	printHelper(this->root);
}
*/
template<typename T>
Node<T>* AVL<T>::insertHelper(Node<T>* node, T data) {
	//create new node with data
	if (node == NULL) {
		node = new Node<T>;
		node->data = data;
		node->height = 0;
		node->left = node->right = NULL;
	} else if (data < node->data) {
		// insert into left of tree if data is less than node
		node->left = this->insertHelper(node->left, data);
		if (this->heightHelper(node->left) - this->heightHelper(node->right) == 2) {
			if (data < node->left->data) {
				//rebalance trree
				node = rotateRight(node);
			} else {
				node = rotateRightx2(node);
			}
		}
	} else if (data > node->data) {
		//inverse case
		node->right = this->insertHelper(node->right, data);
		if(this->heightHelper(node->right) - this->heightHelper(node->left) == 2) {
			if (data > node->right->data) {
				node = rotateLeft(node);
			} else {
				node = rotateLeftx2(node);
			}
		}
	}

	node->height = max(this->heightHelper(node->left), this->heightHelper(node->right)) +1;
	return node;
}

template<typename T>
Node<T>* AVL<T>::rotateRight(Node<T>* &node) {
	Node<T>* temp = node->left;
	node->left = temp->right;
	temp->right = node;
	node->height = max(this->heightHelper(node->left), this->heightHelper(node->right)) +1;
	temp->height = max(this->heightHelper(temp->left), node->height) +1;
	return temp;
}

//rotate node right twice
template<typename T>
Node<T>* AVL<T>::rotateRightx2(Node<T>* &node) {
	node->right = rotateLeft(node->right);
	return rotateRight(node);
}

template<typename T>
Node<T>* AVL<T>::rotateLeft(Node<T>* &node) {
	Node<T>* temp = node->right;
	node->right = temp->left;
	temp->left = node;
	node->height = max(this->heightHelper(node->left), this->heightHelper(node->right)) +1;
	temp->height = max(this->heightHelper(temp->right), node->height) +1;
	return temp;
}

//Rotate node left twice
template<typename T>
Node<T>* AVL<T>::rotateLeftx2(Node<T>* &node) {
	node->right = rotateRight(node->right);
	return rotateLeft(node);
}

template<typename T>
Node<T>* AVL<T>::removeHelper(Node<T>* node, T data) {
	Node<T>* temp;

	if(node == NULL) {
		return NULL;
	} else if(data < node->data) {
		node->left = this->removeHelper(node->left, data);
	} else if (data > node->data) {
		node->right = this->removeHelper(node->right, data);
	} else if (node->left && node->right) {
		temp = this->findMin(node->right);
		node->data = temp->data;
		node->right = this->removeHelper(node->right, node->data);
	} else {
		temp = node;
		if(node->left == NULL) {
			node = node->right;
		} else if (node->right == NULL) {
			node = node->left;
		}
		delete temp;
	}

	if(node == NULL) {
		return NULL;
	}

	node->height = max(this->heightHelper(node->left), this->heightHelper(node->right)) +1;

	if(this->heightHelper(node->left) - this->heightHelper(node->right) == 2) {
		if (this->heightHelper(node->left->left) - this->heightHelper(node->left->right) == 1) {
			return rotateLeft(node);
		} else {
			return rotateLeftx2(node);
		}
	} else if (this->heightHelper(node->right) - this->heightHelper(node->right) == 2) {
		if(this->heightHelper(node->right->right)- this->heightHelper(node->right->left) == 1) {
			return rotateRight(node);
		} else {
			return rotateRightx2(node);
		}
	}
	return node;
	//2 children

}

/*
template<typename T>
Node<T>* AVL<T>::findMin(Node<T>* node) {
	if (node == NULL) {
		return NULL;
	} else if (node->left == NULL) {
		return node;
	} else {
		return findMin(node->left);
	}

}
*/

/*
template<typename T>
void AVL<T>::removeNode(Node<T>* node) {
	if (node) {
		removeNode(node->left);
		removeNode(node->right);
		delete node;
	}
}

template<typename T>
void AVL<T>::copy(Node<T>* node) {
	if (node) {
		insert(node->data);
		copy(node->left);
		copy(node->right);
	}
}



template<typename T>
AVL<T>& AVL<T>::operator=(const AVL& rhs) {
	//cout << "hello";
	if(this != &rhs) {
		//cout << "hello2";
          this->removeNode(this->root);
          this->root = NULL;
          this->copy(rhs.root);
          //root->height = rhs.root->height;
     }
    // cout << "success:";
     return *this;
}
*/
#endif