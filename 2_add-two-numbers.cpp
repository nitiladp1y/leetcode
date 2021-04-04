/*
给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。

你可以假设除了数字 0 之外，这两个数字都不会以零开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* 44 ms */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	ListNode *head = NULL;
    	ListNode *tail = NULL;
    	bool carry = false;
        while(l1 || l2 || carry)
        {
        	int value = 0;
        	if (l1)
        	{
        		value += l1->val;
        		l1 = l1->next;
        	}
			if (l2)
        	{
        		value += l2->val;
        		l2 = l2->next;
        	}
        	if(carry)
        	{
				++value;
				carry = false;        		
        	}
        	if (value >= 10)
        	{
        		value = value % 10;
        		carry = true;
        	}
        	ListNode *tmp = new ListNode(value);
        	if (head)
        	{
        		tail->next = tmp;
        		tail = tmp;
        	}
        	else
        	{
        		head = tmp;
        		tail = tmp;
        	}
		}
		return head;
    }
};