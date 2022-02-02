#include<bits/stdc++.h>
using namespace std;

void reactHome(int source, int destination) {
  cout << "Source " << source << " Destination " << destination << endl;
  if(source == destination) {
    cout << "Reached home" << endl;
    return;
  }
  return reactHome(source+1, destination);
}

int main() {
  int destination = 10;
  int source = 1;
  reactHome(source, destination);
  return 0;
}