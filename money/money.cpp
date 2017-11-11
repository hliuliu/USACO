
/*
ID: heng_li1
TASK: money
LANG: C++11                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("money.out");
    ifstream fin ("money.in");

    int v,n;
    fin >> v >> n;

    vector<int> coins(v);



    for (int &c:coins) {
    	fin >> c;
    }
    sort(coins.begin(),coins.end());

    vector<long long> dp(n+1,0);

    dp[0] = 1;
    for(int c:coins) {
    	for(int i = c; i<=n;i++) {
    		dp[i] += dp[i-c];
    	}
    }

    fout << dp[n] << endl;

    fout.close();
    return 0;
}
