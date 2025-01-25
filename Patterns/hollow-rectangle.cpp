// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    int n = 4; // number of rows

    for(int i=0; i<n; i++){
        if(i==0 or i== (n-1)){
            for(int j=0;j<n;j++){
                cout << "*";
            }
            cout << endl;
            continue;
        }
        cout << "*";
        for(int j = 0; j<n-2; j++){
            cout << " ";
        }
        cout << "*";
     cout << endl;
    }
    
    return 0;
}

// OR

int n = 4; // number of rows
for(int i=0; i<n; i++){
    for(int j=0;j<n;j++){
        if(i==0 || j==0 || i==(n-1) || j==(n-1)){
            cout << "*";
        }else cout << " ";
    }
    cout << endl;
}

******
*    *
*    *
*    *
*    *
******