// Iterative Solution
// Time Complexity -> O(n)
// Space Complexity -> O(n)
stack<int> insertAtBottom(stack<int> st,int x){
        
        stack<int> newStack;
        
        while(!st.empty())
        {
            newStack.push(st.top());
            st.pop();
        }
        
        st.push(x);
        
        while(!newStack.empty())
        {
            st.push(newStack.top());
            newStack.pop();
        }
        
        return st;
    }

// Recursive Solution
// Time Complexity -> O(n)
// Space Complexity -> O(n) (recusion stack)

void helper(stack<int>& st, int x)
    {
        if(st.empty())
        {
            st.push(x);
            return;
        }
        
        int topVal = st.top();
        st.pop();
        helper(st, x);
        st.push(topVal);
        return;
    }
    
    stack<int> insertAtBottom(stack<int> st,int x){
        
        helper(st, x);
        
        return st;
        
    }
