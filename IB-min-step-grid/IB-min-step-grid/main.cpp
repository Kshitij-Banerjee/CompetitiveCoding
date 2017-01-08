//
//  main.cpp
//  IB-min-step-grid
//
//  Created by Kshitij Banerjee on 11/10/16.
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
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

#include <unordered_map>
#include <algorithm>
// Input : X and Y co-ordinates of the points in order.
// Each point is represented by (X[i], Y[i])

int distance( pair<int,int> start, pair<int,int> end ){
    return max( abs(start.first - end.first) , abs(start.second - end.second) );
}

int coverPoints(vector<int> &X, vector<int> &Y) {
    int dist = 0;
    pair<int,int> start = make_pair(X[0], Y[0]);
    vector< pair<int,int> > vec;
    for( int i = 1; i < X.size(); i ++ ){
        vec.push_back( make_pair(X[i],Y[i]) );
    }
    
    for( auto i : vec ){
        dist += distance( start, i );
        start = i;
    }
    return dist;
}


int main(int argc, const char * argv[]) {
    int x[] = { -7 };
    int y[] = { -1 };
    vi X(x, x+1);
    vi Y(y, y+1);
    cout << coverPoints( X, Y);
    return 0;
}
