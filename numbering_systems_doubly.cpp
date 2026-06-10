#include <iostream>
using namespace std;

class node {
private:
    int data;
    node* next;
    node* prev;
public:
    node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }

    void setNext(node* p) {
        next = p;
    }

    void setPrev(node* p) {
        prev = p;
    }

    node* getNext() {
        return next;
    }

    node* getPrev() {
        return prev;
    }

    int getData() {
        return data;
    }
};

class list {
private:
    node* root;
public:
    list() {
        root = NULL;
    }

    node* getRoot() const {
        return root;
    }

    void setRoot(node* p) {
        root = p;
    }

    void insertAtHead(int k) {
        node* newNode = new node(k);
        newNode->setNext(root);
        if (root != NULL) {
            root->setPrev(newNode);
        }
        root = newNode;
    }

    int deleteAtHead() {
        if (root == NULL) {
            cout << "List is empty\n";
            return -9999;
        }
        int val = root->getData();
        node* temp = root;
        root = root->getNext();
        if (root != NULL) {
            root->setPrev(NULL);
        }
        delete temp;
        return val;
    }

    bool isEmpty() const {
        return root == NULL;
    }
};

class stack : public list {
public:
    void push(int v) {
        insertAtHead(v);
    }

    int pop() {
        return deleteAtHead();
    }

    bool empty() const {
        return getRoot() == NULL;
    }
};

char HexChar(int num) {
    if (num < 10) return '0' + num;
    return 'A' + (num - 10);
}

void convertToBinary(int number) {
    stack S;
    while (number > 0) {
        S.push(number % 2);
        number /= 2;
    }
    cout << "Binary: ";
    while (!S.empty()) {
        cout << S.pop();
    }
    cout << endl;
}

void convertToOctal(int number) {
    stack S;
    while (number > 0) {
        S.push(number % 8);
        number /= 8;
    }
    cout << "Octal: ";
    while (!S.empty()) {
        cout << S.pop();
    }
    cout << endl;
}

void convertToHex(int number) {
    stack S;
    while (number > 0) {
        S.push(number % 16);
        number /= 16;
    }
    cout << "Hexadecimal: ";
    while (!S.empty()) {
        cout << HexChar(S.pop());
    }
    cout << endl;
}

int main() {
    int number, choice;

    cout << "Enter a positive integer: ";
    cin >> number;

    if (number <= 0) {
        cout << "Invalid input.\n";
        return 1;
    }

    cout << "Choose conversion system:\n";
    cout << "1. Binary\n";
    cout << "2. Octal\n";
    cout << "3. Hexadecimal\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        convertToBinary(number);
    }
    else if (choice == 2) {
        convertToOctal(number);
    }
    else if (choice == 3) {
        convertToHex(number);
    }
    else {
        cout << "Invalid choice.\n";
    }

    return 0;
}
