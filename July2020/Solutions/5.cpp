#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
#include <algorithm>

using namespace std;


int main() {
    ofstream fout ("verybest.out");
    ifstream fin ("verybest.in");
    int c, p, sum=0, m=0;
    fin >> c >> p;
    int chickens[c];
    for (int i = 0; i < c; i++) {
        fin >> chickens[i];
        sum += chickens[i];
        if (chickens[i] > m) m = chickens[i];
    }
    int low = m;
    int high = sum + 1;
    int currsize = (low + high) / 2;
    while (high - low > 1) {
        int currsum = 0, currused = 0, currpos = 0;
        while (currused < p && currpos < c) {
            while (currsum+chickens[currpos] <= currsize && currpos < c) {
                currsum += chickens[currpos];
                currpos += 1;
            }
            currused += 1;
            currsum = 0;
        }
        if (currpos == c) {
            high = currsize;
        } else {
            low = currsize;
        }
        currsize = (low + high) / 2;
    }
    fout << high;
    return 0;
}









