#include<iostream>
#include<vector>

using namespace std;


vector<vector<int> > generate(int A) {
    vector<vector<int> > v;
    for(int i=0;i<A;i++){
        vector<int>v1;
        for(int j=0;j<=i;j++){
            int val =0;
            if(i == 0){
                val = 1;    
            }else if(j==i){                                
                    val = v[i-1][j-1] ;                                
            }else{
                
                if(j==0){
                    val = v[i-1][j] ;
                }
                else if(j>0){
                    val = v[i-1][j] + v[i-1][j-1];
                }
            }
            v1.push_back(val);
        }
        v.push_back(v1);
    }
    return v;
}

int main(){
    int A;
    cin>>A;
    vector<vector<int> > result;
    result = generate(A);
    vector<int>::iterator it;
    for(int i = 0; i<A; i++){
        for(it = result[i].begin(); it!=result[i].end();++it){
            cout<<*it<<" ";
        }
        cout<<endl;
    }
}