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