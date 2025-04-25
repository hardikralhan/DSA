class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // brute
        // loop the 2d array, where it is 0 make row and col -1 in the same array
        // and then make -1 to 0. it takes TC at around n3

        // better
        // find location of zero and then put 0 in their rows and cols
        // - make a row and col array of 0
        // - wherever you find 0 in 2d array put row and col with 1
        // - now loop row with col as nested array and wherever it is 1 put 0 

        int n = matrix.size(); int m = matrix[0].size();
        vector<int> row(n, 0); vector<int> col(m, 0);
        for(int i=0; i<n; i++){ // row
            for(int j=0; j<m; j++){ // col
                if(matrix[i][j] == 0){   // wherever find 0 mark row col with 1
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        for(int i=0; i<row.size(); i++){
            for(int j=0; j<col.size(); j++){
                if(row[i] == 1 || col[j] == 1){
                    matrix[i][j] = 0;
                }
            }
        }

        // optimal soln
        // (check the video explanation)
        // thought process is to optimise it in O(1)
        // so we will make row and col in the matrix itseelf
        // row will be matrix[0] and col will be 1st element of every row
        // row = matrix[0][any col] , col = matrix[any row][0]
        // we will put 0 in those row col to know the location where to put 0's in the matrix
        // will take one col0 vaariable as 1 because col 0 and row 0 block is common for both of them
        // so col 0 will be taken seperately
        // after finding all the location - iterate row(i), col(j) from 1 -> n to put zeros for those locations
        // solve for 0 of col and then row

        int n = matrix.size(); int m = matrix[0].size();
        int col0 = 1;
        // step 1 fill locations of 0 
        for(int i=0; i<n; i++){ // row
            for(int j=0; j<m; j++){ // col
                if(matrix[i][j] == 0){   // marking for locations
                    matrix[i][0] = 0; // mark 0 for row
                    if(j == 0 && matrix[i][0] == 0){  // becaue we cant put 0 for col location, already occupied by row
                        col0 = 0;
                    }else{
                        matrix[0][j] = 0; // mark 0 for col
                    } 
                }
            }
        }

        // step 2 iterate through 1 to n or m and fill 0 
        for(int i =1; i<n; i++){
            for(int j = 1; j<m; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        // step 3 solve right side portion (col) first
        if(matrix[0][0] == 0){
            for(int j = 1;  j<m; j++){
                matrix[0][j] = 0;
            }
        }
        // step 4 solve left down (row) portion
        if(col0 == 0){
            for(int i = 0; i<n; i++){
                matrix[i][0] = 0;
            }
        }

    }
};