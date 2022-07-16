{\rtf1\ansi\ansicpg1252\cocoartf1348\cocoasubrtf170
{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;\f1\fnil\fcharset0 Menlo-Bold;}
{\colortbl;\red255\green255\blue255;\red63\green127\blue95;\red127\green0\blue85;\red42\green0\blue255;
\red100\green70\blue50;}
\margl1440\margr1440\vieww9380\viewh6320\viewkind0
\deftab720
\pard\pardeftab720

\f0\fs24 \cf2 //Time Complexity : O(logN)-- only for search\cf0 \
\cf2 //Space Complexity : O(1)\cf0 \
\cf2 //Assumption : Returns the first index in case there are multiple \ul occurences\cf0 \ulnone \
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

\f1\b \cf3 int
\f0\b0 \cf0  
\f1\b partition
\f0\b0 (
\f1\b \cf5 T
\f0\b0 \cf0 * arr, 
\f1\b \cf3 int
\f0\b0 \cf0  start, 
\f1\b \cf3 int
\f0\b0 \cf0  end) \{\
	
\f1\b \cf3 int
\f0\b0 \cf0  size = end+1;\
	
\f1\b \cf3 int
\f0\b0 \cf0  pivot = arr[(start+end)/2];\
	
\f1\b \cf3 while
\f0\b0 \cf0 (start <=  end) \{\
		
\f1\b \cf3 while
\f0\b0 \cf0  (arr[start] < pivot) start++; \cf2 //\ul Uptil\ulnone  start, all elements<pivot are at leftmost\cf0 \
		
\f1\b \cf3 while
\f0\b0 \cf0 (arr[end] > pivot) end--; \cf2 //All elements>pivot are at rightmost\cf0 \
		
\f1\b \cf3 if
\f0\b0 \cf0  (start <= end) \{\
			
\f1\b \cf3 if
\f0\b0 \cf0  (start!=end) swap(&arr[start], &arr[end]);\
			start++;\
			end--;\
		\}\
	\}\
	
\f1\b \cf3 return
\f0\b0 \cf0  start; \cf2 //Elements \ul uptil\ulnone  left are less than pivot\cf0 \
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
\f1\b QuickSort
\f0\b0 (
\f1\b \cf5 T
\f0\b0 \cf0 * arr, 
\f1\b \cf3 int
\f0\b0 \cf0  start, 
\f1\b \cf3 int
\f0\b0 \cf0  end) \{\
	
\f1\b \cf3 int
\f0\b0 \cf0  index = partition<
\f1\b \cf5 T
\f0\b0 \cf0 >(arr, start, end);\
	
\f1\b \cf3 if
\f0\b0 \cf0  (start < index-1)\
		QuickSort(arr, start, index-1);\
	
\f1\b \cf3 if
\f0\b0 \cf0  (index < end)\
		QuickSort(arr, index, end);\
\}\
\

\f1\b \cf3 template
\f0\b0 \cf0  <
\f1\b \cf3 typename
\f0\b0 \cf0  
\f1\b \cf5 T
\f0\b0 \cf0 >\

\f1\b \cf5 T
\f0\b0 \cf0 * 
\f1\b QuickSort
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
\
	QuickSort<
\f1\b \cf5 T
\f0\b0 \cf0 >(arr, 0, size-1);\
	
\f1\b \cf3 return
\f0\b0 \cf0  arr;\
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
\f1\b BinarySearch
\f0\b0 (
\f1\b \cf5 T
\f0\b0 \cf0 * arr, 
\f1\b \cf3 int
\f0\b0 \cf0  start, 
\f1\b \cf3 int
\f0\b0 \cf0  end, 
\f1\b \cf5 T
\f0\b0 \cf0  x) \{\
	
\f1\b \cf3 if
\f0\b0 \cf0  (start > end) \{\
		cout << \cf4 "Element not found"\cf0  << endl;\
		
\f1\b \cf3 return
\f0\b0 \cf0 ;\
	\}\
	
\f1\b \cf3 int
\f0\b0 \cf0  mid = (start+end)/2;\
	cout << \cf4 "Looking for "\cf0  << x << \cf4 " with start "\cf0  << start << \cf4 " and end "\cf0  << end << \cf4 " and mid "\cf0  << mid << endl;\
	
\f1\b \cf3 if
\f0\b0 \cf0  (arr[mid] == x) \{\
		cout << \cf4 "Found "\cf0  << x << \cf4 " at "\cf0  << mid << \cf4 " position"\cf0  << endl;\
		
\f1\b \cf3 return
\f0\b0 \cf0 ;\
	\} 
\f1\b \cf3 else
\f0\b0 \cf0  
\f1\b \cf3 if
\f0\b0 \cf0  (arr[mid] > x)\
		BinarySearch(arr, start, mid-1, x);\
	
\f1\b \cf3 else
\f0\b0 \cf0 \
		BinarySearch(arr, mid+1, end, x);\
\}\
\

\f1\b \cf3 int
\f0\b0 \cf0  
\f1\b main
\f0\b0 () \{\
	\cf2 //\ul int\ulnone  \ul arr\ulnone [] = \{64, 34, 25, 12, 22, 11, 90\};\cf0 \
	
\f1\b \cf3 char
\f0\b0 \cf0  arr[] = \{\cf4 'a'\cf0 , \cf4 'x'\cf0 , \cf4 'k'\cf0 , \cf4 'h'\cf0 , \cf4 's'\cf0 \};\
\
	
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
	res = QuickSort<
\f1\b \cf3 char
\f0\b0 \cf0 >(arr, size);\
	cout << \cf4 "Sorted array: "\cf0  << endl;\
	printArr<
\f1\b \cf3 char
\f0\b0 \cf0 >(res, size);\
\
	\cf2 //\ul int\ulnone  \ul val\ulnone  = 34;\cf0 \
	
\f1\b \cf3 char
\f0\b0 \cf0  val = \cf4 's'\cf0 ;\
	BinarySearch(res, 0, size-1, val);\
\
\}\
}