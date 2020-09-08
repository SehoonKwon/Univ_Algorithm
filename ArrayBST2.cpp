//#include <iostream>
//#include <cstdlib>
//using namespace std;
//
////US
//class BinarySearchTree
//{
//private:
//	int count = 0;
//	int elem[512] = { 0 }; //because this is not balanced tree, so we need to size of 2^0 + 2^1 + ... + 2^7 = 255, and there is no value in index 0, so plus 1
//						   // =256
//						   // 
//public:
//	void insert(int);
//	void remove(int);
//	int search(int);
//	int getIndex(int);
//	void replace_R(int, int);
//	void replace_L(int, int);
//	void print(void);
//};
//void BinarySearchTree::print(void)
//{
//	for (int i = 1; i < 256; i++)
//	{
//		if (elem[i] != 0) cout << elem[i] << " ";
//	}
//}
//
//void BinarySearchTree::replace_R(int k, int m) //right child
//{
//	if (k < 256)
//	{
//		if (elem[2 * k] == 0 && elem[2 * k + 1] != 0)
//		{
//			elem[2 * m + 1] = elem[2 * k + 1];
//			elem[2 * k + 1] = 0;
//			replace_R(2 * k + 1, 2 * m + 1);
//		}
//		else if (elem[2 * k] != 0 && elem[2 * k + 1] == 0)
//		{
//			elem[2 * m] = elem[2 * k];
//			elem[2 * k] = 0;
//			replace_L(2 * k, 2 * m);
//		}
//		else if (elem[2 * k] != 0 && elem[2 * k + 1] != 0)
//		{
//			elem[2 * m] = elem[2 * k];
//			elem[2 * m + 1] = elem[2 * k + 1];
//			elem[2 * k] = 0;
//			elem[2 * k + 1] = 0;
//			replace_L(2 * k, 2 * m);
//			replace_R(2 * k + 1, 2 * m + 1);
//		}
//		else return;
//	}
//}
//
//void BinarySearchTree::replace_L(int k, int m)//left child
//{
//	if (k < 256)
//	{
//		if (elem[2 * k] == 0 && elem[2 * k + 1] != 0)
//		{
//			elem[2 * m + 1] = elem[2 * k + 1];
//			elem[2 * k + 1] = 0;
//			replace_R(2 * k + 1, 2 * m + 1);
//		}
//		else if (elem[2 * k] != 0 && elem[2 * k + 1] == 0)
//		{
//			elem[2 * m] = elem[2 * k];
//			elem[2 * k] = 0;
//			replace_L(2 * k, 2 * m);
//		}
//		else if (elem[2 * k] != 0 && elem[2 * k + 1] != 0)
//		{
//			elem[2 * m] = elem[2 * k];
//			elem[2 * m + 1] = elem[2 * k + 1];
//			elem[2 * k] = 0;
//			elem[2 * k + 1] = 0;
//			replace_L(2 * k, 2 * m);
//			replace_R(2 * k + 1, 2 * m + 1);
//		}
//		else return;
//	}
//}
//int BinarySearchTree::getIndex(int d)
//{
//	int k = 1;
//	while (k<256)
//	{
//		if (d > elem[k])
//		{
//			k = 2 * k + 1;
//		}
//		else if (d < elem[k])
//		{
//			k = 2 * k;
//		}
//		else return k;
//	}
//	return 0;
//}
//int BinarySearchTree::search(int d)
//{
//	int k = 1;
//	while (k<256)
//	{
//		if (d < elem[k])
//		{
//			k = 2 * k;
//		}
//		else if (d > elem[k])
//		{
//			k = 2 * k + 1;
//		}
//		else return d;
//	}
//	return 0;
//}
//
//void BinarySearchTree::insert(int d)
//{
//	int k = 1; // test index
//
//	while (elem[k] != 0 && k < 256)
//	{
//		//Note: ALL insertions are as leaf nodes
//		if (d > elem[k])
//		{
//			k = 2 * k + 1;
//		}
//		else
//		{
//			k = 2 * k;
//		}
//	}
//	if (k < 256)
//	{
//		elem[k] = d;
//	}
//}
//
//void BinarySearchTree::remove(int d)
//{
//	int sch, k, rep_k;
//	sch = search(d);
//	if (sch == 0) cout << sch << endl;
//
//	else
//	{
//		count--;
//		cout << sch << endl;
//		k = getIndex(d);
//		if ((elem[2 * k] == 0 && elem[2 * k + 1] != 0) || (elem[2 * k] != 0 && elem[2 * k + 1] == 0))// removing a node with a single child
//		{
//			if (elem[2 * k] == 0 && elem[2 * k + 1] != 0)
//			{
//				elem[k] = elem[2 * k + 1];
//				elem[2 * k + 1] = 0;
//				replace_R(2 * k + 1, k);
//			}
//			else // left child present, no right child
//			{
//				elem[k] = elem[2 * k];
//				elem[2 * k] = 0;
//				replace_L(2 * k, k);
//			}
//			return;
//		}
//
//		//We're looking at a leaf node
//		else if (elem[2 * k] == 0 && elem[2 * k + 1] == 0)//removing a leaf node
//		{
//			elem[k] = 0;
//		}
//
//
//		//Node with 2 children
//		// replace node with smallest value in right subtree
//
//		else if (elem[2 * k] != 0 && elem[2 * k + 1] != 0)// removing a node with 2 children
//		{
//			rep_k = 2 * k + 1;
//			if ((elem[2 * rep_k] == 0) && (elem[2 * rep_k + 1] == 0)) //right child doesn't have a child
//			{
//				elem[(rep_k - 1) / 2] = elem[rep_k];
//				elem[rep_k] = 0;
//			}
//			else // right child has children
//			{
//				//if the node's right child has a left child
//				// Move all the way down left to locate smallest element
//
//				if (elem[2 * rep_k] != 0)
//				{
//					rep_k = 2 * rep_k;
//					while (rep_k < 256) //find a smallest child
//					{
//						if (elem[2 * rep_k] != 0)
//						{
//							rep_k = 2 * rep_k;
//						}
//					}
//					elem[k] = elem[rep_k];
//					elem[rep_k] = 0;
//					if ((elem[2 * rep_k + 1] != 0) && ((2 * rep_k + 1) < 256)) //smallest elem has a right child
//					{
//						replace_R(2 * rep_k + 1, rep_k);
//						elem[2 * rep_k + 1] = 0;
//					}
//
//				}
//				else
//				{
//					rep_k = 2 * rep_k + 1;
//					while (rep_k < 256) //find a smallest child
//					{
//						if (elem[2 * rep_k] != 0)
//						{
//							rep_k = 2 * rep_k;
//						}
//					}
//					elem[k] = elem[rep_k];
//					elem[rep_k] = 0;
//					if ((elem[2 * rep_k + 1] != 0) && ((2 * rep_k + 1) < 256)) //smallest elem has a right child
//					{
//						replace_R(2 * rep_k + 1, rep_k);
//						elem[2 * rep_k + 1] = 0;
//					}
//				}
//
//			}
//			return;
//		}
//	}
//
//}
//
//
//int main()
//{
//	BinarySearchTree b;
//	int ch;
//	while (1)
//	{
//		cin >> ch;
//		if (ch > 0) b.insert(ch);
//		else if (ch < 0) b.remove(-ch);
//		else
//		{
//			b.print();
//			break;
//		}
//	}
//}