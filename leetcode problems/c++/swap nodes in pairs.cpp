// Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

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

// time complexity: O(n)
// space complexity: O(1) 

class Solution {
public:
    ListNode* swapPairs(ListNode* head) { 
        if(head == NULL || head->next == NULL) return head;
        ListNode* newHead = head->next;
        ListNode* cur = head;
        ListNode* pre = NULL;
        while(cur != NULL && cur->next != NULL){
            ListNode* next = cur->next;
            cur->next = next->next;
            next->next = cur;
            if(pre != NULL) pre->next = next;
            pre = cur;
            cur = cur->next;
        }
        return newHead;
    }
    };
