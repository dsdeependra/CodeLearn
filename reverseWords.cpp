#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

void reverse(string& str, int i, int j){
    for(i; i<j;){
        swap(str[i],str[j]);
        i++;j--;
    }
}

void reversewords(string& s){
    //first remove trailing space;
    
    //reverse the entire string
    int len = s.length();
    reverse(s,0,len-1);
    cout<<s<<endl;
    int j =0;
    for(int i=0;i<len;i++){
        if(s[i] == ' '){
            reverse(s,j,i-1);
            j=i+1;
        }
    }
}


int main(){
    string s="I am hero";
    reversewords(s);
    cout<<s<<endl;
    return 0;
}