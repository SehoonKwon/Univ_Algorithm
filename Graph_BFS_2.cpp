//#include <iostream>
//#include <vector>
//#include <queue>
//#include <list>
//using namespace std;
//
//int n, m, v;
//int cnt;
//vector<int> togo;
//
//int R, N, Cnt=1, Gcnt=0;
//int Array[100][100][100] = { 0 };
//int Adj[100][100][100] = { 0 };
//bool visit[100][100][100] = { 0 };
//
//queue<int> q;
//
//
//void BFS(int i, int j, int k)
//{
//	for (; i < N; i++)
//	{
//		for (0; j < N; j++)
//		{
//			for (; k < N; k++)
//			{
//				if (Array[i][j][k] == 1)
//				{
//					if (visit[i][j][k] == 0)
//					{
//						visit[i][j][k] = 1;
//						if (q.empty()) Gcnt++;
//						for (int l = 0; l < R; l++)
//						{
//							if (Array[i + R][j][k] == 1)
//							{
//								q.push(Cnt);
//								Cnt++;
//								BFS(i + R, j, k);
//							}
//							if (Array[i + R][j + R][k] == 1)
//							{
//								q.push(Cnt);
//								Cnt++;
//								BFS(i + R, j+R, k);
//							}
//							if (Array[i][j + R][k + R] == 1)
//							{
//								q.push(Cnt);
//								Cnt++;
//								BFS(i + R, j+R, k+R);
//							}
//
//							if (Array[i][j + R][k] == 1)
//							{
//								q.push(Cnt);
//								Cnt++;
//								BFS(i, j+R, k);
//							}
//							if (Array[i][j + R][k + R] == 1)
//							{
//								q.push(Cnt);
//								Cnt++;
//								BFS(i, j+R, k+R);
//							}
//
//							if (Array[i][j][k + R] == 1)
//							{
//								q.push(Cnt);
//								Cnt++;
//								BFS(i, j, k+R);
//							}
//							if (Array[i + R][j][k + R] == 1)
//							{
//								q.push(Cnt);
//								Cnt++;
//								BFS(i + R, j, k+R);
//							}
//						}
//					}
//				}
//			}
//		}
//	}
////	if (!q.empty()) q.pop();
//}
//
//int main()
//{
//	cin >> R >> N;
//	if (R < 0 || R > 4) return 0;
//	if (N < 4 || N > 100) return 0;
//
//	int n, count=0;
//
//	//z
//	for (int i = 0; i < N; i++)
//	{
//		//y
//		for (int j = 0; j < N; j++)
//		{
//			//x
//			for (int k = 0; k < N; k++)
//			{
//				cin >> Array[i][j][k];
//				if(Array[i][j][k]==1)	count++;
//			}
//		}
//	}
//
//	if (R == 0) cout << count;
//	else
//	{
//		for (int i = 0; i < N; i++)
//		{
//			for (int j = 0; j < N; j++)
//			{
//				for (int k = 0; k < N; k++)	if((Array[i][j][k] == 1)) BFS(i, j, k);
//			}
//		}
//
//		cout << Gcnt;
//	}
//
//	return 0;
//}