#include "../include/12_SortList.h"

ListNode* FunGetHalfPart(ListNode* head, ListNode* end)
{
	int pivot = head->val;
	ListNode* p = head;
	ListNode* q = p->next;
	int tmp;

	while (q != end)
	{
		if (q->val < pivot)
		{
			p = p->next;
			tmp = p->val;
			p->val = q->val;
			q->val = tmp;
		}
		q = q->next;
	}
	tmp = p->val;
	p->val = head->val;
	head->val = tmp;

	return p;
}

void FunQuickSort(ListNode* head, ListNode* end)
{
	if (head != end)
	{
		ListNode *newPart = FunGetHalfPart(head, end);
		FunQuickSort(head, newPart);
		FunQuickSort(newPart->next, end);
	}
}

ListNode* SortList(ListNode* head)
{
	FunQuickSort(head, nullptr);
	return head;
}