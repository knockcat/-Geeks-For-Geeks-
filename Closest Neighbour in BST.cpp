
//Naive Approach
void inorder(Node* root, int& ans, int n)
    {
        if(root)
        {
            inorder(root->left, ans, n);
            if(root->key <= n)
                ans = max(ans, root->key);
            inorder(root->right, ans, n);
        }
    }
  
    int findMaxForN(Node* root, int n) {
        // code here
        
        // Time Complexity -> O(n);
        // Space Complexity -> O(height); recursion stack
        
        int ans = -1;
        
        inorder(root, ans, n);
        
        return ans;
    }


// _____________________________________________________________


// Expected Appraoch
int findMaxForN(Node* root, int n) {
        // code here
        
        // if(follow)
        //     update ans, move to right
        // else
        //     move to left // smaller
        
        // Time Complexity -> O(height of tree)
        // Space Complexity ->  O(1)
        
        int ans = -1;
        
        while(root)
        {
            if(root->key <= n)
            {
                ans = root->key;
                root = root->right;
            }
            else
                root = root->left;
        }
        
        return ans;
    }
