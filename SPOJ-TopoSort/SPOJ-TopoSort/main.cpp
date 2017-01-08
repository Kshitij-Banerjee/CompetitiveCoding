//
//  main.cpp
//  SPOJ-TopoSort
//
//  Created by Kshitij Banerjee on 07/01/17.
//  Copyright © 2017 Kshitij Banerjee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);
    
    vector<vector<int> > graph(N);
    vector<int> incount(N);
    
    while( M -- ){
        int x, y;
        scanf("%d", &x);
        scanf("%d", &y);
        
        graph[x-1].push_back(y-1);
        incount[y-1]++;
    }
    
    
    vector<int> output;
    
    priority_queue<int, vector<int>, ::greater<int> > Q;
    for( int i = 0; i < graph.size(); i ++ ) {
        if( incount[i] == 0 ) Q.push(i);
    }
    
    int visited_count = 0;
    
    while( !Q.empty() ) {
        int top = Q.top();
        Q.pop();
        visited_count ++;
        output.push_back(top+1);
        for( auto x : graph[top] ) {
            incount[x]--;
            if( incount[x] == 0 )
                Q.push(x);
        }
    }
    
    if( visited_count != N ) {
        cout << "Sandro fails.";
        return 0;
    }
    
    
    for( int i = 0; i < output.size()-1; i ++ ) {
        cout << output[i] << " ";
    }
    cout << output.back();
    
    return 0;
}
