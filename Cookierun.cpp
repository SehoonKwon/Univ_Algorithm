//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <iostream>
//using namespace std;
//
//int V, E, HP; //���, ����, ü��
//int flag[100] = { 0 }; //���� ���ϴ� ��� ǥ���ϴ� �÷���
//
//// ���� ����ü
//// src = ������, dest = ������, weight = ����ġ
//struct Edge
//{
//	int src, dest, weight;
//};
//
//// �׷��� ����ü
//struct Graph
//{
//	int V, E; //��� , ���� ��
//
//	struct Edge* edge; //����� ����
//};
//
//// V�� E�� ���� ������ ������ ���� ���� �׷����� �����Ѵ�.
//struct Graph* createGraph(int V, int E)
//{
//	struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
//
//	graph->V = V;
//	graph->E = E;
//
//	graph->edge = (struct Edge*) malloc(graph->E * sizeof(struct Edge));
//
//	return graph;
//}
//
//void printResult(int *dist, int n)
//{
//	for (int i = 0; i < n; i++)	if (!flag[i]) cout << i << " "; //i�� ��� ������ŭ�̹Ƿ� i�� ����ȣ�� �ǹ��ϰ� �ȴ�.
//	cout << endl;
//}
//
////���� ���� �Լ��κ�
//void BellmanFord(struct Graph* graph, int src)
//{
//	int V = graph->V;
//	int E = graph->E;
//	int *dist = (int*)malloc(sizeof(int)*V); // int dist[V+1]�� ����.
//
//	// ��� �ִ� �Ÿ��� ���Ѵ�� �������ְ� �������� 0���� ����
//	for (int i = 0; i < V; i++)	dist[i] = 99999;
//	dist[src] = 0;
//
//	// ���� ���� �˰���
//	for (int i = 1; i <= V - 1; i++)
//	{
//		for (int j = 0; j < E; j++)
//		{
//			int u = graph->edge[j].src; 
//			int v = graph->edge[j].dest;
//			int weight = graph->edge[j].weight;
//
//			// ����u��(��������) ���Ѵ밡 �ƴϰ� ������������ �ִ� �Ÿ� + ����ġ�� �������� ����ġ���� ���� �� ������Ʈ ���ش�.
//			if (dist[u] != 99999 && dist[u] + weight < dist[v])	dist[v] = dist[u] + weight;
//		}
//	}
//
//	// ���� ����ġ ������ ������ �ִ� ��ΰ� �۾����� ���� �ִٸ�
//	// Ž���Ͽ� �˷��ش�.
//	for (int i = 0; i < E; i++)
//	{
//		int u = graph->edge[i].src;
//		int v = graph->edge[i].dest;
//		int weight = graph->edge[i].weight;
//
//		// if������ ������ġ �ִܰŸ� + ����ġ�� ����ؼ� �� �۾��� ��� ���� ����Ŭ�� �ִٰ� �Ǵ��Ѵ�.
//		if (dist[u] != 99999 && dist[u] + weight < dist[v])
//			cout << "Negative cycle" << endl;
//	}
//
//	for (int i = 0; i < V; i++) if (HP - dist[i] < 0) flag[i] = 1;
//	printResult(dist, V);
//
//	return;
//}
//
//
//int main()
//{
//	cin >> V >> E;
//
//	struct Graph* graph = createGraph(V, E);
//
//	// �׷��� ������ �Է����ش�.
//	for (int i = 0; i < E; i++)
//	{
//		cin >> graph->edge[i].src;
//		cin >> graph->edge[i].dest;
//		cin >> graph->edge[i].weight;
//	}
//
//	cin >> HP;
//
//	BellmanFord(graph, 0);
//
//	return 0;
//}