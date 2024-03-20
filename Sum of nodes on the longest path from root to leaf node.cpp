// Time Complexity -> O(n)
// Space Complexity -> O(n)

pair<int,int> helper(Node* root, int length)
    {
        if(!root)
            return {0, 0};
        
        pair<int,int> left = helper(root->left, length);
        pair<int,int> right = helper(root->right, length);
        
        if(left.second > right.second)
        {
            return {root->data + left.first, left.second + 1};
        }
        else if(left.second < right.second)
        {
            return {root->data + right.first, right.second + 1};
        }
        else
        {
            return {max(left.first , right.first) + root->data, left.second + 1};
        }
        
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        
        return helper(root, 0).first;
    }
