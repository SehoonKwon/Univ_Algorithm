////////BFS (�Ｚ��ī���� �⺻)
//#include<stdio.h>
//#define MAX_VERTEX 30 
//int num;
//int map[MAX_VERTEX][MAX_VERTEX]; //edge�� ����Ǹ� 1
//int visit[MAX_VERTEX]; //�湮�� ��ȣ�� 1, �ƴϸ� 0
//int queue[MAX_VERTEX];//
//int rear, front;
//
//void BFS(int vertex)
//{
//	int i; visit[vertex] = 1;
//	printf("%d ", vertex);
//	queue[rear++] = vertex;
//	while (front < rear)
//	{
//		vertex = queue[front++];
//		printf("%d ", vertex);
//		for (i = 1; i <= num; i++)
//		{
//			if (map[vertex][i] == 1 && !visit[i])
//			{
//				visit[i] = 1;
//				queue[rear++] = i;
//			}
//		}
//	}
//
//}
//int main(void)
//{
//	int T;
//	int test_case;
//	int i, j;
//	int start;
//	int v1;
//	int v2;
//	scanf("%d", &T);
//	for (test_case = 1; test_case <= T; test_case++)
//	{
//		for (i = 0; i < MAX_VERTEX; i++)
//		{
//			for (j = 0; j < MAX_VERTEX; j++)
//			{
//				map[i][j] = 0;
//			}
//			visit[i] = 0;
//			queue[i] = 0;
//		}
//		front = 0;
//		rear = 0;
//		scanf("%d %d", &num, &start);//vertex ����, ���� vertex
//		while (true)
//		{
//			scanf("%d %d", &v1, &v2);
//			if (v1 == -1 && v2 == -1)
//			{
//				break;
//			}
//			map[v1][v2] = map[v2][v1] = 1;
//		}
//		printf("#%d ", test_case);
//		BFS(start);
//		printf("\n");
//	}
//	return 0;
//}