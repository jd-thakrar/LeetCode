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

        int total = 0;
        ListNode* hd = head;
        while (hd) {
            total++;
            hd = hd->next;
        }

        int nidx = total - n;
        if (nidx == 0)
            return head->next;
        int i = 0;
        ListNode *prev = nullptr, *cur = head;
        while (cur) {

            if (i == nidx) {
                prev->next = cur->next;
                return head;
            }
            prev = cur;
            cur = cur->next;
            i++;
        }
        return head;
    }
};