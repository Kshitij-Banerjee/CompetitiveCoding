//
//  main.cpp
//  Uber-IntPartionEq
//
//  Created by Kshitij Banerjee on 22/08/16.
//  Copyright (c) 2016 Kshitij Banerjee. All rights reserved.
//


#include <iostream>
#include <map>
#include <vector>
using namespace std;


static int final_count = 0;

// Returns true if there is a subset of set[] with sun equal to given sum
bool isSubsetSum(int set[], int n, int sum, int count, map<int, int>& dp)
{
    
    cout << "n " << n << " sum " << sum << " count " << count << " final " << final_count << endl;
    if( dp[sum] != 0)
        return dp[sum];
    
    // Base Cases
    if (sum == 0){
        dp[sum] = count == final_count;
        return dp[sum];
    }
    if (n == 0 && sum != 0)
        return false;
    
    bool exclude = isSubsetSum(set, n-1, sum, count, dp );
    bool include = isSubsetSum(set, n-1, sum-set[n-1], count+1, dp);
    
    return exclude || include;
}

int main(int argc, const char * argv[]) {
    
    map<int, int> dp;
    
    int arr[]  = { -5, 1, 1, 3, 0, 4 };
    int total_sum = 0;
    for( int i = 0; i < 6; i++ )
        total_sum += arr[i];
    final_count = 3;
    for( int i = total_sum/2; i > 0; i --){
        if( isSubsetSum(arr, 6, i, 0, dp) ){
            cout << "Minimum difference is " << abs(i - (total_sum -i)) << endl;
            return 0;
        }
    }
    
    
    return 0;
}
