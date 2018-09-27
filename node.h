//
// Created by Sebastian on 25/09/2018.
//

#ifndef W5_NODE_H
#define W5_NODE_H

template <typename T>
struct Node {
    T data;
    struct Node* right= nullptr;
    struct Node* left= nullptr;
    void killSelf(){
        delete this;
    };
};

#endif //W5_NODE_H
