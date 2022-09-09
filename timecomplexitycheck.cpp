#include <iostream>
#include <vector>
using namespace std;
int cnt=0;
int searchNumOccurrence(vector<int> &V, int k, int start, int end) {
cout<<"1";
cnt+=1;
if (start > end) return 0;
int mid = (start + end) / 2;
if (V[mid] < k) return searchNumOccurrence(V, k, mid + 1, end);
if (V[mid] > k) return searchNumOccurrence(V, k, start, mid - 1);
return searchNumOccurrence(V, k, start, mid - 1) + 1 + searchNumOccurrence(V, k, mid + 1, end);
}
int main(){

vector<int> V{4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};
for(int i=0; i<11; i++){
cout<<i+1<<" - ";
searchNumOccurrence(V, 4, 0, i);
cout<<" - "<<cnt<<endl;
cnt = 0;
}
return(0);
}