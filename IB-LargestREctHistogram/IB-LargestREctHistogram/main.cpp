//
//  main.cpp
//  IB-LargestREctHistogram
//
//  Created by Kshitij Banerjee on 28/12/16.
//  Copyright © 2016 Kshitij Banerjee. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;


int largestRectangleArea(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if( A.size() == 1 ) return A[0];
    if( A.empty() ) return 0;
    
    int ans = INT_MIN;
    A.push_back(0); // sentinel to close the loops.
    stack<pair<int,int>> st;
    st.push(make_pair(0,0));
    
    for( int i = 0; i < A.size(); i ++ ) {
        if( A[i] == st.top().first){
            st.pop();
            st.push(make_pair(A[i],i+1));
            continue;
        }
        else if( A[i] > st.top().first ){
            st.push(make_pair(A[i],i+1) );
        }
        else{
            
            while( st.top().first > A[i]){
                pair<int,int> peak = st.top();
                st.pop();
                ans = max( ans, peak.first * (i-st.top().second) );
            }
            if( A[i] == st.top().first) st.pop();
            
            st.push(make_pair(A[i],i+1) );
        }
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[] = { 78, 65, 65, 2, 86, 20, 73, 95, 1, 67, 32, 26, 83, 67, 90, 16, 98, 60, 84, 56, 9, 1, 84, 16, 9, 9, 86, 47, 19, 80, 82, 58, 49, 27, 23, 70, 51, 53, 22, 65, 23, 90, 26, 40, 8, 48, 67, 64, 57, 86, 100, 17, 91, 83, 9, 30, 68, 77, 98, 1, 80, 36, 93, 20, 16, 7, 21, 88, 100, 84, 43, 57, 22, 60, 78, 11, 42, 73, 11, 90, 98, 83, 89, 23, 17, 35, 78, 76, 80, 39, 63, 93, 7, 72
  };
    vector<int> inp(arr, arr + 94);
    std::cout << largestRectangleArea(inp);
    return 0;
}
