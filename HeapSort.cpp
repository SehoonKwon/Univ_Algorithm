//#include <iostream>
//using namespace std;
//
//// A function to heapify the Aay.
//void MaxHeapify(int arr[], int i, int n)
//{
//	int j, temp; // variable to use. j for is for tree node, temp is for temporary storage during node value exchanging. 
//	temp = arr[i]; 
//	j = 2 * i; // move to child node.  
//
//	while (j <= n)
//	{
//		if (j < n && arr[j + 1] > arr[j]) // in case j is not max index and right child value > left child value 
//			j = j + 1;
//
//		// break if parent value is already greater than child value.
//		if (temp > arr[j])	break; 
//
//		// change value with the parent node if temp < arr[j].
//		else if (temp <= arr[j])
//		{
//			arr[j / 2] = arr[j];
//			j = 2 * j;
//		}
//	}
//	arr[j / 2] = temp;
//
//	return;
//}
//
////do heap sort.
//void HeapSort(int arr[], int n)
//{
//	int i, temp; // temp is for temporary storage during node value exchanging.
//	for (i = n; i >= 2; i--) 
//	{
//		//input maximum value at the end.
//		temp = arr[i];
//		arr[i] = arr[1];
//		arr[1] = temp;
//
//		// Make node agian.
//		MaxHeapify(arr, 1, i - 1);
//	}
//}
//
////Make heap , arr is array and n is the number of index
//void Build_MaxHeap(int arr[], int n)
//{
//	int i;
//
//	for (i = n / 2; i >= 1; i--)
//	{
//		MaxHeapify(arr, i, n);
//	}
//}
//int main()
//{
//	int n, i, j, size;
//	int A[101]; // 
//
//	i = 1; // index start 1
//
//	for (;;)
//	{
//		cin >> n;
//
//		if (n == 0) break;
//		else if (1 <= n && n <= 20) //
//		{
//			Build_MaxHeap(A, i-1); // Make heap
//			HeapSort(A, i-1); // do heap sort
//
//			// Print the sorted data
//			for (i = 1; i <= n; i++) // index 1 ~ index n 
//			{
//				cout << A[i] << endl; //do print
//			}
//
//			//배열 삭제
//			for (int i = 1; i <= size-1; i++)
//			{
//				A[i] = A[i + n];
//			}
//			size = size - n;
//			i = size;
//		}
//
//		else if (n >= 20200101) // 
//		{
//			A[i] = n;
//			i++;
//			size++;
//		}
//	}
//
//	return 0;
//}