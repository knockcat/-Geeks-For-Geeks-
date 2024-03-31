class Solution {
  public:

    /*You are required to complete below function */
    
    void inorder(Node* root, vector<int>& arr)
    {
        // O(n)
        
        if(root)
        {
            // left root right
            inorder(root->left, arr);
            arr.push_back(root->data);
            inorder(root->right, arr);
        }
    }
    
    int merge(int low, int mid, int high, vector<int>& arr, vector<int>& output)
    {
        int i = low, j = mid+1;
        int k = low;
        
        int inversions = 0;
        
        while(i <= mid and j <= high)
        {
            if(arr[i] <= arr[j])
                output[k++] = arr[i++];
            else{
                output[k++] = arr[j++];
                inversions += (mid - i + 1);
            }
        }
        
        while(i <= mid)
            output[k++] = arr[i++];
        while(j <= high)
            output[k++] = arr[j++];
            
        for(int i = low; i <= high; ++i)
            arr[i] = output[i];
            
        return inversions;
    }
    
    int mergeSort(int low, int high, vector<int>& arr, vector<int>& output)
    {
        int inversions = 0;
        
        if(low < high)
        {
            int mid = (low + high) / 2;
            
            inversions += mergeSort(low, mid, arr, output);
            inversions += mergeSort(mid+1, high, arr, output);
            inversions += merge(low, mid, high, arr, output);
            
        }
        
        return inversions;
    }
    
    int pairsViolatingBST(int n, Node *root) {
        // your code goes here
        
        // first step
        // get the inorder Traversal of given tree
        
        // Time Complexity -> O(n * log(n))
        // Space Complexity -> O(n)
        
        vector<int> arr, output(n);
        
        inorder(root, arr);
        
        
        // second step count inversion
        
        return mergeSort(0, n-1, arr, output);
        
    }
};
