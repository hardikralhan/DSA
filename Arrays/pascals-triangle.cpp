// numRows = 5

vector<vector<int>> generate(int numRows) {
        
}

// use combination R-1 C C-1   (R is row and C is col)
// n C r  = n!/r!*(n-r)!
// 4C2 = 6

// O(n3) solution
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0; i<numRows; i++){
            vector<int> temp;
            for(int j=0; j<=i; j++){
                int combination = findCombination(i, j);
                temp.push_back(combination);
            }
            ans.push_back(temp);
        }
        return ans;
    }

    int findCombination(int n, int r){    //n is row and r is col
        int res = 1;
        for(int i=0; i<r; i++){    // goes till col ends
            res = res* (n - i);    // 4-0=4 then 4-1=3  so 4*3
            res = res/ (i+1);      // 0+1=1 then 1+1=2  so 1*2
        }
        return res;
    }
};


// O(n2) - looping row
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0; i<numRows; i++){
            vector<int> combinations = findRowCombinations(i);
            ans.push_back(combinations);
        }
        return ans;
    }

    vector<int> findRowCombinations(int n){  // gives all values of a row
        int res = 1;
        vector<int> temp = {1};
        for(int i=0; i<n; i++){    // goes till row ends
            res = res* (n - i);    // 4-0=4 then 4-1=3  so 4*3(numerator part)
            res = res/ (i+1);      // 0+1=1 then 1+1=2  so 1*2(denominator part)
            temp.push_back(res);
        }
        return temp;
    }
};