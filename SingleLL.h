#pragma once
#include<iostream>
#include<string>
using namespace std;

template <typename E>
class SingleLL {
private:
	template <typename E>
	class SNode {
	private:
		E elem;
		SNode<E>* next;
		friend class SingleLL<E>;
	};
public:
	SingleLL();
	~SingleLL();
	bool empty() const;
	const E& front() const;
	const E& back() const;
	void addFront(const E& e);
	void removeFront();
	void addBack(const E& e);
	void removeBack();
	int size() const;
private:
	SNode<E>* head;
	SNode<E>* tail;
	int count;
};

template <typename E>
SingleLL<E>::SingleLL()
	:head(NULL), tail(NULL) {}

template <typename E>
SingleLL<E>::~SingleLL()
{
	while (!empty()) removeFront();
}

template <typename E>
bool SingleLL<E>::empty() const
{
	return head == NULL;
}

template <typename E>
const E& SingleLL<E>::front() const
{
	return head->elem;
}

template <typename E>
const E& SingleLL<E>::back() const
{
	return tail->elem;
}

template <typename E>
void SingleLL<E>::addFront(const E& e)
{
	if (head == NULL)
	{
		head = new SNode<E>;
		head->next = NULL;
		head->elem = e;
		tail = head;
	}
	else
	{
		SNode<E>* v = new SNode<E>;
		v->elem = e;
		v->next = head;
		head = v;

	}
	count = count + 1;
}

template <typename E>
void SingleLL<E>::removeFront()
{
	if (count == 0)
	{
		head = NULL;
		tail = NULL;
	}
	if (head == NULL)
	{
		cout << "head is NULL" << endl;
	}
	else
	{
		SNode<E>* old = head;
		head = old->next;
		delete old;
	}
	count = count - 1;
}

template <typename E>
void SingleLL<E>::addBack(const E& e)
{
	SNode<E>* a = new SNode<E>;
	if (tail == NULL)
	{
		tail = a;
		a->elem = e;
		a->next = NULL;
		head = tail;
	}
	else
	{
		a->elem = e;
		a->next = NULL;
		tail->next = a;
		tail = a;
	}
	count = count + 1;
}

template <typename E>
void SingleLL<E>::removeBack()
{
	SNode<E>* h = head;
	SNode<E>* t = tail;
	if (h != tail)
	{
		while (h->next != tail)
		{
			h = h->next;
		}
		tail = h;
		h->next = NULL;
		delete t;
	}
	else
	{
		delete t;
	}
	count = count - 1;
}

template <typename E>
int SingleLL<E>::size() const
{
	return count;
}