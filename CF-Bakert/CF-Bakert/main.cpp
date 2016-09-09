#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <set>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

#define sz(a) int((a).size())
#define pb push_back
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

int main(int argc, const char * argv[]) {
    int n,m,k;
    cin >> n;
    cin >> m;
    cin >> k;
    
    if( k <= 0){
        cout << "-1";
        return 0;
    }
    
    vector< priority_queue< ii, vector<ii>, greater<ii> > > G(n+1);
    
    for( int i =0; i < m ; i ++){
        int s, e, l;
        cin >> s;
        cin >> e;
        cin >> l;
        
        G[s].push( make_pair(l,e) );
        G[e].push( make_pair(l,s) );
    }
    
    vector< int > storages(n+1, 0);
    set<int> ks;
    
    for( int i =0 ;i < k ; i ++ ){
        int ki;
        cin >> ki;
        storages[ki] = 1;
        ks.insert(ki);
    }
    
    int min_cost = INT_MAX;
    for( auto store : ks ){
        
        while( !G[store].empty() ){
            
            ii edge = G[store].top();
            G[store].pop();
            
            if( storages[edge.second]){
                continue;
            }
            
            min_cost = min(min_cost, edge.first);
            break;
        }
    }
    
    
    cout << (min_cost == INT_MAX ? -1 : min_cost) ;
    return 0;
}
