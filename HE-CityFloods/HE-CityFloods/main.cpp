//
//  main.cpp
//  HE-CityFloods
//
//  Created by Kshitij Banerjee on 09/10/16.
//  Copyright © 2016 Kshitij Banerjee. All rights reserved.
//


#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <numeric>

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
typedef pair<int, int> pii;
#define ll long long

#define sz(a) int((a).size())
#define pb push_back
#define all(x) x.begin(), x.end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

#include <unordered_map>
#include <algorithm>

int find_set( int i , vi& parent){
    if( parent[i] != i ) parent[i] = find_set( parent[i], parent );
    return parent[i];
}
void merge(int i , int j, vi& parent, vi& rank){
    
    int I, J;
    I = find_set(i,parent);
    J = find_set(j,parent);
   
    if( I == J ) return ;
    if( rank[I] > rank[J] ){ parent[J] = I; }
    else{
        parent[I] = J;
        if( rank[I] == rank[J] ) rank[J] ++;
    }
    
}

int main(int argc, const char * argv[]) {
    int N, C;
    cin >> N >> C;
    vi parent(N,0);
    vi rank(N,1);
    iota(all(parent), 0);
    
    
    while( C-- ){
        int i,j;
        cin >> i >> j;
        merge(i-1,j-1, parent, rank);
    }
    
    for_each( all(parent), [parent](int x) mutable -> void {::find_set(x, parent);});
    set<int> remaining(all(parent));
    
    cout << remaining.size();
    return 0;
}
