class Solution {
    public:
        int reverse(int x) {
            long ans = 0;
            while(x != 0){  // cant have x < 0 condition because it can go less than 0 
                int rem = x % 10;
                ans = (ans * 10) + rem;
                x = x/10;
                if(ans > INT_MAX || ans < INT_MIN) return 0;
            }
            return (int)ans;
        }
    };