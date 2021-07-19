#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s;
vector<int> father;
vector<char> dict;
vector<int> labels;
int rep[26];
int cur;

int myFind(int x){
	if (x == father[x])
        return x;
    father[x] = myFind(father[x]);
    return father[x];
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); // 加速 for cin, cout
    cin >> s;
    for (int i = 0; i < 26; i++) {
    	father.push_back(i);
    }
    for (int i = 0; i < 26; i++) {
    	dict.push_back('a' + i);
    }
    for (int i = 0; i < s.length(); i++) {
    	labels.push_back(s[i] - 'a');
    }
    for (int i = 0; i < 26; i++) {
    	rep[i] = i;
    }
    cur = 25;
    int Q;
    cin >> Q;
    while (Q--) {
    	int type;
    	cin >> type;
    	if (type == 1) {
    		char c1, c2;
    		cin >> c1 >> c2;
    		/*
				char c1[2], c2[2];
				scanf("%s%s", c1, c2);
    		*/
    		/*
				char c1, c2;
				scanf(" %c %c", &c1, &c2);
    		*/
    		father[rep[c1 - 'a']] = rep[c2 - 'a'];
    		rep[c1 - 'a'] = ++cur;
    		father.push_back(cur);
    		dict.push_back(c1);
    	} else {
    		char c;
    		cin >> c;
    		labels.push_back(rep[c - 'a']);
    	}
    }
    for (int label : labels) {
    	int root = myFind(label);
    	cout << dict[root];
    }
    cout << '\n';
    return 0;
} 