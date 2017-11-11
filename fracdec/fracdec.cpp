
/*
ID: heng_li1
TASK: fracdec
LANG: C++11                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    ofstream fout ("fracdec.out");
    ifstream fin ("fracdec.in");

    int num,dem;

    fin >> num >> dem;

    int q = num/dem;

    string decexp = to_string(q) + ".";

    num = num %dem;
    if (!num) {
    	fout << decexp << 0 << endl;
    }else {

	    vector<int> decplaces, remainders;

	    vector<int> rpos(dem,-1);


	    int rep = -1;

	    while (num) {
	    	if (rpos[num]>=0) {
	    		rep = rpos[num];
	    		break;
	    	}
	    	rpos[num] = remainders.size();
	    	remainders.push_back(num);
	    	num *= 10;
	    	bool flag = false;
	    	while (num<dem) {
	    		if (rpos[num]>=0) {
	    			rep = rpos[num];
	    			flag = true;
	    			break;
	    		}
	    		rpos[num] = remainders.size();
	    		remainders.push_back(num);
	    		num*=10;
	    		decplaces.push_back(0);
	    	}
	    	if (flag) {
	    		break;
	    	}
	    	decplaces.push_back(num/dem);
	    	num = num%dem;
	    }
	    while (decplaces.size()<remainders.size()) {
	    	decplaces.push_back(0);
	    }
	    // copy(decplaces.begin(),decplaces.end(),ostream_iterator<int>(cerr," "));
	    // cerr << endl;
	    // cerr << rep << endl;

	    for (int i = 0;i<decplaces.size();i++) {
	    	if (rep==i) {
	    		decexp.append("(");
	    	}
	    	decexp.append(to_string(decplaces[i]));
	    }
	    if (rep>=0) {
	    	decexp.append(")");
	    }
	    int i;
	    for (i =0;i<decexp.size();i++) {
	    	if (i&& !(i%76)) {
	    		fout << endl;
	    	}
	    	fout << decexp[i]; 
	    }
	    fout << endl;
	}

    fout.close();
    return 0;
}
