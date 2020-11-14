#include <bits/stdc++.h>

using namespace std;

class Node {
   public:
    int data;
    Node *next;
    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedList {
   private:
    Node *root;
    int size;

   public:
    LinkedList() {
        root = NULL;
        size = 0;
    }
    Node *insert_first(int data);
    Node *insert_end(int data);
    Node *insert_before(int pos, int data);
    Node *insert_after(int pos, int data);
    int remove_first();
    int remove_end();
    int remove_before();
    int remove_after();
    int remove_key(int key);
    int get_size();
    void traverse();
};

Node *LinkedList::insert_first(int data) {
    Node *new_node = new Node(data);
    size += 1;
    if (root == NULL) {
        root = new_node;
    } else {
        new_node->next = root;
        root = new_node;
    }
    return new_node;
}

Node *LinkedList::insert_end(int data) {
    Node *new_node = new Node(data);
    size += 1;
    if (root == NULL) {
        root = new_node;
    } else {
        Node *p = root;
        while (p->next != NULL) p = p->next;
        p->next = new_node;
    }
    return new_node;
}

Node *LinkedList::insert_before(int pos, int data) {
    Node *new_node = new Node(data);
    size += 1;
    if (root == NULL) {
        root = new_node;
    } else {
        Node *current = root, *prev;
        for (int i = 0; i < pos; i++) {
            if (current) {
                prev = current;
                current = current->next;
            } else
                break;
        }
        if (prev) {
            new_node->next = prev->next;
            prev->next = new_node;
        } else {
            new_node->next = current;
            root = new_node;
        }
    }
    return new_node;
}

Node *LinkedList::insert_after(int pos, int data) {
    size -= 1;
}

int LinkedList::remove_first() {
    if (root == NULL) return -1;
    size -= 1;
    Node *p = root;
    root = root->next;
    int val = p->data;
    delete p;
    return val;
}

int LinkedList::remove_end() {
    if (root == NULL) return -1;
    size -= 1;
    Node *p = root;
    while (p->next->next != NULL) p = p->next;
    Node *t = p->next;
    int val = t->data;
    p->next = NULL;
    delete t;
    return val;
}

int LinkedList::remove_before() {
    size -= 1;
}

int LinkedList::remove_after() {
    size -= 1;
}

int LinkedList::remove_key(int key) {
    if (root == NULL) return -1;
    if (root->data == key) {
        int val = root->data;
        Node *t = root;
        root = root->next;
        delete t;
        size -= 1;
        return val;
    }
    Node *current = root, *prev = NULL;
    while (current && current->data != key) {
        prev = current;
        current = current->next;
    }
    if (!current) return -1;
    Node *t = current;
    int val = t->data;
    prev->next = current->next;
    delete t;
    size -= 1;
    return val;
}

int LinkedList::get_size() {
    return size;
}

void LinkedList::traverse() {
    Node *p = root;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main(int argc, char const *argv[]) {
    LinkedList list1, list2;
    list1.insert_first(1);
    list1.insert_first(2);
    list1.insert_first(3);
    list1.remove_first();
    list2.insert_first(4);
    list2.insert_first(5);
    list2.insert_first(6);
    list2.insert_before(1, 33);
    list1.traverse();
    list2.traverse();
    cout << list1.get_size() << endl;
    cout << list2.get_size() << endl;
    return 0;
}
