
/*
ID: heng_li1
TASK: milk3
LANG: C++11                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;
typedef pair<int,int> PII;


int mask(PII &a, PII &b, PII &c) {
	int ans =0;
	ans += a.first;
	ans *= 21;
	ans += b.first;
	ans *= 21;
	ans += c.first;
	return ans;
}

void pour(PII &a,PII &b) {
	int change = min(a.first, b.second-b.first);
	a.first -= change;
	b.first += change;
}

void generate(set<int> &content, PII &a, PII &b, PII &c, unordered_set<int> &visited) {
	int ms = mask(a,b,c);
	if (visited.find(ms)!=visited.end()) {
		return;
	}
	visited.insert(ms);
	if (a.first == 0) {
		content.insert(c.first);
	}

	int x,y;

	x = a.first;
	y = b.first;
	pour(a,b);
	generate(content, a, b, c, visited);
	a.first = x;
	b.first = y;

	x = a.first;
	y = c.first;
	pour(a,c);
	generate(content, a, b, c, visited);
	a.first = x;
	c.first = y;

	x = b.first;
	y = a.first;
	pour(b,a);
	generate(content, a, b, c, visited);
	b.first = x;
	a.first = y;

	x = b.first;
	y = c.first;
	pour(b,c);
	generate(content, a, b, c, visited);
	b.first = x;
	c.first = y;

	x = c.first;
	y = a.first;
	pour(c,a);
	generate(content, a, b, c, visited);
	c.first = x;
	a.first = y;

	x = c.first;
	y = b.first;
	pour(c,b);
	generate(content, a, b, c, visited);
	c.first = x;
	b.first = y;
}

int main() {
    ofstream fout ("milk3.out");
    ifstream fin ("milk3.in");

    PII a(0,0),b(0,0),c(0,0);

    fin >> a.second >> b.second >> c.second;
    c.first = c.second;

    set<int> content;

    unordered_set<int> visited;

    generate(content,a,b,c, visited);

    int maxv = 0;

    for ( int v : content) {maxv=v;}


    for (int v: content) {
    	fout << v;
    	if (v<maxv) {
    		fout << " ";
    	}
    }
    fout << endl;

    fout.close();
    return 0;
}
