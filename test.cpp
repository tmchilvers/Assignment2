#include <iostream>
#include <thread>
#include <chrono>
#include <time.h>
#include <unistd.h>
#include <string>

int main() {
  
for(auto k = 0; k < 100; k++) {
  std::cout << string( 100, '\n' );
  std::cout << "Generation " << k+1 << std::endl;
  for(auto i = 0; i < 10; i++){
    for(auto j = 0; j < 12; j++){
      if (i==7 && j==4 && k%2==0) {
        std::cout << "x ";
        continue;
      }
      std::cout << "- ";

    }
    std::cout << "\n";

  }
  sleep(1);
}
}
