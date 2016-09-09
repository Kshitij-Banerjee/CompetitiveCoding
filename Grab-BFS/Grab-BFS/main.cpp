//
//  main.cpp
//  Grab-Task1
//
//  Created by Kshitij Banerjee on 21/08/16.
//  Copyright (c) 2016 Kshitij Banerjee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

typedef vector<string> vs;
typedef vector<string>::iterator vis;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
#define mPR make_pair
#define PR pair
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

#define sz(a) int((a).size())
#define pb push_back
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

#include <algorithm>
using namespace std;


map<int, int> bfs( vvi &G, int capital, int total) {
    
    queue< ii > Q;
    Q.push(mPR(capital,0));
    map<int, int> M;
    
    while( !Q.empty() ){
        
        ii node = Q.front();
        Q.pop();
        
        M[node.second]++;
        
        vi edges = G[node.first];
        for( auto i : edges ){
            Q.push(mPR(i, node.second + 1));
        }
    }
    
    return M;
}

vector<int> solution(vector<int> &T) {
    vvi G(T.size() + 2);
    int capital = -1;
    for( int i =0; i < T.size(); i++){
        G[i].push_back(T[i]);
        G[T[i]].push_back(i);
        if( T[i] == i )
            capital = i;
    }
    
    map<int, int> M = bfs(G, capital, T.size());
    vector<int> output(T.size(), 0);
    for( int i = 0; i < T.size(); i++ ){
        output[i] = M[i];
    }
    
    return output;
}

int main(int argc, const char * argv[]) {
    
    int arr[] = { 9, 1, 4, 9, 0, 4, 8, 9, 0, 1 };
    vector<int> inp(arr, arr + 10);
    vector<int> output = solution(inp);
    for( auto i : output) {
        cout << i << endl;
    }
    return 0;
}
