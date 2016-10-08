#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


void swap( vector<int>& arr, int i, int j){
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}
int main(){
    int T;
    cin >> T;
    for(int a0 = 0; a0 < T; a0++){
        int n;
        cin >> n;
        vector<int> q(n);
        for(int q_i = 0;q_i < n;q_i++){
            cin >> q[q_i];
        }
        
        unordered_map<int, vector<int> > map;
        for( int i = 0; i < q.size(); i ++ ){
            map[abs(q[i] -i -1)].push_back(i);
        }
        
        bool chaotic = false;
        for( auto i : map ){
            if( i.first > 2 && !i.second.empty() ){
                chaotic = true;
                break;
            }
        }
        if(chaotic) {
            cout << "Too chaotic" << endl;
            continue;
        }
        
        vector<int> two = map[2];
        int changes = 0;
        for( auto i : two){
            int value = q[i];
            
            if( value > i+1 ){
                swap(q, i, i+1);
                swap(q, i+1, i+2);
                changes += 2;
                if(q[i]-i-1 == 0){
                    map[1].erase(remove(map[1].begin(), map[1].end(), i+1), map[1].end());
                }
                if( q[i+1] - i -2  == 0 ){
                    map[1].erase(remove(map[1].begin(), map[1].end(), i+2), map[1].end());
                }
            }else{
                swap(q, i, i-1);
                swap(q, i-1, i);
                changes += 2;
                if(q[i]-i+1 == 0){
                    map[1].erase(remove(map[1].begin(), map[1].end(), i-1), map[1].end());
                }
                if( q[i-1]-(i-1)+1  == 0 ){
                    map[1].erase(remove(map[1].begin(), map[1].end(), i-2), map[1].end());
                }
            }
        }
        
        while( !map[1].empty() ){
            int i = map[1][0];
            int value = q[i];
            if( value  > i + 1 ){
                changes ++;
                swap(q[i], q[i+1]);
                map[1].erase(remove(map[1].begin(), map[1].end(), i), map[1].end());
                map[1].erase(remove(map[1].begin(), map[1].end(), i+1), map[1].end());
            }
            else{
                changes ++;
                swap(q[i],q[i-1]);
                map[1].erase(remove(map[1].begin(), map[1].end(), i), map[1].end());
                map[1].erase(remove(map[1].begin(), map[1].end(), i-1), map[1].end());
            }
        }
        
        cout << changes << endl;
    }
    
    return 0;
}

