#include <cstdio>

using namespace std;

struct Node{
	Node* ch[2];
	int sz;

	Node(){
		ch[0] = ch[1] = 0;
		sz = 0;
	}

	void add(int x){
		Node* cur = this;
		sz += 1;
		for (int i = 29; i >= 0; i--) {
			int dir = (x & (1 << i)) ? 1 : 0;
			if (cur->ch[dir] == 0)
				cur->ch[dir] = new Node();
			cur = cur->ch[dir];
			cur->sz += 1;
		}
	}

	void erase(int x){
		Node* cur = this;
		sz -= 1;
		for (int i = 29; i >= 0; i--) {
			int dir = (x & (1 << i)) ? 1 : 0;
			// if (cur->ch[dir] == 0)
			// 	cur->ch[dir] = new Node();
			cur = cur->ch[dir];
			cur->sz -= 1;
		}
	}

	int maxXor(int x){
		int ret = 0;
		Node* cur = this;
		for (int i = 29; i >= 0; i--) {
			int dir = (x & (1 << i)) ? 0 : 1;
			if (cur->ch[dir] == 0 || cur->ch[dir]->sz == 0) {
				cur = cur->ch[dir ^ 1];
			} else {
				cur = cur->ch[dir];
				ret |= (1 << i);
			}
		}
		return ret;
	}
};

int main(){
    int q;
    scanf("%d", &q);
    Node* root = new Node();
    root->add(0);
    while (q--) {
    	char op[2];
    	int x;
    	scanf("%s%d", op, &x);
    	if (op[0] == '+') {
    		root->add(x);
    	} else if (op[0] == '-') {
    		root->erase(x);
    	} else {
    		printf("%d\n", root->maxXor(x));
    	}
    }
    return 0;
}