//#include <iostream>
//using namespace std;
//
//class BST
//{
//private:
//	int elem[512];
//	int tn = 1;
//
//public:
//	BST();
//	int getIndex(int n);
//	int Search(int n);
//	void Insert(int n);
//	void remove(int);
//	void replace_R(int, int);
//	void replace_L(int, int);
//	void PrintBST();
//};
//
//
//BST::BST()
//{
//	for (int i = 0; i < 256; i++) BST::elem[i] = 0;
//}
//
//void BST::PrintBST()
//{
//	for (int i = 1; i < 256; i++)
//	{
//		if (elem[i] == 0) continue;
//		cout << elem[i] << " ";
//	}
//}
//
//
//int BST::getIndex(int n)
//{
//	int index;
//
//	for (int i = 1; i < 256; i++)
//	{
//		if (elem[i] == n)
//		{
//			index = i;
//			break;
//		}
//	}
//	return index;
//}
//
//int BST::Search(int n)
//{
//	//if (elem[tn] == 0)
//	//{
//	//	return 0;
//	//}
//
//	//if (elem[tn] == n)
//	//{
//	//	return n;
//	//}
//
//	//else if (elem[tn] > n)
//	//{
//	//	tn = tn * 2;
//	//	Search(n);
//
//	//}
//	//else if (elem[tn] < n)
//	//{
//	//	tn = tn * 2 + 1;
//	//	Search(n);
//	//}
//
//	int k = 1;
//	while (k<256)
//	{
//		if (n < elem[k])
//		{
//			k = 2 * k;
//		}
//		else if (n > elem[k])
//		{
//			k = 2 * k + 1;
//		}
//		else return n;
//	}
//	return 0;
//
//}
//
//void BST::Insert(int n)
//{
//	if (elem[tn] == 0)
//	{
//		elem[tn] = n;
//	}
//
//	else if (elem[tn] > n)
//	{
//		tn = tn * 2;
//		Insert(n);
//	}
//
//	else if (elem[tn] < n)
//	{
//		tn = tn * 2 + 1;
//		Insert(n);
//	}
//
//	if (tn != 1) tn = 1;
//
//	//int k = 1; // test index
//
//	//while (elem[k] != 0 && k < 256)
//	//{
//	//	//Note: ALL insertions are as leaf nodes
//	//	if (n > elem[k])
//	//	{
//	//		k = 2 * k + 1;
//	//	}
//	//	else
//	//	{
//	//		k = 2 * k;
//	//	}
//	//}
//	//if (k < 256)
//	//{
//	//	elem[k] = n;
//	//}
//}
//
//void BST::replace_R(int k, int m) //right child
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
//void BST::replace_L(int k, int m)//left child
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
//
//void BST::remove(int d)
//{
//
//	int sch, k, rep_k;
//	sch = Search(d);
//	if (sch == 0) cout << sch << endl;
//
//	else
//	{
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
//	BST b;
//	int ch;
//	while (1)
//	{
//		cin >> ch;
//		if (ch > 0) b.Insert(ch);
//		else if (ch < 0) b.remove(-ch);
//		else
//		{
//			b.PrintBST();
//			break;
//		}
//	}
//
//}