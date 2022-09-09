#include<iostream>
using namespace std;

int getFinalValue(string str,int th){
    if(str.size() == 1){
        return stoi(str);
    }
    int n = str.size();
    string str2;
    int sum=0;
    cout<<str<<endl;
    for(int i=0;i<n;i++){
        sum += stoi(to_string(str[i]));
        if(sum > th){
            th = sum;
            str2 += to_string(sum);
        }
    }
    str2 += to_string(sum);
    getFinalValue(str2,th);
    return -1;
}

int main(){
    string str = "1234567";
    // cin>>str;

    int th;
    cin>>th;
    int sol = getFinalValue(str,th);
    cout<<sol<<endl;
}