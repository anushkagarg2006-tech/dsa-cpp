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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* pos = head;
        while (pos != nullptr) {
            pos = pos->next;
            len++;
        }
        if (len == n){
            head = head->next;
        return head;}
        len = len - n;
        pos = head;
        ListNode* prev;
        while (len != 0) {
            prev = pos;
            pos = pos->next;
            len--;
        }
        if (n == 1) {
            prev->next = nullptr;

        } else {
            prev->next = prev->next->next;
        }delete pos;
        return head;
    }
};