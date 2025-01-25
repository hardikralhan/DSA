// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    int n = 4; // number of rows
    for(int i=0; i<n; i++){
        for(int j = 0; j<=i; j++){  //number
            cout << j+1;
        }
        for(int k = 0; k< (2*n - (2*i + 2)); k++){ // spaces
            cout << " ";
        }
        int temp = i+1;
        for(int l =0; l<=i; l++){  //number
            cout << temp;
            temp--;
        }
     cout << endl;
    }
    return 0;
}

1          1
12        21
12       321
1234    4321
12345  54321
123456654321