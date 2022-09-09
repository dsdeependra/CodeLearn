#include<iostream>
#include<cstream>
#include<vector>

using namespace std;

int getMaxProfit(vector<int>price){
    //if any number of transactions 
    //find the local minima and local maxima and find difference and add

    int n = price.size();
    if(n<=1){
        return 0;
    }
    vector<int>::it;
    int result = 0;
    int diff = 0;
    for(int i =0; i<n-1;i++){
        diff = price[i+1]-price[i];
        if(diff>0){ // it means its a positive slope
            result += diff;
        }
    }

    return result;
}

int getProfitMaxDP(vector<int>price, int k){
    //if only k transaction is permitted then we have to try dynamic programming

    int n = price.size();
    int T[k+1][n];
    for(int i=0;i<n;i++){
        T[0][i] = 0;
    }
    for(int i=0 i<k+1;i++){
        T[i][0] = 0;
    }

    for(int i =1; i<k+1 ; i++){
        for(int j=1;j<n;j++){
            //T[i][j] = max(T[i][j-1] , max(price[i] - price[m] + T[i-1][m]);
            int maxM = 0;
            for(int m = 0 ; m < j; m++){
                maxM = max(maxM,(price[i] - price[m]) + T[i-1][m]);
            }
            T[i][j] = max(maxM , T[i][j-1]);
        }
    }

    // the above implementation can be further optimized..
    // int maxDiff = 0;
    // for(int i = 1; i<k+1;i++){
    //     for(int j =1;j<n;j++){
    //         T[i][j] = max(T[i][j-1] , price[j] + maxDiff);
    //         maxDiff = max(maxDiff , T[i-1][j] - price[j]);
    //     }
    // }

    return T[k+1][n];
}

//if only two transactions allowed .. above approach and follwing can be used

int amxProfitTwoTransaction(vector<int> price){
    int n = price.size();
    int A[n],B[n];
    // max profit from the left 
    int maxLeft = 0;
    int maxRight = 0;
    A[0]= 0;
    for(int i = 1;i<n; i++){
        maxLeft = max(maxLeft , abs(price[i]- price[i-1]));
        A[i] = maxLeft;
    }
    B[n-1] = 0
    for(int i = n-2;i >=0; i++){
        maxRight = max(maxRight , abs(price[i]- price[i-1]));
        A[i] = maxRight;
    }

    //now result 
    int result =0;
    for(int i =0; i<n;i++){
        result = max(result , A[i]+B[i]);
    }

    return result;
}

int main(){
    vector<int>A;
    A.push_back(2);
    A.push_back(5);
    A.push_back(7);
    A.push_back(1);
    A.push_back(4);
    A.push_back(3);
    A.push_back(1);
    A.push_back(3);

    int result = getMaxProfit(A);


    return 0;
}