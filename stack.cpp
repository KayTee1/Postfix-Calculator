#include "stack.h"

Stack::Stack() {
  count = 0;
}

void Stack::push(double value) {
  if (count >= MAX_STACK_SIZE) {
    std::cout << "Stack overflow." << std::endl;
    return;
  }

  data[count++] = value;
}

double Stack::pop() {
  if (empty()) {
    std::cout << "Stack underflow." << std::endl;
    return -1;
  }

  return data[--count];
}

double Stack::top() { return data[count - 1]; }

bool Stack::empty() { return count == 0; }

int Stack::size() { return count; }
