//
//  main.cpp
//  TC-Escape
//
//  Created by Kshitij Banerjee on 19/08/16.
//  Copyright (c) 2016 Kshitij Banerjee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <queue>

using namespace std;

typedef vector<string> vs;
typedef vector<string>::iterator vis;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
#define mPR make_pair
#define PR pair
typedef pair<int, int> pii;

class compare{
public:
    bool operator()(const PR<int,pii>&l, const PR<int, pii>&r){
        return l.first > r.first;
    }
};

class Escape{
    static const int LENGTH = 501;
    int dx[4] = { 1, 0, -1, 0};
    int dy[4] = { 0, 1, 0, -1};
    int cost[LENGTH][LENGTH];
    int visited[LENGTH][LENGTH];
    
public:
    int lowest(vector <string> harmful, vector <string> deadly){
        
        if( harmful.empty() && deadly.empty()) return 0;
        
        initialize(cost);
        initialize(visited);
        visited[0][0] = true;
        
        
//        cout << "cost" << endl;
//        print(cost);
//        cout << "vistied"<<  endl;
//        print(visited);
//        
        for(auto s : harmful)
            fill_box(s, 1);
        for(auto s : deadly)
            fill_box(s, 9);
        
        
//        cout << "cost" << endl;
//        print(cost);
//        cout << "vistied"<<  endl;
//        print(visited);
        
        priority_queue<PR<int, pii>, vector<PR<int,pii> >, greater<PR<int,pii>>> q;
        q.push(mPR(0,mPR(0, 0)));
        
        while(!q.empty() ) {
            
            PR<int,pii> curr = q.top();
            q.pop();
            
            for( int i =0; i < 4; i ++){
                
                int x = curr.second.first;
                int y = curr.second.second;
                int newx = x + dx[i];
                int newy = y + dy[i];
                
                if( newx < 0 || newy < 0 || newx > LENGTH-1 || newy > LENGTH-1) continue;
                if( cost[newx][newy] == 9) continue;
                if( visited[newx][newy] ) continue; // visited
                
                if( newx == LENGTH-1 && newy == LENGTH-1 ) {
                    //print(visited);
                 return curr.first+cost[newx][newy];
                }
                visited[newx][newy] = curr.first + cost[newx][newy];
                //print(visited);
                
                q.push(mPR(curr.first+cost[newx][newy], mPR(newx, newy)));
                
            }
        }
        
        //print(visited);
        return -1;
    }
    
    
private:
    void fill_box(string pos, int weight){
        vector<string> elems;
        stringstream ss(pos);
        string item;
        while(getline(ss, item, ' ')){
            elems.push_back(item);
        }
        
        int x1 = stoi(elems[0]);
        int y1 = stoi(elems[1]);
        int x2 = stoi(elems[2]);
        int y2 = stoi(elems[3]);
        
        
        int xm = min(x1, x2);
        int ym = min(y1, y2);
        int xx = max(x1, x2);
        int yy = max(y1, y2);
        
        for(int x = xm; x <= xx; x++)
            for(int y = ym; y <= yy; y++){
                cost[x][y] = weight;
            }
    }
    
    void print(int v[LENGTH][LENGTH]){
        for( int i = 0; i < LENGTH; i ++ ){
            for(int j = 0; j < LENGTH; j++){
                cout << (v[i][j]) << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    
    void initialize(int v[LENGTH][LENGTH]){
        for(int i = 0; i < LENGTH; i ++ ){
            for( int j = 0; j < LENGTH; j++){
                v[i][j]  = 0;
            }
        }
    }
    
};
int main(int argc, const char * argv[]) {
    
    vs harmful, dangerous;
    
    string first[] = {
        "468 209 456 32","71 260 306 427","420 90 424 492","374 253 54 253","319 334 152 431","38 93 204 84","246 0 434 263","12 18 118 461","215 462 44 317","447 214 28 475","3 89 38 125","157 108 138 264","363 17 333 387","457 362 396 324","95 27 374 175","381 196 265 302","105 255 253 134","0 308 453 55","169 28 313 498","103 247 165 376","264 287 363 407","185 255 110 415","475 126 293 112","285 200 66 484","60 178 461 301","347 352 470 479","433 130 383 370","405 378 117 377","403 324 369 133","12 63 174 309","181 0 356 56","473 380 315 378"};
    
   string second[] = {
       "250 384 355 234","28 155 470 4","333 405 12 456","329 221 239 215","334 20 429 338","85 42 188 388","219 187 12 111","467 453 358 133","472 172 257 288","412 246 431 86","335 22 448 47","150 14 149 11","224 136 466 328","369 209 184 262","274 488 425 195","55 82 279 253","153 201 65 228","208 230 132 223","369 305 397 267","200 145 98 198","422 67 252 479","231 252 401 190","312 20 0 350","406 72 207 294","488 329 338 326","117 264 497 447","491 341 139 438","40 413 329 290","148 245 53 386","147 70 186 131","300 407 71 183","300 186 251 198","178 67 487 77","98 158 55 433","167 231 253 90","268 406 81 271","312 161 387 153","33 442 25 412","56 69 177 428","5 92 61 247"};
    
    for( auto i : first)
        harmful.push_back(i);
    for(auto i : second)
        dangerous.push_back(i);
    
    Escape e;
    
    std::cout << e.lowest(harmful, dangerous);
    return 0;
}
