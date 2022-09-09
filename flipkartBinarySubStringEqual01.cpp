#include<iostream>
#include<vector>
#include<map>
using namespace std;

int lengthBinary(string A){
    map<int,int> m;
    m[0] = -1;
    int count_0=0;
    int count_1 = 0;
    int res = 0;
    for(int i=0;i<A.size();i++){
        if(A[i] == '0'){
            count_0++;
        }else{
            count_1++;
        }
        // cout<<count_0<<" "<<count_1<<endl;
        if(m.find(count_1-count_0) != m.end()){
            res = max(res,i-m[count_1-count_0]);
        }else{
            m[count_1-count_0] = i;
        }        
    }
    return res;

}

int main(){
    string s = "101001000";

    int result = lengthBinary(s);
    cout<<"length is "<<result<<endl;

}