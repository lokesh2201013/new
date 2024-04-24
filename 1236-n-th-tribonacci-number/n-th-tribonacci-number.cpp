class Solution {
public:
    int tribonacci(int n) {
      long long  int t0=0,t1=1,t2=1,ta=0;
      if(n==0)
      {
        return 0;
      }

      if(n==1||n==2)
      {
        return 1;
    }
        for(int i=0 ; i<n-2;i++)
        {
            ta=t0+t1+t2;
            t0=t1;
            t1=t2;
            t2=ta;
        }
        return ta;
    }
};