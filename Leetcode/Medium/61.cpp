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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        int i = 1;
        ListNode *cur=head;
        while(cur && cur->next){
            cur = cur->next;
            i++;
        }
        
        int toreach = i - (k%i);
        int c = 1;
        cur->next = head;
        ListNode *nex = head;
        while(nex && nex->next && c<toreach){
            nex = nex->next;
            c++;
        }
        
        head = nex->next;
        nex->next = nullptr;
        
        return head;
    }
};