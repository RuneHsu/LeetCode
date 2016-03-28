// Source: https://leetcode.com/problems/super-ugly-number/
// Date: 2016-03-28

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int primesSize = primes.size();
        vector<int> res(n);
        vector<int> pf(primes);
        vector<int> primesInd(primesSize);
        res[0] = 1;
        int min_val;
        for(int i=1; i<n; i++){
            int min_val = *min_element(pf.begin(),pf.end());
            res[i] = min_val;
            for(int j=0; j< primesSize; j++){
            if(min_val == pf[j]){                             // pay attention to this part
                pf[j] = primes[j]*res[++primesInd[j]];
            }
        }
        }
        return res[n-1];
    }
};

/********************** Another solution *********************/
// ref: https://github.com/kamyu104/LeetCode/blob/master/C%2B%2B/super-ugly-number.cpp
// Heap solution. (308ms)
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        vector<int> uglies(n), idx(primes.size()), ugly_by_last_prime(n);
        uglies[0] = 1;

        for (int i = 0; i < primes.size(); ++i) {
            heap.push({primes[i], i});
        }
        for (int i = 1; i < n; ++i) {
            int k;
            tie(uglies[i], k) = heap.top();
            heap.pop();
            ugly_by_last_prime[i] = k;
            while (ugly_by_last_prime[++idx[k]] > k);  // worst time: O(k)
            heap.push({uglies[idx[k]] * primes[k], k});
        }
        return uglies[n - 1];
    }
};
