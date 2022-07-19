class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<n-1;i++)
        {
            if(arr[i]==0)
            {
                for(int j=n-2;j>i;j--)
                {
                    arr[j+1]=arr[j];
                }
                arr[i+1]=0;
                i++;
            }
        }
    }
};


//Method 2
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int s=arr.size(), i=s-1;
        while(i>=0)
        {
            if(arr[i] == 0)
            {
                arr.insert(arr.begin()+i,0);
                arr.pop_back();
            }
            --i;
        }
    }
};


//Method 3
class Solution {
public:
    void duplicateZeros(vector<int>& arr) 
    {
        int shift = count(begin(arr), end(arr), 0), size = arr.size();
        for (int i = arr.size() - 1; i >= 0; i--) 
        {
            if (!arr[i]) shift--;
            if (i + shift < size) 
            {
                arr[i + shift] = arr[i];
                if (!arr[i] && i + shift + 1 < size)
                    arr[i + shift + 1] = 0;
            }
        }
    }
};
