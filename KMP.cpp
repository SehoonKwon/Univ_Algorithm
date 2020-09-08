//#include <iostream>
//#include <string>
//#include <string.h>
//using namespace std;
////
////int KMP(char *p, char *t);
////char* InitNext(char *p);
////
////
////int main()
////{
////	char text[100] = "10011101001010001010011101";
////	char pattern[50] = "10100111";
////
////	int M, N, pos, previous = 0, i = 0;
////
////	M = strlen(pattern);
////	N = strlen(text);
////
////	while (1)
////	{
////		pos = KMP(pattern, text + i);
////		pos += previous;
////		i = pos + M;
////		if (i <= N) cout << "패턴이 발생한 위치" << endl;
////		else
////		{
////			cout << "발견 못함" << endl;
////			break;
////		}
////	}
////
////	return 0;
////}
////
////int KMP(char *p, char *t)
////{
////	int i, j, M, N;
////	M = strlen(p);
////	N = strlen(t);
////	char [] next = new char[M];
////
////	next = InitNext(p);
////	cout << next << endl;
////
////	for (i = 0, j = 0; j < M && i < N; i++, j++)
////	{
////		while (j >= 0 && t[i] != p[j])	j = next[j];
////	}
////
////	if (j == M) return i - M;
////	else return i;
////}
////
////char* InitNext(char *p)
////{
////	int i, j;
////	const int M = strlen(p);
////	char [] next = new char[M];
////	
////
////	next[0] = -1;
////	cout << next << endl;
////	for (i = 0, j = -1; i < M; i++, j++)
////	{
////		next[i] = j;
////		while (j >= 0 && p[i] != p[j]) {
////			next[i] = (p[i] == p[j]) ? next[j] : j;
////		}
////	}
////
////	return next;
////}
//
//////////////////////////////////////////////////////
//
//void computeLPSArray(char *pat, int M, int *lps);
//
//// Prints occurrences of txt[] in pat[]
//void KMPSearch(char *pat, char *txt)
//{
//	int M = strlen(pat);
//	int N = strlen(txt);
//
//	// create lps[] that will hold the longest prefix suffix
//	// values for pattern
//	//int lps[M];
//	int *lps = new int[M];
//
//	// Preprocess the pattern (calculate lps[] array)
//	computeLPSArray(pat, M, lps);
//
//	int i = 0;  // index for txt[]
//	int j = 0;  // index for pat[]
//	while (i < N)
//	{
//		if (pat[j] == txt[i])
//		{
//			j++;
//			i++;
//		}
//
//		if (j == M)
//		{
//			printf("Found pattern at index %d n", i - j);
//			j = lps[j - 1];
//		}
//
//		// mismatch after j matches
//		else if (i < N && pat[j] != txt[i])
//		{
//			// Do not match lps[0..lps[j-1]] characters,
//			// they will match anyway
//			if (j != 0)
//				j = lps[j - 1];
//			else
//				i = i + 1;
//		}
//	}
//}
//
//// Fills lps[] for given patttern pat[0..M-1]
//void computeLPSArray(char *pat, int M, int *lps)
//{
//	// length of the previous longest prefix suffix
//	int len = 0;
//
//	lps[0] = 0; // lps[0] is always 0
//
//				// the loop calculates lps[i] for i = 1 to M-1
//	int i = 1;
//	while (i < M)
//	{
//		if (pat[i] == pat[len])
//		{
//			len++;
//			lps[i] = len;
//			i++;
//		}
//		else // (pat[i] != pat[len])
//		{
//			// This is tricky. Consider the example.
//			// AAACAAAA and i = 7. The idea is similar 
//			// to search step.
//			if (len != 0)
//			{
//				len = lps[len - 1];
//
//				// Also, note that we do not increment
//				// i here
//			}
//			else // if (len == 0)
//			{
//				lps[i] = 0;
//				i++;
//			}
//		}
//	}
//}
//
//// Driver program to test above function
//int main()
//{
//	char *txt = "ABABDABACDABABCABAB";
//	char *pat = "ABABCABAB";
//	KMPSearch(pat, txt);
//	return 0;
//}