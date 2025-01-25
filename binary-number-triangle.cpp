// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    int n = 5; // number of rows
    for(int i=0; i<n; i++){
        if((i+1)%2 == 0){    // even row
            int temp = 0;
            for(int j=0; j<=i; j++){
                cout << temp; 
                if(temp == 0){
                    temp++;
                }else{
                    temp--;
                }
            }   
        }
        if((i+1)%2 != 0){    // odd row
            int temp = 1;
            for(int j=0; j<=i; j++){
                cout << temp; 
                if(temp == 1){
                    temp--;
                }else{
                    temp++;
                }
            }   
        }
     cout << endl;
    }
    return 0;
}