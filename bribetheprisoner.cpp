#include<iostream>
#include<cstdio>

using namespace std;

int minBribe(int prisArray[],int low,int high,int minBribeValue){
    //find left prisCount
    int i=low;
    int leftPrisCount =0;
    while(prisArray[i] !=0){
        i++;
        leftPrisCount++;
    }
    //find right
    int j=high;
    int rightPrisCount =0;
    while(prisArray[j] !=0){
        j--;
        rightPrisCount++;
    }

    if(i == j){
        minBribeValue = high-low;
        return minBribeValue;
    }

    int selectedCount;
    
    if(leftPrisCount > rightPrisCount){
        selectedCount = leftPrisCount;    
    }else{
        selectedCount = rightPrisCount;
    } 
    cout<<selectedCount<<endl;
    minBribeValue = selectedCount + high-low ;
    

    if(leftPrisCount > rightPrisCount){
        return minBribe(prisArray,i,high,minBribeValue);
    }
    return minBribe(prisArray,low,j,minBribeValue);

}

int main(){
    int t;
    cin>>t;
    for(int i =1;i<=t;i++){
        int p,q;
        cin>>p>>q;
        int a[q];
        int prisArray[p];
        for(int i=0;i<p;i++){
            prisArray[i] = 1;
        }

        for(int i=0;i<q;i++){
            int test ;
            cin>>test;
            a[i] = test;
            prisArray[test-1] = 0;
        }

        //for(int i=0;i<p;i++){
          //  cout<<prisArray[i]<<" ";
        //}
        
        int result = minBribe(prisArray,0,p-1,0);
        cout<<"case #"<<i<<" "<<result<<endl;
    }

}
