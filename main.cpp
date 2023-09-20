#include <iostream>
#include <mutex>

#include "finegrainedqueue.h"

void show_queue(const FineGrainedQueue &queue) {
  Node *current = queue.getHead();
  while (current != nullptr) {
    std::cout << current->value << " ";
    current = current->next;
  }
  std::cout << std::endl;
}

int main() {
  FineGrainedQueue new_queue;

  new_queue.insertIntoMiddle(80, 2);
  new_queue.insertIntoMiddle(55, 3);
  new_queue.insertIntoMiddle(30, 5);
  new_queue.insertIntoMiddle(4, 2);
  new_queue.insertIntoMiddle(34, 55);
  new_queue.insertIntoMiddle(74, 55);
  new_queue.insertIntoMiddle(24, 55);

  show_queue(new_queue);

  return 0;
}
