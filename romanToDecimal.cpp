#include<iostream>
#include<map>

using namespace std;





int romanToDecimal(string &A){

    map<char,int> romanValue;
    romanValue['I']=1;
    romanValue['V']=5;
    romanValue['X']=10;
    romanValue['L']=50;
    romanValue['C']=100;
    romanValue['D']=500;
    romanValue['M']=1000;

    map<char,int> indexValue;
    indexValue['I']=1;
    indexValue['V']=2;
    indexValue['X']=3;
    indexValue['L']=4;
    indexValue['C']=5;
    indexValue['D']=6;
    indexValue['M']=7; 
      
    int ans = 0;
    char prev;
    for(int i = 0;i<A.size();i++){
        char c = A[i];
        int check = romanValue.find(c)->second;
        // if(c == 'V' && prev == 'I')|| (c == 'D' && prev == 'L')|| (c == 'D' && prev == 'X'){
        if((c != prev) && (indexValue.find(prev)->second < indexValue.find(c)->second ) ){
            //int prevVal = 
            check -= romanValue.find(prev)->second;
            check -= romanValue.find(prev)->second;
        }
       
        
        prev = c;
        ans += check;
    }
    return ans;
}

int main(){
    // string roman = "MXCIII";
    string roman = "IIIC";
    int val = romanToDecimal(roman);
    cout<<val<<endl;
    return 0;
}
