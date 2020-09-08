#include<iostream>
using namespace std;

//Floyd Func.
void Floyd(int n, int** W, int** D, int** P)
{
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (W[i][j] != 0)   D[i][j] = W[i][j];
		}
	}

	for (int k = 1; k < n + 1; k++)
	{
		for (int i = 1; i < n + 1; i++)
		{
			for (int j = 1; j < n + 1; j++)
			{
				if (D[i][k] + D[k][j] < D[i][j]) //minimum function
				{
					P[i][j] = k;
					D[i][j] = D[i][k] + D[k][j];
				}
			}
		}
	}
}

//To get path
void Path(int q, int r, int** P)
{
	if (P[q][r] != 0)
	{
		Path(q, P[q][r], P);
		cout << P[q][r] << " ";
		Path(P[q][r], r, P);
	}
}

int main()
{
	//for compile speed up
	cin.tie(NULL); 
	ios_base::sync_with_stdio(false); 

	int n, m, Max_num = 99999;
	cin >> n >> m; // Insert number of Node, edge.

	//2D dynamic array. for distance 
	int** W;
	W = new int*[n + 1]();
	for (int i = 0; i < n + 1; i++) W[i] = new int[n + 1]();

	//until m, insert edge, distance
	for (int k = 0; k < m; k++)
	{
		int i, j;
		cin >> i >> j;
		cin >> W[i][j];
	}

	//this means no path
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (i != j && W[i][j] == 0) W[i][j] = Max_num;
		}
	}
	
	//2D dynamic array for Distance, Path
	int** D;
	int** P;
	D = new int*[n + 1]();
	P = new int*[n + 1]();
	for (int i = 0; i < n + 1; i++) D[i] = new int[n + 1]();
	for (int i = 0; i < n + 1; i++) P[i] = new int[n + 1]();

	//get value array D, P
	Floyd(n, W, D, P);

	int start, end; //start vertex, end vertex
	for (;;)
	{
		cin >> start;
		if (start == 0) break;
		cin >> end;
		if (D[start][end] == Max_num) cout << "0" << endl; // 0 means no path
		else
		{
			cout << D[start][end] << " "; // print distance

			//print path
			cout << start << " ";
			Path(start, end, P);
			cout << end << endl;
		}
	}

	//delete dynamic mem.
	delete[]D;
	delete[]P;
	delete[]W;

	return 0;
}
