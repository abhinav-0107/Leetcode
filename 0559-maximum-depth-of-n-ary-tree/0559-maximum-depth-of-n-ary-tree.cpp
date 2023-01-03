/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int depth(Node* curr){
        if(!curr) return 0;
        int d = 0;
        for(auto child : curr->children) d = max(d , depth(child) + 1);
        return d;
    }

    int maxDepth(Node* root) {
        if(!root) return 0;
        return depth(root) + 1;
    }
};