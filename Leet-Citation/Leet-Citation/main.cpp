//
//  main.cpp
//  Leet-Citation
//
//  Created by Kshitij Banerjee on 18/08/16.
//  Copyright (c) 2016 Kshitij Banerjee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations_orig) {
        
        if( citations_orig.empty()) return 0;
        
        vector<int> citations;
        for(auto i : citations_orig)
            if( i > 0 )
                citations.push_back(i);
        
        if( citations.empty()) return 0;
        vector<int> counts(citations.size());
        
        
        for( int i =0; i < citations.size(); i++){
            counts[i] = citations.size() - i;
        }
        
        for(auto i: citations) cout << i << " ";
        cout << endl;
        for(auto i: counts ) cout << i << " ";
        cout << endl;
        
        for( int i = citations.size(); i > 0; i-- ) {
            if( citations[i-1] == 0) return counts[i];
            if( counts[i-1] >= citations[i-1])
                return citations[i-1];
        }
        
        return counts[0];
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[] = { 4, 4, 0, 0};
    vector<int> inp(begin(arr), end(arr));
    Solution s;
    cout << s.hIndex(inp);
    return 0;
}
