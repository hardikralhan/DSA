class Solution {  // log10(num) time complexity
    public:
        int countDigits(int num) {
            int store = num;
            int count = 0;
            while(num != 0){
                int rem = num % 10;
                num = num/10;
                if(store % rem == 0){
                    count++;
                }
            }
            return count;
        }
    };