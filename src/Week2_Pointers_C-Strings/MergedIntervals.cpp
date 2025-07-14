#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    // If there are no intervals, return an empty array.
    if (intervals.empty()) return {};
    
    // Step 1: Sort intervals based on the start time.
    sort(intervals.begin(), intervals.end());
    
    vector<vector<int>> mergedIntervals;
    
    // Step 2: Initialize with the first interval.
    mergedIntervals.push_back(intervals[0]);
    
    for (int i = 1; i < intervals.size(); i++) {
        // If the current interval overlaps with the last merged one
        if (intervals[i][0] <= mergedIntervals.back()[1]) {
            // Merge the intervals by updating the end time of the last merged interval
            mergedIntervals.back()[1] = max(mergedIntervals.back()[1], intervals[i][1]);
        } else {
            // Otherwise, no overlap, so just add the current interval to the result.
            mergedIntervals.push_back(intervals[i]);
        }
    }
    
    return mergedIntervals;
}

int main()
{
    vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};
    vector<vector<int>> result = mergeIntervals(intervals);
    
    // Output the merged intervals.
    for (auto& interval : result) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;
    
    return 0;
}
