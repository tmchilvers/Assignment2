#include <iostream>
#include <thread>
#include <chrono>
#include <time.h>
#include <unistd.h>

using namespace std;

int main() {
for(int k = 0; k < 100; k++) {
  cout << "Generation " << k+1 << endl;
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 12; j++){
      if (i==7 && j==4 && k%2==0) {
        cout << "x ";
        continue;
      }
      cout << "- ";

    }
    cout << "\n";

  }
  sleep(1);
}
}
