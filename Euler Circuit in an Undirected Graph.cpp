bool isEularCircuitExist(int v, vector<int>adj[]){
	    // Code here
	    
	   // even degree for all nodes
	    
	    for(int i = 0; i < v; ++i)
	    {
	        if(adj[i].size() & 1)
	            return false;
	    }
	    
	    return true;
	}
