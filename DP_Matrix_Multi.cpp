//#include <stdio.h>
//#include <iostream>
//#include <limits.h>
//using namespace std;
//
//#define N 6
//
//int P[N + 1][N + 1] = { 0 };
//
//void order(int i, int j, int arr[][N+1])
//{
//	if (i == j) cout << "A" << i;
//	else
//	{
//		int k;
//
//		k = P[i][j];
//		cout << "(";
//		order(i, k, arr);
//		order(k + 1, j, arr);
//		cout << ")";
//	}
//}
//
//int Minmult(int *d, int p[][N + 1], int n)
//{
//	int M[N + 1][N + 1] = { 0 };
//	int h, i, j, k, q;
//	for (h = 1; h <= n - 1; h++) {
//		for (i = 1; i <= n - h; i++) {
//			j = i + h;
//			M[i][j] = INT_MAX;
//			for (k = i; k < j; k++) {
//				q = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];
//				if (q < M[i][j]) {
//					M[i][j] = q;
//					p[i][j] = k;
//				}
//			}
//		}
//	}
//	return M[1][n];
//}
//
//int main()
//{
//	int d[7] = { 4, 2, 3, 1, 2, 2, 3 };
//	int result;
//
//	result = Minmult(d, P, N);
//	printf("ÃÖ¼Ò °ö¼À È½¼ö : %d\n", result);
//	order(1, N, P);
//
//	return 0;
//}
//
//
//
//
//////ÃÖÀûÇà·Ä°ö¼À
//
////#include <stdio.h> 
////#include <limits.h>
////
////#define N 6
////
////int MatrixChainMult(int *d, int p[][N + 1], int n)
////{
////   int M[N + 1][N + 1] = { 0 };
////   int h, i, j, k, q;
////   for (h = 1; h <= n - 1; h++) 
////   {
////      for (i = 1; i <= n - h; i++) 
////      {
////         j = i + h;
////         M[i][j] = INT_MAX;
////         for (k = i; k < j; k++) 
////         {
////            q = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];
////            if (q < M[i][j]) 
////            {
////               M[i][j] = q;
////               p[i][j] = k;
////            }
////         }
////      }
////   }
////   return M[1][n];
////}
////void order(int i, int p[][N + 1], int j)
////{
////   if (i == j) printf("A%d", i);
////   else
////   {
////      int k = p[i][j];
////      printf("(");
////      order(i, p,k);
////      order(k + 1,p, j);
////      printf(")");
////   }
////}
////int main()
////{
////   int d[7] = { 4, 2, 3, 1, 2, 2, 3 };//4x2 2x3 3x1 ...
////   int p[N + 1][N + 1] = { 0 };
////   int result;
////
////   result = MatrixChainMult(d, p, N);
////   printf("ÃÖ¼Ò °ö¼À È½¼ö : %d\n", result);
////   order(1, p ,N);
////   return 0;
////}
