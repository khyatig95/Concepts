{\rtf1\ansi\ansicpg1252\cocoartf1348\cocoasubrtf170
{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;\f1\fnil\fcharset0 Menlo-Bold;}
{\colortbl;\red255\green255\blue255;\red63\green127\blue95;\red127\green0\blue85;\red42\green0\blue255;
\red100\green70\blue50;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab720
\pard\pardeftab720

\f0\fs24 \cf2 //Time Complexity : O(NlogN)\cf0 \
\cf2 //Space Complexity : O(N) -- Worst Case as if start!=0,\cf0 \
\cf2 //the size of helper == size of end+1\cf0 \
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

\f1\b \cf3 void
\f0\b0 \cf0  
\f1\b Merge
\f0\b0 (
\f1\b \cf5 T
\f0\b0 \cf0 * arr, 
\f1\b \cf3 int
\f0\b0 \cf0  start, 
\f1\b \cf3 int
\f0\b0 \cf0  mid, 
\f1\b \cf3 int
\f0\b0 \cf0  end) \{\
	cout << \cf4 "Merge with start="\cf0  << start << \cf4 " and mid="\cf0  << mid << \cf4 " and end="\cf0  << end << endl;\
	
\f1\b \cf5 T
\f0\b0 \cf0  helper[end+1];\
	\cf2 //Copy the contents to a helper array\cf0 \
	
\f1\b \cf3 for
\f0\b0 \cf0  (
\f1\b \cf3 int
\f0\b0 \cf0  i=start; i<=end; i++)\
		helper[i] = arr[i];\
	cout << \cf4 "Helper is "\cf0  << endl;\
	printArr<
\f1\b \cf5 T
\f0\b0 \cf0 >(helper, end+1);\
	
\f1\b \cf3 int
\f0\b0 \cf0  left = start;\
	
\f1\b \cf3 int
\f0\b0 \cf0  right = mid+1;\
	
\f1\b \cf3 int
\f0\b0 \cf0  curr = start;\
\
	
\f1\b \cf3 while
\f0\b0 \cf0 (left<=mid && right<=end) \{\
		cout << \cf4 "helper_left= "\cf0  << helper[left] << \cf4 " and helper_right= "\cf0  << helper[right] << endl;\
		
\f1\b \cf3 if
\f0\b0 \cf0  (helper[left] < helper[right]) \{\
			arr[curr] = helper[left];\
			left++;\
		\} 
\f1\b \cf3 else
\f0\b0 \cf0  \{\
			arr[curr] = helper[right];\
			right++;\
		\}\
		curr++;\
	\}\
	\cf2 //Iterate for remaining left elements\cf0 \
	
\f1\b \cf3 for
\f0\b0 \cf0  (
\f1\b \cf3 int
\f0\b0 \cf0  i = left; i <= mid; i++) \{\
		arr[curr] = helper[i];\
		curr++;\
	\}\
	\cf2 //No need to copy remaining right elements as they are already in the correct position in \ul arr\cf0 \ulnone \
	printArr<
\f1\b \cf5 T
\f0\b0 \cf0 >(arr, end+1);\
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
\f1\b MergeSort
\f0\b0 (
\f1\b \cf5 T
\f0\b0 \cf0 * arr, 
\f1\b \cf3 int
\f0\b0 \cf0  start, 
\f1\b \cf3 int
\f0\b0 \cf0  end) \{\
	cout << \cf4 "MergeSort with start="\cf0  << start << \cf4 " and end="\cf0  << end << endl;\
	
\f1\b \cf3 if
\f0\b0 \cf0  (start < end) \{\
		
\f1\b \cf3 int
\f0\b0 \cf0  mid = (start+end)/2;\
		MergeSort(arr, start, mid);\
		MergeSort(arr, mid+1, end);\
		Merge(arr, start, mid, end);\
	\}\
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
\f1\b MergeSort
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
	MergeSort<
\f1\b \cf5 T
\f0\b0 \cf0 >(arr, 0, size-1);\
	
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
	res = MergeSort<
\f1\b \cf3 char
\f0\b0 \cf0 >(arr, size);\
	cout << \cf4 "Sorted array: "\cf0  << endl;\
	printArr<
\f1\b \cf3 char
\f0\b0 \cf0 >(res, size);\
\}\
}