// Source: https://leetcode.com/problems/climbing-stairs/
// Date: 2016-03-27
/********************************************************************
* You are climbing a stair case. It takes n steps to reach to the top.
*
* Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*********************************************************************/

// Time too long
class Solution {
public:
    int climbStairs(int n) {
    if (n==0) return 0;
        int count=0;
        int i, j, demoninator, numerator;
        for(i=0; i<=n; i++){
            if((n-i)%2 == 0){
             j = (n-i)/2;
             demoninator=1;
             numerator = 1;
             for (int num=1;num<=(i+j); num++){
                 demoninator = demoninator * num;
                     if (num<=i){
                     numerator = numerator*num;
                     } else {
                         numerator = numerator*((i+j)-num+1);
                     }
                }
                 count += demoninator/numerator;
             }
        }  
        return count;
    }
  };

// consider this problem as probability problem, not wise

/**************************** Other solution ************************/
// Actually, this is a fibonacci problem. every time you got two choices, (climb 1 step from n-1 or climb 2 steps from n-2).
class Solution{
public:
    int climbStairs(int n){
    if (n<=3) return n;
    vector<int> res(3);
    res[0] = 1;   //pay attention to this 
    res[1] = 1;
    for (int i=2; i<=n; i++){
    res[i%3] = res[(i-1)%3] + res[(i-2)%3];
    }
    return res[n%3];
  }
};

// recursive way, but too time consuming (recursive is a time consuming way)
class Solution{
public:
    int climbStairs(int n){
    if (n<=2) return n;
    return climbStairs(n-1) + climbStairs(n-2);
    }
  };
    

      
