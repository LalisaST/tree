#include "Tree.h"

Node::Node() {
    sons.clear();
    data = 0;
}

Tree::Tree() {
    count = 0;
    root = nullptr;
}

Node* Tree::getRoot() {
    return root;
}

void Tree::push(int data, Node* parent) {
    Node* newNode = new Node();
    newNode->data = data;
    if (count == 0) root = newNode;
    else parent->sons.push_back(newNode);
    count++;
}

void Tree::popDop(Node* buff, bool& flag) {
    std::vector<Node*>::iterator iter = buff->sons.begin();
    for (int i = 0; i < buff->sons.size(); i++) {
        Node* current = buff->sons[i];
        if (current->sons.empty()) {
            flag = true;
            buff->sons.erase(iter);
            delete current;
            return;
        }
        else {
            popDop(current, flag);
            if (flag == true) return;
        }
        iter++;
    }
}

void Tree::pop() {
    if (count != 0) {
        bool flag = false;
        Node* buff = root;
        if (buff->sons.empty()) delete buff;
        else {
            popDop(buff, flag);
        }
        count--;
    }
    else cout << "ERROR: Tree is empty" << endl;
}

Node* Tree::findDop(Node* buff, int data, bool& flag) {
    for (int i = 0; i < buff->sons.size(); i++) {
        Node* current = buff->sons[i];
        if (current->data == data) {
            flag = true;
            return current;
        }
        else {
            Node* buffReturn = findDop(current, data, flag);
            if (flag == true) return buffReturn;
        }
    }
    return nullptr;
}

Node* Tree::find(int data) {
    if (count != 0) {
        Node* buff = root;
        bool flag = false;
        if (buff->data == data) return buff;
        else buff = findDop(buff, data, flag);
        if (buff == nullptr) cout << "ERROR: Element is not found" << endl;
        else return buff;
    }
    else cout << "ERROR: Tree is empty" << endl;
    return nullptr;
}

int Tree::Count() const {
    return count;
}

int Tree::heightDop(Node* buff) {
    if (buff == nullptr) return 0;
    else {
        int Height = 0;
        for (int i = 0; i < buff->sons.size(); i++) {
            Node* current = buff->sons[i];
            Height = std::max(Height, heightDop(current));
        }
        return Height + 1;
    }
}

int Tree::height() {
    if (count != 0) {
        Node* buff = root;
        return heightDop(buff);
    }
    else return 0;
}

void Tree::pathDop(int data, int& level, Node* buff, bool& flag) {
    level++;
    for (int i = 0; i < buff->sons.size(); i++) {
        Node* current = buff->sons[i];
        if (current->data == data) {
            flag = true;
            cout << level << " ";
        }
        pathDop(data, level, current, flag);
    }
    level--;
}

void Tree::path(int data) {
    if (count != 0) {
        bool flag = false;
        int level = 0;
        cout << "Path = ";
        if (root->data == data) {
            flag = true;
            cout << level << " ";
        }
        pathDop(data, level, root, flag);
        cout << endl;
        if (flag == false) cout << "ERROR: Elements are not found" << endl;
    }
    else cout << "ERROR: Tree is empty" << endl;
}

void Tree::printDop(Node* buff) {
    for (int i = 0; i < buff->sons.size(); i++) {
        Node* current = buff->sons[i];
        cout << current->data << " ";
        printDop(current);
    }
}

void Tree::print() {
    if (count != 0) {
        Node* buff = root;
        cout << root->data << " ";
        printDop(buff);
        cout << endl;
    }
    else cout << "ERROR: Tree is empty" << endl;
}

void Tree::pushNode(Node* buff, Node* parent) {
    Node* newNode = new Node();
    newNode->data = buff->data;
    parent->sons.push_back(newNode);
    for (int i = 0; i < buff->sons.size(); i++) {
        pushNode(buff->sons[i], newNode);
    }
    count++;
}

void Tree::split(Tree& first, Tree& second) {
    first.push(root->data, nullptr);
    second.push(root->data, nullptr);
    for (int i = 0; i < root->sons.size() / 2; i++) {
        first.pushNode(root->sons[i], first.getRoot());
    }
    cout << "First tree: ";
    first.print();
    cout << "First count = " << first.Count() << " " << "First height = " << first.height() << endl;
    for (int i = root->sons.size() / 2; i < root->sons.size(); i++) {
        second.pushNode(root->sons[i], second.getRoot());
    }
    cout << "Second tree: ";
    second.print();
    cout << "Second count = " << second.Count() << " " << "Second height = " << second.height() << endl;
}

bool Tree::operator==(const Tree& a) const {
    return (count == a.count);
}

bool Tree::operator!=(const Tree& a) const {
    return (count != a.count);
}

bool Tree::operator>(const Tree& a) const {
    return (count > a.count);
}

bool Tree::operator>=(const Tree& a) const {
    return (count >= a.count);
}

bool Tree::operator<(const Tree& a) const {
    return (count < a.count);
}

bool Tree::operator<=(const Tree& a) const {
    return (count <= a.count);
}

Tree::~Tree() {
    int buffCount = count;
    for (int i = 0; i < buffCount; i++) pop();
}
