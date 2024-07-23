// Run in repl.it:
// g++ -pthread -std=c++17 -o calc calc.cpp; 
//./calc < calc_test1.in
// Run in zeus:
// g++ -pthread -o calc calc.cpp; 
//./calc < calc_test1.in

#include <cstdlib>
#include <iostream>
#include <string>

#include "dlist.h"

/*
  operations: + add
              - subtract
              * multiply 
              / divide
              n negate top item
              d duplicate top item
              r reverse top two items
              p print top item
              c clear entire stack
              a print all items
              q quit
*/

class divZero {
};

class badInput {
};

/**** INSTRUCTOR NOTE: DO NOT MODIFY ABOVE THIS LINE ****/

/*******************************************************
 * INSTRUCTOR NOTE: Implement the functions below.     *
 * You may throw exception classes emptyList, divZero, *
 * or badInput from these functions as needed.         *
 ******************************************************/

// EFFECTS: performs + operation
void DoAdd(Dlist<double> &stack) {
    double num1 = stack.RemoveFront();
    double num2 = stack.RemoveFront();
    stack.InsertFront(num1 + num2);
}

// EFFECTS: performs - operation
void DoSub(Dlist<double> &stack) {
    double num1 = stack.RemoveFront();
    double num2 = stack.RemoveFront();
    stack.InsertFront(num2 - num1);
}

// EFFECTS: performs * operation
void DoMult(Dlist<double> &stack) {
    double num1 = stack.RemoveFront();
    double num2 = stack.RemoveFront();
    stack.InsertFront(num1 * num2);
}

// EFFECTS: performs / operation
void DoDiv(Dlist<double> &stack) {
    double num1 = stack.RemoveFront();
    double num2 = stack.RemoveFront();

    //divide by zero case
    if (num1 == 0) {
        throw divZero();
    } else {    //all other cases
        stack.InsertFront(num2 / num1);
    }
}

// EFFECTS: performs n operation
void DoNeg(Dlist<double> &stack) {
    double num = stack.RemoveFront();
    stack.InsertFront(num * -1);

}

// EFFECTS: performs d operation
void DoDup(Dlist<double> &stack) {
    double num = stack.RemoveFront();
    stack.InsertFront(num);
    stack.InsertFront(num);
}

// EFFECTS: performs r operation
void DoRev(Dlist<double> &stack) {
    double num1 = stack.RemoveFront();
    double num2 = stack.RemoveFront();
    stack.InsertFront(num1);
    stack.InsertFront(num2);
}

// EFFECTS: performs p operation
void DoPrint(Dlist<double> &stack) {
    double num = stack.RemoveFront();
    std::cout << num << "\n";
    stack.InsertFront(num);
}

// EFFECTS: performs c operation
void DoClear(Dlist<double> &stack) {
    while (!stack.IsEmpty()) {
        stack.RemoveFront();
    }
}

// EFFECTS: performs a operation
void DoPrintAll(Dlist<double> &stack) {
    Dlist<double> printStack = stack;
    while (!printStack.IsEmpty()) {
        std::cout << stack.RemoveFront() << " ";
    }
    std::cout << "\n";
}

/**** INSTRUCTOR NOTE: DO NOT MODIFY BELOW THIS LINE ****/

bool DoOne(Dlist<double> &stack) {
    std::string s;
    double d;

    std::cin >> s;
    switch (s[0]) {
        case '+':
            DoAdd(stack);
            break;
        case '-':
            DoSub(stack);
            break;
        case '*':
            DoMult(stack);
            break;
        case '/':
            DoDiv(stack);
            break;
        case 'n':
            DoNeg(stack);
            break;
        case 'd':
            DoDup(stack);
            break;
        case 'r':
            DoRev(stack);
            break;
        case 'p':
            DoPrint(stack);
            break;
        case 'c':
            DoClear(stack);
            break;
        case 'a':
            DoPrintAll(stack);
            break;
        case 'q':
            return true;
            break;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            d = std::atof(s.c_str());
            stack.InsertFront(d);
            break;
        default:
            badInput e;
            throw e;
            break;
    }
    return false;
}

int main() {
    Dlist<double> stack;

    bool done = false;
    while (!done) {
        try {
            done = DoOne(stack);
        } catch (emptyList e) {
            std::cout << "Not enough operands\n";
        } catch (divZero e) {
            std::cout << "Divide by zero\n";
        } catch (badInput e) {
            std::cout << "Bad input\n";
        }
    }
}
