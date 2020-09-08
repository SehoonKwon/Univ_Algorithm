//#include<stdio.h>
//#include<queue>
//#include<string.h>
//using namespace std;
//
//queue <int> qx;
//queue <int> qy;
//
//int height, width, i, j, map[51][51], len[51][51], mx, fx[4] = { 0,1,0,-1 }, fy[4] = { -1,0,1,0 }, tmpX, tmpY, x, y;
//bool visited[51][51];
//char alpha;
//
//void bfs(int i, int j)
//{
//	visited[i][j] = true;
//
//	qx.push(i); qy.push(j);
//
//	while (!qx.empty() && !qy.empty()) 
//	{
//		tmpX = qx.front(); qx.pop();
//		tmpY = qy.front(); qy.pop();
//
//		for (i = 0; i < 4; i++)
//		{
//			x = tmpX + fx[i]; // (tmpX, tmpY) 동서남북 탐색
//
//			y = tmpY + fy[i];
//
//			if (map[x][y] == 1 && !visited[x][y]) 
//			{
//				visited[x][y] = true;
//				qx.push(x); qy.push(y);
//				len[x][y] = len[tmpX][tmpY] + 1; //길이 하나 늘림
//
//				if (len[x][y] > mx) mx = len[x][y];
//			}
//		}
//	}
//}
//
//int main()
//{
//	scanf_s("%d %d", &height, &width);
//
//	for (i = 0; i < height; i++)
//	{
//		getchar(); // 개행시 버퍼에 있는 \n을 없애기 위함.
//
//		for (j = 0; j < width; j++)
//		{
//			alpha = getchar(); //한 문자씩 받아서
////			printf("%d ", alpha);
//
//			if (alpha == 'L')	map[i][j] = 1; //육지면 1
//			else map[i][j] = 0; //바다면 0 저장
//		}
//	}
//
//	//모든 지점 탐색
//	for (i = 0; i < height; i++) 
//	{
//		for (j = 0; j < width; j++) 
//		{
//			if (map[i][j] == 1)
//			{
//				bfs(i, j);
//				memset(len, 0, sizeof(len)); //len 초기화
//				memset(visited, 0, sizeof(visited)); //visit 초기화 다음 bfs작동을 위해서
//			}
//		}
//	}
//
//	printf("%d\n", mx);
//
//	return 0;
//}
