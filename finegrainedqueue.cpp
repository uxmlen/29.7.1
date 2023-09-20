#include "finegrainedqueue.h"

void FineGrainedQueue::insertIntoMiddle(int value, int pos) {
  int current_pos = 1;
  Node *new_node = new Node;
  new_node->value = value;
  new_node->next = nullptr;

  std::lock_guard<std::mutex> lock(queue_mutex);

  if (head == nullptr) {
    head = new_node;
  } else {
      Node *current = head;
      Node *previous = nullptr;

      while (current_pos < pos && current != nullptr) {
        previous = current;
        current = current->next;
        current_pos++;
      }

      if (current == nullptr) {
        previous->next = new_node;
      } else {
        std::lock_guard<std::mutex> previous_node(previous->node_mutex);
        previous->next = new_node;
        std::lock_guard<std::mutex> next_node(current->node_mutex);
        new_node->next = current;
      }
  }
}

Node *FineGrainedQueue::getHead() const noexcept { return head; }
