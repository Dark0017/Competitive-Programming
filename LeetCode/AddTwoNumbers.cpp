#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

int getListLength(ListNode* head)
{
	if (head == NULL)
		return 0;

	ListNode* headNode = head;
	int length{ 0 };

	while (headNode != NULL)
	{
		length++;
		headNode = headNode->next;
	}

	return length;

}



void setNodesToZero(ListNode* head, int nNodes)
{

	


	ListNode* headNode = head;

	while (headNode->next != NULL)
	{
		headNode = headNode->next;
	}

	nNodes--; //loop will run until nNodes is zero but we're counting length from 1
	do {
		ListNode* node = new ListNode;
		node->val = 0;
		node->next = NULL;
		headNode->next = node;
		headNode = headNode->next;
	} while (nNodes--);
}

void printList(ListNode* head)
{
	ListNode* headNode = head;

	while (headNode != NULL)
	{
		cout << headNode->val << " ";
		headNode = headNode->next;
	}
}

ListNode* makeListFromArr(vector<int> arr)
{
	ListNode* head = new ListNode;
	head->val = arr[0];

	ListNode* headNode = head;

	for (int i{ 1 }; i < arr.size(); i++)
	{
		ListNode* node = new ListNode;
		node->val = arr[i];
		node->next = NULL;

		headNode->next = node;
		headNode = node;
	}

	return head;
}

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

		int lengthL1 = getListLength(l1);
		int lengthL2 = getListLength(l2);

		if (lengthL1 > lengthL2)
		{
			setNodesToZero(l2, lengthL1 - lengthL2);
			lengthL2 = lengthL1;
		}
		if (lengthL1 < lengthL2)
		{
			setNodesToZero(l1, lengthL2 - lengthL1);
			lengthL1 = lengthL2;
		}
		vector<int> result(lengthL1, 0);
		vector<int> carry(lengthL1 + 1, 0);

		ListNode* head1 = l1;
		ListNode* head2 = l2;

		for (int i{ 0 }; i < lengthL1; i++)
		{
			int res{ 0 };
			res = head1->val + head2->val + carry[i];
			
			if (res > 9)
			{
				carry[i + 1] = res / 10; 
				res = res - ((res / 10) * 10);
			}

			result[i] = res;
			head1 = head1->next;
			head2 = head2->next;
		}

		if (carry[lengthL1] > 0)
		{
			result.resize(lengthL1 + 1);
			result[lengthL1] = carry[lengthL1];
		}

		return makeListFromArr(result);
	}
};

