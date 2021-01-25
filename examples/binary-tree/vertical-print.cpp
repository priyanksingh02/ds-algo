#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct node {
    int data = 0;
    node * left = nullptr;
    node * right = nullptr;

    node(int d): data {d} {}
};

map<int, vector<int> > storage;

void print_verical_helper(node * root, int value) {
    if(root) storage[value].push_back(root->data);
    if(root->left) print_verical_helper(root->left,value-1);
    if(root->right) print_verical_helper(root->right,value+1);
}

void print_vertical(node * root) {
    int root_value = 0;
    print_verical_helper(root,root_value);
    for(auto vertical_line: storage) {
        for(auto item: vertical_line.second) {
            cout << item << " ";
        }
        cout << "\n";
    }
}

int main() {
    //sample tree
    node one(1);
    node two(2);
    node three(3);
    one.left = &two;
    one.right = &three;
    node four(4);
    node five(5);
    two.left = &four;
    two.right = &five;
    node six(6);
    node seven(7);
    three.left = &six;
    three.right = &seven;
    node eight(8);
    node nine(9);
    six.right = &eight;
    seven.right = &nine;

    node * root = &one;
    print_vertical(root);
}
