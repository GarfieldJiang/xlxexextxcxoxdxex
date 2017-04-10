// https://leetcode.com/problems/add-two-numbers/#/description

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL, *prev = NULL, *cur = NULL;
        int carry = 0;
        while (l1 || l2 || carry) {
            int newValue;
            newValue = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            cur = l1 ? l1 : l2 ? l2 : new ListNode(0);
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
            carry = newValue / 10;
            cur->val = newValue % 10;
            cur->next = NULL;
            prev ? (prev->next = cur) : (head = cur);
            prev = cur;
        }

        return head;
    }
};
