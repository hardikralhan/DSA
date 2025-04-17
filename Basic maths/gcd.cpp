// naive approach )(min(n1,n2))

class Solution {
    public:
        int GCD(int n1,int n2) {
            int gcd = 1;
            for(int i =1; i<= min(n1,n2); i++){
                if(n1 % i == 0 && n2 % i == 0){
                    gcd = i;
                }
            }
            return gcd;
        }
    };

    // euclidean algorithm - gcd(a,b) = gcd(a-b,b)  where a is always greater than b
    // we can also write like gcd(a,b) = gcd(a%b,b) where a is always greater than b 
    // you will find it after solving gcd(a-b,b) again and again that it is equal to gcd(a%b,b)

    // gcd of 52,10 after using program will be 0,2
    // once anyone becomes 0 the other number is gcd

    class Solution {
        public:
            int GCD(int n1,int n2) {
                int a = max(n1,n2);
                int b = min(n1,n2);
                while(a !=0 || b !=0){  // loop till anyone becomes 0
                    temp = a%b;
                    a = max(temp,b);
                    b = min(temp,a);
                }
                return max(a,b);
            }
        };
    // check this solution once