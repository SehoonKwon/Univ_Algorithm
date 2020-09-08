//#include <iostream>
//#include <string>
//#include <string.h>
//using namespace std;
//
//void swap(int* a, int* b);
//void Quick_Sort(int* array, int start, int end);
//void computeLPSArray(char *pat, int M, int *lps);
//int KMPSearch(char *pat, char *txt);
//
//
//void swap(int* a, int* b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//
//void Quick_Sort(int* array, int start, int end)
//{
//	if (start >= end) return;
//
//	int mid = (start + end) / 2;
//	int pivot = array[mid];
//
//	swap(&array[start], &array[mid]);
//
//	int p = start + 1, q = end;
//
//	while (1) {
//
//		while (array[p] <= pivot) { p++; }
//		while (array[q]>pivot) { q--; }
//		
//		if (p>q) break;
//		
//		swap(&array[p], &array[q]);
//	}
//
//	swap(&array[start], &array[q]);
//
//	Quick_Sort(array, start, q - 1);
//
//	Quick_Sort(array, q + 1, end);
//}
//
//
//int KMPSearch(char *pat, char *txt)
//{
//	int M = strlen(pat);
//	int N = strlen(txt);
//
//	int *lps = new int[M];
//
//	computeLPSArray(pat, M, lps);
//
//	int i = 0;
//	int j = 0;
//	int pos;
//
//	while (i < N)
//	{
//		if (pat[j] == txt[i])
//		{
//			j++;
//			i++;
//		}
//
//		if (j == M)
//		{
//			pos = i - j;
//			j = lps[j - 1];
//			return pos;
//		}
//
//		else if (i < N && pat[j] != txt[i])
//		{
//			if (j != 0)
//			{
//				j = lps[j - 1];
//			}
//			else
//			{
//				i = i + 1;
//			}
//
//		}
//	}
//
//	return -1;
//}
//
//void computeLPSArray(char *pat, int M, int *lps)
//{
//	int len = 0;
//
//	lps[0] = 0; 
//
//	int i = 1;
//	while (i < M)
//	{
//		if (pat[i] == pat[len])
//		{
//			len++;
//			lps[i] = len;
//			i++;
//		}
//		else 
//		{
//
//			if (len != 0)
//			{
//				len = lps[len - 1];
//			}
//			else 
//			{
//				lps[i] = 0;
//				i++;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int count = 0;
//	char keyword[8] = { 0 };
//	char target[100][250] = { 0 };
//	int A[100] = { 0 };
//
//	int k = 0;
//
//	cin.getline(keyword,8);
//
//	int N = strlen(keyword);
//
//	for (;;)
//	{
//		cin.getline(target[count],250);
//
//		/*cout << target[0] << endl;
//		cout << target[1] << endl;*/
//	
//		if (!strcmp(target[count], "0"))	break;
//
//		k = KMPSearch(keyword, target[count]);
//		A[count] = k;
//		count++;
//	}
//
//	int isMin = 0;
//
//	for (int i = 0; i < count; i++)
//	{
//		for (int j = 0; j < count; j++)
//		{
//			if (A[i] != 0 && A[j] != 0)
//			{
//				if (A[i] < A[j])  isMin = 1;
//				else if (A[i] == A[j]) continue;
//				else
//				{
//					isMin = 0;
//					break;
//				}
//
//				if (isMin == 1)
//				{
//					cout << target[i] << endl;
//					A[i] = 0;
//					i = 0;
//				}
//			}
//			//int isEnd = 1;
//
//			//if (isEnd == 1) return 0;
//		}
//	}
//	for (int i2 = 0; i2 < count; i2++)
//	{
//		//				if (A[i2] != 0) isEnd = 0;
//		cout << A[i2] << endl;
//	}
//
//	return 0;
//}
