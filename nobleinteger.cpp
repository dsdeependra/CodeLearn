#include<iostream>
#include<vector>

using namespace std;

// void removeDuplicate(vector<int> &A){
//     for(int i = 0;i<A.size()-1;i++){
//         if(A[i] == A[i+1]){
//             A.erase(A.begin()+(i));
//         }
//     }
    

//     for(int i = 0;i<A.size()-1;i++){
//         cout<<A[i]<<" ";
//     }
// }

int isNoble(vector<int> &v){
    sort(v.begin(), v.end()) ;
	int size_v = v.size();
	for(int i=0;i<size_v;i++){
		while(i+1<size_v && v[i]==v[i+1])
			i++;
		if(v[i]==size_v-1-i)
			return 1;
	}
	return -1;
}

int main(){
    vector<int>v;
    // int A[] = { -4, 7, 5, 3, 5, -4, 2, -1, -9, -8, -3, 0, 9, -7, -4, -10, -4, 2, 6, 1, -2, -3, -1, -8, 0, -8, -7, -3, 5, -1, -8, -8, 8, -1, -3, 3, 6, 1, -8, -1, 3, -9, 9, -6, 7, 8, -6, 5, 0, 3, -4, 1, -10, 6, 3, -8, 0, 6, -9, -5, -5, -6, -3, 6, -5, -4, -1, 3, 7, -6, 5, -8, -5, 4, -3, 4, -6, -7, 0, -3, -2, 6, 8, -2, -6, -7, 1, 4, 9, 2, -10, 6, -2, 9, 2, -4, -4, 4, 9, 5, 0, 4, 8, -3, -9, 7, -8, 7, 2, 2, 6, -9, -10, -4, -9, -5, -1, -6, 9, -10, -1, 1, 7, 7, 1, -9, 5, -1, -3, -3, 6, 7, 3, -4, -5, -4, -7, 9, -6, -2, 1, 2, -1, -7, 9, 0, -2, -2, 5, -10, -1, 6, -7, 8, -5, -4, 1, -9, 5, 9, -2, -6, -2, -9, 0, 3, -10, 4, -6, -6, 4, -3, 6, -7, 1, -3, -5, 9, 6, 2, 1, 7, -2, 5 };

    int A[] = { 1, 2, 7, 0, 9, 3, 6, 0, 6};
    
    int size = sizeof(A)/sizeof(A[0]);
    //cout<<size<<endl;
    for(int i = 0;i<size;i++){
        v.push_back(A[i]);
    }
    int isNobleInt = isNoble(v);
    cout<<isNobleInt<<endl;
    
}

