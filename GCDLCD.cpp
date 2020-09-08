//#include <iostream>
//#include <stdlib.h>
//using namespace std;
//int GCD(int a, int b);
//int LCM(int a, int b);
//
//int main()
//{
//	int x, y;
//	int g, l;
//
//	cin >> x;
//	if (x < 1)   exit(1);
//
//	cin >> y;
//	if (y < 1)   exit(1);
//
//	g = GCD(x, y);
//	l = LCM(x, y);
//
//	cout << g << endl << l << endl;
//
//	return 0;
//}
//
//int GCD(int a, int b)
//{
//	int k, N;
//
//	if (a > b) N = b;
//	else N = a;
//
//	for (int i = 1; i <= N; i++)
//	{
//		if ((a%i == 0) && (b%i == 0)) k = i;
//	}
//
//	return k;
//}
//
//int LCM(int a, int b)
//{
//	int k, N;
//	bool flag = 0;
//	for (int i = 1; i <= b; i++)
//	{
//		for (int j = 1; j <= a; j++)
//		{
//			if (a*i == b*j)
//			{
//				k = a*i;
//				flag = 1;
//				break;
//			}
//		}
//		if (flag == 1) break;
//	}
//
//	return k;
//}