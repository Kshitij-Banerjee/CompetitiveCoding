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

static int set_size = 0;

static int dx[4] = { 1, 0, -1, 0 };
static int dy[4] = { 0, 1, 0, -1 };

unsigned nChoosek( unsigned n, unsigned k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;
    
    int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}


void bfs( vector<string>& grid, vector<vector<int> >& arr, int i, int j){
    
    if( arr[i][j] == 'V') return;
    
    queue<ii> q;
    
    q.push(mPR(i, j));
    
    while( !q.empty() ){
        ii pos = q.front();
        q.pop();
        
        if( pos.first <0 || pos.first >= grid.size() || pos.second <=0 || pos.second >= grid[0].length() )
            continue;
        
        if( grid[pos.first][pos.second] == 'N')
            continue;
        
        if( arr[pos.first][pos.second] != -1 )
            continue;
        
        arr[pos.first][pos.second] = set_size;
        
        if( grid[pos.first][pos.second == 'Y'] )
            for( int k = 0; k < 4; k++){
                q.push(mPR( pos.first + dx[k], pos.second + dy[k]));
            }
    }
}

int Group(vector<string> grid) {
    
    vector<vector<int> > arr(grid.size(), vector<int>(grid[0].length(), -1));
    
    for( int i = 0; i < grid.size(); i ++ ){
        for( int j = 0; j < grid[0].size(); j++ ){
            
            if( grid[i][j] == 'N')
                continue;
            else if(arr[i][j] == -1){
                set_size ++;
                bfs(grid, arr, i , j);
            }
            
        }
    }
    long ans = 0;
    cout << "Set size = "  << set_size << endl;
    for( int i = 0; i <= set_size; i+=2) {
        ans += nChoosek(set_size, i );
        ans %= 1000000007;
    }
   
    for( int i = 0; i < grid.size(); i ++ ){
        for( int j = 0; j < grid[0].size(); j++ ){
            cout << arr[i][j] << ": " ;
        }
        cout << endl;
    }
    
    return ans;
}


int main(int argc, const char * argv[]) {
    
    string arr[] = { "YNNYNY", "NYNYNN", "NYNNYN", "YNYNNN" };
    vector<string> inp( arr, arr+4);
    cout << Group(inp) << endl;
    return 0;
}
