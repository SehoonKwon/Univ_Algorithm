//#include <iostream>
//using namespace std;
//char k;
//int h, w, a[101][101], b[101][101], acheck[101][101], bcheck[101][101];
//int n, acnt, bcnt, dh[] = { 0,0,-1,1 }, dw[] = { -1,1,0,0 };//a�� ������ b�� ����
//
////�����ο� DFS
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
////���Ϳ� DFS
//void bDFS(int h, int w, int color, int bcnt)
//{
//	bcheck[h][w] = color; //�湮 ǥ��. �ʿ� ���� �Ҵ��ϹǷμ� ǥ���Ѵ�.
//
//	//�����¿� Ž��
//	for (int i = 0; i < 4; i++)
//	{
//		int nh = h + dh[i];
//		int nw = w + dw[i];
//
//		//���� �ȿ���
//		if (0 <= nh && nh < n && 0 <= nw && nw <= n)
//		{
//			//���� �ִµ� �湮 ��������(Map�� ���� Ȯ������ ���� ���¸�)
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
//	//RGB Map�Է¹ޱ�. ������ ���� �ʿ��� G�� R�� ���� ������ �ִ´�
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
//	//�Ϲ���, ���� �� ��쿡 ���� DFS. �Ϲ����� 3���� ���� ������ 2���� ����
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