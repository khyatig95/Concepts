{\rtf1\ansi\ansicpg1252\cocoartf1348\cocoasubrtf170
{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;\f1\fnil\fcharset0 Menlo-Bold;}
{\colortbl;\red255\green255\blue255;\red63\green127\blue95;\red127\green0\blue85;\red42\green0\blue255;
\red100\green70\blue50;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab720
\pard\pardeftab720

\f0\fs24 \cf2 //Time Complexity : O(N^2)\cf0 \
\cf2 //Space Complexity : O(1)\cf0 \
\
\pard\pardeftab720

\f1\b \cf3 #include
\f0\b0 \cf0  \cf4 <iostream>\cf0 \

\f1\b \cf3 using
\f0\b0 \cf0  
\f1\b \cf3 namespace
\f0\b0 \cf0  std;\
\

\f1\b \cf3 template
\f0\b0 \cf0  <
\f1\b \cf3 typename
\f0\b0 \cf0  
\f1\b \cf5 T
\f0\b0 \cf0 >\

\f1\b \cf3 void
\f0\b0 \cf0  
\f1\b swap
\f0\b0 (
\f1\b \cf5 T
\f0\b0 \cf0 * x, 
\f1\b \cf5 T
\f0\b0 \cf0 * y) \{\
	cout << \cf4 "Swapping "\cf0  << *x << \cf4 " and "\cf0  << *y << endl;\
	
\f1\b \cf5 T
\f0\b0 \cf0  temp = *x;\
	*x = *y;\
	*y = temp;\
\}\
\

\f1\b \cf3 template
\f0\b0 \cf0  <
\f1\b \cf3 typename
\f0\b0 \cf0  
\f1\b \cf5 T
\f0\b0 \cf0 >\

\f1\b \cf3 void
\f0\b0 \cf0  
\f1\b printArr
\f0\b0 (
\f1\b \cf5 T
\f0\b0 \cf0 * arr, 
\f1\b \cf3 int
\f0\b0 \cf0  size) \{\
	cout << \cf4 "[ "\cf0  ;\
	
\f1\b \cf3 for
\f0\b0 \cf0  (
\f1\b \cf3 int
\f0\b0 \cf0  i=0; i<size; i++)\
		cout << arr[i] << \cf4 " "\cf0 ;\
	cout << \cf4 "]"\cf0  << endl;\
\}\
\

\f1\b \cf3 template
\f0\b0 \cf0  <
\f1\b \cf3 typename
\f0\b0 \cf0  
\f1\b \cf5 T
\f0\b0 \cf0 >\
\pard\pardeftab720

\f1\b \cf5 T
\f0\b0 \cf0 * 
\f1\b SelectionSort
\f0\b0 (
\f1\b \cf5 T
\f0\b0 \cf0 * arr, 
\f1\b \cf3 int
\f0\b0 \cf0  size) \{\
	
\f1\b \cf3 if
\f0\b0 \cf0  (size == 0 || size == 1) \{\
		cout << \cf4 "Array is empty or has just one element"\cf0  << endl;\
		
\f1\b \cf3 return
\f0\b0 \cf0  arr;\
	\}\
	
\f1\b \cf3 int
\f0\b0 \cf0  min;\
	
\f1\b \cf3 for
\f0\b0 \cf0  (
\f1\b \cf3 int
\f0\b0 \cf0  i=0; i<size-1; i++) \{\
		min = i;\
		
\f1\b \cf3 for
\f0\b0 \cf0  (
\f1\b \cf3 int
\f0\b0 \cf0  j=i+1; j < size ; j++) \{\
			cout << \cf4 "Comparing \cf4 \ul \ulc4 min\cf4 \ulnone  "\cf0  << arr[min] << \cf4 " with "\cf0  << arr[j] << endl;\
			
\f1\b \cf3 if
\f0\b0 \cf0  (arr[min] > arr[j])\
				min = j;\
		\}\
		
\f1\b \cf3 if
\f0\b0 \cf0  (arr[min] != arr[i]) \cf2 //Not the \ul min\ulnone  we started out with\cf0 \
			swap(&arr[min], &arr[i]);\
		cout << endl;\
	\}\
	
\f1\b \cf3 return
\f0\b0 \cf0  arr;\
\}\
\
\pard\pardeftab720

\f1\b \cf3 int
\f0\b0 \cf0  
\f1\b main
\f0\b0 () \{\
	\cf2 //\ul int\ulnone  \ul arr\ulnone [] = \{64, 34, 25, 12, 22, 11, 90\};\cf0 \
	
\f1\b \cf3 char
\f0\b0 \cf0  arr[] = \{\cf4 'a'\cf0 , \cf4 'x'\cf0 , \cf4 'k'\cf0 , \cf4 'h'\cf0 , \cf4 's'\cf0 \};\
	
\f1\b \cf3 int
\f0\b0 \cf0  size = 
\f1\b \cf3 sizeof
\f0\b0 \cf0 (arr)/
\f1\b \cf3 sizeof
\f0\b0 \cf0 (arr[0]); \cf2 //Will give number of elements in array\cf0 \
	\cf2 //\ul int\ulnone * res;\cf0 \
	
\f1\b \cf3 char
\f0\b0 \cf0 * res;\
	cout << \cf4 "Unsorted array: "\cf0  << endl;\
	printArr<
\f1\b \cf3 char
\f0\b0 \cf0 >(arr, size);\
	res = SelectionSort<
\f1\b \cf3 char
\f0\b0 \cf0 >(arr, size);\
	cout << \cf4 "Sorted array: "\cf0  << endl;\
	printArr<
\f1\b \cf3 char
\f0\b0 \cf0 >(res, size);\
\}\
}