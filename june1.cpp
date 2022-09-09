#include<iostream>
#include<cmath>
#include<vector>
#include<iomanip>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;

        vector<int> v;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            v.push_back(temp);
        }
        vector<int>::iterator it;
        int count_a = 0;
        int count_b = 0;
        for(it = v.begin();it!=v.end();++it){
            if(*it == a){
                count_a++;
            }
            if(*it == b){
                count_b++;
            }
        }
        std::cout << std::setprecision(10) << std::fixed;        
        double result = (count_a / (double)n) * (count_b / (double)n);
        cout<<result<<endl;
    }

    return 0;
}