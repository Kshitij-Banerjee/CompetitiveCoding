//
//  main.cpp
//  IB-LRUCache
//
//  Created by Kshitij Banerjee on 12/11/16.
//  Copyright © 2016 Kshitij Banerjee. All rights reserved.
//

#include <iostream>
#include <unordered_map>
using namespace std;


struct LLNode{
    int key;
    LLNode* next;
    LLNode* prev;
    LLNode(int val) : key(val), next(NULL), prev(NULL) {}
};

LLNode* head;
unordered_map<int, LLNode*> map_of_indexes;
unordered_map<int, int> kv_map;
int cap;

class LRUCache{
public:
    int get( int);
    void set(int, int);
    LRUCache(int);
    
};

LRUCache::LRUCache(int capacity) {
    
    head = NULL;
    map_of_indexes.clear();
    kv_map.clear();
    cap = capacity;
}

int LRUCache::get(int key) {
    if( kv_map.find(key) != kv_map.end() ){
        LLNode* node = map_of_indexes.find(key)->second;
        if( node->prev ) node->prev->next = node->next;
        if( node->next ) node->next->prev = node->prev;
        node->prev = NULL;
        node->next = head;
        head = node;
        return kv_map.find(key)->second;
    }
    
    return -1;
}

void LRUCache::set(int key, int value) {
    
    if( get(key) != -1 ) return;
    
    kv_map.insert(make_pair(key,value));
    LLNode* node = new LLNode(key);
    map_of_indexes.insert(make_pair(key,node));
    
    node->next = head;
    if( head ) head->prev = node;
    head = node;
    
    if( kv_map.size() > cap ){
        LLNode* last = head;
        while( last->next != NULL )
            last = last->next;
        
        if( last->prev ) last->prev->next = NULL;
        else head = node;
        
        kv_map.erase(last->key);
        map_of_indexes.erase(last->key);
        delete last;
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    LRUCache cache(1);
    cache.set(2,1);
    cache.get(2);
    cache.set(3,2);
    cache.get(2);
    cache.get(3);
    return 0;
}
