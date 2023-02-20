#include <iostream>
#include <string>
#include "stack.h"
#include "calc.h"
using namespace std;

double handleExpression(string expression){
    //Calc class
    Calc calc;

    //initializing stacks for numbers and operations
    Stack numbers;
    Stack operations;


    //boolean to check if a special option is used
    bool options{false};

    //finding digits or '.' in expression
    for (int i = 0; i < expression.length(); i++) {
        if (isdigit(expression[i]) || expression[i] == '.') {
            //building decimal numbers as string num_str then pushing it as double into numbers Stack
            string num_str;
            while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.')) {
                num_str += expression[i];
                i++;
            }
            i--;
            //saving num to stack numbers
            double num = stod(num_str);
            numbers.push(num);
        }
    }
    for (int i = 0; i < expression.length(); i++){
        if (
            expression[i] == '+' || expression[i] == '-' || expression[i] == '*' ||
            expression[i] == '/' || expression[i] == '%' || expression[i] == '^' ||
            expression[i] == 'v' || expression[i] == 'x' || expression[i] == 's' ||
            expression[i] == 'a') {

            //swapping places of num1 and num2 for optionX
            if(expression[i] == 'x'){
                calc.optionX(numbers);
            }
            else if(expression[i] == 's' || expression[i] == 'a'){
                options = true;
                calc.options(numbers, expression[i]);
            }
            else{
                while (!operations.empty()) {
                    //calculating num1 and num2 with operation and pushing it to numbers stack
                    calc.calculateFromStack(numbers, operations);
                }
                //pushing the current expression to operations stack
                operations.push(expression[i]);
            }
        }
    }

    //final answer is calculated in the options function already
    if(options != true){
        while (!operations.empty()) {
            //calculating remaining operations from stack
            calc.calculateFromStack(numbers, operations);
        }
    }

    //returning the final answer
    return numbers.top();

}

int main(){

    string expression;
    getline(cin, expression);

    double result = handleExpression(expression);
    cout << result << endl;

    return 0;

}