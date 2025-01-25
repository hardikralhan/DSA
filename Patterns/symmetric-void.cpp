// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    int n = 10; // number of rows
    
    // reverse
    for(int i=0; i<n/2; i++){
        for(int j = i; j<n/2; j++){
            cout << "*";
        }
        for(int j = 0; j< (2*i); j++){
            cout << " ";
        }
        for(int j = i; j<n/2; j++){
            cout << "*";
        }
     cout << endl;
    }
    
    //straight
    int half = n/2;
    for(int i=0; i<n/2; i++){
        for(int j = 0; j<=i; j++){
            cout << "*";
        }
        for(int j = 0; j< (2*half-(2*i +2)); j++){
            cout << " ";
        }
        for(int j = 0; j<=i; j++){
            cout << "*";
        }
     cout << endl;
    }
    return 0;
}


************
*****  *****
****    ****
***      ***
**        **
*          *
*          *
**        **
***      ***
****    ****
*****  *****
************