//
//  main.cpp
//  HR-RangeMin
//
//  Created by Kshitij Banerjee on 06/10/16.
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


class SegTree{
private:
    vi _tree;
    vi _arr;
    
    void build(int i , int j, int index){
        if( i == j ){
            _tree[index] = _arr[i];
            return;
        }
        
        int mid = i + (j-i)/2;
        build(i, mid, index*2+1);
        build(mid+1, j, index*2+2);
        
        _tree[index] = min(_tree[index*2+1] , _tree[index*2+2]);
    }
    
    int query( int i , int j, int lo, int high, int index) {
        if( i > high || j < lo ) return INT_MAX;
        if( lo >= i && high <= j ) return _tree[index];
        
        int mid = lo + (high - lo)/2;
        int left = query(i, j, lo, mid, index*2+1);
        int right = query(i, j, mid+1, high, index*2+2);
        return min( left, right ) ;
    }
    
    void update( int x, int y, int i , int j , int index ){
        
        if( i == j ){
            _tree[index] = y;
            return;
        }
        
        int mid = i + (j-i)/2;
        if( x <= mid ){
           update(x, y, i, mid, 2*index+1);
        }
        else{
            update(x, y, mid+1, j, 2*index+2);
        }
        
        _tree[index] = min(_tree[index*2+1], _tree[index*2+2]);
    }
    
public:
    SegTree(vi &arr): _arr(arr) {
        _tree.resize(4*arr.size() + 1);
        
        build(0, (int)arr.size()-1, 0);
    }
    
    int query(int i, int j) {
        return query(i, j, 0, (int)_arr.size()-1, 0);
    }
    
    
    void update(int x, int y){
        update(x,y,0,(int)_arr.size()-1, 0);
    }
};

int main(int argc, const char * argv[]) {
    int N, Q;
    cin >> N >> Q;
    
    
    vi arr(N,0);
    for( int i= 0; i < N;i ++ )
        cin >> arr[i];
    
    SegTree tree( arr );
    
    while(Q--){
        char q;
        cin >> q;
        int i,j;
        cin >> i >> j;
        
        if( q == 'q' )
            cout << tree.query(i-1,j-1) << endl;
        else
            tree.update(i-1,j);
    }
    
    return 0;
}
