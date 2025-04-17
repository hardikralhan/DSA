/**
 * @input A : Integer
 * 
 * @Output Integer
 */
 int solve(int A) {
    // count digits
    int temp = A;
    int count = 0;
    while(temp != 0){
        count++;
        temp = temp/10;
    }
    
    // now find armstrong
    int real = A;
    long ans = 0;
    while(A != 0){
        int rem = A % 10;
        ans = ans + pow(rem,count);
        A = A/10;
    }
    if(ans == real) return 1;
    else return 0;
    
}
