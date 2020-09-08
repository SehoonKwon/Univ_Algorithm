//#pragma once
//#include <iostream>
//using namespace std;
//
//class Node
//{
//public :
//	int data;
//	Node* Next;
//};
//
//class Queue
//{
//private :
//	Node* head;
//	Node* tail;
//
//public:
//	Queue();
//	~Queue();
//	void Enqueue(int data);
//	void Dequeue();
//	void Print();
//	int Front();
//};
//
//Queue::Queue()
//	:head(NULL), tail(NULL) {};
//
//Queue::~Queue()
//{
//
//}
//
//void Queue::Enqueue(int data)
//{
//	Node* newNode = new Node();
//	newNode->data = data;
//	newNode->Next = NULL;
//	
//	if (head == NULL)
//	{
//		head = newNode;
//		tail = newNode;
//	}
//
//	else
//	{
//		tail->Next = newNode;
//		tail = newNode;
//	}
//}
//
//void Queue::Dequeue()
//{
//	if (head == NULL) cout << "No data" << endl;
//	else
//	{
//		Node* temp = head;
//		head = head->Next;
//		delete temp;
//	}
//}
//
//void Queue::Print()
//{
//	if (head != NULL)
//	{
//		Node* Pnode = head;
//		while (Pnode)
//		{
//			cout << Pnode->data << " " << endl;
//			Pnode = Pnode->Next;
//		}
//	}
//}
//
//int Queue::Front()
//{
//	if (head == NULL) cout << "No data" << endl;
//	else return head->data;
//}
//
//
//#include "UD_Queue.h"
//#include <iostream>
//using namespace std;
//
//#define N 10
//
//bool visit[N];
//
//void BFS(int s)
//{
//	for (int i = 0; i < N; i++)	visit[i] = false;
//
//	visit[s] = true;
//	Queue Q;
//	Q.Enqueue(s);
//	while
//}
//
//int main()
//{
//
//
//	return 0;
//}