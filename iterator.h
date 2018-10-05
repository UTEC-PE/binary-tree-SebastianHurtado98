//
// Created by Sebastian on 25/09/2018.
//

#ifndef W5_ITERATOR_H
#define W5_ITERATOR_H

#include "node.h"
#include <deque>
using namespace std;

template <typename T>
class Iterator {
private:
    Node<T>* current;
    Node<T>* head;


public:
    Iterator() : current(nullptr) {};
    Iterator(Node<T>* current) : current(current), head(current) {};
    Iterator(Node<T>* current, Node<T>* head) : current(current), head(head) {};

    Iterator<T> operator=(Iterator<T> node){
        current= node.current;
        return node;
    };
    bool operator!=(Iterator<T> cmp){ // Podría ser null el current, no?
        return (current->data!=cmp.current->data);
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
    Node<T>* rn(){
        return current;
    }


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


#endif //W5_ITERATOR_H
