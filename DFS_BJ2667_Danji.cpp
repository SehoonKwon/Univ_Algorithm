//////단지 백준 2667
//#include<stdio.h>
//
//void DFS(int v, int n, int**,bool**);
//
//int st[10000] = { 0 }; 
//int dx[4] = { 0,-1,0,1 };
//int dy[4] = { -1,0,1,0 };
//int group = 0, num_group[10000] = { 0 }; //group은 단지 수, num_group[]은 단지별로 아파트 수를 담는 배열
//
//void insertionSort(int arr[], int n)
//{
//   int i, key, j;
//
//   for (i = 1; i < n; i++)
//   {
//      key = arr[i];
//      j = i - 1;
//      
//	  while (j >= 0 && arr[j] > key)
//      {
//         arr[j + 1] = arr[j];
//         j = j - 1;
//      }
//
//      arr[j + 1] = key;
//   }
//}
//
//int main(void)
//{
//   int n;
//   int** map;
//   scanf("%d",&n); 
//   map = new int*[n + 1]{ 0 }; //아파트 맵
//   for (int i = 0; i < n + 1; i = i + 1) map[i] = new int[n+ 1] { 0 };//좌표는 (1,1)부터 쓸거
//   
//   bool** visit;
//   visit = new bool*[n + 1]{ 0 };
//   for (int i = 0; i < n + 1; i = i + 1) visit[i] = new bool[n + 1]{ 0 };
//   
//   for (int i = 1; i <= n; i++)
//   {
//      for (int j = 1; j <= n; j++)
//      {
//         scanf("%1d", &map[i][j]); //띄어쓰기 없이 붙여서 입력받기
//      }
//   }
//
//   DFS(1, n, map, visit); //1부터 시작함 (1,1) ->1, (1,2)->2, (1,3)->3, ...
//   
//   if(num_group[group]!=0)   group++; //group은 0부터 시작했으므로 현재 group 안에 아파트가 있으면 하나 올려줌
//   printf("%d\n", group);
//   
//   insertionSort(num_group, group);
//   for (int i = 0; i < group; i++)
//   {
//      printf("%d\n", num_group[i]);
//   }
//
//   return 0;
//}
//
//void DFS(int vertex, int n, int** map, bool** visit)
//{
//   int top=0, x, y;
//   st[top++] = vertex;
//   
//   while (0<top)
//   { 
//      vertex = st[--top];
//      x = (vertex - 1) / n + 1; 
//      y = vertex%n == 0 ? n : vertex%n;  //vertex를 x, y좌표로 변환
//      
//	  if (!visit[x][y]) 
//      {
//         visit[x][y] = true; //방문표시
//         
//		 if(map[x][y]==1) num_group[group]++; //visit했을 때 단지 내의 아파트 수를 올려줌
//         
//		 for (int i = 0; i<4; i++)
//         {
//            if (0 < x + dx[i] && x + dx[i] < n + 1 && 0 < y + dy[i] && y + dy[i] < n + 1) //움직인 좌표가 map안에 있으면
//            {
//               if (map[x + dx[i]][y + dy[i]] == 1 && !visit[x + dx[i]][y + dy[i]]) //방문안한 집일때 
//               {
//                  st[top++] = (x + dx[i] - 1)*n + y + dy[i]; //그 좌표의 vertex 번호를 push 해줌
//               }
//            }
//         }
//      }
//   }
//
//   for (int i = 1; i <=n; i++)
//   {
//      for (int j = 1; j <=n; j++)
//      {
//         if (!visit[i][j] && map[i][j]==1) //빠져나왔으니 이제 다른 아파트 단지 찾으러감
//         {
//            if(num_group[group]!=0) group++; //다른 아파트 찾았으면 group은 올려주는데 
//											 //이때 현재 group에 아파트가 있어야함 없으면 group을 올리지않음
//            DFS((i-1)*n + j, n, map, visit);
//            break;//다른 DFS하나 불러줬으니 이 DFS는 종료
//         }
//      }
//   }
//}