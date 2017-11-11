
/*
ID: heng_li1
TASK: inflate
LANG: C++11                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct category {int time,points;} category;
typedef  unsigned long long ULL;

bool catcmp(category &a,category &b) {
	int check = a.time*b.points - b.time*a.points;
	if (check) {
		return check<0;
	}
	return a.time<b.time;
}

int main() {
    ofstream fout ("inflate.out");
    ifstream fin ("inflate.in");

    int m,n;

    fin >> m >> n;

    vector<category> contest(n);
    vector<ULL> dp (m+1,0);

    for (category &cat: contest) {
    	fin >> cat.points >> cat.time;
    }

    sort(contest.begin(),contest.end(),catcmp);

    

    for (category &cat: contest) {
    	for (int v=cat.time; v<=m;v++) {
    		dp[v] = max(dp[v], dp[v-cat.time]+cat.points);
    	}
    }

    fout << dp[m] << endl;



    fout.close();
    return 0;
}
