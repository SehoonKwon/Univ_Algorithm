//#include <iostream>
//#include <queue> //ť ���̺귯�� ���
//using namespace std;
//
//int n, v; //��� ��, ���� ���
//
//void DFS(int pre, int v, int** arr, int* visit) 
//{
//	visit[v] = 1; //������ �湮�ߴٰ� ǥ��
//	if (v == pre) cout << v << " "; //���۳��� ���� ����
//	else cout << v << "(" << pre << "-" << v << ") "; //�湮�� ��� / ����� ����
////	for(int i=1; i<n+1; i++) // ���ÿ� ū �ͺ��� ����
//	for (int i = n; i > 0; i--) // ���ÿ� ���� �� ���� ���� � ���� �ִ��Ŀ� ���� �湮 ������ �޶���, ���ǳ�Ʈ���� �̴� ������ �̷��� �ؾ� ����
//	{
//		//���� �Ǿ��ְ� �湮���� ���� ����� �� ��忡 ���� DFS Ž��
//		if (arr[v][i] == 1 && !visit[i]) {
//			DFS(v, i, arr, visit);
//		}
//	}
//}
//
//void BFS(int v, int** arr, int* visit) {
//
//	for (int i = 0; i < n + 1; i++) visit[i] = 0; //visit �迭 �ʱ�ȭ
//	visit[v] = 1; //������ �湮�ߴٰ� ǥ��
//
//	//int type ť ����. pre�� �������� �̱� ���Ͽ� ����. ��� �ൿ�� ¦��� ���ָ� ����� �� ó�� �ൿ�� �� �ִ�.
//	queue<int> q; 
//	queue<int> pre;
//
//	//ť�� ��带 ����
//	q.push(v);
//	pre.push(v);
//
//	//ť�� �� ������
//	while (!q.empty())
//	{
//		//���� �ռ� ��� ��ȣ�� ����
//		int Node = q.front();
//		int preN = pre.front();
//
//		//��� ��ȣ�� ������ ť���� ����
//		q.pop();
//		pre.pop();
//
//		//��� �κ�, ���۳���� ��� ������ �����Ƿ� ���� ��� ����
//		if (Node == preN) cout << Node << " ";
//		else cout << Node << "(" << preN << "-" << Node << ") ";
//
//		//����� �ε�����ŭ �ݺ�. ������ ���� �ִ� �κи� �۵��ϹǷ�
//		for (int i = 1; i < n+1; i++)
//		{
//			//����Ǿ��ְ� �湮�Ǿ����� ���� ���¸�
//			if (arr[Node][i] == 1 && !visit[i])
//			{
//				visit[i] = 1; //�湮�Ͽ��ٰ� ǥ��
//				q.push(i); //���ÿ� �ִ´�
//				pre.push(Node); //���ÿ� �ִ´�.
//			}
//		}
//	}
//}
//
//
//int main() {
//
//	cout << "12131649 �Ǽ��� DFS/BFS" << endl;
//	cout << "��� ��, Ž���� ���۳�� �Է�" << endl;
//
//	cin >> n >> v; // n : ��� ��, m : ���� ��, v : ���� ���
//
//	//2���� ������� �����Ҵ�, 0���ε��� ������� �ʱ� ���� n+1�� ����
//	int **Adj = new int*[n+1]();
//	for (int i = 0; i < n+1; i++)	Adj[i] = new int[n+1]();
//
//
//	int a, b;
//	//���� �̾��� ���� �迭�� ǥ���ϴ� ����
//	for (;;)
//	{
//		cin >> a;
//		if (a == -1) break;
//		cin >> b;
//		Adj[a][b] = 1;
//		Adj[b][a] = 1;
//	}
//
//	int *visit = new int[n+1](); //0�� �ε��� ���x �ϱ� ����
//	cout << "DFS ��� �湮 ����" << endl;
//	for (int i = 0; i < n + 1; i++) visit[i] = 0; //visit �迭 �ʱ�ȭ , DFS�� ��ͷ� ����ϹǷ� �Լ������� �ʱ�ȭ�ϸ� ���ѷ����� ����
//	DFS(v, v,Adj, visit);
//	
//	cout << endl << endl;
//	
//	cout << "BFS ��� �湮 ����" << endl;
//	BFS(v, Adj, visit);
//
//	//�����Ҵ��� �迭�� ��� �޸� ����
//	for (int i = 0; i < n+1; i++)
//	{
//		delete[] Adj[i];
//	}
//
//	delete[] visit;
//	delete[] Adj;
//}