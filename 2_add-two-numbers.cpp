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
        ListNode *tmp_l1 = l1;
        ListNode *tmp_l2 = l2;
    	bool carry = false;
        while(tmp_l1 || tmp_l2 || carry)
        {
        	int value = 0;
        	if (tmp_l1)
        	{
        		value += tmp_l1->val;
        		tmp_l1 = tmp_l1->next;
        	}
			if (tmp_l2)
        	{
        		value += tmp_l2->val;
        		tmp_l2 = tmp_l2->next;
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