int findCeil(Node* root, int key) {
    if (!root) return -1;
    int ceil=INT_MAX;
    while(root){
        if(root->data==key){
            ceil=key;
            break;
        }    
        else if(root->data>key){
            ceil=min(ceil,root->data);
            root=root->left;
        }    
        else root=root->right;
    }
    return ceil;
}
