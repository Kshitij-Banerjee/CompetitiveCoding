//
//  main.cpp
//  Leet-JumpGam
//
//  Created by Kshitij Banerjee on 18/08/16.
//  Copyright (c) 2016 Kshitij Banerjee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

// TLE
class Solution {
public:
    
    map<int, bool> P;
    
    bool canJump(vector<int>& nums) {
        if(nums.size() <= 1 ) {
            return true;
        }
        return canJump(nums, 0, nums.size()-1);
    };
    
    bool canJump(vector<int>&nums, int start, int end ){
        if( end <= 0) return true;
        if(P.find(end) != P.end())
            return P[end];
        
        for( int i  = end - 1; i >= 0 ; i--){
            if( nums[i] >= (end -i))
                if( canJump(nums, start, i) ){
                    P[end] = true;
                    return true;
                }
        }
        P[end] = false;
        return false;
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int arr[] = { 2,3,1,1,4 };
    vector<int> input(arr, arr+5);
    
    Solution s;
    cout << s.canJump(input) << endl;
    return 0;
}
