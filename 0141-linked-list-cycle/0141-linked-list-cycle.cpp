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
    bool hasCycle(ListNode *head) {
        ListNode* curr=head;
        if(head==NULL){
            return false;
        }
        map<ListNode*,int>mp;
        while(mp[curr]==0){
            mp[curr]++;
            curr=curr->next;
            if(curr==NULL){
                return false;
            }
        }
        // cout<<curr->val;
        return true;
    }
};