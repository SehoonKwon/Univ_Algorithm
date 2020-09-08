//#include <iostream>
//#include <algorithm> //sort함수 사용하기 위해 선언
//#include <vector> //벡터 라이브러리 사용
//using namespace std;
//
////간선 클래스
//class Edge {
//public:
//
//	int Node[2]; //이전 노드까지 담기 위해
//	int Weight; //가중치
//
//				//생성자
//	Edge() {};
//
//	Edge(int a, int b, int Weight)
//	{
//		this->Node[0] = a;
//		this->Node[1] = b;
//		this->Weight = Weight;
//	}
//
//	//간선 대소비교. 비교기준은 가중치
//	bool operator <(Edge &edge)
//	{
//		return this->Weight < edge.Weight;
//	}
//
//	bool operator >(Edge &edge)
//	{
//		return this->Weight > edge.Weight;
//	}
//};
//
////싸이클이 없으므로 Tree와 같기 때문에 부모 노드라는 것이 존재한다.
////부모 노드를 가져옴
//int Parent(int *Vertex, int x)
//{
//	if (Vertex[x] == x) return x; //자기가 root노드라면 자신을 리턴.
//	return Vertex[x] = Parent(Vertex, Vertex[x]); //아니라면 재귀함수를 통해 루트노드 갱신
//}
//
////부모 노드를 합친다.
//void Unite(int *Vertex, int a, int b)
//{
//	a = Parent(Vertex, a);
//	b = Parent(Vertex, b);
//
//	//작은 쪽으로 합친다.
//	if (a < b) Vertex[b] = a;
//	else Vertex[a] = b;
//}
//
////싸이클 생성 되는지 확인. 같은 부모를 가리키면 싸이클이 형성된 것
//int isCycle(int *Vertex, int a, int b)
//{
//	a = Parent(Vertex, a);
//	b = Parent(Vertex, b);
//
//	if (a == b) return 1;
//	else return 0;
//}
//
//int main(void)
//{
//	int n, m = 0; //노드 수, 간선 개수
//	cout << "12131649 권세훈 Kruskal" << endl;
//	cout << "정점 개수 입력 : ";
//	cin >> n;
//
//	vector<Edge> v; //Edge 클래스 형태의 벡터 선언
//	int a, b, w; //배열 인덱스 , 가중치
//	cout << "간선 연결. 노드 번호, 가중치" << endl;
//
//	//간선 개수를 입력받지 않고 특정 수가 들어올 경우 반복문 중단
//	for (;;)
//	{
//		cin >> a;
//		if (a == -1) break;
//		cin >> b >> w;
//		v.push_back(Edge(a, b, w)); //벡터 타입에 값을 넣음. 
//	}
//
//	// 간선 정렬. sort함수의 기본은 오름차순 정렬
//	sort(v.begin(), v.end());
//
//	// 각 정점을 저장하기 위한 동적 배열 선언
//	int *Vertex = new int[n]();
//	for (int i = 0; i < n; i++)	Vertex[i] = i;
//
//	int Wsum = 0; //총 가중치 합을 위한 변수
//	int i = 0;
//	while (m < n - 1)
//	{
//		// 부모가 같지 않은경우에만 작동. 부모가 같으면 사이클이 존재
//		if (!isCycle(Vertex, v[i].Node[0] - 1, v[i].Node[1] - 1))
//		{
//			Wsum = Wsum + v[i].Weight; // 새로운 간선을 그릴때 마다 가중치를 더해 총 가중치를 구한다.
//			cout << m + 1 << "번째로 그려지는 간선 " << v[i].Node[0] << "->" << v[i].Node[1] << " 가중치 : " << v[i].Weight << endl; //출력부분
//			Unite(Vertex, v[i].Node[0] - 1, v[i].Node[1] - 1); //새로운 노드들의 부모노드를 합친다.
//			m++; //간선이 늘어난 경우만 간선 개수 +1
//		}
//		else cout << v[i].Node[0] << "->" << v[i].Node[1] << "간선은 싸이클 생성이 되므로 삭제" << endl;
//		i++;
//	}
//
//	cout << "간선 개수 : " << m << endl;
//	cout << "총 가중치 : " << Wsum << endl;
//
//	return 0;
//}