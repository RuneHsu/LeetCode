// Date: 2016-06-21
// ref: https://leetcode.com/problems/count-primes/

/************************************************
* Count the number of prime numbers less than a 
* non-negative number, n.
* the hints are usefull
************************************************/

class Solution {
public:
    int countPrimes(int n) {
        vector<int> stk;
      
        stk.push_back(2);
        stk.push_back(3);
        
        if (n == 0 || n == 1)
            return 0;
        else if (n <= 3){
            return n - 2;
        }
        else{
            for (int i = 4; i < n; i++){
                stk.push_back(i);
                for (int j = 0; j < stk.size()-1; j++){
                    if ( i % stk[j] == 0){
                        stk.pop_back();
                        break;
                    }
                }
            }
            return stk.size();
        }
       
    }
};

class Solution{
    public:
    int countPrimes(int n){
        
    if (n < 3)
        return 0;
        
    vector<bool> isPrime(n,true);   // mark all the number as false
    int upper = sqrt(n);
    int res = 1;
    
    for (int i = 3; i < n; i+= 2){     // increment 2 because all the even number are non-prime
        if (isPrime[i]){
            res++;
            // avoid overflow
            if (i > upper)
                continue;
            for (int j = i*i ; j < n; j += i){
                isPrime[j] = false;
            }
        }
    }
    return res;
    }
};
