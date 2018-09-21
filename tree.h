//
// Created by Sebastian on 12/09/2018.
//

#ifndef W4_TREE_H
#define W4_TREE_H
#include <iostream>
#include "node.h"
#include "iterator.h"
#include <deque>

#include <map>

using namespace std;

template <typename T>

class Tree {
private:

    Node<T>* current;
    int nodes;
    //void which_operator(string str);


public:
    Node<T>* head;
    Tree(){
        head= nullptr;
        current= nullptr;
        nodes=0;
    };


    void create_node(T x){

        auto *n= new Node<T>();

        if(head==nullptr){
            n->data= x;
            head=n;
            current= n;
        }
        else{
            insert_node(x, head);
        }

    };

    void insert_node(T x, Node<T>* &now){

        if (x< now->data){
            auto *n= new Node<T>();
            if(now->left== nullptr){
                n->data= x;
                now->left=n;
            }
            else{
                insert_node(x, (now->left));
            }
        }
        else{
            if(now->right== nullptr){
                auto *n= new Node<T>();
                n->data=x;
                now->right=n;
            }
            else{
                insert_node(x, now->right);
            }
        }

    };

    void print_tree() {
        deque<Node<T>*> stack;
        auto temp= head;
        stack.push_back(temp);

        while (temp->left!= nullptr){
            temp=temp->left;
            stack.push_back(temp);
        }

        while(stack.size()>0) {
            if (stack.back()->right != nullptr) {
                temp = stack.back()->right;
                cout << stack.back()->data;
                stack.pop_back();
                stack.push_back(temp);
                while (temp->left != nullptr) {
                    temp = temp->left;
                    stack.push_back(temp);
                }
            }
            else {
                cout << stack.back()->data;
                stack.pop_back();
            }
        }

    };

    Iterator<T> root(){
        Iterator<T> start(head);
        return start;
    }

    void test(){
        Iterator<T> first;
        first=root();
        ++first;
        ++first;
        cout << *first;
    }

};

//~List();
#endif //W4_TREE_H
