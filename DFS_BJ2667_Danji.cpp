//////���� ���� 2667
//#include<stdio.h>
//
//void DFS(int v, int n, int**,bool**);
//
//int st[10000] = { 0 }; 
//int dx[4] = { 0,-1,0,1 };
//int dy[4] = { -1,0,1,0 };
//int group = 0, num_group[10000] = { 0 }; //group�� ���� ��, num_group[]�� �������� ����Ʈ ���� ��� �迭
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
//   map = new int*[n + 1]{ 0 }; //����Ʈ ��
//   for (int i = 0; i < n + 1; i = i + 1) map[i] = new int[n+ 1] { 0 };//��ǥ�� (1,1)���� ����
//   
//   bool** visit;
//   visit = new bool*[n + 1]{ 0 };
//   for (int i = 0; i < n + 1; i = i + 1) visit[i] = new bool[n + 1]{ 0 };
//   
//   for (int i = 1; i <= n; i++)
//   {
//      for (int j = 1; j <= n; j++)
//      {
//         scanf("%1d", &map[i][j]); //���� ���� �ٿ��� �Է¹ޱ�
//      }
//   }
//
//   DFS(1, n, map, visit); //1���� ������ (1,1) ->1, (1,2)->2, (1,3)->3, ...
//   
//   if(num_group[group]!=0)   group++; //group�� 0���� ���������Ƿ� ���� group �ȿ� ����Ʈ�� ������ �ϳ� �÷���
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
//      y = vertex%n == 0 ? n : vertex%n;  //vertex�� x, y��ǥ�� ��ȯ
//      
//	  if (!visit[x][y]) 
//      {
//         visit[x][y] = true; //�湮ǥ��
//         
//		 if(map[x][y]==1) num_group[group]++; //visit���� �� ���� ���� ����Ʈ ���� �÷���
//         
//		 for (int i = 0; i<4; i++)
//         {
//            if (0 < x + dx[i] && x + dx[i] < n + 1 && 0 < y + dy[i] && y + dy[i] < n + 1) //������ ��ǥ�� map�ȿ� ������
//            {
//               if (map[x + dx[i]][y + dy[i]] == 1 && !visit[x + dx[i]][y + dy[i]]) //�湮���� ���϶� 
//               {
//                  st[top++] = (x + dx[i] - 1)*n + y + dy[i]; //�� ��ǥ�� vertex ��ȣ�� push ����
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
//         if (!visit[i][j] && map[i][j]==1) //������������ ���� �ٸ� ����Ʈ ���� ã������
//         {
//            if(num_group[group]!=0) group++; //�ٸ� ����Ʈ ã������ group�� �÷��ִµ� 
//											 //�̶� ���� group�� ����Ʈ�� �־���� ������ group�� �ø�������
//            DFS((i-1)*n + j, n, map, visit);
//            break;//�ٸ� DFS�ϳ� �ҷ������� �� DFS�� ����
//         }
//      }
//   }
//}