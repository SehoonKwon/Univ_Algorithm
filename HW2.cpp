//#pragma warning (disable : 4996)
//#include <iostream>
//#include <chrono> //마이크로 초, 나노 초 단위를 측정하기 위한 C++라이브러리
//using namespace std;
//
////#define SIZE 1024*50 // File size 50KB (1024byte = 1KB)
////#define SIZE 1024*100 // File size 100KM (비교방법 4, 텍스트 양 2배)
////#define SIZE 1024*150 // File size 100KM (비교방법 4, 텍스트 양 3배)
////#define SIZE 1024*200 // File size 100KM (비교방법 4, 텍스트 양 4배)
//#define SIZE 1024*250 // File size 100KM (비교방법 5, 텍스트 양 5배, 접두사 접미사 같은경우)
//
//
//#define NUM 128 // ASCII 코드 127개의 문자 
//int skip[NUM]; //Initskip배열 생성
//
//int Next[50]; //KMP 알고리즘에서 사용하는 Next배열
//
////Next 배열 생성함수
//void InitNext(char *p)
//{
//	int i, j, M = strlen(p); //반복문에 사용할 변수 선언, 횟수용도 및 반복문 종료조건을 위한 변수
//	Next[0] = -1; // Next배열의 첫 번째 칸은 -1이다. 첫글자 불일치시 한 칸 미루기
//
//	//Next배열을 생성하는 주 코드
//	for (i = 0, j = -1; i < M; i++, j++)
//	{
//		Next[i] = (p[i] == p[j]) ? Next[j] : j; //'신의 한수' 코드 
//		while ((j > 0) && (p[i] != p[j])) j = Next[j]; //같은 것이 있는지 뒤로 역추적
//	}
//}
//
//int KMP(char p[], char t[]) 
//{
//	int i, j, M = strlen(p), N = strlen(t); //반복문을 위한 변수들 생성 및 값 할당
//	InitNext(p); //Next 배열 생성함수 호출
//	for (i = 0, j = 0; j < M && i < N; i++, j++)
//	{
//		while ((j >= 0) && (t[i] != p[j])) j = Next[j]; // Next배열을 이동시키며 찾는 과정	
//	}
//	if (j == M) return i - M; //찾은 경우 찾은 위치를 반환하기 위해 문자열 길이만큼 빼줌(인덱스 한칸씩 비교하며 올라가므로 인덱스의 위치가 문자열의 맨마지막이므로)
//	else return i; //찾지 못한경우 텍스트의 인덱스 위치 반환(후에 조건문으로 못찾았다고 코드를 짠다)
//
//}
//
////BM
//int index(char c)
//{
//	//if (c < 97) //소문자 a 값이 97 대문자와의 구별을 위해서 조건문
//	//{
//	//	if (c == 32) return 0; // 32는 공백
//	//	else return (c - 64); // 대문자 A시작이 65이므로 skip[1]부터 A를 넣기 위해선 -64 (아스키코드)
//
//	//우리는 특수문자까지 고려한 모든 문자열을 찾는 BM을 만드므로 아스키코드에 존재하는 문자만큼 배열을 생성하였으므로 그대로 c값을 반환한다.
//	//c값은 해당 문자열의 ASCII code
//	return c;
//}
//
////Initskip 배열 생성 함수.
//void Initskip(char *p)
//{
//	int i, M = strlen(p); //반복문을 위한 변수 선언 및 생성
//	for (i = 0; i < NUM; i++) skip[i] = M; //모두 패턴의 길이만큼 초기화
//	for (i = 0; i < M; i++) skip[index(p[i])] = M-i-1; //찾고자 하는 패턴의 글자들은 배열 인덱스의 역순의 값을 갖도록한다.
//}
//
//int Mischar(char *p, char *t)
//{
//	int i, j, k, M = strlen(p), N = strlen(t); //반복문을 위한 변수 선언 및 생성
//	Initskip(p); //initskip 배열 생성함수 호출
//	
//	//불일치 문자방책을 이용하여 탐색
//	for (i = M - 1, j = M - 1; j >= 0; i--, j--)
//	{
//		while (t[i] != p[j])
//		{
//			k = skip[index(t[i])];
//			i += (M - j > k) ? M - j : k; //두 개의 경우 중 더 많이 움직이는 경우로 선택한다 
//			if (i >= N) return N;
//			j = M - 1;
//		}
//	}
//
//	return i + 1; // 찾은경우 인덱스 값 반환. 조건문이 감소이므로 +1해주어야 알맞은 위치가 반환된다.
//}
//
////배열 생성 함수
//void Create_Array(char *arr, int length)
//{
//
//	FILE *F; //파일을 열기위해 FILE* 타입 변수선언
//	int i = 0;
//
////	F = fopen("C:\\text\\RFC2616.txt", "r"); //경로에 있는 파일 읽기모드로 열기
////	F = fopen("C:\\text\\RFC2617.txt", "r"); //비교 4 할때의 파일 (텍스트양 2배)
////	F = fopen("C:\\text\\RFC2618.txt", "r"); //비교 4 할때의 파일2 (텍스트양 3배)
////	F = fopen("C:\\text\\RFC2619.txt", "r"); //비교 4 할때의 파일3 (텍스트양 4배)
//	F = fopen("C:\\text\\RFC2620.txt", "r"); //비교 5 할때의 파일 (텍스트양 5배, 맨 마지막 단어 접두사=접미사)
//
//	//파일을 열지 못하면 프로그램 종료
//	if (!F) 
//	{
//		exit(1); //프로그램 종료
//	}
//
//	//파일의 끝까지 반복문
//	while (!(feof(F)))
//	{
//		fscanf(F, "%c", &arr[i]); //읽은 파일의 내용을 배열에 복사.
//		i++;
//	}
//	fclose(F); //열은 파일 닫기
//}
//
//int main()
//{
//	cout << "12131649 권세훈 과제2 KMP vs BM 속도비교" << "\n\n";
//
//	std::chrono::system_clock::time_point start, stop[10]; //방법1)탐색하는데 걸리는 시간 측정하기 위한 변수(이 방법은 처음 시작부터 찾을 때마다 stop기록 시간측정)
////	std::chrono::system_clock::time_point start[10], stop[10]; //방법2)탐색하는데 걸리는 시간 측정하기 위한 변수(이 방법은 찾고 나서 그 이후 다시 찾을 때 까지의 시간측정)
//
//	int count = 0; //찾은 개수
//	int M, N, pos, previous = 0, i = 0;
//	char pattern[50] = "11111511111"; //찾고자 하는 문자패턴
//
//	char *text = new char[SIZE](); //데이터 양 만큼 char 타입 배열 동적할당 및 초기화
//
//	Create_Array(text, SIZE); //배열에 값을 채운다.
//
//	M = strlen(pattern); //찾고자 하는 문자패턴의 길이
//	N = strlen(text); //텍스트의 길이
//
////	cout << "찾는 문자열 : " << pattern << " (using KMP)"<<"\n\n";
//	cout << "찾는 문자열 : " << pattern << " (using BM)" << "\n\n";
//
//	start= std::chrono::system_clock::now(); //방법1)탐색 시작 전 시간측정
//	
//	while (1)
//	{
////		start[count] = std::chrono::system_clock::now(); //방법2)탐색 시작 전 시간측정
////		pos = KMP(pattern, text + i); //KMP
//		pos = Mischar(pattern, text + i); // BM
//		stop[count] = std::chrono::system_clock::now(); //탐색 종료 후 시간 측정
//		pos += previous;
//		i = pos + M;
//		if (i <= N) //찾은 경우에만 출력
//		{
//			cout << "패턴 위치 : " << pos << "\n";
//			count++; // 찾으면 찾은개수 +1
//		}
//		else break;
//		previous = i;
//	}
//
//	cout << "\n정렬 소요시간"<<"\n\n";
//
//	chrono::nanoseconds nano[10]; //나노 단위 초 측정을 위한 나노세컨즈타입 변수
//	chrono::microseconds micro[10]; //마이크로 단위 초 측정을 위한 마이크로세컨즈타입 변수
//
//
//	//측정방법1)
//	for (int i = 0; i < count; i++) //찾은 개수만큼 
//	{
//		nano[i] = stop[i] - start;
//		micro[i] = chrono::duration_cast<chrono::microseconds>(stop[i] - start);
//	}
//
////	cout << "측정 방법1)처음부터 해당 단어를 찾을 때 마다의 시간 기록" << "\n\n";
////	cout << "측정 방법3)텍스트의 첫 단어를 탐색하기까지의 탐색시간" << "\n\n";
////	cout << "측정 방법4)텍스트의 끝 단어를 탐색하기까지의 탐색시간(텍스트 양2배 -> 파일 크기도 2배)" << "\n\n";
////	cout << "측정 방법4-2)텍스트의 끝 단어를 탐색하기까지의 탐색시간(텍스트 양3배 -> 파일 크기도 3배)" << "\n\n";
////	cout << "측정 방법4-3)텍스트의 끝 단어를 탐색하기까지의 탐색시간(텍스트 양4배 -> 파일 크기도 4배)" << "\n\n";
//	cout << "측정 방법5)텍스트의 끝 단어가 접두사=접미사(텍스트 양5배 -> 파일 크기도 5배)" << "\n\n";
//
//	for (int j = 0; j < count; j++)
//	{
//		if (nano[j].count() != 0)
//		{
//			cout << "마이크로 초 : " << micro[j].count() << "\n";
//			cout << "나노 초 : " << nano[j].count() << "\n\n";
//		}
//	}
//
//	////측정 방법2)
//
//	//for (int i = 0; i < count; i++) //찾은 개수만큼 
//	//{
//	//	if (start != 0)
//	//	{
//	//		nano[i] = stop[i] - start[i];
//	//		micro[i] = chrono::duration_cast<chrono::microseconds>(stop[i] - start[i]);
//	//	}
//	//}
//
//	//cout << "측정 방법2)처음 또는 해당 단어를 찾은 뒤 부터 중복된 단어를 다시 찾을 때 까지의 시간 기록" << "\n\n";
//
//	//for (int j = 0; j < count; j++)
//	//{
//	//	if (nano[j].count() != 0)
//	//	{
//	//		cout << "마이크로 초 : " << micro[j].count() << "\n";
//	//		cout << "나노 초 : " << nano[j].count() << "\n\n";
//	//	}
//	//}
//
//	delete[]text; //동적 할당한 배열 반납
//
//	return 0;
//}