#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
};

void getElements(ListNode *node, vector<int>& elements){
	ListNode* p = node;
	if (p == NULL)
	{
		return;
	}
	while(p != NULL)
	{
		elements.push_back(p->m_nKey);
		p = p->m_pNext;
	}
}

int main(){
	int num;
	vector<int> elements;
	ListNode* pHead = NULL;
	ListNode* pLast = NULL;
	cout << "How many?" << endl;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		ListNode* node = new ListNode();
		node->m_nKey = i;
		if (i == num - 1)
		{
			node->m_pNext = NULL;
		}
		if (i == 0)
		{
			pLast = node;
			pHead = node;
		}
		else
		{
			pLast->m_pNext = node;
			pLast = node;
		}
	}
	getElements(pHead, elements);
	for (int i = 0 ; i < elements.size(); i++)
	{
		cout<<elements[elements.size() - 1 - i]<<endl;
	}
	getchar();
	return 0;
}