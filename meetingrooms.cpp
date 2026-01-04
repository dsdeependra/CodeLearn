#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>

using namespace std;

bool canAttendAllMeetings(vector<vector<int>>&intervals){
    sort(intervals.begin(),intervals.end());
    int n = intervals.size();
    int nextStart = INT_MAX;
    for(int i=0;i<n;i++){
        if(i < n-1){
            nextStart = intervals[i+1][0];
        }
        if(intervals[i][0] < nextStart){
            return false;
        }
    }
    return true;
}

int findMinimumRooms(vector<vector<int>>&intervals){
    sort(intervals.begin(),intervals.end());
    int n = intervals.size();
    priority_queue<int>pq;   //minHeap
    int globalMax = 0;
    int nextStart = INT_MAX;
    for(int i=0;i<n;i++){
        if(i < n-1){
            nextStart = intervals[i+1][0];
        }
        //start meeting
        if(intervals[i][1] > nextStart){
            pq.push(intervals[i][1]);
        }
        globalMax = (globalMax >= pq.size()) ? globalMax : pq.size();
        while(!pq.empty() &&  pq.top() <= nextStart){
            pq.pop();
        }
    }
    return globalMax;
}

int main(){
    vector<vector<int>> meetings = {{0, 30}, {5, 10}, {15, 20}};
    int minRoom = findMinimumRooms(meetings);
    cout<<"minimum rooms required for conducting all meetings are :"<<minRoom<<endl;
    return 0;
}