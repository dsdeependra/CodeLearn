#include<iostream>

using namespace std;

bool ischeck(string a){
    int count = 0;
    if((a[0] == 'A' || a[0] == 'B' || a[0] == 'C')){
            count =1;
    }
    for(int i=1 ; i<a.size();i++){
        if((a[i] == 'A' || a[i] == 'B' || a[i] == 'C') && (a[i] != a[i-1])){
            count++;
        }else if((a[i] == 'A' || a[i] == 'B' || a[i] == 'C') && (a[i] == a[i-1])){
            count = 1;
        }
        else{
            count =0;
        }
        //cout<<count<<" "<<a[i]<<endl;
        if(count == 3){
            return true;
        }
    }

    return false;
}

int main(){
    string a;
    cin>>a;

    if(ischeck(a)){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    

}