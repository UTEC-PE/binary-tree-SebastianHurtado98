//
// Created by Sebastian on 19/09/2018.
//

#ifndef W4_ITERATOR_H
#define W4_ITERATOR_H

#include "node.h"
#include <deque>

template <typename T>
class Iterator {
private:
    Node<T>* current;
    Node<T>* head;


public:
    Iterator() : current(nullptr) {};
    Iterator(Node<T>* current) : current(current), head(current) {};

    Iterator<T> operator=(Iterator<T> node){
        current= node.current;
        return node;
    };
    bool operator!=(Iterator<T> cmp){
        return (current->data!=node->data);
    };


    Iterator<T> operator--(){
        if (current->left!= nullptr){
            current= current->left;
            while(current->right!= nullptr){
                current= current->right;
            }
            Iterator<T> start(current);
            return start;
        }
        else{
            deque<Node<T>*> stack;
            auto temp=head;
            stack.push_back(temp);
            while(temp->data!= current->data) {
                if (current->data < temp->data) {
                    temp = temp->left;
                    stack.push_back(temp);
                } else {
                    temp = temp->right;
                    stack.push_back(temp);
                }
            }
            bool i=true;
            while(i){
                if((stack.back()->data)>=current->data){
                    stack.pop_back();
                }else{
                    i=false;
                }

            }

            current= stack.back();
            Iterator<T> start(current);
            return start;
        }

    };
    T operator*(){
        return current->data;
    };


    Iterator<T> operator++(){
        if (current->right!= nullptr){
            current= current->right;
            while(current->left!= nullptr){
                current= current->left;
            }
            Iterator<T> start(current);
            return start;
        }
        else{
            deque<Node<T>*> stack;
            auto temp=head;
            stack.push_back(temp);
            while(temp->data!= current->data) {
                if (current->data < temp->data) {
                    temp = temp->left;
                    stack.push_back(temp);
                } else {
                    temp = temp->right;
                    stack.push_back(temp);
                }
            }
            bool i=true;
            while(i){
                if((stack.back()->data)<=current->data){
                    stack.pop_back();
                }else{
                    i=false;
                }

            }

            current= stack.back();
            Iterator<T> start(current);
            return start;
        }

    };
};

#endif