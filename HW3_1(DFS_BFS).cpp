//#include <iostream>
//#include <queue> //큐 라이브러리 사용
//using namespace std;
//
//int n, v; //노드 수, 시작 노드
//
//void DFS(int pre, int v, int** arr, int* visit) 
//{
//	visit[v] = 1; //들어오면 방문했다고 표시
//	if (v == pre) cout << v << " "; //시작노드는 간선 없음
//	else cout << v << "(" << pre << "-" << v << ") "; //방문한 노드 / 연결된 간선
////	for(int i=1; i<n+1; i++) // 스택에 큰 것부터 넣음
//	for (int i = n; i > 0; i--) // 스택에 작은 것 부터 넣음 어떤 것을 넣느냐에 따라 방문 순서가 달라짐, 강의노트에서 뽑는 순서는 이렇게 해야 나옴
//	{
//		//연결 되어있고 방문하지 않은 노드라면 그 노드에 대해 DFS 탐색
//		if (arr[v][i] == 1 && !visit[i]) {
//			DFS(v, i, arr, visit);
//		}
//	}
//}
//
//void BFS(int v, int** arr, int* visit) {
//
//	for (int i = 0; i < n + 1; i++) visit[i] = 0; //visit 배열 초기화
//	visit[v] = 1; //들어오면 방문했다고 표시
//
//	//int type 큐 선언. pre는 간선까지 뽑기 위하여 선언. 모든 행동을 짝지어서 해주면 연결된 것 처럼 행동할 수 있다.
//	queue<int> q; 
//	queue<int> pre;
//
//	//큐에 노드를 넣음
//	q.push(v);
//	pre.push(v);
//
//	//큐가 빌 때까지
//	while (!q.empty())
//	{
//		//노드와 앞선 노드 번호를 받음
//		int Node = q.front();
//		int preN = pre.front();
//
//		//노드 번호를 받으면 큐에서 삭제
//		q.pop();
//		pre.pop();
//
//		//출력 부분, 시작노드인 경우 간선이 없으므로 간선 출력 제외
//		if (Node == preN) cout << Node << " ";
//		else cout << Node << "(" << preN << "-" << Node << ") ";
//
//		//행렬의 인덱스만큼 반복. 어차피 값이 있는 부분만 작동하므로
//		for (int i = 1; i < n+1; i++)
//		{
//			//연결되어있고 방문되어있지 않은 상태면
//			if (arr[Node][i] == 1 && !visit[i])
//			{
//				visit[i] = 1; //방문하였다고 표시
//				q.push(i); //스택에 넣는다
//				pre.push(Node); //스택에 넣는다.
//			}
//		}
//	}
//}
//
//
//int main() {
//
//	cout << "12131649 권세훈 DFS/BFS" << endl;
//	cout << "노드 수, 탐색할 시작노드 입력" << endl;
//
//	cin >> n >> v; // n : 노드 수, m : 간선 수, v : 시작 노드
//
//	//2차원 인접행렬 동적할당, 0번인덱스 사용하지 않기 위해 n+1개 생성
//	int **Adj = new int*[n+1]();
//	for (int i = 0; i < n+1; i++)	Adj[i] = new int[n+1]();
//
//
//	int a, b;
//	//서로 이어진 노드들 배열에 표시하는 과정
//	for (;;)
//	{
//		cin >> a;
//		if (a == -1) break;
//		cin >> b;
//		Adj[a][b] = 1;
//		Adj[b][a] = 1;
//	}
//
//	int *visit = new int[n+1](); //0번 인덱스 사용x 하기 위해
//	cout << "DFS 노드 방문 순서" << endl;
//	for (int i = 0; i < n + 1; i++) visit[i] = 0; //visit 배열 초기화 , DFS는 재귀로 사용하므로 함수내에서 초기화하면 무한루프로 빠짐
//	DFS(v, v,Adj, visit);
//	
//	cout << endl << endl;
//	
//	cout << "BFS 노드 방문 순서" << endl;
//	BFS(v, Adj, visit);
//
//	//동적할당한 배열들 모두 메모리 해제
//	for (int i = 0; i < n+1; i++)
//	{
//		delete[] Adj[i];
//	}
//
//	delete[] visit;
//	delete[] Adj;
//}