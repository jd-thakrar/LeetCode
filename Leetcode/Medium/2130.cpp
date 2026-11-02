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
    int pairSum(ListNode* head) {
     vector<int> res;
     while(head != nullptr){
        res.push_back(head->val);
        head = head->next;
     }   

     int l = 0, r = res.size() - 1, ans = 0;

     while(l<r){
        ans = max(ans, res[l] + res[r]);
        l++;
        r--;
     }

     return ans;
    }
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
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode *slow = head,* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *cur=slow, *prev=nullptr, *nex;
        while(cur) {
            nex=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nex;
        }
        int ans =0;
        while(prev){
            ans = max(ans, prev->val + head->val);
            prev = prev->next;
            head = head->next;
        }
        return ans;
    }
};