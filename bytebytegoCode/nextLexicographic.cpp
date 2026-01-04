#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

string GetNextLexicoGraphic(string s){
    int i  = s.length()-1;
    int j = s.length()-2;
    int pivot = 0;
    while(j>=0){
        if(s[j]>=s[i]){
            j--;
            i--;
        }
        else{
            pivot = j;
            break;
        }
    }


    if(pivot ==0){
        reverse(s.begin(),s.end());
        return s;
    }
    for(int k = s.length()-1;k>=pivot;k--){
        if(s[k] > s[pivot]){
            swap(s[k],s[pivot]);
            break;
        }
    }
    reverse(s.begin()+pivot+1,s.end());
    return s;
}




int main(){

    string s = "dcba";
    string result = GetNextLexicoGraphic(s);
    cout<<result<<endl;


    return 0;

}
