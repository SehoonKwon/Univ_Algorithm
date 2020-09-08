//#include <iostream>
//using namespace std;
//char k;
//int h, w, a[101][101], b[101][101], acheck[101][101], bcheck[101][101];
//int n, acnt, bcnt, dh[] = { 0,0,-1,1 }, dw[] = { -1,1,0,0 };//a는 정상인 b는 색약
//
////정상인용 DFS
//void aDFS(int h, int w, int color, int acnt)
//{
//	acheck[h][w] = color;
//	for (int i = 0; i < 4; i++)
//	{
//		int nh = h + dh[i];
//		int nw = w + dw[i];
//		if (0 <= nh && nh < n && 0 <= nw && nw <= n)
//		{
//			if (a[nh][nw] == color && acheck[nh][nw] == 0)
//				aDFS(nh, nw, color, acnt);
//
//		}
//	}
//}
//
////색맹용 DFS
//void bDFS(int h, int w, int color, int bcnt)
//{
//	bcheck[h][w] = color; //방문 표시. 맵에 색을 할당하므로서 표시한다.
//
//	//상하좌우 탐색
//	for (int i = 0; i < 4; i++)
//	{
//		int nh = h + dh[i];
//		int nw = w + dw[i];
//
//		//범위 안에서
//		if (0 <= nh && nh < n && 0 <= nw && nw <= n)
//		{
//			//색이 있는데 방문 안했으면(Map에 색을 확인하지 않은 상태면)
//			if (b[nh][nw] == color && bcheck[nh][nw] == 0)
//				bDFS(nh, nw, color, bcnt);
//		}
//	}
//}
//
//int main() {
//
//	cin >> n;
//
//	//RGB Map입력받기. 색맹을 위한 맵에는 G를 R과 같은 값으로 넣는다
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cin >> k;
//			if (k == 'R') {
//				a[i][j] = 1; b[i][j] = 1;
//			}
//			else if (k == 'G') {
//				a[i][j] = 2; b[i][j] = 1;
//			}
//			else if (k == 'B') {
//				a[i][j] = 3; b[i][j] = 2;
//			}
//		}
//
//	}
//
//	//일반인, 색맹 두 경우에 대한 DFS. 일반인은 3가지 경우로 색맹은 2가지 경우로
//	for (int i = 0; i<n; i++)
//		for (int j = 0; j < n; j++)
//		{
//			if (a[i][j] == 1 && acheck[i][j] == 0) {
//				aDFS(i, j, 1, ++acnt);
//			}
//			else if (a[i][j] == 2 && acheck[i][j] == 0) {
//				aDFS(i, j, 2, ++acnt);
//			}
//
//			else if (a[i][j] == 3 && acheck[i][j] == 0) {
//				aDFS(i, j, 3, ++acnt);
//			}
//			else if (b[i][j] == 1 && bcheck[i][j] == 0) {
//				bDFS(i, j, 1, ++bcnt);
//			}
//			else if (b[i][j] == 2 && bcheck[i][j] == 0) {
//				bDFS(i, j, 2, ++bcnt);
//			}
//		}
//
//	cout << acnt << ' ' << bcnt;
//}