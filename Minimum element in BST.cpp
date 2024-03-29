 int minValue(Node* root) {
        // Code here
        
        // Time Complexity -> O(height of tree)
        // Space Complexity -> O(1)
        
        if(root == nullptr)
            return -1;
        
        while(root->left)
            root = root->left;
        
        return root->data;
    }
