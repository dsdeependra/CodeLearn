#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<unordered_map>
using namespace std;

int getnonrepeatingchar(string& str, int n){
    
    unordered_map<char,pair<int,int> > m;

    for(int i =0;i<n;i++){
        m[str[i]].first++;
        m[str[i]].second = i;
    }
    int min_index = n;
    for(auto it:m){
        int count = it.second.first;
        int first_index = it.second.second;
        if(count == 1 && first_index < min_index){
            min_index = first_index;
        }
    }
    return min_index;
}

int main(){
    string str="INTERVIEWBIT";
    int n = str.length();
    cout<<"non repeating char is at index"<<getnonrepeatingchar(str,n)<<endl;
    return 0;
}