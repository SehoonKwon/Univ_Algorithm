//#include<iostream>
//using namespace std;
//
//void Heapify(int *a, int i, int n);
//void Sorting(int *a, int c, int n);
//
//
//int main()
//{
//	int n, size = 0; //size means size of heap
//	int A[101];  //A is array
//
//	for (;;) // until insert 0 infinite loop
//	{
//		cin >> n;
//		if (n == 0) break;
//		else if (20200101 <= n)
//		{
//			if (size == 100) break;
//			size++;
//			Heapify(A, n, size);
//		}
//		else if (1 <= n && n <= 20)
//		{
//			Sorting(A, n, size);
//			for (int i = 0; i < n; i++) size--;
//		}
//		else continue;
//	}
//
//}
//
//void Sorting(int *a, int c, int n) //do Sort
//{
//	int B[101];
//	int k, m, buf, i = 1;
//	k = n;//last value in queue (without deleted value)
//	for (; k >= n - c + 1; k--)
//	{
//		m = 1;// m is current node
//		B[i] = a[1]; //min value into a output array 
//		a[1] = a[k]; //change a root value with last value
//		for (;;)
//		{
//			if (2 * m >= k) break; //if children are useless node, end the for loop
//			if (a[m] <= a[2 * m] && a[m] <= a[2 * m + 1]) break;//if current node is smaller than children, end the for loop
//
//			else if (a[2 * m] < a[2 * m + 1]) //if a left child is smaller, change a current node with left child
//			{
//				buf = a[2 * m];
//				a[2 * m] = a[m];
//				a[m] = buf;
//				m = 2 * m; //change a current node's rank
//			}
//			else if (a[2 * m + 1] <= a[2 * m]) //if a right child is smaller, change a current node with right child
//			{
//				if (2 * m + 1 >= k) break;//if child node is useless node, end the for loop
//				buf = a[2 * m + 1];
//				a[2 * m + 1] = a[m];
//				a[m] = buf;
//				m = 2 * m + 1;//change a current node's rank
//			}
//		}
//		i++;
//	}
//	for (int j = 1; j <= c; j++) //print the output on the screen
//	{
//		cout << B[j] << endl;
//	}
//
//}
//void Heapify(int *a, int i, int n) //upheap process
//{
//	int temp, j, buf; // j is a parent node's rank, temp is current node of input
//	a[n] = i;
//	temp = n;
//	for (;;)
//	{
//		j = temp / 2;
//		if (temp == 1) break;
//		else if (a[temp] >= a[j]) //if it doesn't need to upheap process, end the for loop
//			break;
//
//		else if (a[temp] < a[j]) //if a parent is bigger than a child node, change them 
//		{
//			buf = a[j];
//			a[j] = a[temp];
//			a[temp] = buf;
//			temp = temp / 2; //change the current node's rank
//		}
//	}
//
//	return;
//}
//
