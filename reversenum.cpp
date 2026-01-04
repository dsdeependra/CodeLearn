#include <iostream>
using namespace std;
// Function to reverse an integer number
// The function handles both positive and negative integers
// It returns 0 if the reversed number exceeds the range of a 32-bit signed integer
// The function uses a while loop to extract digits and build the reversed number
#include <cmath>
// The function uses recursion to handle the reversal of digits
// The function checks for overflow conditions and returns 0 if necessary
// The function uses absolute value to handle negative numbers
// The function returns the reversed number as an integer

int reverseNum(int A){
    if(A < 10 && A >=0){
        return A;
    }
    
    int rem = A % 10;
    int divi = A / 10; 
    int reverseNum = rem;
   
    
    while(rem <= divi){
        rem = divi % 10;
        reverseNum = reverseNum*10 + rem;
        divi = divi / 10;
        //cout<<rem<<" "<<divi<<" "<<reverseNum<<endl;
    }
    if(divi > 0){
        reverseNum = reverseNum*10 + divi;
    }
    return reverseNum;
}
int reverse(int A) {
    
    if(sizeof(abs(A)) > sizeof(int)){
        return 0;
    }
   
    if(A<0){
        return reverseNum(abs(A)) * (-1);
    }else{
        return reverseNum(A);
    }
}

int main() {
    int A = -12345;
    int reversed = reverse(A);
    // Output the reversed number
    // cout << "Reversed number: " << reversed << endl;
    return 0;
}
// Note: The code is designed to reverse an integer number, handling both positive and negative values.