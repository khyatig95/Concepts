using namespace std;
#include <iostream>
#include <queue>

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
class BinaryTree {
    public :
        Node<T>* root;
    
        BinaryTree() {
          root = NULL;
        }
        //Create Memory. O(N) [This can be made into O(1) if we store the first node available]
        void insertNode(T x); //Insert the key into the binary tree at the first position available in level order.
        //Delete Memory. O(N) [This can be made into O(1) if we store the rightmost-bottomost node available]
        //CAUTION : Only deletes the first instance of x at the first level 
        void deleteNode(T x);//Delete a node from it by making sure that tree shrinks from the bottom (i.e. the deleted node is replaced by the bottom-most and rightmost node). 
        //O(logN) with O(logN) space complexity 
	//Does depth first search and finds first instance
        void findNode(T x, Node<T>* n); 
        void inOrderTraversal(Node<T>* n);
        void preOrderTraversal(Node<T>* n);
        void postOrderTraversal(Node<T>* n);
};

template <typename T>
void BinaryTree<T> :: insertNode(T x) {
    Node<T>* newNode = new Node<T>(x);
    if (root == NULL) {
        root = newNode;
        cout << "Inserting node " << x << " at root as tree is empty" << endl;
        return;
    }

    //Breadth First Search
    Node<T>* n = root;
    queue<Node<T>*> q;
    q.push(root);
    while(!q.empty()) {
        if (q.front()->left != NULL) 
            q.push(q.front()->left);
        else {
            q.front()->left = newNode;
            cout << "Inserting node " << x << " at left child of " << q.front()->val << endl;
            return;
        }
        if (q.front()->right != NULL) 
            q.push(q.front()->right);
        else {
            cout << "Inserting node " << x << " at right child of " << q.front()->val << endl;
            q.front()->right = newNode;
            return;
        }
        q.pop(); //Remove the first element processed and move to the next one.
    }
}

template <typename T>
void BinaryTree<T> :: deleteNode(T x) {
    Node<T>* replace = NULL;
    Node<T>* deepestNode;
    if (root == NULL) {
        cout << "ERROR: Can't delete from an empty tree!" << endl;
        return;
    }
    if (root->left == NULL && root->right == NULL) { //Just one element
        if (root->val == x) {
            cout << "Found node to be deleted " << endl;
            replace = root;
            root = NULL;
            delete replace;
            return;
        } else {
            cout << "Node to be deleted is not found!" << endl;
            return;
	}
    }    

    
    //Breadth First Search for Node to be deleted
    queue<Node<T>*> q;
    q.push(root);
    while(!q.empty()) {
        if (q.front()->val == x && replace == NULL) { //Found first instance to be deleted    
            replace = q.front();
            cout << "Found node to be deleted " << endl;
        }
        if (q.front()->left != NULL) 
            q.push(q.front()->left);
        
        if (q.front()->right != NULL) 
            q.push(q.front()->right);
            
        deepestNode = q.front();
        q.pop(); //Remove the first element processed and move to the next one.
    }

    while(!q.empty())
        q.pop(); //Empty the queue

    q.push(root);  
    if (replace != NULL) {
        while(!q.empty()) {
            if (q.front()->left == deepestNode) {
                replace->val = deepestNode->val;
                q.front()->left = NULL;
                delete deepestNode;
                return;
            }
            
            if (q.front()->right == deepestNode) {
                replace->val = deepestNode->val;
                q.front()->right = NULL;
                delete deepestNode;
                return;
            }
            if (q.front()->left != NULL) 
                q.push(q.front()->left);
            
            if (q.front()->right != NULL) 
                q.push(q.front()->right);
            q.pop();
        }
    } else
        cout << "Node to be deleted is not found!" << endl;
}

template <typename T> 
void BinaryTree<T> :: findNode(T x, Node<T>* n) {
    if (n == NULL)
        return;
    //cout << "Traversing " << n->val << endl;
    if (n->val == x) {
        cout << "Found " << x << endl;
        return;
    }
   findNode(x, n->left);
   findNode(x, n->right);
}

template <typename T>
void BinaryTree<T> :: inOrderTraversal(Node<T>* n) {
    if (n == NULL) 
        return;
    inOrderTraversal(n->left);
    cout << n->val << " , "; 
    inOrderTraversal(n->right);
}

template <typename T>
void BinaryTree<T> :: preOrderTraversal(Node<T>* n) {
    if (n == NULL) 
        return;
    cout << n->val << " , "; 
    preOrderTraversal(n->left);
    preOrderTraversal(n->right);
}

template <typename T>
void BinaryTree<T> :: postOrderTraversal(Node<T>* n) {
    if (n == NULL) 
        return;
    postOrderTraversal(n->left);
    postOrderTraversal(n->right);
    cout << n->val << " , "; 
}

int main() {
    //Creating test tree manually
    //        10
    //      /    \
    //    11      9
    //   /  \    / 
    //  7   12  15    
    //           \
    //           13
    BinaryTree<int> tree1;
    tree1.root = new Node<int>(10);
    tree1.root->left = new Node<int>(11);
    tree1.root->left->left = new Node<int>(7);
    tree1.root->left->right = new Node<int>(12);
    tree1.root->right = new Node<int>(9);
    tree1.root->right->left = new Node<int>(15);
    tree1.root->right->left->right = new Node<int>(13);

    cout << endl << "In order traversal tree1: " << endl;
    tree1.inOrderTraversal(tree1.root);
    cout << endl << "Pre order traversal tree1: " << endl;
    tree1.preOrderTraversal(tree1.root);
    cout << endl << "Post order traversal tree1: " << endl;
    tree1.postOrderTraversal(tree1.root);
    cout << endl;
    
    //Delete rightmost Node
    //Delete root
    //Delete root of a tree with just one element
    //Delete non existent element
    //Delete when duplicate element exists
    int y = 11;
    tree1.deleteNode(y); 
    cout << endl << "After deletion of " << y << " from tree1: " << endl;
    tree1.inOrderTraversal(tree1.root);
    cout << endl;
    
    y = 20;
    tree1.insertNode(20);
    cout << endl << "After insertion of " << y << " in tree1: " << endl;
    tree1.inOrderTraversal(tree1.root);
    cout << endl;
    
    y = 1;
    tree1.findNode(y, tree1.root);
        
/////////////////////////////////////
    BinaryTree<int> tree2;
    tree2.root = new Node<int>(2);
    tree2.root->left = new Node<int>(2);
    
    cout << endl << "In order traversal tree2: " << endl;
    tree2.inOrderTraversal(tree2.root);
    cout << endl;
    y = 2;
    tree2.deleteNode(y); 
    cout << endl << "After deletion of " << y << " from tree2: " << endl;
    tree2.inOrderTraversal(tree2.root);
    
    return 0;
}