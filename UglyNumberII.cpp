// Source: https://leetcode.com/problems/ugly-number-ii/
// Date: 2016-03-27
/*********************************************
* Write a program to find the n-th ugly number.
*
* Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
*
* For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
*
* Note that 1 is typically treated as an ugly number.
*
* Hint:
*
* 1.The naive approach is to call isUgly for every number until you reach the nth one. Most numbers are not ugly. Try to focus your effort on generating only the ugly ones.
* 2.An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.
* 3.The key is how to maintain the order of the ugly numbers. Try a similar approach of merging from three sorted lists: L1, L2, and L3.
* 4.Assume you have Uk, the kth ugly number. Then Uk+1 must be Min(L1 * 2, L2 * 3, L3 * 5).
**********************************************/
/*************************************************
* [Thoughts]
* 这就是多链表Merge Sort的一个扩展题。
* 对于任意一个ugly number - K, 2*K, 3*K, 和5*K都是ugly number，所以说新的ugly number都是从已有的ugly number上，通过与{2,3,5}相乘而产生的。
* 如果
* Ugly Number:       1,       2,       3,           4,           5,          6,          8,         10,  ..............
* 那么              1*2      2*2        3*2         4*2         5*2         6*2         8*2        10*2  .............. *2
*                   1*3      2*3        3*3         4*3         5*3         6*3         8*3        10*3  .............. *3
*                   1*5      2*5        3*5         4*5         5*5         6*5         8*5        10*5  .............. *5
* 都是ugly number。只要不断把新产生的ugly number通过merge sort添加到原有的ugly number数组中就可以了，直到找到第N个。
*********************************************************************************************************************/
class Solution{
    public:
        int nthUglyNumber(int n){
          vector<int> uglies(n);
          uglies[0] = 1;
          int f2=2, f3=3, f5=5;
          int idx2=0, idx3=0, idx5=0;
          for(int i=1; i<n; i++){
             int min_val = min(min(f2,f3),f5);
             uglies[i] = min_val;
              if (min_val%2==0) {             
                  f2 = 2*uglies[++idx2];
              }
              if (min_val%3==0) {
                  f3 = 3*uglies[++idx3];
              }
              if (min_val%5==0) {
                  f5 = 5*uglies[++idx5];
              }
          }
          return uglies[n-1];
        }
};

class Solution {
public:
    int nthUglyNumber(int n) {
    int i=0, j=0, k=0;
    vector<int> v(1,1);
    int next;
    while(v.size()<n){
        next = min(min(v[i]*2,v[j]*3),v[k]*5);
        if (next%2==0) i++;
        if (next%3==0) j++;
        if (next%5==0) k++;
        v.push_back(next);
    }
    return v.back();
    }
};

class Solution {
public:
    int nthUglyNumber(int n) {
    int i=0, j=0, k=0;
    vector<int> v(1,1);
    int next;
    while(v.size()<n){
        next = min(min(v[i]*2,v[j]*3),v[k]*5);
        if (next%2==0) i++;
        if (next%3==0) j++;
        if (next%5==0) k++;
        v.push_back(next);
    }
    return v.back();
    }
};
