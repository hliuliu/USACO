
/*
ID: heng_li1
TASK: milk
LANG: C++11                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int,int> PII;

int main() {
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");

    int n,m;
    fin >> n >> m;
    vector<PII> markets (m,PII());

    for (PII &p: markets) {
    	fin >> p.first >> p.second;
    }

    sort(markets.begin(),markets.end(), [] (PII &a,PII &b) {return a.first<b.first;});
    int ans =0;
    for (PII &p: markets) {
    	int delta = min(n, p.second);
    	ans += p.first*delta;
    	n-= delta;
    	if (!n) {
    		break;
    	}
    }

    fout << ans << endl;

    fout.close();
    return 0;
}
