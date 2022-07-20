//Method 1
class Solution{
public:
    string remove(string s){
        string st="";
        int size=s.length(),j,l=0,r,change=0;
        for(int i=0;i<size;)
        {
            j=i+1;
            int flag=0;
            while((s[i]==s[j]) && j<size)
            {
                j++;
                flag=1;
                change=1;
            }
            if(flag==1)
            {
                l=j;
                i=j;
            }
            else
            {
                r=i;
                st+=s.substr(l,r-l+1);
                l=j;
                i++;
            }
            
        }
        if(change==0)
        {
            return st;
        }
        else
        {
            return remove(st);
        }
    }
};

//Method 2
class Solution{
public:
    string remove(string s)
    {
        // code here
        stack<char> st;
        bool flag = 1;
        while(flag && s.length())
        {
            flag = 0;
            int i = 0;
            while(i < s.length())
            {
                if(st.empty() || st.top() != s[i])
                    st.push(s[i]);
                else
                {
                    flag = 1;
                    while(!st.empty() && s[i] == st.top())
                        i++;
                    st.pop();
                    st.push(s[i]);
                }
                i++;
            }
            s = "";
            while(!st.empty())
            {
                s.push_back(st.top());
                st.pop();
            }
            reverse(s.begin(), s.end());
        }
        return s;
    }
};

