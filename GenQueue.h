#include <iostream>

using namespace std;

class GenQueue {
public:
  GenQeueue();
  GeneQueue(int maxSize);
  ~GenQueue();
  void insert(char data);
  char remove();
  char peek();

  bool isFull();
  bool isEmpty();
  int getSize();
private:
  int front;
  int rear;
  int numElements;
  int maxSize;
  char *myQueue;
};
