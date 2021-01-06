#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("capture.out");
    ifstream fin ("capture.in");
    int n, r, c, a, b;
    fin >> n >> r >> c >> a >> b;
    int nets[n][2];
    for (int i = 0; i < n; i++) {
        fin >> nets[i][0] >> nets[i][1];
    }
    int answer=0;
    for (int y = 0; y < r - a + 1; y++) {
        int highr=y+a-1, lowr=y;
        for (int x = 0; x < c - b + 1; x++) {
            int lowc=x, highc=x+b-1, current=500;
            bool works = true;
            for (int i = 0; i < n; i++) {
                int cny=nets[i][0], cnx=nets[i][1], sum=0;
                if (cny >= lowr && cny <= highr && cnx >= lowc && cnx <= highc) {
                    works = false;
                    break;
                }
                if (cny < lowr) {sum += lowr - cny;} else if (cny > highr) {sum += cny - highr;}
                if (cnx < lowc) {sum += lowc - cnx;} else if (cnx > highc) {sum += cnx - highc;}
                if (sum < current) current = sum;
            }
            if (current > answer && works) answer = current;
        }
    }
    cout << answer << endl;
    return 0;
}
