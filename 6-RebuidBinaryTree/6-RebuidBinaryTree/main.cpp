#include <iostream>
#include <vector>
using namespace std;

struct BinaryTreeNode
{
	int				 m_nValue;
	BinaryTreeNode*  m_pLeft;
	BinaryTreeNode*	 m_pRight;
};

BinaryTreeNode* RebuildBinaryTree(int* preStart, int* preEnd, int* midStart, int* midEnd){
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nValue = *preStart;
	root->m_pLeft = NULL;
	root->m_pRight = NULL;

	if (preStart == preEnd && midStart == midEnd && *preStart == *midStart)
	{
		return root;
	}
	int* midIndex = midStart;
	int length = 0;
	while (midIndex <= midEnd)
	{
		if (*midIndex == *preStart)
		{
			break;
		}
		midIndex++;
	}
	length = midIndex - midStart;
	if (midIndex > midEnd)
	{
		printf("Invalid input Value!!\n");
		return NULL;
	}
	if (length > 0)
		root->m_pLeft = RebuildBinaryTree(preStart + 1, preStart + length, midStart, midIndex - 1);
	if (length < (preEnd - preStart))
		root->m_pRight = RebuildBinaryTree(preStart + length + 1, preEnd, midIndex + 1, midEnd);
	return root;
}

int main()
{
	int preOrder[8] = {1,2,4,7,3,5,6,8};
	int midOrder[8] = {4,7,2,1,5,3,8,6};

	if (preOrder != NULL && midOrder != NULL && sizeof(preOrder)/sizeof(int) != 0 && sizeof(midOrder)/sizeof(int) != 0)
	{
		BinaryTreeNode* rebuidTree = RebuildBinaryTree(preOrder, preOrder + sizeof(preOrder)/sizeof(int) - 1, midOrder, midOrder + sizeof(midOrder)/sizeof(int) - 1);
	}
	return 0;
}