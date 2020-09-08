//#include <iostream>
//using namespace std;
//
//#define SIZE 500
//
//struct Node {
//	int elem;
//	struct Node* left;
//	struct Node* right;
//};
//
//struct Node* newNode(int elem);
//struct Node* Insert(struct Node* root, int elem);
//struct Node* Delete(struct Node* root, int elem);
//struct Node* FindMax(struct Node* root);
//struct Node* FindMin(struct Node* root);
//int FindElem(struct Node* root, int elem);
//void PrintElem(struct Node* BST);
//
//int main()
//{
//	//Build
//	struct Node* BST = newNode(SIZE / 2);
//	
//	//Insert
//	for (int i = 0; i < 10; i++)
//	{
//		int elem = rand() % SIZE;
//		Insert(BST, elem);
//	}
//
//	//Print
//	PrintElem(BST);
//	cout << endl;
//
//	//Delete
//	for (int i = 0; i < 10; i++)
//	{
//		int elem = rand() % SIZE;
//		BST = Delete(BST, elem);
//	}
//
//	cout << "After Delete" << endl;
//	PrintElem(BST);
//	cout << endl;
//
//	return 0;
//}
//
//struct Node* newNode(int elem)
//{
//	Node* root = new Node();
//	root->elem = elem;
//	root->left = root->right = NULL;
//	return root;
//}
//
//struct Node* Insert(struct Node* root, int elem)
//{
//
//	if (root == NULL) // if root doesn't exist, Make root
//	{
//		root = newNode(elem);
//	}
//	else
//	{
//		if (root->elem > elem) // if inserting elem is smaller than root elem, insert left
//			root->left = Insert(root->left, elem);
//		else if (root->elem < elem) //if inserting elem is bigger than root elem, insert right
//			root->right = Insert(root->right, elem);
//	}
//	
//	return root;
//}
//
//struct Node* Delete(struct Node* root, int elem)
//{
//	if (root == NULL) // if root doesn't exist, return.
//		return NULL;
//	
//	//find elem node
//	else if (root->elem > elem) 
//		root->left = Delete(root->left, elem);
//	else if (root->elem < elem)
//		root->right = Delete(root->right, elem);
//	
//	//if find elem, do delete
//	else
//	{
//		if (root->left == NULL && root->right == NULL) // if node is leaf node
//		{
//			delete root;
//			root = NULL;
//			return root;
//		}
//
//		else if (root->left || root->right)
//		{
//			struct Node* temp = NULL;
//
//			if (root -> left)
//			{
//				temp = FindMax(root->left);
//				root->elem = temp->elem;
//				root->left = Delete(root->left, root->elem);
//			}
//
//			else
//			{
//				temp = FindMin(root->right);
//				root->elem = temp->elem;
//				root->right = Delete(root->right, root->elem);
//			}
//		}
//	}
//	return root;
//}
//
//struct Node* FindMax(struct Node* root)
//{
//	if (root->right)	return FindMax(root->right);
//	else return root;
//}
//
//struct Node* FindMin(struct Node* root)
//{
//	if (root->left) return FindMin(root->left);
//	else return root;
//}
//
//int FindElem(struct Node* root, int elem)
//{
//	if (root == NULL) return -1; // -1 means false
//	else if (root->elem > elem) return FindElem(root->left, elem);
//	else if (root->elem < elem) return FindElem(root->right, elem);
//	else if (root->elem == elem) return 1; // 1 means true
//}
//
//void PrintElem(struct Node* BST)
//{
//	if (BST == NULL) return;
//	if (BST->left != NULL) PrintElem(BST->left);
//	cout << BST->elem << " ";
//	if (BST->right != NULL) PrintElem(BST->right);
//}