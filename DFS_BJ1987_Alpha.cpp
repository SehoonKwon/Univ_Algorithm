//#include<iostream>
//using namespace std;
//int dx[4] = { 0,-1,0,1 };
//int dy[4] = { -1,0,1,0 };
//bool visit[26] = { 0 }; //A~Z
//int out = 1;//���� ĭ ���� -> �ʱⰪ 1
//void DFS(int r, int c, int x, int y, char** map, int cnt)
//{
//	if (cnt > out)   out = cnt;//�ִ� ����
//	for (int i = 0; i<4; i++)
//	{
//		if (0 < x + dx[i] && x + dx[i] < r + 1 && 0 < y + dy[i] && y + dy[i] < c + 1)
//		{
//			if (!visit[(int)map[x + dx[i]][y + dy[i]] - 65])
//			{
//				visit[(int)map[x + dx[i]][y + dy[i]] - 65] = true;
//				DFS(r, c, x + dx[i], y + dy[i], map, cnt + 1);//�� �����
//				visit[(int)map[x + dx[i]][y + dy[i]] - 65] = false;//��� ���ƿ��� ����
//			}
//		}
//	}
//}
//int main(void)
//{
//	int r, c;
//	cin >> r >> c;
//	char** map;
//	map = new char*[r + 1]{ 0 };
//	for (int i = 0; i < r + 1; i = i + 1) map[i] = new char[c + 1]{ 0 };
//	for (int i = 1; i <= r; i++)
//	{
//		for (int j = 1; j <= c; j++)
//		{
//			//scanf(" %c", &map[i][j]);
//			cin >> map[i][j];
//		}
//	}
//	visit[(int)map[1][1] - 65] = true;//ùĭ�� ������ visit
//	DFS(r, c, 1, 1, map, out);
//	cout << out << endl;
//	return 0;
//}