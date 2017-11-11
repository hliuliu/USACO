
/*
ID: heng_li1
TASK: skidesign
LANG: C++11                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int getcost(int height[],int n, int left, int right) {
	int cost =0;
	for (int i=0;i<n && height[i]<height[0]+left; i++) {
		cost += pow(height[i]-height[0]-left,2);
	}
	for (int i=n-1;i>=0 && height[i]>height[n-1]-right;i--) {
		cost += pow(height[i]-height[n-1]+right,2);
	}
	return cost;
}

int main() {
    ofstream fout ("skidesign.out");
    ifstream fin ("skidesign.in");
    int n;
    int heights [1000];
    fin >> n;
    for (int i=0;i<n;i++) {
    	fin >> heights[i];
    }
    sort(heights,heights+n);
    int cost = 1000*100*100;

    int diff = heights[n-1]-heights[0];
    if (diff <=17) {
    	fout << 0 << endl;
    }else {
    	int target = diff - 17;
    	for (int i =0; i<=target;i++) {
    		cost = min(cost, getcost(heights,n,i,target-i));
    	}
    	fout << cost << endl;
    }

    fout.close();
    return 0;
}
