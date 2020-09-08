//#include <iostream>
//#include <algorithm> //sort�Լ� ����ϱ� ���� ����
//#include <vector> //���� ���̺귯�� ���
//using namespace std;
//
////���� Ŭ����
//class Edge {
//public:
//
//	int Node[2]; //���� ������ ��� ����
//	int Weight; //����ġ
//
//				//������
//	Edge() {};
//
//	Edge(int a, int b, int Weight)
//	{
//		this->Node[0] = a;
//		this->Node[1] = b;
//		this->Weight = Weight;
//	}
//
//	//���� ��Һ�. �񱳱����� ����ġ
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
////����Ŭ�� �����Ƿ� Tree�� ���� ������ �θ� ����� ���� �����Ѵ�.
////�θ� ��带 ������
//int Parent(int *Vertex, int x)
//{
//	if (Vertex[x] == x) return x; //�ڱⰡ root����� �ڽ��� ����.
//	return Vertex[x] = Parent(Vertex, Vertex[x]); //�ƴ϶�� ����Լ��� ���� ��Ʈ��� ����
//}
//
////�θ� ��带 ��ģ��.
//void Unite(int *Vertex, int a, int b)
//{
//	a = Parent(Vertex, a);
//	b = Parent(Vertex, b);
//
//	//���� ������ ��ģ��.
//	if (a < b) Vertex[b] = a;
//	else Vertex[a] = b;
//}
//
////����Ŭ ���� �Ǵ��� Ȯ��. ���� �θ� ����Ű�� ����Ŭ�� ������ ��
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
//	int n, m = 0; //��� ��, ���� ����
//	cout << "12131649 �Ǽ��� Kruskal" << endl;
//	cout << "���� ���� �Է� : ";
//	cin >> n;
//
//	vector<Edge> v; //Edge Ŭ���� ������ ���� ����
//	int a, b, w; //�迭 �ε��� , ����ġ
//	cout << "���� ����. ��� ��ȣ, ����ġ" << endl;
//
//	//���� ������ �Է¹��� �ʰ� Ư�� ���� ���� ��� �ݺ��� �ߴ�
//	for (;;)
//	{
//		cin >> a;
//		if (a == -1) break;
//		cin >> b >> w;
//		v.push_back(Edge(a, b, w)); //���� Ÿ�Կ� ���� ����. 
//	}
//
//	// ���� ����. sort�Լ��� �⺻�� �������� ����
//	sort(v.begin(), v.end());
//
//	// �� ������ �����ϱ� ���� ���� �迭 ����
//	int *Vertex = new int[n]();
//	for (int i = 0; i < n; i++)	Vertex[i] = i;
//
//	int Wsum = 0; //�� ����ġ ���� ���� ����
//	int i = 0;
//	while (m < n - 1)
//	{
//		// �θ� ���� ������쿡�� �۵�. �θ� ������ ����Ŭ�� ����
//		if (!isCycle(Vertex, v[i].Node[0] - 1, v[i].Node[1] - 1))
//		{
//			Wsum = Wsum + v[i].Weight; // ���ο� ������ �׸��� ���� ����ġ�� ���� �� ����ġ�� ���Ѵ�.
//			cout << m + 1 << "��°�� �׷����� ���� " << v[i].Node[0] << "->" << v[i].Node[1] << " ����ġ : " << v[i].Weight << endl; //��ºκ�
//			Unite(Vertex, v[i].Node[0] - 1, v[i].Node[1] - 1); //���ο� ������ �θ��带 ��ģ��.
//			m++; //������ �þ ��츸 ���� ���� +1
//		}
//		else cout << v[i].Node[0] << "->" << v[i].Node[1] << "������ ����Ŭ ������ �ǹǷ� ����" << endl;
//		i++;
//	}
//
//	cout << "���� ���� : " << m << endl;
//	cout << "�� ����ġ : " << Wsum << endl;
//
//	return 0;
//}