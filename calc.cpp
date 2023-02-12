#include <iostream>
#include <cmath>
#include "calc.h"
using namespace std;

Calc::Calc(){ }

void Calc::optionSA(Stack &numbers, char option)
{
    int answer{};
    //stackSize for calculating average
    int stackSize = numbers.size();

    //adding up Stack items for sum or average
    while(!numbers.empty()){
        answer += numbers.top();
        numbers.pop();
    }

    //a = average
    if(option == 'a'){
        answer = answer / stackSize;
    }
    //pushing final answer to the top of the stack
    numbers.push(answer);

}


void Calc::optionX(Stack &numbers)
{
    //swapping the places of num1 and num2 in numbers stack
    double num1 = numbers.pop();
    double num2 = numbers.pop();
    numbers.push(num1);
    numbers.push(num2);
}


void Calc::calculateFromStack(Stack &numbers, Stack &operations)
{
    //calculating num1 and num2 with operation and pushing it to numbers stack
    double num2 = numbers.top();
    numbers.pop();
    double num1 = numbers.top();
    numbers.pop();
    char operation = operations.top();
    operations.pop();
    numbers.push(this->calculate(num1, num2, operation));
}



double Calc::calculate(double num1, double num2, char operation)
{
    switch(operation){
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        case '%':
            return fmod(num1, num2);
        case '^':
            return pow(num1, num2);
        case 'v':
            return sqrt(num2);
        default:
            return 0;
    }
    return 0;
}
