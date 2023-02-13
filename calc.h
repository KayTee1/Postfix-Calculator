#pragma once
#include "stack.h"

class Calc {

public:
    Calc();

    void options(Stack &numbers, char option);
    void optionX(Stack &numbers);

    double calculate(double num1, double num2, char operation);
    void calculateFromStack(Stack &numbers, Stack &operations);

private:
    int num1, num2;

    char operation;
    char option;
};