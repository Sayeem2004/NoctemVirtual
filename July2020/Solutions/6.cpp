#include <iostream>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

int main() {
  ofstream fout ("stonks.out");
  ifstream fin ("stonks.in");
  int n;
  fin >> n;
  vector<int> vect;
  for (int i = 0; i < n; i++) {
    int a;
    fin >> a;
    vect.push_back(a);
  }
  int happy = 0;
  int pos = 0;
  for (int i = 0; i < n / 2; i++) {
    int thappy = 0;
    int tpos = i + 1;
    int num = vect[i];
    vector<int> vect2(vect.begin() + i, vect.end());
    sort(vect2.begin(),vect2.end());
    auto it = find(vect2.begin(), vect2.end(), num);
    auto tthappy = distance(it, vect2.end());
    thappy = tthappy + 1;
    if (thappy > happy) {
      happy = thappy;
      pos = tpos;
    }
  }
  fout << pos << endl;
}
