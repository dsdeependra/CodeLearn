#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> GetTriplets(vector<int> &num) {
    vector<int> result;
    int n = num.size();
    
    // Sort the array
    sort(num.begin(), num.end());
    
    // Iterate through the array
    for (int i = 0; i < n - 2; i++) {
        // Skip duplicates
        if (i > 0 && num[i] == num[i - 1]) continue;
        
        int left = i + 1;
        int right = n - 1;
        
        while (left < right) {
            int sum = num[i] + num[left] + num[right];
            if (sum == 0) {
                result.push_back(num[i]);
                result.push_back(num[left]);
                result.push_back(num[right]);
                
                // Skip duplicates for left and right
                while (left < right && num[left] == num[left + 1]) left++;
                while (left < right && num[right] == num[right - 1]) right--;
                
                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }
    
    return result;
}
#include <unordered_map>

int main (){

    vector<int>num = {1,2,-2,1,-1,2};
    vector<int>result = GetTriplets(num);
    
    cout<< "Triplets that sum to zero: ";
    for (size_t i = 0; i < result.size(); i += 3) {
        cout << "{" << result[i] << ", " << result[i + 1] << ", " << result[i + 2] << "} ";
    }
    cout << endl;
    return 0;
}