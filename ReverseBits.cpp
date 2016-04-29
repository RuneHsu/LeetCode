// Source: https://leetcode.com/problems/reverse-bits/
// Date: 2016-04-29

/******************************************************************
* Reverse bits of a given 32 bits unsigned integer.
*
* For example, given input 43261596 (represented in binary as 
* 00000010100101000001111010011100), return 964176192 (represented 
* in binary as 00111001011110000010100101000000).
*
* Follow up:
* If this function is called many times, how would you optimize it?
*********************************************************************/
// bulk data ref: https://leetcode.com/discuss/27328/java-solution-and-optimization

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
      uint32_t result = 0;                 // initialize as 0 can guarantee the 0s before the first 1
      
      for(int i=0; i<32; i++){
          result = (result<<1) + (n>>i & 1);     // (n>>i & 1) to extract every bit of n from left to right 
                                                 // (result<<1) to store the extracted bit
      }
      return result;
    }
};

class Solution {
    public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        
        for(int i=0; i<32; i++, n >>= 1){
            result <<= 1;
            result |= n & 1;
        }
        return result;
    }
};

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result=0;
        uint32_t A[32];
        for(int i=31;i>=0;i--){
            A[31-i] = pow(2.0,i);
        }
        for(int j=0;j<32;j++){
            if(n&1){
                result += A[j];
            }
            n = n>>1;
        }
        return result;
    }
};

class Solution {
    public:
    uint32_t reverseBits(uint32_t n) {
        n =  (n << 16) | (n >> 16);                             // keep reversing half of the number 1100>>2 | 0011<<2
        n = (n & 0xff00ff00) >> 8 | (n & 0x00ff00ff) << 8;
        n = (n & 0xf0f0f0f0) >> 4 | (n & 0x0f0f0f0f) << 4;
        n = (n & 0xcccccccc) >> 2 | (n & 0x33333333) << 2;
        n = (n & 0xaaaaaaaa) >> 1 | (n & 0x55555555) << 1;
        return n;
    }
};
