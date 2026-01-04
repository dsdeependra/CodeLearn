#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> GetPairSumIndex(vector<int>&input,int target){
    map<int,int>m;
    vector<int,int>result;
    for(int i=0;i<input.size();++i){
        if(m.find(input[i]) !=m.end()){
            result = {m.find(input[i])->second,i};
            break;
        }
        else{
            m.insert({target-input[i],i});
        }
    }
    return result;
}

int main(){
    vector<int>input = {-1,3,4,2};
    int target = 1;
    vector<int>result = GetPairSumIndex(input,target);
    cout<<result[0]<<" "<<result[1]<<endl;
    return 0;
}
