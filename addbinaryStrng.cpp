#include<iostream>
#include<cmath>
using namespace std;


string addBinary(string a, string b) {
    
   string result = ""; // Initialize result
    int s = 0;          // Initialize digit sum
 
  
    int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || s == 1)
    {
        // Comput sum of last digits and carry
        s += ((i >= 0)? a[i] - '0': 0);
        // cout<<s<<endl;
        
        s += ((j >= 0)? b[j] - '0': 0);
        // cout<<s<<endl;
        // If current digit sum is 1 or 3, add 1 to result
        result = char(s % 2 + '0') + result;
 
        // Compute carry
        s /= 2;
 
        // Move to next digits
        i--; j--;
    }
    return result;
    
}

int main(){

    string A = "11";
    string B ="101";
    cout<<addBinary(A,B)<<endl;
    return 0;
}
