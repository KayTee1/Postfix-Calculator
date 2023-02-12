#pragma once
#include <iostream>

typedef double Stack_entry;

const int MAX_STACK_SIZE = 50;

class Stack {
public:
  Stack();

  void push(double value);
  double pop();
  double top();

  bool empty();
  int size();

private:
  int count;
  Stack_entry data[MAX_STACK_SIZE];
};
