// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write C++ code here
    // 36 divisor is 1,2,3,4,5,6,9....36
    // normal way is to loop all from 1 to 36 and check and print
    
    // other way is to check the pattern and you will see
    // 1 - 36
    // 2 - 18
    // 3 - 12
    // 4 - 9
    // 6 - 6 --------------------(till here)
    // 9 - 4
    // 12 - 3 and so on till 36 - 1
    // if we wil divide the number by the index we dont have to go all the way
    
    int n = 36;
    vector<int> arr;
    for(int i=1; i <= sqrt(36); i++){
        if(n%i == 0){
            arr.push_back(i);
            if(i != (n/i)){
                arr.push_back(n/i);
            }
        }
    }
    sort(arr.begin(),arr.end()); // sort in ascending
    for(int x : arr){
        cout << x << " ";
    }
    return 0;
}