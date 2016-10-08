//
//  Queue.cpp
//  ProducerConsumer
//
//  Created by Kshitij Banerjee on 23/09/16.
//  Copyright © 2016 Kshitij Banerjee. All rights reserved.
//

#include "Queue.hpp"

#include <mutex>
#include <condition_variable>
#include <iostream>

void MQueue::push(int i){
    
    unique_lock<mutex> lock(_mx);
    cv.wait(lock, [this]{ return this->_Q.size() < 10; });
    _Q.push_back(i);
    cout << "Pushed "<<  i << endl;
    cout << "Queue : ";
    for( int i = 0; i < _Q.size(); i ++ ) cout << _Q[i] << " " ;
    cout << endl;
    cout << endl;
    lock.unlock();
    cv.notify_one();
}

int MQueue::pop(){
    
    unique_lock<mutex> lock(_mx);
    cv.wait(lock, [this]{ return this->_Q.size() > 0; });
    
    int i = _Q.back();
    _Q.pop_back();
    cout << "Popped " <<  i << endl;
    cout << "Queue : ";
    for( int i = 0; i < _Q.size(); i ++ ) cout << _Q[i] << " " ;
    cout << endl;
    cout << endl;
    lock.unlock();
    cv.notify_one();
    return i;
}
