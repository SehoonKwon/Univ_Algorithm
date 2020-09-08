//#include<iostream>
//using namespace std;
//
////Max func.
//int max(int x, int y)
//{
//	int max;
//	if (x > y) max = x;
//	else max = y;
//
//	return max;
//}
//
////count max cheese func.
//int max_cheese(int **Arr, int N, int M)
//{
//	//2D Dynamic Array
//	int **CHZ_NUM;
//
//	CHZ_NUM = new int*[N]();
//	for (int i = 0; i < N; i++) CHZ_NUM[i] = new int[N]();
//
//	//start point
//	CHZ_NUM[N - 1][0] = Arr[N - 1][0];
//
//	//up
//	for (int i = N - 2; i >= 0; i--)
//	{
//		//if trap, up direct all under value 0 to react block 
//		if (Arr[i][0] == 2)
//		{
//			for (int k = i; k >= 0; k--) CHZ_NUM[k][0] = -10;
//			break;
//		}
//
//		// if reach cheese, number of cheese up
//		CHZ_NUM[i][0] = Arr[i][0] + CHZ_NUM[i + 1][0];
//	}
//
//	//right
//	for (int j = 1; j < M; j++)
//	{
//		//if trap, right direct all under value 0 to react block
//		if (Arr[N - 1][j] == 2)
//		{
//			for (int k = j; k<M; k++) CHZ_NUM[N - 1][k] = -10;
//			break;
//		}
//
//		// if reach cheese, number of cheese up
//		CHZ_NUM[N - 1][j] = Arr[N - 1][j] + CHZ_NUM[N - 1][j - 1];
//	}
//
//	//Do count number of cheese
//	for (int i = N - 2; i >= 0; i--)
//	{
//		for (int j = 1; j < M; j++)
//		{
//			//if reach trap , insert under value 0 in order to don't be selected max value
//			if (Arr[i][j] == 2)
//			{
//				CHZ_NUM[i][j] = -10;
//				continue;
//			}
//
//			CHZ_NUM[i][j] = Arr[i][j] + max(CHZ_NUM[i + 1][j], CHZ_NUM[i][j - 1]);
//		}
//	}
//
//	//return number of cheese
//	return CHZ_NUM[0][N - 1];
//}
//
//int main()
//{
//	int N, M;
//
//	cin >> N >> M;
//
//	//2D Dynamic Array 
//	int **Array;
//	Array = new int*[N]();
//	for (int i = 0; i < N; i++) Array[i] = new int[N]();
//
//	int E;
//
//	//input
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			cin >> E;
//			Array[i][j] = E;
//		}
//	}
//
//	cout << max_cheese(Array, N, M) << endl;
//
//	return 0;
//}
//
////Recursive Property : CHZ_NUM[i][j] =  -10 (if Arr[i][j] == 2 (trap)) -> if reach trap, insert under value 0 in order to don't be selected max value
////										Arr[i][j] + max(CHZ_NUM[i + 1][j], CHZ_NUM[i][j - 1]) otherwise. -> chz_num value is select max value between down position or left position.
////										if reach cheese, arr[i][j] (cheese) value is 1. therefore arr + max chz_num(down, left) mean number of cheese + 1 and present number of cheese. 
