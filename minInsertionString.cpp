#include<iostream>

using namespace std;

int findMinInsertion(char str[], int l, int h){
    if(l > h) return INT_MAX;
    if(l == h) return 0;
    if(l == h-1) return (str[l] == str[h]) ? 0 : 1;

    return (str[l] == str[h])? findMinInsertion(str,l+1,h-1) : min(findMinInsertion(str,l+1,h),findMinInsertion(str,l,h-1)) +1;
}


int findMinInsertionDP(char str[] , int n){
    int table[n][n],l,h,gap;
    memset(table,0,sizeof(table));

    for(gap = 0;gap<n;++gap){
        for(l = 0,h=gap;h<n;++l,++h){
            table[l][h] = (str[l] == str[h]) ? table[l+1][h-1] : min(table[l][h-1],table[l+1][h]) + 1;
        }
    }

    return table[0][n-1];
}


int main(){
    char str[] = "abcde";
    int sol = findMinInsertion(str,0,strlen(str)-1);
    int sol2 = findMinInsertionDP(str,strlen(str));
    cout<<sol2<<endl;
}