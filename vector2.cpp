
#include<iostream>
#include<vector>

using namespace std;



int main(){
	
   
    int n;
    cin>>n;

    
	vector<int> v;
	vector<int>v2(n,0);
	vector<int>::iterator it;
   
	for(int i=0;i<n;i++){
		int test;
		cin>>test;
		v.push_back(test);
		v2[test]++;
	} 
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		int testCase;
		cin>>testCase;
		int countAns = v2[testCase];
		if(countAns == 0){
			cout<<"NOT PRESENT"<<endl;
		}else{
			cout<<countAns<<endl;
		}
	}
    
    return 0;
}
