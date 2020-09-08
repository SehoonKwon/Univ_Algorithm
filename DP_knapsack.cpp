//#include <iostream>
//#include <algorithm> //max함수 사용
//#include <chrono> //마이크로 초, 나노 초 단위를 측정하기 위한 C++라이브러리
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
//	//배열 채우기
//	for (i = 0; i <= n; i++)
//	{
//		for (w = 0; w <= weight; w++)
//		{
//			//아무것도 없는 경우
//			if (i == 0 || w == 0)
//				K[i][w] = 0;
//
//			// 1.넣을 공간이 있고 i번째 물품을 넣은 가치 2.i번째 물품을 넣을 수 없는 경우의 가치 중 큰 값을 할당
//			else if (W[i - 1] <= w)
//			{
//				K[i][w] = max(P[i - 1] + K[i - 1][w - W[i - 1]], K[i - 1][w]);
//			}
//
//			//i번째를 넣기 전에 이미 무게가 다 찬 경우
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
//	std::chrono::system_clock::time_point start, stop; //탐색하는데 걸리는 시간 측정하기 위한 변수
//
//	cout << "12131649 권세훈 DP_0-1 Knapsack" << endl << endl;
//
//	cout << "물품 개수 " << N <<endl;
//
//	cout << "품목 별 무게/가치 입력" << endl;
//
//	//물품의 가치와 무게를 입력할 배열 생성
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
//	weight = weight*0.7; //무게는 전체 물품 무게합의 70%로 설정
//	cout << "무게 제한 : " << weight << endl;
//
//	cout << endl << "가장 많이 담았을 때의 가치" << endl;
//
//	start = std::chrono::system_clock::now(); //DP 시작 전 시간측정
//	cout << knapSack(weight, W, P, N) << endl << endl;
//	stop = std::chrono::system_clock::now(); //DP  종료 후 시간 측정
//
//	chrono::microseconds micro; //마이크로 단위 초 측정을 위한 나노세컨즈타입 변수
//	micro = chrono::duration_cast<chrono::microseconds>(stop - start);
//	cout << "수행시간 : " << micro.count() << "ms" << endl;
//
//	delete[] P;
//	delete[] W;
//
//	return 0;
//}