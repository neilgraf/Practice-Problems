// 67. Add Binary
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Given two binary strings a and b, return their sum as a binary string.

 

// Example 1:

// Input: a = "11", b = "1"
// Output: "100"
// Example 2:

// Input: a = "1010", b = "1011"
// Output: "10101"
 

// Constraints:

// 1 <= a.length, b.length <= 104
// a and b consist only of '0' or '1' characters.
// Each string does not contain leading zeros except for the zero itself.

//Completed

class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int carry = 0;
        int aIdx = a.length() - 1;
        int bIdx = b.length() - 1; 
        
        while(aIdx >= 0 || bIdx >= 0 || carry){
            if(aIdx >= 0){
                carry += (a[aIdx] - '0');
            }
            if(bIdx >= 0){
                carry += (b[bIdx] - '0');
            }

            switch(carry){
                case 0:
                    ans = "0" + ans;
                    carry = 0;
                    break;
                case 1:
                    ans = "1" + ans;
                    carry = 0;
                    break;
                case 2:
                    ans = "0" + ans;
                    carry = 1;
                    break;
                case 3:
                    ans = "1" + ans;
                    carry = 1;
                    break;
            }
            aIdx--;
            bIdx--;
        }

        return ans;
    }
};