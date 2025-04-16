class Solution {
public:
    bool isPalindrome(int x) {
        int real = x;
        long ans = 0;
        while(x != 0){  // reverse a number
            int rem = x%10;
            if(rem < 0) return false;
            ans = (ans * 10) + rem;
            x=x/10;
        }
        if(ans == real) return true;
        return false;
    }
};