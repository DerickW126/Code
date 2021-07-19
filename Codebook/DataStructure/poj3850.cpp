#include <iostream>
#include <algorithm>
using namespace std;
struct Treap{
    int val;
    int pri;
    int size;
    int mn;
    bool rev;
    Treap* l;
    Treap* r;
    Treap(int x = 0) {
        rev = false;
        mn = x;
        val = x;
        pri = rand();
        size = 1;
        l = nullptr;
        r = nullptr;
    }
};
void pull(Treap* root){
    root->size = 1;
    root->mn = root->val;
    if(root->l != nullptr) {
        root->size += root->l->size;
        root->mn = min(root->mn, root->l->mn);
    }
    if(root->r != nullptr){
        root->size += root->r->size;
        root->mn = min(root->mn, root->r->mn);
    }
}
void push(Treap* root){
    if(root->rev){
        swap(root->l, root->r);
        if(root->l) root->l->rev ^= 1;
        if(root->r) root->r->rev ^= 1;
        root->rev = false;
    }
}
Treap* merge(Treap* a, Treap* b){
    if(!a) return b;
    if(!b) return a;
    if(a->pri >= b->pri){
        push(a);
        a->r = merge(a->r, b);
        pull(a);
        return a;
    } else {
        push(b);
        b->l = merge(a, b->l);
        pull(b);
        return b;
    }
}
int sz(Treap* root){
    if(!root) return 0;
    else return root->size;
}
void splitBySize(Treap* t, int k, Treap *&a, Treap *&b){
    if(!t) {
        a = nullptr;
        b = nullptr;
        return;
    } 
    push(t);
    if(sz(t->l) < k){
        a = t;
        splitBySize(t->r, k-sz(t->l)-1, a->r, b);
        pull(a);
    } else {
        b = t;
        splitBySize(t->l, k, a, b->l);
        pull(b);
    }
}
void print(Treap* root){
    if(!root) return;
    print(root->l);
    cout << root->val << ' ';
    print(root->r);
}
int main(){
    int n;
    cin >> n;
    Treap* root = nullptr;
    for(int i = 0;i < n;i++){
        int x;
        cin >> x;
        Treap* tmp = new Treap(x);
        root = merge(root,tmp);
    }
    int m;
    cin >> m;
    for(int i = 0;i < m;i++){
        string s;
        cin >> s;
        if(s == "INSERT"){
            int x, P;
            cin >> x >> P;
            Treap *a, *b;
            splitBySize(root, x, a, b);
            Treap* tmp = new Treap(P);
            root = merge(a, tmp);
            root = merge(root, b);
        } else if(s == "DELETE"){
            int x;
            cin >> x;
            Treap *a, *b, *tmp;
            splitBySize(root, x, a, b);
            splitBySize(a, x-1, a, tmp);
            root = merge(a,b);
        } else if(s == "MIN"){
            int x, y;
            cin >> x >> y;
            Treap *a, *b, *c;
            splitBySize(root, x-1, a, b);
            splitBySize(b, y-x+1, b, c);
            cout << b->mn << '\n';
            root = merge(a, b);
            root = merge(root, c);
        } else if(s == "REVERSE"){
            int x, y;
            cin >> x >> y;
            Treap *a, *b, *c;
            splitBySize(root, x-1, a, b);
            splitBySize(b, y-x+1, b, c);
            b->rev ^= 1;
            root = merge(a, b);
            root = merge(root, c);
        }
    }
}
/*
5
1 2 3 4 5
1
MIN 5 5
*/