#include <iostream>
#include <cstdlib>
using namespace std;
struct Treap{
    int key;
    int pri;
    int size;
    Treap* l;
    Treap* r;
    Treap(int x = 0) {
        key = x;
        pri = rand();
        size = 1;
        l = nullptr;
        r = nullptr;
    }
};
void pull(Treap* root){
    root->size = 1;
    if(root->l != nullptr) root->size += root->l->size;
    if(root->r != nullptr) root->size += root->r->size;
}
Treap* merge(Treap* a, Treap* b){
    if(!a) return b;
    if(!b) return a;
    if(a->pri >= b->pri){
        a->r = merge(a->r, b);
        pull(a);
        return a;
    } else {
        b->l = merge(a, b->l);
        pull(b);
        return b;
    }
}
void split(Treap* t, int k, Treap *&a, Treap *&b){
    if(!t) {
        a = nullptr;
        b = nullptr;
        return;
    } 
    if(t->key <= k){
        a = t;
        split(t->r, k, a->r, b);
        pull(a);
    } else {
        b = t;
        split(t->l,k, a, b->l);
        pull(b);
    }
}
void splitBySize(Treap* t, int k, Treap *&a, Treap *&b){
    if(!t) {
        a = nullptr;
        b = nullptr;
        return;
    } 
    if(t->l && t->l->size < k){
        a = t;
        splitBySize(t->r, k-t->l->size-1, a->r, b);
        pull(a);
    } else {
        b = t;
        splitBySize(t->l,k, a, b->l);
        pull(b);
    }
}
void print(Treap* root){
    if(!root) return;
    print(root->l);
    cout << root->key << ' ';
    print(root->r);
}
int depth(Treap* root){
    if(!root) return 0;
    return max(depth(root->l), depth(root->r)) + 1;
}
int main(){
    srand(clock());
    Treap* root = nullptr;
    for(int i = 1;i <= 1000000;i++){
        Treap* tmp = new Treap(i);
        root = merge(root,tmp);
    }
    cout << root->size << '\n';
}