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
    ListNode *detectCycle(ListNode *head) {
        if(!head)return NULL;
        map<ListNode*,int>mp;
        ListNode* curr=head;
        while(!mp[curr]){
            mp[curr]++;
            curr=curr->next;
            if(!curr){
                return NULL;
            }
        }
        return curr;
    }
};