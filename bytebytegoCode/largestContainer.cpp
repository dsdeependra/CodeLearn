#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int GetLargestContainer(vector<int>& heights) {
    int maxArea = 0;
    int left = 0;
    int right = heights.size() - 1;

    while (left < right) {
        int width = right - left;
        int height = min(heights[left], heights[right]);
        int area = width * height;
        maxArea = max(maxArea, area);

        if (heights[left] < heights[right]) {
            left++;
        } else {
            right--;
        }
    }

    return maxArea;
}

int main() {
    vector<int> heights= {2,7,8,3,7,6};
    int result = GetLargestContainer(heights);
    cout<<result<<endl;
    
    return 0;
}
