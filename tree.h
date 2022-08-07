#ifndef UNTITLED2_TREE_H
#define UNTITLED2_TREE_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>


using std::cout;
using std::endl;


struct Node {
    Node();

    int data;
    std::vector<Node*> sons;
};

class Tree {
private:
    Node* root;
    int count;

    void popDop(Node* buff, bool& flag);
    Node* findDop(Node* buff, int data, bool& flag);
    int heightDop(Node* buff);
    void printDop(Node* root);
    void pathDop(int data, int& level, Node* buff, bool& flag);
    void pushNode(Node* buff, Node* parent);

public:
    Tree();

    Node* getRoot();

    void push(int d, Node* parent);

    void pop();

    Node* find(int data);

    int Count() const;

    int height();

    void path(int data);

    void print();

    void split(Tree& first, Tree& second);

    bool operator==(const Tree& a) const;

    bool operator!=(const Tree& a) const;

    bool operator>(const Tree& a) const;

    bool operator>=(const Tree& a) const;

    bool operator<(const Tree& a) const;

    bool operator<=(const Tree& a) const;

    ~Tree();
};
    #endif
