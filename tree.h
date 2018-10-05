//
// Created by Sebastian on 25/09/2018.
//

#ifndef W5_TREE_H
#define W5_TREE_H
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

    void print_in_order(Node<T>* node){
        if (node->left!= nullptr){
            print_in_order(node->left);
        }
        cout << node->data << " ";
        if(node->right!= nullptr){
            print_in_order(node->right);
        }
    };
    void print_pre_order(Node<T>* node){
        cout << node->data << " ";
        if (node->left!= nullptr){
            print_in_order(node->left);
        }
        if(node->right!= nullptr){
            print_in_order(node->right);
        }
    };
    void print_post_order(Node<T>* node){
        if (node->left!= nullptr){
            print_in_order(node->left);
        }
        if(node->right!= nullptr){
            print_in_order(node->right);
        }
        cout << node->data << " ";
    };
    void insert_node(T x, Node<T>* &now){
        if(x!=now->data){
        if (x < now->data) {
            auto *n = new Node<T>();
            if (now->left == nullptr) {
                n->data = x;
                now->left = n;
            } else {
                insert_node(x, (now->left));
            }
        } else {
            if (now->right == nullptr) {
                auto *n = new Node<T>();
                n->data = x;
                now->right = n;
            } else {
                insert_node(x, now->right);
            }
        }}
        /*else{
            cout << "Ya existe el nodo";
        }*/

    };

public:
    Node<T>* head;
    Tree(){
        head= nullptr;
        current= nullptr;

    };

    void print_in_order(){
        print_in_order(head);
    };
    void print_pre_order(){
        print_pre_order(head);
    };

    void print_post_order(){
        print_post_order(head);
    };


    void insert_node(T x) {

            auto *n = new Node<T>();

        if (head == nullptr) {
            n->data = x;
            head = n;
            current = n;
        } else {
            insert_node(x, head);
        }
    };


    void print_tree(){
        Iterator<int> it1= begin();
        Iterator<int> it2= last();
        while(it1!=it2){
            cout << *it1 << " ";
            ++it1;
        }
        cout <<*it1;
    }

    /* imprimir sin iteradores
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
     */

    Iterator<T> root(){
        Iterator<T> start(head);
        return start;
    }
    Iterator<T> begin(){
        auto temp=head;
        while(temp->left!= nullptr){
            temp=temp->left;
        }
        Iterator<T> first(temp, head);
        return first;
    }

    Iterator<T> last(){
        auto temp= head;
        while(temp->right!= nullptr){
            temp=temp->right;
        }
        Iterator<T> final(temp, head); // Y lara imrpimir el último elemento?
        return final;
    }
    Node<T>* find(int x){
        auto temp=head;
        Iterator<T> it= begin();
        while(it.rn()!= nullptr){
            if(*it==x){
                temp=it.rn();

            }
            else{
                ++it;
            }
        }
        return temp;

    };

    int level(Node<T>* x){
        T val= x->data;
        auto temp= head;
        int count=1;
        while(temp->data!=val){
            if(val<temp->data){
                temp= temp->left;
            }
            else{
                temp=temp->right;
            }
            count++;
        }
        return count;
    }

    T weight(Node<T>* x){
        return (x->data) * level(x); // El peso es la cantidad de nodos, no la data
    }

    Node<T>* father(Node<T>* x){
        if(x!=head){
        T n= x->data;
        auto temp=head;
        while((temp->left != x )&& (temp->right!=x)) {
            if (n > temp->data) {
                temp = temp->right;
            } else {
                temp = temp->left;
            }
        }
        return temp;}
        else{
            cout << "Root no tiene padre" << endl;
            return head;
        }
    }

    T remove(int x) {
        auto current= find(x);
        Iterator<T> it(current, head);
        if(current->left!= nullptr && current->right!= nullptr){
            T temp=current->data;
            //reemplazar por la data de it++
            x= remove(*(++it));
            current->data= x;
            return temp;

        } else { if(current->left!= nullptr || current->right!= nullptr){
            if(current->left!= nullptr ){
                T temp=current->data;
                //reemplazar por la data de it--
                x= remove(*(--it));
                current->data= x;
                return temp;
            }
            else{
                T temp=current->data;
                //reemplazar por la data de it++
                x= remove(*(++it));
                current->data= x;
                return temp;
            }
        } else{
                //matalo y busca al padre
                T temp=current->data;
                auto dad= father(current);
                if(dad->right==current){
                    dad->right= nullptr;
                }
                else{
                    dad->left= nullptr;
                }
                current->killSelf();
                return temp;
        }}


    }


    ~Tree(){
        Iterator<T> start= begin();
        while(start.rn()!= nullptr){
            start.rn()->killSelf();
            ++start;
        }
    }

};

#endif //W5_TREE_H
