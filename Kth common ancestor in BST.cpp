class Solution
{
    public:
    
    /*You are required to complete below function */
    
    Node* lowestCommonAncestor(Node*root, int x, int y)
    {
        if(!root)
            return nullptr;
        if(x < root->data and y < root->data)
            return lowestCommonAncestor(root->left, x, y);
        if(x > root->data and y >  root->data)
            return lowestCommonAncestor(root->right, x, y);
        return root;
    }
    
    void getPath(Node* root, Node* lca, vector<int>& path)
    {
        while(root->data != lca->data)
        {
            path.push_back(root->data);
            
            if(lca->data > root->data)
                root = root->right;
            else
                root = root->left;
        }
        
        path.push_back(lca->data);
    }
    
    int kthCommonAncestor(Node *root, int k,int x, int y)
    {
        // your code goes here
        
        // Time Complexity -> (height of bst)
        // Space Complexity -> (height of bst)
        
        // 1st step
        Node* lca = lowestCommonAncestor(root, x, y); 
        
        // 2nd step
        // all nodes in the path from root to lca
        vector<int> path;
        getPath(root, lca, path);
        
        reverse(path.begin(), path.end()); // O(height of tree)
        
        // 3rd step
        if(k > path.size())
            return -1;
        return path[k-1];
        
    }
};
