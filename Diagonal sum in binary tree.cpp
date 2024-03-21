vector <int> diagonalSum(Node* root) {
        // Add your code here
        
        // Time Complexity -> O(n)
        // Space Complexity -> O(n)
        
        vector<int> res;
        
        queue<Node*> q;
        
        q.push(root);
        
        while(!q.empty())
        {
            int size = q.size();
            
            int currSum = 0;
            
            for(int i = 0; i < size; ++i)
            {
                Node* curr = q.front();
                q.pop();
                
                while(curr) // iterating all on its right
                {
                    currSum += curr->data;
                    
                    if(curr->left) // for next level
                        q.push(curr->left);
                        
                    curr = curr->right;
                }
            }
            
            res.push_back(currSum);
        }
        
        return res;
    }
