{\rtf1\ansi\ansicpg1252\cocoartf1348\cocoasubrtf170
{\fonttbl\f0\fnil\fcharset0 Menlo-Bold;\f1\fnil\fcharset0 Menlo-Regular;}
{\colortbl;\red255\green255\blue255;\red127\green0\blue85;\red42\green0\blue255;\red100\green70\blue50;
\red0\green80\blue50;\red0\green0\blue192;\red63\green127\blue95;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab720
\pard\pardeftab720

\f0\b\fs24 \cf2 #include
\f1\b0 \cf0  \cf3 <iostream>\cf0 \

\f0\b \cf2 using
\f1\b0 \cf0  
\f0\b \cf2 namespace
\f1\b0 \cf0  std;\
\

\f0\b \cf2 template
\f1\b0 \cf0  <
\f0\b \cf2 typename
\f1\b0 \cf0  
\f0\b \cf4 T
\f1\b0 \cf0 >\

\f0\b \cf2 class
\f1\b0 \cf0  \cf5 Node\cf0  \{\

\f0\b \cf2 public
\f1\b0 \cf0  :\
	
\f0\b \cf4 T
\f1\b0 \cf0  \cf6 val\cf0 ;\
	\cf5 Node\cf0 * \cf6 left\cf0 ;\
	\cf5 Node\cf0 * \cf6 right\cf0 ;\
\
	
\f0\b Node
\f1\b0 (
\f0\b \cf4 T
\f1\b0 \cf0  x) \{\
		\cf6 val\cf0  = x;\
		\cf6 left\cf0  = NULL;\
		\cf6 right\cf0  = NULL;\
	\}\
\};\
\

\f0\b \cf2 template
\f1\b0 \cf0  <
\f0\b \cf2 typename
\f1\b0 \cf0  
\f0\b \cf4 T
\f1\b0 \cf0 >\

\f0\b \cf2 class
\f1\b0 \cf0  \cf5 BinarySearchTree\cf0  \{\

\f0\b \cf2 public
\f1\b0 \cf0  :\
	\cf5 Node\cf0 <
\f0\b \cf4 T
\f1\b0 \cf0 >* \cf6 root\cf0 ;\
	
\f0\b BinarySearchTree
\f1\b0 () \{\
		\cf6 root\cf0  = NULL;\
	\}\
	
\f0\b \cf2 void
\f1\b0 \cf0  
\f0\b insertNode
\f1\b0 (
\f0\b \cf4 T
\f1\b0 \cf0  newVal, \cf5 Node\cf0 <
\f0\b \cf4 T
\f1\b0 \cf0 >* start);\
	
\f0\b \cf2 bool
\f1\b0 \cf0  
\f0\b findNode
\f1\b0 (
\f0\b \cf4 T
\f1\b0 \cf0  newVal);\
	\cf5 Node\cf0 <
\f0\b \cf4 T
\f1\b0 \cf0 >* 
\f0\b deleteNode
\f1\b0 (
\f0\b \cf4 T
\f1\b0 \cf0  delVal, \cf5 Node\cf0 <
\f0\b \cf4 T
\f1\b0 \cf0 >* start);  \cf7 //returns replacement of the node deleted\cf0 \
	\cf5 Node\cf0 <
\f0\b \cf4 T
\f1\b0 \cf0 >* 
\f0\b getSmallest
\f1\b0 (\cf5 Node\cf0 <
\f0\b \cf4 T
\f1\b0 \cf0 >* n);\
	
\f0\b \cf2 void
\f1\b0 \cf0  
\f0\b inOrderTraversal
\f1\b0 (\cf5 Node\cf0 <
\f0\b \cf4 T
\f1\b0 \cf0 >* n);\
\};\
\

\f0\b \cf2 template
\f1\b0 \cf0  <
\f0\b \cf2 typename
\f1\b0 \cf0  
\f0\b \cf4 T
\f1\b0 \cf0 >\

\f0\b \cf2 void
\f1\b0 \cf0  
\f0\b BinarySearchTree<T> :: insertNode
\f1\b0 (
\f0\b \cf4 T
\f1\b0 \cf0  newVal, \cf5 Node\cf0 <
\f0\b \cf4 T
\f1\b0 \cf0 >* start) \{\
	
\f0\b \cf2 if
\f1\b0 \cf0  (\cf6 root\cf0  == NULL) \{\
		\cf6 root\cf0  = 
\f0\b \cf2 new
\f1\b0 \cf0  \cf5 Node\cf0 <
\f0\b \cf4 T
\f1\b0 \cf0 >(newVal);\
		
\f0\b \cf2 return
\f1\b0 \cf0 ;\
	\}\
\
	
\f0\b \cf2 if
\f1\b0 \cf0  (newVal <= start->\cf6 val\cf0 ) \{\
		
\f0\b \cf2 if
\f1\b0 \cf0  (start->\cf6 left\cf0  == NULL) \{\
			start->\cf6 left\cf0  = 
\f0\b \cf2 new
\f1\b0 \cf0  \cf5 Node\cf0 <
\f0\b \cf4 T
\f1\b0 \cf0 >(newVal);\
			
\f0\b \cf2 return
\f1\b0 \cf0 ;\
		\} 
\f0\b \cf2 else
\f1\b0 \cf0 \
			insertNode(newVal, start->\cf6 left\cf0 );\
	\} 
\f0\b \cf2 else
\f1\b0 \cf0  \{\
		
\f0\b \cf2 if
\f1\b0 \cf0  (start->\cf6 right\cf0  == NULL) \{\
			start->\cf6 right\cf0  = 
\f0\b \cf2 new
\f1\b0 \cf0  \cf5 Node\cf0 <
\f0\b \cf4 T
\f1\b0 \cf0 >(newVal);\
			
\f0\b \cf2 return
\f1\b0 \cf0 ;\
		\} 
\f0\b \cf2 else
\f1\b0 \cf0 \
			insertNode(newVal, start->\cf6 right\cf0 );\
	\}\
\}\
\

\f0\b \cf2 template
\f1\b0 \cf0  <
\f0\b \cf2 typename
\f1\b0 \cf0  
\f0\b \cf4 T
\f1\b0 \cf0 >\

\f0\b \cf2 bool
\f1\b0 \cf0  
\f0\b BinarySearchTree<T> :: findNode
\f1\b0 (
\f0\b \cf4 T
\f1\b0 \cf0  newVal) \{\
	\cf5 Node\cf0 <
\f0\b \cf4 T
\f1\b0 \cf0 >* n = \cf6 root\cf0 ;\
	
\f0\b \cf2 while
\f1\b0 \cf0 (n != NULL) \{\
		
\f0\b \cf2 if
\f1\b0 \cf0  (n->\cf6 val\cf0  == newVal)\
			
\f0\b \cf2 return
\f1\b0 \cf0  
\f0\b \cf2 true
\f1\b0 \cf0 ;\
		
\f0\b \cf2 if
\f1\b0 \cf0  (newVal < n->\cf6 val\cf0 )\
			n = n->\cf6 left\cf0 ;\
		
\f0\b \cf2 else
\f1\b0 \cf0 \
			n = n->\cf6 right\cf0 ;\
	\}\
	
\f0\b \cf2 return
\f1\b0 \cf0  
\f0\b \cf2 false
\f1\b0 \cf0 ;\
\}\
\

\f0\b \cf2 template
\f1\b0 \cf0  <
\f0\b \cf2 typename
\f1\b0 \cf0  
\f0\b \cf4 T
\f1\b0 \cf0 >\
\pard\pardeftab720
\cf5 Node\cf0 <
\f0\b \cf4 T
\f1\b0 \cf0 >* 
\f0\b BinarySearchTree<T> :: deleteNode
\f1\b0 (
\f0\b \cf4 T
\f1\b0 \cf0  delVal, \cf5 Node\cf0 <
\f0\b \cf4 T
\f1\b0 \cf0 >* start) \{\
	
\f0\b \cf2 if
\f1\b0 \cf0  (\cf6 root\cf0  == NULL) \{\
		cout << \cf3 "ERROR : \ul Cant\ulnone  delete from an empty tree"\cf0  << endl;\
		
\f0\b \cf2 return
\f1\b0 \cf0  \cf6 root\cf0 ;\
	\}\
\
	
\f0\b \cf2 if
\f1\b0 \cf0  (delVal < start->\cf6 val\cf0 )\
		start->\cf6 left\cf0  = deleteNode(delVal, start->\cf6 left\cf0 );\
	
\f0\b \cf2 else
\f1\b0 \cf0  
\f0\b \cf2 if
\f1\b0 \cf0  (delVal > start->\cf6 val\cf0 )\
		start->\cf6 right\cf0  = deleteNode(delVal, start->\cf6 right\cf0 );\
	
\f0\b \cf2 else
\f1\b0 \cf0  \{ \cf7 //start's \ul val\ulnone  == delVal\cf0 \
		
\f0\b \cf2 if
\f1\b0 \cf0  (start->\cf6 left\cf0  == NULL && start->\cf6 right\cf0  == NULL) \{\
			cout << \cf3 "Deleting "\cf0  << delVal << \cf3 " with no children"\cf0  << endl;\
			
\f0\b \cf2 delete
\f1\b0 \cf0  start;\
			
\f0\b \cf2 return
\f1\b0 \cf0  NULL;\
		\} 
\f0\b \cf2 else
\f1\b0 \cf0  
\f0\b \cf2 if
\f1\b0 \cf0  (start->\cf6 left\cf0  == NULL) \{\
			\cf5 Node\cf0 <
\f0\b \cf4 T
\f1\b0 \cf0 >* temp = start->\cf6 right\cf0 ;\
			cout << \cf3 "Deleting "\cf0  << delVal << \cf3 " with no left child and replacing with "\cf0  << temp->\cf6 val\cf0  << endl;\
			
\f0\b \cf2 delete
\f1\b0 \cf0  start;\
			
\f0\b \cf2 return
\f1\b0 \cf0  temp;\
		\} 
\f0\b \cf2 else
\f1\b0 \cf0  
\f0\b \cf2 if
\f1\b0 \cf0  (start->\cf6 right\cf0  == NULL) \{\
			\cf5 Node\cf0 <
\f0\b \cf4 T
\f1\b0 \cf0 >* temp = start->\cf6 left\cf0 ;\
			cout << \cf3 "Deleting "\cf0  << delVal << \cf3 " with no right child and replacing with "\cf0  << temp->\cf6 val\cf0  << endl;\
			
\f0\b \cf2 delete
\f1\b0 \cf0  start;\
			
\f0\b \cf2 return
\f1\b0 \cf0  temp;\
		\} 
\f0\b \cf2 else
\f1\b0 \cf0  \{\
		   \cf5 Node\cf0 <
\f0\b \cf4 T
\f1\b0 \cf0 >* temp = getSmallest(start->\cf6 right\cf0 );\
		   start->\cf6 val\cf0 = temp->\cf6 val\cf0 ;\
		   cout << \cf3 "Deleting "\cf0  << delVal << \cf3 " with both children and replacing with "\cf0  << temp->\cf6 val\cf0  << endl;\
		   start->\cf6 right\cf0  = deleteNode(temp->\cf6 val\cf0 , start->\cf6 right\cf0 ); \cf7 //Delete the element we are replacing\cf0 \
		\}\
	\}\
	
\f0\b \cf2 return
\f1\b0 \cf0  start;\
\}\
\
\pard\pardeftab720

\f0\b \cf2 template
\f1\b0 \cf0  <
\f0\b \cf2 typename
\f1\b0 \cf0  
\f0\b \cf4 T
\f1\b0 \cf0 >\
\pard\pardeftab720
\cf5 Node\cf0 <
\f0\b \cf4 T
\f1\b0 \cf0 >* 
\f0\b BinarySearchTree<T> :: getSmallest
\f1\b0 (\cf5 Node\cf0 <
\f0\b \cf4 T
\f1\b0 \cf0 >* n) \{\
	
\f0\b \cf2 while
\f1\b0 \cf0 (n->\cf6 left\cf0  != NULL)\
		n = n->\cf6 left\cf0 ;\
	
\f0\b \cf2 return
\f1\b0 \cf0  n;\
\}\
\
\
\pard\pardeftab720

\f0\b \cf2 template
\f1\b0 \cf0  <
\f0\b \cf2 typename
\f1\b0 \cf0  
\f0\b \cf4 T
\f1\b0 \cf0 >\

\f0\b \cf2 void
\f1\b0 \cf0  
\f0\b BinarySearchTree<T> :: inOrderTraversal
\f1\b0 (\cf5 Node\cf0 <
\f0\b \cf4 T
\f1\b0 \cf0 >* n) \{\
    
\f0\b \cf2 if
\f1\b0 \cf0  (n == NULL)\
        
\f0\b \cf2 return
\f1\b0 \cf0 ;\
    inOrderTraversal(n->\cf6 left\cf0 );\
    cout << n->\cf6 val\cf0  << \cf3 ", "\cf0 ;\
    inOrderTraversal(n->\cf6 right\cf0 );\
\}\
\

\f0\b \cf2 int
\f1\b0 \cf0  
\f0\b main
\f1\b0 () \{\
	\cf7 //Creating test tree\cf0 \
	\cf7 //        8\cf0 \
	\cf7 //      /   \\\cf0 \
\pard\pardeftab720
\cf7 	//     5     25\cf0 \
	\cf7 //    /      /\cf0 \
	\cf7 //  -1      15\cf0 \
	\cf7 //         /  \\\cf0 \
\cf7 	//        13  16\cf0 \
	\cf7 // 				\\\cf0 \
\cf7 	//				17\cf0 \
\
	\cf5 BinarySearchTree\cf0 <
\f0\b \cf2 int
\f1\b0 \cf0 >* tree1 = 
\f0\b \cf2 new
\f1\b0 \cf0  \cf5 BinarySearchTree\cf0 <
\f0\b \cf2 int
\f1\b0 \cf0 >();\
	tree1->insertNode(8, tree1->\cf6 root\cf0 );\
	tree1->insertNode(5, tree1->\cf6 root\cf0 );\
	tree1->insertNode(-1, tree1->\cf6 root\cf0 );\
	tree1->insertNode(25, tree1->\cf6 root\cf0 );\
	tree1->insertNode(15, tree1->\cf6 root\cf0 );\
	tree1->insertNode(16, tree1->\cf6 root\cf0 );\
	tree1->insertNode(13, tree1->\cf6 root\cf0 );\
	tree1->insertNode(17, tree1->\cf6 root\cf0 );\
\
\
	cout << \cf3 "Root is "\cf0  << tree1->\cf6 root\cf0 ->\cf6 val\cf0  << endl;\
	cout << \cf3 "Root->left is "\cf0  << tree1->\cf6 root\cf0 ->\cf6 left\cf0 ->\cf6 val\cf0  << endl;\
	cout << \cf3 "Root->right is "\cf0  << tree1->\cf6 root\cf0 ->\cf6 right\cf0 ->\cf6 val\cf0  << endl;\
	cout << \cf3 "Root->left->left is "\cf0  << tree1->\cf6 root\cf0 ->\cf6 left\cf0 ->\cf6 left\cf0 ->\cf6 val\cf0  << endl;\
	cout << \cf3 "Root->right->left is "\cf0  << tree1->\cf6 root\cf0 ->\cf6 right\cf0 ->\cf6 left\cf0 ->\cf6 val\cf0  << endl;\
	cout << \cf3 "Root->right->left->right is "\cf0  << tree1->\cf6 root\cf0 ->\cf6 right\cf0 ->\cf6 left\cf0 ->\cf6 right\cf0 ->\cf6 val\cf0  << endl;\
	cout << \cf3 "Root->right->left->left is "\cf0  << tree1->\cf6 root\cf0 ->\cf6 right\cf0 ->\cf6 left\cf0 ->\cf6 left\cf0 ->\cf6 val\cf0  << endl;\
	cout << \cf3 "Root->right->left->right->right is "\cf0  << tree1->\cf6 root\cf0 ->\cf6 right\cf0 ->\cf6 left\cf0 ->\cf6 right\cf0 ->\cf6 right\cf0 ->\cf6 val\cf0  << endl;\
\
\
	tree1->inOrderTraversal(tree1->\cf6 root\cf0 );\
	cout << endl;\
\
	\cf7 //x is present in tree\cf0 \
	\cf7 //x is not present in tree\cf0 \
	\cf7 //x is root\cf0 \
	
\f0\b \cf2 int
\f1\b0 \cf0  x = 8;\
	
\f0\b \cf2 if
\f1\b0 \cf0  (tree1->findNode(x))\
		cout << x << \cf3 " is present in the tree"\cf0  << endl;\
	
\f0\b \cf2 else
\f1\b0 \cf0 \
		cout << x << \cf3 " is NOT present in the tree"\cf0  << endl;\
\
	\cf7 //Delete an existing element\cf0 \
	\cf7 //     no children\cf0 \
	\cf7 //     left child only\cf0 \
	\cf7 //     right child only\cf0 \
	\cf7 //     both children\cf0 \
	\cf7 //Delete a non-existent element\cf0 \
	
\f0\b \cf2 int
\f1\b0 \cf0  y = 105;\
	tree1->\cf6 root\cf0  = tree1->deleteNode(y, tree1->\cf6 root\cf0 );\
	tree1->inOrderTraversal(tree1->\cf6 root\cf0 );\
	cout << endl;\
\
	\cf7 //Delete from empty tree\cf0 \
	\cf7 //BinarySearchTree\ul <int>\ulnone * tree2 = new BinarySearchTree\ul <int>\ulnone ();\cf0 \
	\cf7 //tree2->deleteNode(25, tree2->root);\cf0 \
\
    
\f0\b \cf2 return
\f1\b0 \cf0  0;\
\}\
}