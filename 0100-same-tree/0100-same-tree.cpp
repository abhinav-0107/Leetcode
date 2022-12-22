//Brute Force

// class Solution {
// public:
//     void preorder(TreeNode* Node, vector<int>&V){
//         if(Node==NULL){
//             V.push_back(INT_MIN);
//             return ;
//         }
//         V.push_back(Node->val);
//         preorder(Node->left,V);
//         preorder(Node->right,V);
//     }
    
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         vector<int>v1,v2;
//         preorder(p,v1);
//         preorder(q,v2);
//         return v1==v2;
//     }
// };


//Optimal

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p || !q) return p==q;
        return (p->val==q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};