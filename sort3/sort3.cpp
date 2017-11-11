
/*
ID: heng_li1
TASK: sort3
LANG: C++11                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

int main() {
    ofstream fout ("sort3.out");
    ifstream fin ("sort3.in");

    int n;
    fin >> n;


    vector<int> A(n);

    for (int &i: A) {
    	fin >> i;
    }

    vector<int> ctrs (4,0);

    for (int i : A) {
    	ctrs[i]++;
    }

    vector<int> As(n);

    int i =0;

    for (int j=1;j<4;j++) {
    	for (int k =0;k<ctrs[j];k++,i++) {
    		As[i] = j;
    	}
    }

    int miss1 = 0;

    for (i=0;i<n;i++) {
    	if (A[i]==1 && As[i]!=1) {
    		miss1++;
    	}
    }

    deque<int> tmp;

    for (i=0;i<ctrs[1];i++) {
    	switch(A[i]) {
    		case 1:
    			break;
    		case 2:
    			tmp.push_front(2);
    			break;
    		case 3:
    			tmp.push_back(3);
    	}
    }

    for (;i<n;i++) {
    	if (A[i]==1) {
    		A[i]=tmp.front();
    		tmp.pop_front();
    	}
    }

    int miss2 = 0;

    for (i=ctrs[1];i<ctrs[1]+ctrs[2];i++) {
    	if (A[i]!=As[i]) {
    		miss2++;
    	}
    }

    fout << miss1+miss2 << endl;

    fout.close();
    return 0;
}
