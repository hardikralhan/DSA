class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // brute force
        // int n = matrix.size();
        // vector<vector<int>> result(n, vector<int>(n,-1));
        // for(int i = 0; i<n; i++){
        //     for(int j = 0; j<n; j++){
        //         result[j][n-1-i] = matrix[i][j];
        //     }
        // }

        // optimal solution - transponse and revesrse
        int n = matrix.size();
        for(int i =0; i<=n-2; i++){
            for(int j=1+i; j<n; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp; 
            }
        }
        for(int i =0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};