#include <bits/stdc++.h>

using namespace std;

class Node {
   public:
    int data;
    Node* lchild;
    Node* rchild;
    Node(int val) {
        data = val;
        lchild = NULL;
        rchild = NULL;
    }
};

class BST {
   private:
    Node* root;
    Node* empty(Node* p) {
        if (p == NULL)
            return NULL;
        empty(p->lchild);
        empty(p->rchild);
        delete p;
        return NULL;
    }

    Node* insert(Node* p, int data) {
        if (p == NULL) {
            p = new Node(data);
            return p;
        }
        if (data < p->data) {
            p->lchild = insert(p->lchild, data);
        } else if (data > p->data) {
            p->rchild = insert(p->rchild, data);
        }
        return p;
    }

    Node* findMin(Node* p) {
        if (p == NULL) return NULL;
        if (p->lchild == NULL) return p;
        return findMin(p->lchild);
    }

    Node* findMax(Node* p) {
        if (p == NULL) return NULL;
        if (p->rchild == NULL) return p;
        return findMax(p->rchild);
    }

    int height(Node* p) {
        if (p == NULL) return 0;
        int l = height(p->lchild);
        int h = height(p->rchild);
        return l > h ? l + 1 : h + 1;
    }

    Node* inorder_predecessor(Node* p) {
        if (p == NULL) return NULL;
        if (p->rchild) return inorder_predecessor(p->rchild);
        return p;
    }

    Node* inorder_successor(Node* p) {
        if (p == NULL) return NULL;
        if (p->lchild) return inorder_successor(p->lchild);
        return p;
    }

    Node* erase(Node* p, int key) {
        Node* q;
        if (p == NULL) return NULL;
        if (p->lchild == NULL && p->rchild == NULL) {
            if (p == root) root = NULL;
            delete (p);
            return NULL;
        }
        if (key < p->data)
            p->lchild = erase(p->lchild, key);
        else if (key > p->data)
            p->rchild = erase(p->rchild, key);
        if (height(p->lchild) > height(p->rchild)) {
            q = inorder_predecessor(p->lchild);
            p->data = q->data;
            p->lchild = erase(p->lchild, q->data);
        } else {
            q = inorder_successor(p->rchild);
            p->data = q->data;
            p->rchild = erase(p->rchild, q->data);
        }
        return p;
    }

    void preorder(Node* p) {
        if (p == NULL) return;
        cout << p->data << ' ';
        preorder(p->lchild);
        preorder(p->rchild);
    }

    void inorder(Node* p) {
        if (p == NULL) return;
        inorder(p->lchild);
        cout << p->data << ' ';
        inorder(p->rchild);
    }

    void postorder(Node* p) {
        if (p == NULL) return;
        postorder(p->lchild);
        postorder(p->rchild);
        cout << p->data << ' ';
    }

    Node* find(Node* p, int key) {
        if (p == NULL) return NULL;
        if (key < p->data) return find(p->lchild, key);
        if (key > p->data) return find(p->rchild, key);
        return p;
    }

   public:
    BST() {
        root = NULL;
    }

    ~BST() {
        root = empty(root);
    }

    void insert(int data) {
        root = insert(root, data);
    }

    void erase(int key) {
        root = erase(root, key);
    }

    void display_preorder() {
        preorder(root);
        cout << endl;
    }

    void display_inorder() {
        inorder(root);
        cout << endl;
    }

    void display_postorder() {
        postorder(root);
        cout << endl;
    }

    bool find(int key) {
        Node* p = find(root, key);
        return p != NULL ? true : false;
    }
};

int main() {
    BST t;
    t.insert(20);
    t.insert(25);
    t.insert(15);
    t.insert(10);
    t.insert(30);
    t.display_inorder();
    cout << "20 exists: " << t.find(20) << endl;
    t.erase(20);
    cout << "20 exists: " << t.find(20) << endl;
    t.display_preorder();
    t.display_inorder();
    t.display_postorder();
    t.erase(25);
    t.display_inorder();
    t.erase(30);
    t.display_preorder();
    return 0;
}