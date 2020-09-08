//#include <iostream>
//#include <algorithm> //max�Լ� ���
//#include <chrono> //����ũ�� ��, ���� �� ������ �����ϱ� ���� C++���̺귯��
//#include "Define.h"
//using namespace std;
//
//int knapSack(int weight, int *W, int *P, int n)
//{
//	int i, w;
//	int **K;
//	K = new int*[n + 1]();
//	for (int i = 0; i < n + 1; i++) K[i] = new int[weight + 1]();
//
//	//�迭 ä���
//	for (i = 0; i <= n; i++)
//	{
//		for (w = 0; w <= weight; w++)
//		{
//			//�ƹ��͵� ���� ���
//			if (i == 0 || w == 0)
//				K[i][w] = 0;
//
//			// 1.���� ������ �ְ� i��° ��ǰ�� ���� ��ġ 2.i��° ��ǰ�� ���� �� ���� ����� ��ġ �� ū ���� �Ҵ�
//			else if (W[i - 1] <= w)
//			{
//				K[i][w] = max(P[i - 1] + K[i - 1][w - W[i - 1]], K[i - 1][w]);
//			}
//
//			//i��°�� �ֱ� ���� �̹� ���԰� �� �� ���
//			else
//				K[i][w] = K[i - 1][w];
//		}
//	}
//
//	return K[n][weight];
//}
//
//int main()
//{
//	std::chrono::system_clock::time_point start, stop; //Ž���ϴµ� �ɸ��� �ð� �����ϱ� ���� ����
//
//	cout << "12131649 �Ǽ��� DP_0-1 Knapsack" << endl << endl;
//
//	cout << "��ǰ ���� " << N <<endl;
//
//	cout << "ǰ�� �� ����/��ġ �Է�" << endl;
//
//	//��ǰ�� ��ġ�� ���Ը� �Է��� �迭 ����
//	int *P, *W;
//	P = new int[N]();
//	W = new int[N]();
//	int weight = 0;
//
//	for (int i=0; i<N; i++)
//	{
//		cin >> W[i] >> P[i];
//		weight += W[i];
//	}
//
//	weight = weight*0.7; //���Դ� ��ü ��ǰ �������� 70%�� ����
//	cout << "���� ���� : " << weight << endl;
//
//	cout << endl << "���� ���� ����� ���� ��ġ" << endl;
//
//	start = std::chrono::system_clock::now(); //DP ���� �� �ð�����
//	cout << knapSack(weight, W, P, N) << endl << endl;
//	stop = std::chrono::system_clock::now(); //DP  ���� �� �ð� ����
//
//	chrono::microseconds micro; //����ũ�� ���� �� ������ ���� ���뼼����Ÿ�� ����
//	micro = chrono::duration_cast<chrono::microseconds>(stop - start);
//	cout << "����ð� : " << micro.count() << "ms" << endl;
//
//	delete[] P;
//	delete[] W;
//
//	return 0;
//}