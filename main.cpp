#include <iostream>
#include <map>
#include <string>
#include<algorithm>
#include "tree.h"

using namespace std;


int main(int argc, char const *argv[]) {
    //menu();
    Tree<int> tree;
    tree.create_node(10);
    tree.create_node(12);
    tree.create_node(14);
    tree.create_node(8);
    tree.create_node(6);
    cout << tree.remove(10) << endl;
    tree.print_tree();


    cin.get();
    return EXIT_SUCCESS;
}