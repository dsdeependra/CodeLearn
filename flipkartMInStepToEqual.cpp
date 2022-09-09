#include<iostream>
#include<vector>

using namespace std;

bool allElementEqual(vector<int>inputArray){
    for(int i=0;i<inputArray.size()-1;i++){
        //cout<<inputArray[i]<<" ";
        if(inputArray[i] != inputArray[i+1]){
            return false;
        }
    }
    //cout<<endl;
    return true;
}

int minStepRequired(vector<int>inputArray , int size){
    int stepCount = 1;
    while(true){
        if(allElementEqual(inputArray)){
            return stepCount;
        }else{
            int max = *max_element(inputArray.begin(),inputArray.end());
            for(int i=0;i<size;i++){
                if(inputArray[i] != max){
                    inputArray[i]++;
                }
            }
            stepCount++;
        }
    }
    return stepCount;
}

int sumArray(vector<int>arr){
    int sum =0;
    for(int i=0;i<arr.size();i++){
        sum +=arr[i];
    }
    return sum;
}


int main(){
    // int inputArray[] = {1,2,3,4,5};
    int n ;
    cin>>n;
    vector<int> inputArray;
    for(int i=0;i< n;i++){
        int temp;cin>>temp;inputArray.push_back(temp);
    }
    // int n = inputArray.size();

    int min = *min_element(inputArray.begin(),inputArray.end());

    int result = sumArray(inputArray) - n*min;
    cout<<result<<endl;
}