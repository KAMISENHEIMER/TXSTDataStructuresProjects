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
    //make sure there are enough values to use
    if (!stack.IsEmpty()) {     //the first value exists
        double num1 = stack.RemoveFront();
        if (!stack.IsEmpty()) {     //the second value exists
            double num2 = stack.RemoveFront();
            stack.InsertFront(num1 + num2);     //all values exist, perform the addition and add to stack
        } else {    //the second value does not exist
            stack.InsertFront(num1);    //add the first value back into the stack
            throw emptyList();      //addition not performed, throw empty list error
        }
    } else {    //the first value does not exist
        throw emptyList();      //addition not performed, throw empty list error
    }
}

// EFFECTS: performs - operation
void DoSub(Dlist<double> &stack) {      //exactly the same as the addition, but using - instead
    //make sure there are enough values to use
    if (!stack.IsEmpty()) {     //the first value exists
        double num1 = stack.RemoveFront();
        if (!stack.IsEmpty()) {     //the second value exists
            double num2 = stack.RemoveFront();
            stack.InsertFront(num2 - num1);     //all values exist, perform the subtraction and add to stack
        } else {    //the second value does not exist
            stack.InsertFront(num1);    //add the first value back into the stack
            throw emptyList();      //subtraction not performed, throw empty list error
        }
    } else {    //the first value does not exist
        throw emptyList();      //subtraction not performed, throw empty list error
    }
}

// EFFECTS: performs * operation
void DoMult(Dlist<double> &stack) {      //exactly the same as the addition, but using * instead
    //make sure there are enough values to use
    if (!stack.IsEmpty()) {     //the first value exists
        double num1 = stack.RemoveFront();
        if (!stack.IsEmpty()) {     //the second value exists
            double num2 = stack.RemoveFront();
            stack.InsertFront(num1 * num2);     //all values exist, perform the multiplication and add to stack
        } else {    //the second value does not exist
            stack.InsertFront(num1);    //add the first value back into the stack
            throw emptyList();      //multiplication not performed, throw empty list error
        }
    } else {    //the first value does not exist
        throw emptyList();      //multiplication not performed, throw empty list error
    }
}

// EFFECTS: performs / operation
void DoDiv(Dlist<double> &stack) {      //similar to addition, but using / and checking a divide by 0 case
    //make sure there are enough values to use
    if (!stack.IsEmpty()) {     //the first value exists
        double num1 = stack.RemoveFront();
        if (num1 != 0) {       //the first value is valid (not 0)
            if (!stack.IsEmpty()) {     //the second value exists
                double num2 = stack.RemoveFront();
                stack.InsertFront(num2 / num1);     //all values exist and are valid, perform the division and add to stack
            } else {    //the second value does not exist
                stack.InsertFront(num1);    //add the first value back into the stack
                throw emptyList();      //division not performed, throw empty list error
            }
        } else {    //the first value is a zero
            stack.InsertFront(num1);    //add the first value back into the stack
            throw divZero();      //division not performed, throw div zero error
        }
    } else {    //the first value does not exist
        throw emptyList();      //division not performed, throw empty list error
    }
}

// EFFECTS: performs n operation
void DoNeg(Dlist<double> &stack) {
    //no need for empty list check, as it is built into the RemoveFront() function, and there would be nothing to add back to the stack
    double num = stack.RemoveFront();
    stack.InsertFront(num * -1);

}

// EFFECTS: performs d operation
void DoDup(Dlist<double> &stack) {
    //no need for empty list check, as it is built into the RemoveFront() function, and there would be nothing to add back to the stack
    double num = stack.RemoveFront();
    stack.InsertFront(num);
    stack.InsertFront(num);
}

// EFFECTS: performs r operation
void DoRev(Dlist<double> &stack) {
    //make sure there are enough values to use
    if (!stack.IsEmpty()) {     //the first value exists
        double num1 = stack.RemoveFront();
        if (!stack.IsEmpty()) {     //the second value exists
            double num2 = stack.RemoveFront();
            stack.InsertFront(num1);
            stack.InsertFront(num2);     //all values exist, reverse the values
        } else {    //the second value does not exist
            stack.InsertFront(num1);    //add the first value back into the stack
            throw emptyList();      //reverse not performed, throw empty list error
        }
    } else {    //the first value does not exist
        throw emptyList();      //reverse not performed, throw empty list error
    }
}

// EFFECTS: performs p operation
void DoPrint(Dlist<double> &stack) {
    //no need for empty list check, as it is built into the RemoveFront() function, and there would be nothing to add back to the stack
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
        std::cout << printStack.RemoveFront() << " ";
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
