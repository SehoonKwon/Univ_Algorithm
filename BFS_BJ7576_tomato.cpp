//#include <stdio.h>
//#include <queue>
//using namespace std;
//
//const int dx[] = { 0,0,-1,1 };
//const int dy[] = { -1,1,0,0 };
//int n, m, ans, a[1001][1001];
//queue<pair<int, int> > que;
//
//int main() {
//	int i, j;
//	int k = 0;
//	scanf("%d %d", &m, &n);
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < m; j++)
//		{
//			scanf("%d", &a[i][j]); //배열에 토마토 상태 값 넣기
//			if (a[i][j] == 1) que.push({ i,j }); //익은 토마토면 큐에 넣는다.
//		}
//	}
//
//	while (!que.empty())
//	{
//		/*auto*/ pair<int, int>  now = que.front(); //auto는 할당하는 값에 맞춰서 변수타입을 지정해준다.
//													//now라는 변수에 큐 팝
//		que.pop(); //값 뽑았으니 제거
//		int x = now.first, y = now.second; //x, y에 i,j값 할당. 위치 값
//
//		ans = ans > a[x][y] ? ans : a[x][y]; //답을 출력하는 변수와 배열의 값을 비교하여 더 큰 값 ans에 할당, 처음 시작 시 1로 시작하므로 나중에 -1필요
//											 //익은 토마토일때 큐에 넣고 이 큐를 팝하면서 시작하므로
//		
//		//4방향 검사
//		for (i = 0; i < 4; i++)
//		{
//			int nx = x + dx[i], ny = y + dy[i];
//			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; //배열을 벗어나는 인덱스거나 썩은 토마토면 넘어감
//
//			//만약 안익은 토마토면
//			if (a[nx][ny] == 0)
//			{
//				que.push({ nx,ny }); //큐에 넣는다.
//				a[nx][ny] = a[x][y] + 1; // 며칠째에 익었는지 표시. 첫 날부터 주위 토마토를 익힐때 +1씩 해온다.
//										 // 첫 시작시 1이므로 첫째날이 +1되서 2로 됌. 그러므로 -1하는 과정이 필요한 것
//			}
//		}
//	}
//
//	//전체 배열 검사. 안익은 토마토가 있으면 답 변수에 0 할당
//	for (i = 0; i < n; i++)
//		for (j = 0; j < m; j++)
//			if (a[i][j] == 0) ans = 0;
//
//	//토마토가 모두 익는 날짜 출력. 모두 익지 못하는 상태면 -1 출력인데 이는 ans = 0을 할당함으로서 해결
//	//위에 처음 시작시 1로 시작하므로 날짜 -1하는 작업 필요
//	printf("%d", ans - 1);
//
//	return 0;
//}