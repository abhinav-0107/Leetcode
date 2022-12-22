//Brute Force

// class Solution {
// public:
//     int maxi=0;
//     void dfs(TreeNode* curr){
//         if(!curr) return;
//         int lh=height(curr->left);
//         int rh=height(curr->right);
//         maxi=max(maxi,lh+rh);
//         dfs(curr->left);
//         dfs(curr->right);
//     }

//     int height(TreeNode* node){
//         if(!node) return 0;
//         int lh=height(node->left);
//         int rh=height(node->right);
//         return 1+max(lh,rh);
//     }
    
//     int diameterOfBinaryTree(TreeNode* root) {
//         dfs(root);
//         return maxi;
//     }
// };

// Optimal

class Solution {
public:
    int maxi=0;
    int diameter(TreeNode* curr){
        if(!curr) return 0;
        int lh=diameter(curr->left);
        int rh=diameter(curr->right);
        maxi=max(maxi,lh+rh);
        return 1+max(lh,rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int temp= diameter(root);
        return maxi;
    }
};