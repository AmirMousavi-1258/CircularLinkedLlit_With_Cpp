#include <iostream>
using namespace std;

class node {
    friend class list;
    int data;
    node* next;
};

class list {
    node* first;
public:
    list() { first = nullptr; }

    node* Node(int);
    void pushFirst(int);
    void pushAfter(int, node*);
    void pushEnd(int);
    void popFirst();
    void popAfter(node*);
    void popEnd();
    void print();
    int Size();
};


void list::print() {
    if (first == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    node* F = first;
    do {
        cout << F->data << endl;
        F = F->next;
    } while (F != first);
}

void list::pushFirst(int Data) {
    node* p = new node;
    p->data = Data;
    if (first == nullptr) {
        p->next = p; 
        first = p;
        return;
    }
    node* last = first;
    while (last->next != first) {
        last = last->next;
    }
    p->next = first;
    last->next = p;
    first = p;
}


void list::pushAfter(int Data, node* N) {
    if (N == nullptr) {
        cout << "node doesn't exist." << endl;
        return;
    }
    node* p = new node;
    p->data = Data;
    p->next = N->next;
    N->next = p;
}


void list::pushEnd(int Data) {
    node* p = new node;
    p->data = Data;
    if (first == nullptr) {
        p->next = p;
        first = p;
        return;
    }
    node* last = first;
    while (last->next != first) {
        last = last->next;
    }
    last->next = p;
    p->next = first;
}


void list::popFirst() {
    if (first == nullptr) {
        cout << "list is empty" << endl;
        return;
    }
    if (first->next == first) { 
        delete first;
        first = nullptr;
        return;
    }
    node* last = first;
    while (last->next != first) {
        last = last->next;
    }
    node* temp = first;
    first = first->next;
    last->next = first;
    delete temp;
}


void list::popAfter(node* N) {
    if (first == nullptr || N == nullptr || N->next == nullptr) {
        cout << "node doesn't exist" << endl;
        return;
    }
    node* p = N->next;
    if (p == first) { 
        cout << "cant use popAfter" << endl;
        return;
    }
    N->next = p->next;
    delete p;
}


void list::popEnd() {
    if (first == nullptr) {
        cout << "list is empty." << endl;
        return;
    }
    if (first->next == first) {
        delete first;
        first = nullptr;
        return;
    }
    node* prev = nullptr;
    node* curr = first;
    while (curr->next != first) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = first;
    delete curr;
}


int list::Size() {
    if (first == nullptr) return 0;
    int count = 0;
    node* F = first;
    do {
        count++;
        F = F->next;
    } while (F != first);
    return count;
}


node* list::Node(int Data) {
    if (first == nullptr) return nullptr;
    node* F = first;
    do {
        if (F->data == Data) return F;
        F = F->next;
    } while (F != first);
    return nullptr;
}

int main() {
    list Li;
    Li.pushFirst(12);
    Li.pushFirst(17);
    Li.pushAfter(15, Li.Node(17)); 
    Li.pushEnd(22);

    cout << "Size: " << Li.Size() << endl;
    

    return 0;
}
