//
//  main.cpp
//  ProducerConsumer
//
//  Created by Kshitij Banerjee on 23/09/16.
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
#include "Queue.hpp"
#include "Consumer.hpp"
#include "Producer.hpp"
#include <thread>

int main(int argc, const char * argv[]) {
    
    MQueue q;
    
    thread thread1(&Consumer::consume, Consumer(q), 30 );
    thread thread2(&Producer::produce, Producer(q), 10 );
    thread thread3(&Producer::produce, Producer(q), 10 );
    thread thread4(&Producer::produce, Producer(q), 10 );
    
    
    thread2.join();
    thread1.join();
    thread4.join();
    thread3.join();
    return 0;
}
