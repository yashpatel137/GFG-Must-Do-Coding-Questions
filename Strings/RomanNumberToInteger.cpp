//Method 1
class Solution {
  public:
    int romanToDecimal(string &str) {
        unordered_map<char,int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        int ans=0;
        int n=str.length();
        for(int i=0;i<n;i++)
        {
            if(i<n-1)
            {
                if(mp[str[i]]>=mp[str[i+1]])
                {
                    ans+=mp[str[i]];
                }
                else
                {
                    ans-=mp[str[i]];
                }
            }
            else
            {
                ans+=mp[str[i]];
            }
        }
        return ans;
    }
};

//Method 2
int symbolValue(char c)
{
    if(c == 'I')
        return 1;
    if(c == 'V')
        return 5;
    if(c == 'X')
        return 10;
    if(c == 'L')
        return 50;
    if(c == 'C')
        return 100;
    if(c == 'D')
        return 500;
    if(c == 'M')
        return 1000;
}
int romanToDecimal(string &str)
{
    // code here
    int res = 0;
    for(int i = 0 ; i < str.length() - 1 ; i++)
    {
        if(symbolValue(str[i+1]) <= symbolValue(str[i]))
            res += symbolValue(str[i]);
        else
            res -= symbolValue(str[i]);
    }
    res += symbolValue(str[str.length() - 1]);
    return res;
}
