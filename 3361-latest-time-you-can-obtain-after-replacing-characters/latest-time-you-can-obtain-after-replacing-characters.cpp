class Solution {
public:
    string findLatestTime(string s) {
        if(s[0]=='?'&&(s[1]<='1'||s[1]=='?'))
        {
            s[0]='1';
        }
        else if(s[0]=='?'&&s[1]>1)
        {
            s[0]='0';
        }
        
       for(int i=1 ; i<5 ; i++)
       {
        if(s[i]=='?'&&i<2)
        {
            if(s[0]=='0')
            {
                s[i]='9';
            }
            else if(s[0]=='1')
            {
                s[i]='1';
            }
        }
        if(s[i]=='?'&& i>2)
        {
           if(i==3)
           {
            s[i]='5';
           }
           else if(i==4)
           {
            s[i]='9';
           }
        }
       }
       return s; 
    }
};
