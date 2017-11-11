
/*
ID: heng_li1
TASK: stamps
LANG: C++11                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long ULL;
typedef unsigned int UI;

int main() {
    ofstream fout ("stamps.out");
    ifstream fin ("stamps.in");

    int k,n;
    fin >>k>>n;

    vector<int> amts (n);

    for (int &el:amts) {
    	fin >> el;
    }

    sort(amts.begin(),amts.end());

    vector<UI> dp (amts.back()*k+1,1<<30);
    dp[0] =0;

    for (int a:amts) {
    	for (int i = a;i<dp.size();i++) {
    		dp[i] = min(dp[i],dp[i-a]+1);
    	}
    }

    int ans= dp.size()-1;

    for (int i=1;i<dp.size();i++) {
    	if(dp[i]>k) {
    		ans= i-1;
    		break;
    	}
    }

    fout << ans << endl;



    fout.close();
    return 0;
}
