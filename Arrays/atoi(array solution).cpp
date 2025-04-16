class Solution {
public:
    int myAtoi(string s) {
        int idx = 0;
        int sSize = s.size();
        int sign = 1;
        long ans = 0;

        while(idx < sSize && s[idx] == ' '){  //condition for whitespaces
            idx++;
        }

        if(s[idx] == '-') {sign = -1; idx++;} // condition to check sign
        else if(s[idx] == '+') idx++;

        while(idx < sSize){
            if(s[idx]< '0' || s[idx]> '9'){  // if element not a number then break
                break;
            }
            ans = ans * 10 + (s[idx] - '0'); // 0 + ('4' - '0') = 52-48 = 4 (ASCII values)
            if(sign*ans > INT_MAX) return INT_MAX;  // if ans is long just return
            if(sign*ans < INT_MIN) return INT_MIN; 
            idx++;
        }

        return (int)(sign*ans);
    }
};