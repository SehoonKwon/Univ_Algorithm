//#pragma warning (disable : 4996)
//#include <iostream>
//#include <chrono> //����ũ�� ��, ���� �� ������ �����ϱ� ���� C++���̺귯��
//using namespace std;
//
////#define SIZE 1024*50 // File size 50KB (1024byte = 1KB)
////#define SIZE 1024*100 // File size 100KM (�񱳹�� 4, �ؽ�Ʈ �� 2��)
////#define SIZE 1024*150 // File size 100KM (�񱳹�� 4, �ؽ�Ʈ �� 3��)
////#define SIZE 1024*200 // File size 100KM (�񱳹�� 4, �ؽ�Ʈ �� 4��)
//#define SIZE 1024*250 // File size 100KM (�񱳹�� 5, �ؽ�Ʈ �� 5��, ���λ� ���̻� �������)
//
//
//#define NUM 128 // ASCII �ڵ� 127���� ���� 
//int skip[NUM]; //Initskip�迭 ����
//
//int Next[50]; //KMP �˰��򿡼� ����ϴ� Next�迭
//
////Next �迭 �����Լ�
//void InitNext(char *p)
//{
//	int i, j, M = strlen(p); //�ݺ����� ����� ���� ����, Ƚ���뵵 �� �ݺ��� ���������� ���� ����
//	Next[0] = -1; // Next�迭�� ù ��° ĭ�� -1�̴�. ù���� ����ġ�� �� ĭ �̷��
//
//	//Next�迭�� �����ϴ� �� �ڵ�
//	for (i = 0, j = -1; i < M; i++, j++)
//	{
//		Next[i] = (p[i] == p[j]) ? Next[j] : j; //'���� �Ѽ�' �ڵ� 
//		while ((j > 0) && (p[i] != p[j])) j = Next[j]; //���� ���� �ִ��� �ڷ� ������
//	}
//}
//
//int KMP(char p[], char t[]) 
//{
//	int i, j, M = strlen(p), N = strlen(t); //�ݺ����� ���� ������ ���� �� �� �Ҵ�
//	InitNext(p); //Next �迭 �����Լ� ȣ��
//	for (i = 0, j = 0; j < M && i < N; i++, j++)
//	{
//		while ((j >= 0) && (t[i] != p[j])) j = Next[j]; // Next�迭�� �̵���Ű�� ã�� ����	
//	}
//	if (j == M) return i - M; //ã�� ��� ã�� ��ġ�� ��ȯ�ϱ� ���� ���ڿ� ���̸�ŭ ����(�ε��� ��ĭ�� ���ϸ� �ö󰡹Ƿ� �ε����� ��ġ�� ���ڿ��� �Ǹ������̹Ƿ�)
//	else return i; //ã�� ���Ѱ�� �ؽ�Ʈ�� �ε��� ��ġ ��ȯ(�Ŀ� ���ǹ����� ��ã�Ҵٰ� �ڵ带 §��)
//
//}
//
////BM
//int index(char c)
//{
//	//if (c < 97) //�ҹ��� a ���� 97 �빮�ڿ��� ������ ���ؼ� ���ǹ�
//	//{
//	//	if (c == 32) return 0; // 32�� ����
//	//	else return (c - 64); // �빮�� A������ 65�̹Ƿ� skip[1]���� A�� �ֱ� ���ؼ� -64 (�ƽ�Ű�ڵ�)
//
//	//�츮�� Ư�����ڱ��� ����� ��� ���ڿ��� ã�� BM�� ����Ƿ� �ƽ�Ű�ڵ忡 �����ϴ� ���ڸ�ŭ �迭�� �����Ͽ����Ƿ� �״�� c���� ��ȯ�Ѵ�.
//	//c���� �ش� ���ڿ��� ASCII code
//	return c;
//}
//
////Initskip �迭 ���� �Լ�.
//void Initskip(char *p)
//{
//	int i, M = strlen(p); //�ݺ����� ���� ���� ���� �� ����
//	for (i = 0; i < NUM; i++) skip[i] = M; //��� ������ ���̸�ŭ �ʱ�ȭ
//	for (i = 0; i < M; i++) skip[index(p[i])] = M-i-1; //ã���� �ϴ� ������ ���ڵ��� �迭 �ε����� ������ ���� �������Ѵ�.
//}
//
//int Mischar(char *p, char *t)
//{
//	int i, j, k, M = strlen(p), N = strlen(t); //�ݺ����� ���� ���� ���� �� ����
//	Initskip(p); //initskip �迭 �����Լ� ȣ��
//	
//	//����ġ ���ڹ�å�� �̿��Ͽ� Ž��
//	for (i = M - 1, j = M - 1; j >= 0; i--, j--)
//	{
//		while (t[i] != p[j])
//		{
//			k = skip[index(t[i])];
//			i += (M - j > k) ? M - j : k; //�� ���� ��� �� �� ���� �����̴� ���� �����Ѵ� 
//			if (i >= N) return N;
//			j = M - 1;
//		}
//	}
//
//	return i + 1; // ã����� �ε��� �� ��ȯ. ���ǹ��� �����̹Ƿ� +1���־�� �˸��� ��ġ�� ��ȯ�ȴ�.
//}
//
////�迭 ���� �Լ�
//void Create_Array(char *arr, int length)
//{
//
//	FILE *F; //������ �������� FILE* Ÿ�� ��������
//	int i = 0;
//
////	F = fopen("C:\\text\\RFC2616.txt", "r"); //��ο� �ִ� ���� �б���� ����
////	F = fopen("C:\\text\\RFC2617.txt", "r"); //�� 4 �Ҷ��� ���� (�ؽ�Ʈ�� 2��)
////	F = fopen("C:\\text\\RFC2618.txt", "r"); //�� 4 �Ҷ��� ����2 (�ؽ�Ʈ�� 3��)
////	F = fopen("C:\\text\\RFC2619.txt", "r"); //�� 4 �Ҷ��� ����3 (�ؽ�Ʈ�� 4��)
//	F = fopen("C:\\text\\RFC2620.txt", "r"); //�� 5 �Ҷ��� ���� (�ؽ�Ʈ�� 5��, �� ������ �ܾ� ���λ�=���̻�)
//
//	//������ ���� ���ϸ� ���α׷� ����
//	if (!F) 
//	{
//		exit(1); //���α׷� ����
//	}
//
//	//������ ������ �ݺ���
//	while (!(feof(F)))
//	{
//		fscanf(F, "%c", &arr[i]); //���� ������ ������ �迭�� ����.
//		i++;
//	}
//	fclose(F); //���� ���� �ݱ�
//}
//
//int main()
//{
//	cout << "12131649 �Ǽ��� ����2 KMP vs BM �ӵ���" << "\n\n";
//
//	std::chrono::system_clock::time_point start, stop[10]; //���1)Ž���ϴµ� �ɸ��� �ð� �����ϱ� ���� ����(�� ����� ó�� ���ۺ��� ã�� ������ stop��� �ð�����)
////	std::chrono::system_clock::time_point start[10], stop[10]; //���2)Ž���ϴµ� �ɸ��� �ð� �����ϱ� ���� ����(�� ����� ã�� ���� �� ���� �ٽ� ã�� �� ������ �ð�����)
//
//	int count = 0; //ã�� ����
//	int M, N, pos, previous = 0, i = 0;
//	char pattern[50] = "11111511111"; //ã���� �ϴ� ��������
//
//	char *text = new char[SIZE](); //������ �� ��ŭ char Ÿ�� �迭 �����Ҵ� �� �ʱ�ȭ
//
//	Create_Array(text, SIZE); //�迭�� ���� ä���.
//
//	M = strlen(pattern); //ã���� �ϴ� ���������� ����
//	N = strlen(text); //�ؽ�Ʈ�� ����
//
////	cout << "ã�� ���ڿ� : " << pattern << " (using KMP)"<<"\n\n";
//	cout << "ã�� ���ڿ� : " << pattern << " (using BM)" << "\n\n";
//
//	start= std::chrono::system_clock::now(); //���1)Ž�� ���� �� �ð�����
//	
//	while (1)
//	{
////		start[count] = std::chrono::system_clock::now(); //���2)Ž�� ���� �� �ð�����
////		pos = KMP(pattern, text + i); //KMP
//		pos = Mischar(pattern, text + i); // BM
//		stop[count] = std::chrono::system_clock::now(); //Ž�� ���� �� �ð� ����
//		pos += previous;
//		i = pos + M;
//		if (i <= N) //ã�� ��쿡�� ���
//		{
//			cout << "���� ��ġ : " << pos << "\n";
//			count++; // ã���� ã������ +1
//		}
//		else break;
//		previous = i;
//	}
//
//	cout << "\n���� �ҿ�ð�"<<"\n\n";
//
//	chrono::nanoseconds nano[10]; //���� ���� �� ������ ���� ���뼼����Ÿ�� ����
//	chrono::microseconds micro[10]; //����ũ�� ���� �� ������ ���� ����ũ�μ�����Ÿ�� ����
//
//
//	//�������1)
//	for (int i = 0; i < count; i++) //ã�� ������ŭ 
//	{
//		nano[i] = stop[i] - start;
//		micro[i] = chrono::duration_cast<chrono::microseconds>(stop[i] - start);
//	}
//
////	cout << "���� ���1)ó������ �ش� �ܾ ã�� �� ������ �ð� ���" << "\n\n";
////	cout << "���� ���3)�ؽ�Ʈ�� ù �ܾ Ž���ϱ������ Ž���ð�" << "\n\n";
////	cout << "���� ���4)�ؽ�Ʈ�� �� �ܾ Ž���ϱ������ Ž���ð�(�ؽ�Ʈ ��2�� -> ���� ũ�⵵ 2��)" << "\n\n";
////	cout << "���� ���4-2)�ؽ�Ʈ�� �� �ܾ Ž���ϱ������ Ž���ð�(�ؽ�Ʈ ��3�� -> ���� ũ�⵵ 3��)" << "\n\n";
////	cout << "���� ���4-3)�ؽ�Ʈ�� �� �ܾ Ž���ϱ������ Ž���ð�(�ؽ�Ʈ ��4�� -> ���� ũ�⵵ 4��)" << "\n\n";
//	cout << "���� ���5)�ؽ�Ʈ�� �� �ܾ ���λ�=���̻�(�ؽ�Ʈ ��5�� -> ���� ũ�⵵ 5��)" << "\n\n";
//
//	for (int j = 0; j < count; j++)
//	{
//		if (nano[j].count() != 0)
//		{
//			cout << "����ũ�� �� : " << micro[j].count() << "\n";
//			cout << "���� �� : " << nano[j].count() << "\n\n";
//		}
//	}
//
//	////���� ���2)
//
//	//for (int i = 0; i < count; i++) //ã�� ������ŭ 
//	//{
//	//	if (start != 0)
//	//	{
//	//		nano[i] = stop[i] - start[i];
//	//		micro[i] = chrono::duration_cast<chrono::microseconds>(stop[i] - start[i]);
//	//	}
//	//}
//
//	//cout << "���� ���2)ó�� �Ǵ� �ش� �ܾ ã�� �� ���� �ߺ��� �ܾ �ٽ� ã�� �� ������ �ð� ���" << "\n\n";
//
//	//for (int j = 0; j < count; j++)
//	//{
//	//	if (nano[j].count() != 0)
//	//	{
//	//		cout << "����ũ�� �� : " << micro[j].count() << "\n";
//	//		cout << "���� �� : " << nano[j].count() << "\n\n";
//	//	}
//	//}
//
//	delete[]text; //���� �Ҵ��� �迭 �ݳ�
//
//	return 0;
//}