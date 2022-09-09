#include<iostream>
#include<cstdio>

using namespace std;

int getonecount(unsigned number){    
    unsigned temp = number;
    int i=0;
    int count_one  = 0;
    if(number  == 0 ){
        return 0;
    }
    else if(number < 1){
        return 1;
    }else{
        for(long i= 0; temp>0;i++){
            int check_one = temp % 2;            
            temp = temp / 2;
            if(check_one == 1){
                count_one++;
            }
        }
    }
    return count_one;
}

int main(){
    unsigned number = 4294967295;
    int one_count = getonecount(number);
    cout<<one_count<<endl;
    return 0;
}
