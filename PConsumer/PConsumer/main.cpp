//
//  main.cpp
//  PConsumer
//
//  Created by Kshitij Banerjee on 16/11/16.
//  Copyright © 2016 Kshitij Banerjee. All rights reserved.
//

#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>


using namespace std;

class Broker{
    vector<int> messages;
    int readers;
    bool w;
    mutex rm;
    mutex wm;
    
    condition_variable cv;
    int size;
public:
    Broker(int sz) : size(sz), readers(0) {};
    
    void write(int i){
        unique_lock<mutex> l(wm);
        cv.wait(l, [&] { return readers == 0; });
                
        messages.push_back(i);
        cout << " Pushed : " << i << endl;
        l.unlock();
        cv.notify_all();
    }
    
    int read(){
        
        // if no writer.. add reader
        unique_lock<mutex> wl(wm);
        cv.wait(wl, [&]{ return w == 0; });
        
        unique_lock<mutex> rl(rm);
        readers++;
        rl.unlock();
        
        for( auto i : messages ) cout << i << " ";
        
        rl.lock();
        readers--;
        if( readers == 0 ) cv.notify_one();
        rl.unlock();
        
        
    }
};

class Producer{
    Broker* b;
public:
    Producer(Broker* brok) : b(brok) {}
    
    void operator()(int x){
        
        for( int  i = 0; i < 10; i ++ ){
            
            b->push( rand() % x );
          
        }
    }
    
};

class Consumer{
    Broker* b;
    
public:
    Consumer(Broker* brok) : b(brok){}

    void operator()(){
        for( int i =0 ; i < 10; i ++ )
            b->pop();
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    
    Broker b(10);
    
    Producer p(&b);
    Consumer c(&b);
    
    thread t1(p, 10);
    thread t2(c);
    
    t2.join();
    t1.join();
    
    
    return 0;
}
