#pragma once

#include <mutex>

struct Node {
  int value;
  Node *next;

  std::mutex node_mutex;
};

class FineGrainedQueue {
public:
  FineGrainedQueue() : head(nullptr) {}

  void insertIntoMiddle(int value, int pos);
  Node *getHead() const noexcept;

private:
  Node *head;
  std::mutex queue_mutex;
};
