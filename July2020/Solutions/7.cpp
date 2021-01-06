
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
#include <algorithm>

using namespace std;

int r;
vector<int> all;

int solve(int index, int m) {
    if (index == r) {return 0;}
    int ha = all[index];
    if (ha < m) {
        return solve(index+1, m);
    } else {
        int with, without;
        with = ha + solve(index+1, ha);
        without = solve(index+1, m);
        return max(with, without);
    }
}

int main() {
    ofstream fout ("spring.out");
    ifstream fin ("spring.in");
    fin >> r;
    for (int i = 0; i < r; i++) {
        int current;
        fin >> current;
        all.push_back(current);
    }
    fout << solve(0, 0);
    return 0;
}









