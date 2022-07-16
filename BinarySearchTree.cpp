#include <iostream>
using namespace std;

template <typename T>
class Node {
public :
	T val;
	Node* left;
	Node* right;

	Node(T x) {
		val = x;
		left = NULL;
		right = NULL;
	}
};

template <typename T>
class BinarySearchTree {
public :
	Node<T>* root;
	BinarySearchTree() {
		root = NULL;
	}
	void insertNode(T newVal, Node<T>* start);
	bool findNode(T newVal);
	Node<T>* deleteNode(T delVal, Node<T>* start);  //returns replacement of the node deleted
	Node<T>* getSmallest(Node<T>* n);
	void inOrderTraversal(Node<T>* n);
};

template <typename T>
void BinarySearchTree<T> :: insertNode(T newVal, Node<T>* start) {
	if (root == NULL) {
		root = new Node<T>(newVal);
		return;
	}

	if (newVal <= start->val) {
		if (start->left == NULL) {
			start->left = new Node<T>(newVal);
			return;
		} else
			insertNode(newVal, start->left);
	} else {
		if (start->right == NULL) {
			start->right = new Node<T>(newVal);
			return;
		} else
			insertNode(newVal, start->right);
	}
}

template <typename T>
bool BinarySearchTree<T> :: findNode(T newVal) {
	Node<T>* n = root;
	while(n != NULL) {
		if (n->val == newVal)
			return true;
		if (newVal < n->val)
			n = n->left;
		else
			n = n->right;
	}
	return false;
}

template <typename T>
Node<T>* BinarySearchTree<T> :: deleteNode(T delVal, Node<T>* start) {
	if (root == NULL) {
		cout << "ERROR : Cant delete from an empty tree" << endl;
		return root;
	}

	if (delVal < start->val)
		start->left = deleteNode(delVal, start->left);
	else if (delVal > start->val)
		start->right = deleteNode(delVal, start->right);
	else { //start's val == delVal
		if (start->left == NULL && start->right == NULL) {
			cout << "Deleting " << delVal << " with no children" << endl;
			delete start;
			return NULL;
		} else if (start->left == NULL) {
			Node<T>* temp = start->right;
			cout << "Deleting " << delVal << " with no left child and replacing with " << temp->val << endl;
			delete start;
			return temp;
		} else if (start->right == NULL) {
			Node<T>* temp = start->left;
			cout << "Deleting " << delVal << " with no right child and replacing with " << temp->val << endl;
			delete start;
			return temp;
		} else {
		   Node<T>* temp = getSmallest(start->right);
		   start->val= temp->val;
		   cout << "Deleting " << delVal << " with both children and replacing with " << temp->val << endl;
		   start->right = deleteNode(temp->val, start->right); //Delete the element we are replacing
		}
	}
	return start;
}

template <typename T>
Node<T>* BinarySearchTree<T> :: getSmallest(Node<T>* n) {
	while(n->left != NULL)
		n = n->left;
	return n;
}


template <typename T>
void BinarySearchTree<T> :: inOrderTraversal(Node<T>* n) {
    if (n == NULL)
        return;
    inOrderTraversal(n->left);
    cout << n->val << ", ";
    inOrderTraversal(n->right);
}

int main() {
	//Creating test tree
	//        8
	//      /   \
	//     5     25
	//    /      /
	//  -1      15
	//         /  \
	//        13  16
	// 				\
	//				17

	BinarySearchTree<int>* tree1 = new BinarySearchTree<int>();
	tree1->insertNode(8, tree1->root);
	tree1->insertNode(5, tree1->root);
	tree1->insertNode(-1, tree1->root);
	tree1->insertNode(25, tree1->root);
	tree1->insertNode(15, tree1->root);
	tree1->insertNode(16, tree1->root);
	tree1->insertNode(13, tree1->root);
	tree1->insertNode(17, tree1->root);


	cout << "Root is " << tree1->root->val << endl;
	cout << "Root->left is " << tree1->root->left->val << endl;
	cout << "Root->right is " << tree1->root->right->val << endl;
	cout << "Root->left->left is " << tree1->root->left->left->val << endl;
	cout << "Root->right->left is " << tree1->root->right->left->val << endl;
	cout << "Root->right->left->right is " << tree1->root->right->left->right->val << endl;
	cout << "Root->right->left->left is " << tree1->root->right->left->left->val << endl;
	cout << "Root->right->left->right->right is " << tree1->root->right->left->right->right->val << endl;


	tree1->inOrderTraversal(tree1->root);
	cout << endl;

	//x is present in tree
	//x is not present in tree
	//x is root
	int x = 8;
	if (tree1->findNode(x))
		cout << x << " is present in the tree" << endl;
	else
		cout << x << " is NOT present in the tree" << endl;

	//Delete an existing element
	//     no children
	//     left child only
	//     right child only
	//     both children
	//Delete a non-existent element
	int y = 105;
	tree1->root = tree1->deleteNode(y, tree1->root);
	tree1->inOrderTraversal(tree1->root);
	cout << endl;

	//Delete from empty tree
	//BinarySearchTree<int>* tree2 = new BinarySearchTree<int>();
	//tree2->deleteNode(25, tree2->root);

    return 0;
}
