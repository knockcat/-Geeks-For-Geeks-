// Naive Appraoch ( Accepted)
vector <int> zigZagTraversal(Node* root)
    {
    	// Code here

      // Time Complexity -> O(N)
      // Space Complexity -> O(N)
      
    	queue<Node*> q;
    	
    	vector<int> res;
    	
    	bool ok = true;
    	
    	q.push(root);
    	
    	while(!q.empty())
    	{
    	    int size = q.size();
    	    
    	    vector<int> currLevel;
    	    
    	    for(int i = 0; i < size; ++i)
    	    {
    	        Node* curr = q.front();
    	        q.pop();
    	        
    	        currLevel.push_back(curr->data);
    	        
    	        if(curr->left)
    	            q.push(curr->left);
    	           
    	        if(curr->right)
    	            q.push(curr->right);
    	    }
    	    
    	    if(!ok)
    	        reverse(currLevel.begin(), currLevel.end());
    	       
    	    ok ^= 1;
    	    
    	    for(auto ele : currLevel)
    	        res.push_back(ele);
    	}
    	
    	return res;
    }

// Slight Better than naive

vector <int> zigZagTraversal(Node* root)
    {
    	// Code here

      // Time Complexity -> O(N)
      // Space Complexity -> O(N)
      
    	queue<Node*> q;
    	
    	vector<int> res;
    	
    	bool ok = true, leftToRight = true;
    	
    	q.push(root);
    	
    	while(!q.empty())
    	{
    	    int size = q.size();
    	    
    	    vector<int> currLevel(size);
    	    
    	    for(int i = 0; i < size; ++i)
    	    {
    	        Node* curr = q.front();
    	        q.pop();
    	        
    	        int idx = (leftToRight ? i : size - i - 1);
    	        
    	        currLevel[idx] = curr->data;
    	        
    	        if(curr->left)
    	            q.push(curr->left);
    	           
    	        if(curr->right)
    	            q.push(curr->right);
    	    }

    	    for(auto ele : currLevel)
    	        res.push_back(ele);
    	    ok ^= 1;
    	    leftToRight ^= 1;
    	}
    	
    	return res;
    }

// Better Optimised

vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
      // Time Complexity -> O(N)
      // Space Complexity -> O(N)
    	
    	deque<Node*> q;
    	
    	vector<int> res;
    	
    	res.push_back(root->data);
    	
    	bool ok = true;
    	
    	q.push_back(root);
    	
    	while(!q.empty())
    	{
    	    int size = q.size();
    	    
    	    for(int i = 0; i < size; ++i)
    	    {
    	        Node* curr;
    	        if(ok)
    	        {
    	            curr = q.front();
    	            q.pop_front();
    	        }
    	        else
    	        {
    	            curr = q.back();
    	            q.pop_back();
    	        }
    	       
    	        
    	        if(ok)
    	        {
    	            if(curr->right)
    	            {
    	                q.push_back(curr->right);
    	                res.push_back(curr->right->data);
    	            }
    	            
    	            if(curr->left)
    	            {
    	                q.push_back(curr->left);
    	                res.push_back(curr->left->data);
    	            }
    	        }
    	        else
    	        {
    	            if(curr->left)
    	            {
    	                q.push_front(curr->left);
    	                res.push_back(curr->left->data);
    	            }
    	            
    	            if(curr->right)
    	            {
    	                q.push_front(curr->right);
    	                res.push_back(curr->right->data);
    	            }
    	        }
    	    }
    	    ok ^= 1;
    	}
    	
    	return res;
    }
