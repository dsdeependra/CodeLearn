#include<iostream>

using namespace std;

string decBinary(int A){
      string str;
   if(A==0){
        str = to_string(0);
        return str;
    }
    if(A==1){
        str = to_string(1);
        return str;
    }
    while(A/2 >= 1){
        int r = A%2;
        A /=2; 
        str += to_string(r);
        //cout<<str<<endl;
    }
    str += to_string(1); 
    reverse(str.begin(), str.end());
    return str;
}
int main(){

    int a;
    
    cin>>a;
    string str = decBinary(a);
    cout<<str<<endl;
    return 0;
}