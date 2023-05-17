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
    int i=0;
    void rev(ListNode* curr,vector<int>& v){
        if(curr==NULL)return;
        v.push_back(curr->val);
        rev(curr->next,v);
        v[i]+=curr->val;
        i++;
    }
    
    int pairSum(ListNode* head) {
        ListNode* curr=head;
        vector<int>v;
        rev(curr,v);
        return *max_element(v.begin(),v.end());
    }
};