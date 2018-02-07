//
// Created by Ke Jin on 2/5/18.
//



#ifndef PLAYGROUND_DISJOINT_SET_H
#define PLAYGROUND_DISJOINT_SET_H

#include <vector>

using namespace std;

struct Node{
    Node* parent = nullptr;
    int rank = 0;

    Node* findroot(){
        if(parent == nullptr) return this;
        parent = parent->findroot();
        return parent;
    }
};

bool merge(Node* a, Node* b){
    auto ra = a->findroot(), rb = b->findroot();
    if(ra == rb) return false;
    if(ra->rank >= rb->rank){
        rb->parent = ra;
        if(ra->rank == rb->rank) ++ra->rank;
    }
    else{
        ra->parent = rb;
    }
    return true;
}




#endif //PLAYGROUND_DISJOINT_SET_H
