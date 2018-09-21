//
// Created by Sebastian on 12/09/2018.
//

#ifndef W4_NODE_H
#define W4_NODE_H

template <typename T>
struct Node {
    T data;
    struct Node* right= nullptr;
    struct Node* left= nullptr;
    void killSelf();
};

#endif //W4_NODE_H
