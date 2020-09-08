//#include <stdio.h> 
//#include <limits.h>
//#include <iostream>
//using namespace std;
//
//int N;
//
//struct tree_node
//{
//	tree_node* left;
//	tree_node* right;
//	int key;
//};
//
//tree_node* BuildTree(int i, int **arr, int j, int* PK)
//{
//	if (i > j)return NULL;
//	int k;
//	tree_node* p;
//	k = arr[i][j];
//	if (k == 0) return NULL;
//	else
//	{
//		p = new tree_node;
//		p->key = PK[k];
//		p->left = BuildTree(i, arr, k - 1, PK);
//		p->right = BuildTree(k + 1, arr, j, PK);
//		return p;
//	}
//}
//
//float OptimalBST(float *p, int **arr, int n)
//{
//	float **A;
//	A = new float*[n+1]();
//	for (int i = 0; i < N+1; i++) A[i] = new float[n+1]();
//
//	float q, p_sum;
//	int h, i, j, k, m;
//
//	for (i = 1; i < n+1; i++)
//	{
//		A[i][i] = p[i];
//		arr[i][i] = i;
//	}
//
//	for (h = 1; h < n; h++)
//	{
//		for (i = 1; i <= n - h; i++)
//		{
//			j = i + h;
//			A[i][j] = 100;
//			p_sum = 0;
//			for (m = i; m <= j; m++)
//				p_sum = p_sum + p[m];
//			for (k = i; k <= j; k++)
//			{
//				if(k+1 <= N) q = A[i][k - 1] + A[k + 1][j] + p_sum;
//				else q = A[i][k] + p_sum + 0.0000;
//
//				if (q < A[i][j])
//				{
//					A[i][j] = q;
//					arr[i][j] = k;
//				}
//			}
//		}
//	}
//	return A[1][n];
//}
//
//void SelectionSort(float *p, int* arr, int n)
//{
//	int i, j, min_idx, temp1;
//	float temp2;
//
//	for (i = 0; i < n - 1; i++)
//	{
//		min_idx = i;
//		for (j = i + 1; j < n; j++)
//			if (arr[j] < arr[min_idx])
//				min_idx = j;
//		temp1 = arr[min_idx];
//		arr[min_idx] = arr[i];
//		arr[i] = temp1;
//
//		temp2 = p[min_idx];
//		p[min_idx] = p[i];
//		p[i] = temp2;
//	}
//}
//
//void printArray(int arr[], int n)
//{
//	for (int i = 0; i<n; ++i)
//		cout << arr[i] << " ";
//	cout << "\n";
//}
//
//void printArray2(float arr[], int n)
//{
//	for (int i = 0; i<n; ++i)
//		cout << arr[i] << " ";
//	cout << "\n";
//}
//
//int main()
//{
//	int M1;
//	float M2;
//
//	cin >> N;
//
//	int **Array;
//	Array = new int*[N+1]();
//	for (int i = 0; i < N+1; i++) Array[i] = new int[N+1]();
//
//	float *P = new float[N+1]();
//
//	int *PK = new int[N + 1]();
//
//	for(int i = 1; i < N+1; i++)
//	{
//		cin >> M1 >> M2;
//		P[i] = M2;
//		PK[i] = M1;
//	}
//
//	SelectionSort(P, PK, N + 1);
//	printArray2(P, N + 1);
//	printArray(PK, N + 1);
//
//	float result;	
//
//	tree_node* p1 = new tree_node;
//	result = OptimalBST(P, Array, N);
//
//	//cout << result << " ";
//	//p1 = BuildTree(1, Array, N, PK);
//	//cout << p1->key;
//
//	return 0;
//} 
