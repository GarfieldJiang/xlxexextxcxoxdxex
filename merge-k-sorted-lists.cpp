// https://leetcode.com/problems/merge-k-sorted-lists/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#define SWAP(a, b) { auto tmp = (a); (a) = (b); (b) = tmp; }

// Slow but accepted.
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0) return 0;
        auto head = lists[0];
        for (int i = 1; i < k; i++) {
            head = merge2Lists(lists[i], head);
        }
        return head;
    }
    
private:
    ListNode* merge2Lists(ListNode* headA, ListNode* headB) {
        if (!headA) return headB;
        if (!headB) return headA;
        
        ListNode* head = 0;
        if (headA->val > headB->val) {
            SWAP(headA, headB);
        }
        
        head = headA;
        auto prevA = headA;
        headA = headA->next;
        while (headB) {
            if (!headA) {
                prevA->next = headB;
                break;
            }
            
            auto cacheHeadB = headB;
            ListNode* prevB = 0;
            while (headB && headB->val <= headA->val) {
                prevB = headB;
                headB = headB->next;
            }
            
            if (prevB) {
                prevA->next = cacheHeadB;
                prevB->next = headA;
            }
                        
            prevA = headA;
            headA = headA->next;
        }
        
        return head;
    }
};
