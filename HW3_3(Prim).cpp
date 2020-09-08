#include<iostream>
using namespace std;

//#define 0  -1

int N; //���� ����
int** Array; //���� ���� �� ����ġ�� ���� ���
int *W; //����ġ ��� �����
int *Pre; //�θ�
int *Q; //ť(���)
int Wsum = 0; //�� ����ġ

int Qcnt; //ť(���) ����


//PQ Q�����Լ�
void PQ_push(int a)
{
	Q[a] = 0; //ť(���)�� �ִ´�
	Qcnt++; //ť(���) ���� ����
}

int PQ_pop()
{
	int i;
	int min = 100000; //��� ���� ������ min�� �ǵ��� ū �� �ƹ��ų� ����
	int index = -1; //�ӽ� ����� �ε���. �湮 ���θ� ǥ��
	
	for (i = 0; i < N; i++)
	{
		if (Q[i] == -1) continue; //�湮�� ť��� �Ѿ��.
		
		//����ġ�� min���� ���� �� min�� ����
		if (W[i] < min)
		{
			index = i;
			min = W[i];
		}
	}

	if (index == -1) return -1; //�ε����� ��ȿ���� ������ -1 ����
	Q[index] = -1; //�ش� �ε����� ���� ��忡 �湮�Ͽ��ٰ� ǥ��
	Qcnt--; //ť(���) ���� ����

	return index; //���� ���� ����ġ�� ���� �ִ� �ε��� ����
}

//PQ�� ������� Ȯ���ϴ� �Լ�
bool PQ_Empty()
{
	return Qcnt == 0;
}

void Prim(int start)
{
	int i, v, w;

	Qcnt = 0; //Prim �˰��� ���۽�  ť(���) ���� �ʱ�ȭ

	for (i = 0; i<N; i++)
	{
		W[i] = 1000;
		Pre[i] = 0; //���� ��� �ʱ�ȭ
		PQ_push(i); //PQ�� ť(���) ���� �־��ش�
	}

	W[start] = 0; //���� ����� ����ġ�� 0���� �ؼ� ���� ���� �̾Ƴ����� ��.
	
	//PQ�� �� �� ����
	while(!PQ_Empty())
	{
		//���� ���� ���� �̾Ƴ���. �켱 ���� ť �̿�
		v = PQ_pop();

		Wsum = Wsum + W[v]; //�� ����ġ ���ϱ�

		//��� ��ȣ�� 1���� �����ϱ� ���ؼ� v�� +1 (0�� ���� ���ٰ� ����. ���ǳ�Ʈó��)
		if (v == start)	cout << "�������� : " << v + 1 << " " << " W : " << W[v] << endl;
		else 	cout << "��� ���Ե� ���� : " << v + 1 << " " << "  W : " << W[v] << "  ���� : " << Pre[v] + 1 << "->" << v + 1 << endl;
		for (int i = 0; i < N; i++)
		{
			//������Ŀ� ���� �ְ� ����ġ�� �۴ٸ�
			if ((Array[v][i] != 0) && (W[i] > Array[v][i]))
			{
				W[i] = Array[v][i]; //����ġ ������Ʈ
				Pre[i] = v; //���� ��尡 �������� ǥ��
			}
		}
	}
}

int main()
{
	cout << "12131649 �Ǽ��� Prim" << endl;
	cout << "���� ���� �Է�" << endl;
	cin >> N; //���� ���� �Է�

	W = new int[N]();
	Pre = new int[N]();
	Q = new int[N]();

	Array = new int*[N]();
	for (int i = 0; i < N; i++) Array[i] = new int[N]();

	int A, B, D;
	cout << "���� ����. ��� ��ȣ, ����ġ" << endl;
	for (;;)
	{
		cin >> A;
		if (A == -1) break;
		cin >> B >> D;

		//0�� �ε��� ���� �����Ƿ� �� �ε���-1��
		Array[A-1][B-1] = D;
		Array[B-1][A-1] = D;
	}

	Prim(0); //���� ���� ù��° ���. 0���� ������ ���� �츮�� �����ϴ� 1�������� �����ϵ��� ������ �ڵ带 ��������
	cout << "�� ����ġ : " << Wsum << endl;

	return 0;
}
