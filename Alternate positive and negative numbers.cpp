// https://practice.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1

class Solution
{
public:
    void rearrange(int arr[], int n)
    {
        // code here
        vector<int> positive, negative;

        for (int i = 0; i < n; ++i)
        {
            if (arr[i] >= 0)
                positive.push_back(arr[i]);
            else
                negative.push_back(arr[i]);
        }

        int i = 0, j = 0, k = 0;

        while (j < positive.size() && k < negative.size())
        {
            arr[i++] = positive[j++];
            arr[i++] = negative[k++];
        }
        while (j < positive.size())
        {
            arr[i++] = positive[j++];
        }
        while (k < negative.size())
        {
            arr[i++] = negative[k++];
        }
    }
};
