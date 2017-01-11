//
//  main.cpp
//  SPOJ-InversionCount
//
//  Created by Kshitij Banerjee on 11/01/17.
//  Copyright © 2017 Kshitij Banerjee. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

#define ll long long

ll merge(vector<int>& input, int start1, int end1, int start2, int end2){
    vector<int> arr(end2 - start1+1);
    
    int i = 0;
    ll inversions = 0;
    int start_save = start1;
    
    while( (start1 <= end1) && (start2 <= end2) ){
        if( input[start2] < input[start1] ) {
            arr[i++] = input[start2++];
            inversions += ( end1 - start1 + 1);
        }
        else {
            arr[i++] = input[start1++];
        }
    }
    
    while( start1 <= end1 ){
        arr[i++] = input[start1++];
    }
    
    while( start2 <= end2 ){
        arr[i++] = input[start2++];
    }
    
    for( auto i : arr ){
        input[start_save++] = i;
    }
    
    return inversions;
}

ll solve(vector<int>& input, int start, int end){
    
    if( start >= end ) return 0;
    
    int mid = (start + end)/2;
    
    ll one = solve(input, start, mid);
    ll two = solve(input, mid+1, end);
    ll mer = merge(input, start, mid, mid+1, end);
    
    return one + two + mer;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int N ;
    cin >> N ;
    string space;
    getline(cin, space);
    
    while( N -- ) {
        int T;
        cin >> T;
        vector<int> inp(T);

        for( int i = 0; i < T; i ++ ) {
            cin >> inp[i];
        }
        
        getline(cin, space);
        getline(cin, space);
        
        cout << solve(inp,0, (int)inp.size()-1) << endl;
    }
    return 0;
}
