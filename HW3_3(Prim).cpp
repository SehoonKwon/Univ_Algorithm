#include<iostream>
using namespace std;

//#define 0  -1

int N; //정점 개수
int** Array; //간선 정보 및 가중치를 가진 행렬
int *W; //가중치 행렬 복사용
int *Pre; //부모
int *Q; //큐(노드)
int Wsum = 0; //총 가중치

int Qcnt; //큐(노드) 개수


//PQ Q삽입함수
void PQ_push(int a)
{
	Q[a] = 0; //큐(노드)를 넣는다
	Qcnt++; //큐(노드) 개수 증가
}

int PQ_pop()
{
	int i;
	int min = 100000; //어느 수를 만나도 min이 되도록 큰 값 아무거나 설정
	int index = -1; //임시 저장용 인덱스. 방문 여부를 표시
	
	for (i = 0; i < N; i++)
	{
		if (Q[i] == -1) continue; //방문한 큐라면 넘어간다.
		
		//가중치가 min보다 작을 때 min값 갱신
		if (W[i] < min)
		{
			index = i;
			min = W[i];
		}
	}

	if (index == -1) return -1; //인덱스가 유효하지 않으면 -1 리턴
	Q[index] = -1; //해당 인덱스를 가진 노드에 방문하였다고 표시
	Qcnt--; //큐(노드) 개수 감소

	return index; //가장 작은 가중치를 갖고 있던 인덱스 리턴
}

//PQ가 비었는지 확인하는 함수
bool PQ_Empty()
{
	return Qcnt == 0;
}

void Prim(int start)
{
	int i, v, w;

	Qcnt = 0; //Prim 알고리즘 시작시  큐(노드) 개수 초기화

	for (i = 0; i<N; i++)
	{
		W[i] = 1000;
		Pre[i] = 0; //이전 노드 초기화
		PQ_push(i); //PQ에 큐(노드) 들을 넣어준다
	}

	W[start] = 0; //시작 노드의 가중치를 0으로 해서 제일 먼저 뽑아내도록 함.
	
	//PQ가 빌 때 까지
	while(!PQ_Empty())
	{
		//제일 작은 수를 뽑아낸다. 우선 순위 큐 이용
		v = PQ_pop();

		Wsum = Wsum + W[v]; //총 가중치 구하기

		//노드 번호를 1부터 시작하기 위해서 v값 +1 (0번 노드는 없다고 가정. 강의노트처럼)
		if (v == start)	cout << "시작정점 : " << v + 1 << " " << " W : " << W[v] << endl;
		else 	cout << "방금 포함된 정점 : " << v + 1 << " " << "  W : " << W[v] << "  간선 : " << Pre[v] + 1 << "->" << v + 1 << endl;
		for (int i = 0; i < N; i++)
		{
			//인접행렬에 값이 있고 가중치가 작다면
			if ((Array[v][i] != 0) && (W[i] > Array[v][i]))
			{
				W[i] = Array[v][i]; //가중치 업데이트
				Pre[i] = v; //이전 노드가 무엇인지 표시
			}
		}
	}
}

int main()
{
	cout << "12131649 권세훈 Prim" << endl;
	cout << "정점 개수 입력" << endl;
	cin >> N; //정점 개수 입력

	W = new int[N]();
	Pre = new int[N]();
	Q = new int[N]();

	Array = new int*[N]();
	for (int i = 0; i < N; i++) Array[i] = new int[N]();

	int A, B, D;
	cout << "간선 연결. 노드 번호, 가중치" << endl;
	for (;;)
	{
		cin >> A;
		if (A == -1) break;
		cin >> B >> D;

		//0번 인덱스 부터 있으므로 각 인덱스-1씩
		Array[A-1][B-1] = D;
		Array[B-1][A-1] = D;
	}

	Prim(0); //시작 노드는 첫번째 노드. 0으로 넣지만 실제 우리가 생각하는 1번노드부터 시작하도록 위에서 코드를 설정해줌
	cout << "총 가중치 : " << Wsum << endl;

	return 0;
}
