//#include <iostream>
//#include <string>
//using namespace std;
//
//class node
//{
//public:
//	int key;
//	int value;
//};
//
//class tree
//{
//private:
//	node arrayOfNodes[255];
//
//public:
//	tree()
//	{
//		for (int i = 0; i<256; i++)
//		{
//			arrayOfNodes[i].key = NULL;
//			arrayOfNodes[i].value = NULL;
//		}
//	}
//
//	bool insert(node n, int i = 0)
//	{
//		node current = arrayOfNodes[i];
//		if (current.key == NULL) { arrayOfNodes[i].key = n.key; arrayOfNodes[i].value = n.value; }
//		else if (current.key == n.key) return false;
//		else if (n.key < current.key) return insert(n, 2 * i + 1);
//		else if (n.key > current.key) return insert(n, 2 * i + 2);
//	}
//
//	void print()
//	{
//		int i = 0;
//		while (i<100)
//		{
//			node n = arrayOfNodes[i++];
//			cout << n.key << " ";
//		}
//		cout << "\n";
//	}
//
//	bool deletenode(int key, int n = 0)
//	{
//		int i = findPos(key, n); //position of the node to be deleted
//		if (i == -1 || arrayOfNodes[i].key == NULL) return false;
//		else
//		{
//			arrayOfNodes[i].key = NULL; arrayOfNodes[i].value = NULL; //deleting the node
//			if ((arrayOfNodes[2 * i + 2]).key == NULL)
//			{
//				if ((arrayOfNodes[2 * i + 1]).key != NULL) //if the node has only left child
//				{
//					int k = 2 * i + 1; int a[100];
//					for (int iter = 0; iter < 100; iter++) a[iter] = NULL;
//					a[0] = k; int index = 0;
//					//doing a bfs to discover the nodes in the left subtree to move it to the deleted nodes's position
//					for (int iter = 0; a[iter] != NULL && iter < 100; iter++)
//					{
//						for (int x = 0; x < 100; x++)
//						{
//							if (isPowerOfTwo(a[iter] + 1 - x))
//							{
//								arrayOfNodes[(a[iter] + x - 1) / 2] = arrayOfNodes[a[iter]];
//								arrayOfNodes[a[iter]].key = NULL; arrayOfNodes[a[iter]].value = NULL;
//								break;
//							}
//						}
//						if (arrayOfNodes[2 * a[iter] + 1].key != NULL)
//						{
//							a[++index] = 2 * a[iter] + 1;
//						}
//						if (arrayOfNodes[2 * a[iter] + 2].key != NULL)
//						{
//							a[++index] = 2 * a[iter] + 2;
//						}
//					}
//				}
//			}
//			else
//			{
//				if ((arrayOfNodes[2 * i + 1]).key == NULL) //if the node has only right child
//				{
//					int k = 2 * i + 2; int a[100];
//					for (int iter = 0; iter < 100; iter++) a[iter] = NULL;
//					a[0] = k; int index = 0;
//					//doing a bfs to discover the nodes in the right subtree to move it to the deleted nodes's position
//					for (int iter = 0; a[iter] != NULL && iter < 100; iter++)
//					{
//						for (int x = 0; x < 100; x++)
//						{
//							if (isPowerOfTwo((a[iter] + x) / 2 + 1))
//							{
//								arrayOfNodes[(a[iter] - 2 - x) / 2] = arrayOfNodes[a[iter]];
//								break;
//							}
//						}
//						arrayOfNodes[a[iter]].key = NULL; arrayOfNodes[a[iter]].value = NULL;
//						if (arrayOfNodes[2 * a[iter] + 1].key != NULL)
//						{
//							a[++index] = 2 * a[iter] + 1;
//						}
//						if (arrayOfNodes[2 * a[iter] + 2].key != NULL)
//						{
//							a[++index] = 2 * a[iter] + 2;
//						}
//					}
//				}
//				else //if the node has both children
//				{
//					int x = findPosOfMin(2 * i + 2);
//					node toBeCopied = arrayOfNodes[x];
//					(arrayOfNodes[i]).key = toBeCopied.key;
//					(arrayOfNodes[i]).value = toBeCopied.value;
//					deletenode(toBeCopied.key, x);
//				}
//			}
//		}
//	}
//
//	bool isPowerOfTwo(int x)
//	{
//		while (((x % 2) == 0) && x > 1) /* While x is even and > 1 */
//			x /= 2;
//		return (x == 1);
//	}
//
//	int findPosOfMin(int i = )
//	{
//		if (2 * i + 1 > 100) return i;
//		else if (arrayOfNodes[2 * i + 1].key == NULL) return i;
//		else return findPosOfMin(2 * i + 1);
//	}
//
//	int findPos(int key, int i = 1)
//	{
//		node current = arrayOfNodes[i];
//		if (i > 100 || current.key == NULL) return -1;
//		if (current.key == key) return i;
//		else if (key < current.key) return findPos(key, 2 * i + 1);
//		else if (key > current.key) return findPos(key, 2 * i + 2);
//	}
//
//	node find(int key, int i = 1)
//	{
//		node current = arrayOfNodes[i];
//		if (i > 100 || current.key == NULL) return current;
//		if (current.key == key) return current;
//		else if (key < current.key) return find(key, 2 * i + 1);
//		else if (key > current.key) return find(key, 2 * i + 2);
//	}
//};
//
//int main() // by default
//{
//	tree t;
//	int c;
//	while (1)
//	{
//		cin >> c;
//		if (c > 0)
//		{
//			node n; //memory leak?
//			t.insert(n);
//		}
//		else if (c < 0)
//		{
//			int key;
////			cout << "Enter key\n"; cin >> key;
//			node n = t.find(value);
//			if (n.key != NULL)
//				cout << "Value is " << n.value << "\n";
//			else
//				cout << "Node doesn't exist\n";
//		}
//		//else if (c == 0)
//		//{
//		//	int key;
//		//	cout << "Enter key\n"; cin >> key;
//		//	t.deletenode(key);
//		//}
//		else if (c == 0)
//		{
//			t.print();
//			return 0;
//		}
//		//cout << "Do you want to continue? Y/N \n";
//		//cin >> c;
//	}
////	cin.get();
//	return 0;
//}