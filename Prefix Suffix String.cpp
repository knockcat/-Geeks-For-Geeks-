//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:


    class Node{
        public:
            Node* child[26] = {nullptr};
            
            bool isContains(char ch)
            {
                return child[ch - 'a'] != nullptr;
            }
            
            void  put(char ch, Node* node)
            {
                child[ch - 'a'] = node;
            }
            
            Node* get(char ch)
            {
                return child[ch - 'a'];
            }
    };
    
    class Trie{
        private:
            Node* root;
        
        public:
            Trie()
            {
                root = new Node();
            }
            
            void insert(string& word)
            {
                Node* temp = root;
                int n = word.size();
                
                for(int i = 0; i < n; ++i)
                {
                    if(!temp->isContains(word[i]))
                        temp->put(word[i], new Node());
                    temp = temp->get(word[i]);
                }
            }
            
            bool search(string& word)
            {
                Node* temp = root;
                int n = word.size();
                
                for(int i = 0; i < n; ++i)
                {
                    if(!temp->isContains(word[i]))
                        return 0;
                    temp = temp->get(word[i]);
                }
                
                return true;
            }
    };
    

    int prefixSuffixString(vector<string> &s1,vector<string> s2){
        // Code here
        
        Trie *obj = new Trie();
        
        for(auto &s : s1)
        {
            string str = s;
            reverse(str.begin(),str.end());
            
            obj->insert(s);
            obj->insert(str);
        }
        
        int cnt = 0;
        
        for(auto &s : s2)
        {
            string str = s;
            reverse(str.begin(),str.end());
            if(obj->search(s) or obj->search(str))
                ++cnt;
        }
        
        return cnt;
        
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}
// } Driver Code Ends
