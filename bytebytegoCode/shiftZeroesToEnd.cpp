#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> ShiftZeroesToEndBasic(vector<int>&input){
    vector<int>result;
    int count =0;
    for(int i :input){
        if(i !=0){
            result.push_back(i);
            count++;
        }
    }
    while(count<input.size()){
        result.push_back(0);
    }
    return result;
}

void ShiftZeroesToEndInPlace(vector<int>&input){
    int left = 0;
    int right = 1;
    int len = input.size();
    while(right < len){
        if(input[left] !=0){
            left++;right++;
        }
        if(input[left] == 0 ){
            if(input[right] !=0){
                swap(input[left],input[right]);
                left++;
                right++;
            }
            if(input[right] ==0){
                right++;
            }
        }
    }
}

int main (){
    vector<int> input = {0,1,0,3,2};
    ShiftZeroesToEndInPlace(input);

    for(int i: input){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;

}
