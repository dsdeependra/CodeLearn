#include<iostream>
#include<cstdio>

using namespace std;



int getCount(string A , int n){
	
	int count =0;
    if(n == 0 || n == 1){
        return 1;
    }
    if(A[n-1] >= '0'){
        count = getCount(A,n-1);
    }
    
    if(A[n-2] == '1' || (A[n-2] == '2' && A[n-1] < '7')){
        count += getCount(A,n-2);
    }
    return count;
}


int getCountDP(string A , int n){
	 int count[n];
	
    if(n == 1){
	    if(A == "0"){
	        //count[i] = 0;
	        return 0;
		}else{
			return 1;
		}
	   
	}
	count[0] = 1;
	count[1] = 1;
   
	for(int i=2;i<n;i++){
		if(A[i-1] > '0'){
			count[i] = count[i-1];
		}
		
		if(A[i-2] == '1' || (A[i-2] == '2' && A[i-1] < '7')){
			count[i] += count[i-2];
		}
		if(A[i-1] == '0' && A[i-2] > '2' ){
			return 0;
		}
	}
    return count[n-1];
}


int main() {
	
	string A ="2611055971756562";
    int n = A.length();
    int count = getCountDP(A,n);
    cout<<count<<endl;
    return 0;
}
