//#include<iostream>
//using namespace std;
//#define MAX_VERTEX 100
//int map[MAX_VERTEX][MAX_VERTEX][MAX_VERTEX] = { 0 };
//int visit[MAX_VERTEX][MAX_VERTEX][MAX_VERTEX] = { 0 };
//int queue[MAX_VERTEX*MAX_VERTEX*MAX_VERTEX] = { 0 };
//int group = 1, num_star = 0;
//
//void BFS(int limit, int n, int vertex)
//{
//	int front = 0, rear = 0, i, j, k;
//	int r = 0, s = 0, t = 0;
//	visit[vertex / 10000][(vertex % 10000) / 100][vertex % 100] = 1;
//	queue[rear++] = vertex;
//	while (front < rear)
//	{
//		vertex = queue[front++];
//
//		if (vertex / 10000 - limit <0) r = 0;
//		else r = vertex / 10000 - limit;
//
//		if ((vertex % 10000) / 100 - limit < 0) s = 0;
//		else s = (vertex % 10000) / 100 - limit;
//
//		if (vertex % 100 - limit < 0) t = 0;
//		else t = vertex % 100 - limit;
//
//		for (i = r; (i <= vertex / 10000 + limit); i++)
//		{
//			for (j = s; j <= ((vertex % 10000) / 100 + limit); j++)
//			{
//				for (k = t; (k <= vertex % 100 + limit); k++)
//				{
//					if (visit[i][j][k] != 1)
//					{
//						visit[i][j][k] = 1;
//						if (map[i][j][k] == 1)
//						{
//							queue[rear++] = i * 10000 + j * 100 + k;
//						}
//					}
//					if (k == n - 1) break;
//				}
//				if (j == n - 1) break;
//			}
//			if (i == n - 1) break;
//		}
//	}
//	for (int i = 0; i <n; i++)
//	{
//		for (int j = 0; j <n; j++)
//		{
//			for (int k = 0; k <n; k++)
//			{
//				if (visit[i][j][k] == 0 && map[i][j][k] == 1)
//				{
//					BFS(limit, n, i * 10000 + j * 100 + k);
//					group++;
//					break;
//				}
//			}
//		}
//	}
//}
//int main(void)
//{
//	int R, N;
//	cin >> R >> N;
//	for (int i = 0; i <N; i++)
//	{
//		for (int j = 0; j <N; j++)
//		{
//			for (int k = 0; k <N; k++)
//			{
//				cin >> map[i][j][k];
//				if (map[i][j][k] == 1)num_star++;
//			}
//		}
//	}
//
//	if (R == 0) group = num_star;
//	else BFS(R, N, 0);
//	cout << group << endl;
//	return 0;
//}
//
