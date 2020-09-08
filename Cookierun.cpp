//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <iostream>
//using namespace std;
//
//int V, E, HP; //노드, 간선, 체력
//int flag[100] = { 0 }; //도달 못하는 노드 표시하는 플래그
//
//// 간선 구조체
//// src = 시작점, dest = 도착점, weight = 가중치
//struct Edge
//{
//	int src, dest, weight;
//};
//
//// 그래프 구조체
//struct Graph
//{
//	int V, E; //노드 , 간선 수
//
//	struct Edge* edge; //연결용 간선
//};
//
//// V와 E를 통해 정점과 간선의 수를 가진 그래프를 생성한다.
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
//	for (int i = 0; i < n; i++)	if (!flag[i]) cout << i << " "; //i가 노드 개수만큼이므로 i는 노드번호를 의미하게 된다.
//	cout << endl;
//}
//
////벨만 포드 함수부분
//void BellmanFord(struct Graph* graph, int src)
//{
//	int V = graph->V;
//	int E = graph->E;
//	int *dist = (int*)malloc(sizeof(int)*V); // int dist[V+1]과 같다.
//
//	// 모든 최단 거리를 무한대로 지정해주고 시작점만 0으로 설정
//	for (int i = 0; i < V; i++)	dist[i] = 99999;
//	dist[src] = 0;
//
//	// 벨만 포드 알고리즘
//	for (int i = 1; i <= V - 1; i++)
//	{
//		for (int j = 0; j < E; j++)
//		{
//			int u = graph->edge[j].src; 
//			int v = graph->edge[j].dest;
//			int weight = graph->edge[j].weight;
//
//			// 정점u가(시작점이) 무한대가 아니고 시작점까지의 최단 거리 + 가중치가 도착점의 가중치보다 작을 때 업데이트 해준다.
//			if (dist[u] != 99999 && dist[u] + weight < dist[v])	dist[v] = dist[u] + weight;
//		}
//	}
//
//	// 음의 가중치 때문에 무한히 최단 경로가 작아지는 것이 있다면
//	// 탐색하여 알려준다.
//	for (int i = 0; i < E; i++)
//	{
//		int u = graph->edge[i].src;
//		int v = graph->edge[i].dest;
//		int weight = graph->edge[i].weight;
//
//		// if문에서 현재위치 최단거리 + 가중치가 계속해서 더 작아질 경우 음의 사이클이 있다고 판단한다.
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
//	// 그래프 정보를 입력해준다.
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