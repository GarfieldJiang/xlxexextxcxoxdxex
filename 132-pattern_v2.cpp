// https://leetcode.com/problems/132-pattern/description/

#include <vector>
#include <iostream>
#include <chrono>
#include <ratio>
#include <cmath>

using namespace std;
using namespace std::chrono;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int size = nums.size();
        vector<int> mins(size);
        vector<int> maxs(size);
        
        int minMaxIndex = -1;
        for (int i = 0; i < size; i++) {
            if (minMaxIndex < 0 || nums[i] < mins[minMaxIndex]) {
                minMaxIndex++;
                //cout << "minMaxIndex: " << minMaxIndex << endl;
                maxs[minMaxIndex] = mins[minMaxIndex] = nums[i];
                continue;
            }
            
            int afterWhich = binarySearchForInclusion(nums[i], mins, maxs, minMaxIndex + 1);
            if (afterWhich < 0) {
                return true;
            }
            
            int newMinMaxIndex = afterWhich;
            maxs[newMinMaxIndex] = nums[i];
            mins[newMinMaxIndex] = mins[minMaxIndex];
            minMaxIndex = newMinMaxIndex;
            //cout << "minMaxIndex: " << minMaxIndex << endl;
        }
        
        return false;
    }
    
    // return value:
    //   0 and positive: the index of interval after which num falls.
    //   -1: included in some interval.
    int binarySearchForInclusion(int num, vector<int>& mins, vector<int>& maxs, int count) {
        int afterWhich = 0;
        for (int beg = 0, end = count, mid = end / 2; beg < end; mid = beg + (end - beg) / 2) {
            //cout << "beg: " << beg << ", end: " << end << ", mid: " << mid << endl;
            if (num < maxs[mid] && num > mins[mid]) {
                return -1;
            }
            
            if (num >= maxs[mid]) {
                end = mid;
                afterWhich = mid;
            } else {
                beg = mid + 1;
                afterWhich = mid + 1;
            }
        }
        
        return afterWhich;
    }
};

// Performance test
int main()
{
    int start = 1 << 5;
    int stepMultiplier = 2;
    int end = 1 << 25;

    for (int n = start; n <= end; n *= stepMultiplier) {
        vector<int> input;
        for (int i = 0; i < n; i++) {
            input.push_back(2 * n - i);
        }

        for (int i = n; i < 2 * n; i++) {
            input.push_back(-2 * n + i);
        }

        Solution solution;
        high_resolution_clock::time_point startTime = high_resolution_clock::now();
        solution.find132pattern(input);
        high_resolution_clock::time_point endTime = high_resolution_clock::now();
        duration<double, milli> ms = endTime - startTime;

        double nLogN = n * log(double(n)) / log(double(2));
        cout << "n = " << n << ", n*log(n) = " << nLogN <<  ", ms = " << ms.count()
             << ", n/ms = " << n / ms.count() << ", n*log(n)/ms = " << nLogN / ms.count() <<  endl;
    }

    return 0;
}
