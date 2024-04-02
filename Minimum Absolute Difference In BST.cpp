// Naive Approach

class Solution
{
    public:
    
    void inorder(Node* root, vector<int>& v)
    {
        if(root)
        {
            inorder(root->left, v);
            v.push_back(root->data);
            inorder(root->right, v);
        }
    }
    
    int absolute_diff(Node *root)
    {
        //Your code here
        
        vector<int> v;
        
        inorder(root, v);
        
        int res = INT_MAX;
        
        for(int i = 1; i < v.size(); ++i)
            res = min(res, v[i] - v[i-1]);
            
        return res;
    }
};

// Expected Approach

class Solution
{
    public:
    
    void inorder(Node* root, Node*& prev, int& ans)
    {
        if(root)
        {
            inorder(root->left, prev, ans);
            
            if(prev)
            ans = min(ans, root->data - prev->data);
            
            prev = root;
            
            inorder(root->right, prev, ans);
        }
    }
    
    int absolute_diff(Node *root)
    {
        //Your code here
        
        // Time Complexity -> O(n)
        // Space Complexity -> O(1) // O(N) auxiliary stack space

        int ans = INT_MAX;
        
        Node* prev = nullptr;
        
        inorder(root, prev, ans);
        
        return ans;
    }
