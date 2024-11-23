//
//  main.cpp
//  Discrete Maths Tasks
//
//  Created by Omar Nouh on 11/21/24.
//

#include <iostream>
#include <vector>
using namespace std;

/*
bool notVar (bool p);
bool varOrvar (bool p, bool q);
bool varAndvar (bool p, bool q);
bool satisfiabilityCheck_VarOrVar (bool p, bool q);
bool satisfiabilityCheck_VarAndVar (bool p, bool q);
bool satisfiabilityCheck (bool p);
*/
 
int main(int argc, const char * argv[]) {
    // insert code here...
    // std::cout << "Hello, World!\n";
    int numOfvariables;                                         // definition of the number of arguments and the checker
    bool finalizeDecision;
    do {
        cout << "How many variables are present?" << endl;
        cin >> numOfvariables;                                  // input the number of variable that will be created
        cout << "Are you sure?" << endl <<"If yes type type any number, if no type 0 to re-enter the number of values" << endl;
        cin >> finalizeDecision;                                // if changes are needed or wrong input restart the loop
    } while (finalizeDecision == false);
    vector<char> nameOfvar;                                     // creation of array to carry the names (p is to initialize but is replaced in the following code
    nameOfvar.resize(numOfvariables);
    char name;
//    char nameOfvar[] = {'p'};
    int i = 0;                                                  // the index/counter will be needed in a later code
    for (i = 0; i < numOfvariables; i++) {                      // the loop to name each statement
        cout << "enter the variable's letter representative" << endl;
//        cin >> nameOfvar[i];
        cin >> name;
        nameOfvar.at(i) = name;                                    // place the naming in an array
    }
/*    cout << nameOfvar << endl; */                             // test code to check the size of the array and values
/*    cout << i << endl; */                                     // test code to check the value of the array's index
    double possibilities = pow(2, numOfvariables);
    int e = 1;
    for (int k = 0; k < numOfvariables; k++) {                  // loop to seperate each argument name into it's own array that will carry truth values
        vector<bool> nameOfvar[k];                              // dynamic array who's name is that which was enterred in the array 'nameOfvar[]'
        cout << nameOfvar << endl;
        for (double l = 0; l < possibilities; l++, e++) {            // loop to generate the arrangement of 'T' and 'F' for the argument
            while (((int)(possibilities / pow(2, ((e))))) < (pow(2, (numOfvariables - e))) ) {  // loop to place the true at the position that switches every power of 2
                nameOfvar[k][l] = true;
                cout << nameOfvar[k][l] << endl;
                /*nameOfvar[k].at(l) = true;*/                         // set the position to true
                l++;                                            // increase position by 1
            }
            while (((int)(possibilities / pow(2, ((e))))) >= (pow(2, (numOfvariables - e))) ) { // loop to place the false at the position that switches every power of 2
                nameOfvar[k][l] = false;
                /*nameOfvar[k].at(l) = false;*/                        // set the position to false
                l++;                                            // increase position by 1
            }
            e++;                                                // variable true/false chunks counter increases
        }
    }
    for (int j = 0; j < numOfvariables; j++) {
        cout << nameOfvar.at(j) << endl;
    }
    
    return 0;
}

// A set of statements is Satisfiable if and only if there is at least one interpretation that makes all statements of the set True at the same time.

// we will first create for each argument its array of possible values nut that depends on how many arguments we treat



















/*
// Functions to Check conditions such as the 'And' (⌃), 'Or' (⌄), 'Not' (~)

    // varAndvar needs both arguments to be true
bool varAndvar (bool p, bool q) {           // definition of the function and it's parameters
    bool checkAnd = 0;                      // definition of a new variable to carry the anding of the two arguments (p ⌃ q)
    if ((p == 1) && (q == 1)) {             // if true, the variable 'checkAnd' carries 1
        checkAnd = 1;
    } else {                                // if false, the variable 'checkAnd' carries 0
        checkAnd = 0;
    }
    return checkAnd;                        // the function returns wiith the value of 'checkAnd'
}

    // varOrvar only needs one argument to be true (or both)
bool varOrvar (bool p, bool q) {            // definition of the function and it's parameters
    bool checkOr = 0;                       // definition of a new variable to carry the oring of the two arguments (p ⌄ q)
    if ((p == 1) || (q == 1)) {             // if true, the variable 'checkOr' carries 1
        checkOr = 1;
    } else {                                // if false, the variable 'checkOr' carries 0
        checkOr = 0;
    }
    return checkOr;                         // the function returns wiith the value of 'checkOr'
}

    // notVar inverts the argument's value
bool notVar (bool p) {                      // definition of the function and it's parameter
    bool notp = 0;                          // definition of a new variable to carry the inversion of the argument (~p)
    if (p == 0) {                           // if p is true, ~p is false
        notp = 1;
    } else if (p == 1) {                    // if p is false, ~p is true
        notp = 0;
    }
    return notp;                            // the function returns with the inverted value of the initial argument
}

    // Function that checks the Satisfiability of the two arguments
bool satisfiabilityCheck_VarOrVar (bool p, bool q) {            // definition of the function and it's parameters
    bool Satisfiable[] = {0};                                   // definition of the array with varying size (two variables will induce 4 possibilities (i.e. 2^2)
    int i = 0;                                                  // index of the array
    if (notVar(p) && notVar(q)) {
        for (int a = 1; a >= 0; a--) {                          // first loop to simulate the possible values of the first argument (p)
            for (int b = 1; b >= 0; b--) {                      // second embeded loop to simualte the possible combinations for the second argument (q)
                bool p = a;                                     // p takes two the value of a which is 0 or 1
                bool q = b;                                     // for every value of p there are two values of q which are 1 or 0
                if ((p == 1) || (q == 1)) {                     // only one truth between both arguments is needed to verify the satisfiability of the statement
                    Satisfiable[i] = 1;
                    break;                                      // exit the loop  as soon as we find the truth value
                }
                i++;                                            // increment i to move to the next index int the array
            }
        }
    } else if (notVar(p)) {
        for (int a = 1; a >= 0; a--) {                          // first loop to simulate the possible values of the first argument (p)
            for (int b = 0; b <= 1; b++) {                      // second embeded loop to simualte the possible combinations for the second argument (q)
                bool p = a;                                     // p takes two the value of a which is 0 or 1
                bool q = b;                                     // for every value of p there are two values of q which are 1 or 0
                if ((p == 1) || (q == 1)) {                     // only one truth between both arguments is needed to verify the satisfiability of the statement
                    Satisfiable[i] = 1;
                    break;                                      // exit the loop  as soon as we find the truth value
                }
                i++;                                            // increment i to move to the next index int the array
            }
        }
    } else if (notVar(q)) {
        for (int a = 0; a <= 1; a++) {                          // first loop to simulate the possible values of the first argument (p)
            for (int b = 1; b >= 0; b--) {                      // second embeded loop to simualte the possible combinations for the second argument (q)
                bool p = a;                                     // p takes two the value of a which is 0 or 1
                bool q = b;                                     // for every value of p there are two values of q which are 1 or 0
                if ((p == 1) || (q == 1)) {                     // only one truth between both arguments is needed to verify the satisfiability of the statement
                    Satisfiable[i] = 1;
                    break;                                      // exit the loop  as soon as we find the truth value
                }
                i++;                                            // increment i to move to the next index int the array
            }
        }
    } else {
        for (int a = 0; a <= 1; a++) {                          // first loop to simulate the possible values of the first argument (p)
            for (int b = 0; b <= 1; b++) {                      // second embeded loop to simualte the possible combinations for the second argument (q)
                bool p = a;                                     // p takes two the value of a which is 0 or 1
                bool q = b;                                     // for every value of p there are two values of q which are 1 or 0
                if ((p == 1) || (q == 1)) {                     // only one truth between both arguments is needed to verify the satisfiability of the statement
                    Satisfiable[i] = 1;
                    break;                                      // exit the loop  as soon as we find the truth value
                }
                i++;                                            // increment i to move to the next index int the array
            }
        }
    }
    
    
    bool satisfied = 0;                                         // creation of a new variable that will be returned to prove the satisfiability of the arguments
    for (int h = 0; h < i; h++) {                               // we check all the indexes of the array looking for one true value (i.e. which would be of 1)
        if (Satisfiable[i] == 1) {                              // if found, we exit the loop and assign the variable 'satisfied' the boolean expressioon true (in other words 1)
            satisfied = true;
            cout << "the statement is satisfiable" << endl;
            break;
        } else {                                                // if not found, the variable 'satisfied' maintains it's status of false (in other wordss 0)
            satisfied = false;
            cout << "the statement is not satisfiable" << endl;
        }
    }
    return satisfied;                                           // the function returns with the truthness of 'satisfied'
}

    // Function that checks the Satisfiability of the two arguments
bool satisfiabilityCheck_VarAndVar (bool p, bool q) {           // definition of the function and it's parameters
    bool Satisfiable[] = {0};                                   // definition of the array with varying size (two variables will induce 4 possibilities (i.e. 2^2)
    int i = 0;                                                  // index of the array
    if (notVar(p) && notVar(q)) {
        for (int a = 1; a >= 0; a--) {                              // first loop to simulate the possible values of the first argument (p)
            for (int b = 1; b >= 0; b--) {                          // second embeded loop to simualte the possible combinations for the second argument (q)
                bool p = a;                                         // p takes two the value of a which is 0 or 1
                bool q = b;                                         // for every value of p there are two values of q which are 1 or 0
                if ((p == 1) && (q == 1)) {                         // both argument's truths are needed to verify the satisfiability of the statement
                    Satisfiable[i] = 1;
                    break;                                          // exit the loop  as soon as we find the truth value
                }
                i++;                                                // increment i to move to the next index int the array
            }
        }
    } else if (notVar(p)) {
        for (int a = 1; a >= 0; a--) {                              // first loop to simulate the possible values of the first argument (p)
            for (int b = 0; b <= 1; b++) {                          // second embeded loop to simualte the possible combinations for the second argument (q)
                bool p = a;                                         // p takes two the value of a which is 0 or 1
                bool q = b;                                         // for every value of p there are two values of q which are 1 or 0
                if ((p == 1) && (q == 1)) {                         // both argument's truths are needed to verify the satisfiability of the statement
                    Satisfiable[i] = 1;
                    break;                                          // exit the loop  as soon as we find the truth value
                }
                i++;                                                // increment i to move to the next index int the array
            }
        }
    } else if (notVar(q)) {
        for (int a = 0; a <= 1; a++) {                              // first loop to simulate the possible values of the first argument (p)
            for (int b = 1; b >= 0; b--) {                          // second embeded loop to simualte the possible combinations for the second argument (q)
                bool p = a;                                         // p takes two the value of a which is 0 or 1
                bool q = b;                                         // for every value of p there are two values of q which are 1 or 0
                if ((p == 1) && (q == 1)) {                         // both argument's truths are needed to verify the satisfiability of the statement
                    Satisfiable[i] = 1;
                    break;                                          // exit the loop  as soon as we find the truth value
                }
                i++;                                                // increment i to move to the next index int the array
            }
        }
    } else {
        for (int a = 0; a <= 1; a++) {                              // first loop to simulate the possible values of the first argument (p)
            for (int b = 0; b <= 1; b++) {                          // second embeded loop to simualte the possible combinations for the second argument (q)
                bool p = a;                                         // p takes two the value of a which is 0 or 1
                bool q = b;                                         // for every value of p there are two values of q which are 1 or 0
                if ((p == 1) && (q == 1)) {                         // both argument's truths are needed to verify the satisfiability of the statement
                    Satisfiable[i] = 1;
                    break;                                          // exit the loop  as soon as we find the truth value
                }
                i++;                                                // increment i to move to the next index int the array
            }
        }
    }
    
    for (int a = 0; a <= 1; a++) {                              // first loop to simulate the possible values of the first argument (p)
        for (int b = 0; b <= 1; b++) {                          // second embeded loop to simualte the possible combinations for the second argument (q)
            bool p = a;                                         // p takes two the value of a which is 0 or 1
            bool q = b;                                         // for every value of p there are two values of q which are 1 or 0
            if ((p == 1) && (q == 1)) {                         // both argument's truths are needed to verify the satisfiability of the statement
                Satisfiable[i] = 1;
                break;                                          // exit the loop  as soon as we find the truth value
            }
            i++;                                                // increment i to move to the next index int the array
        }
    }
    
    bool satisfied = 0;                                         // creation of a new variable that will be returned to prove the satisfiability of the arguments
    for (int h = 0; h < i; h++) {                               // we check all the indexes of the array looking for one true value (i.e. which would be of 1)
        if (Satisfiable[i] == 1) {                              // if found, we exit the loop and assign the variable 'satisfied' the boolean expressioon true (in other words 1)
            satisfied = true;
            cout << "the statement is satisfiable" << endl;
            break;
        } else {                                                // if not found, the variable 'satisfied' maintains it's status of false (in other wordss 0)
            satisfied = false;
            cout << "the statement is not satisfiable" << endl;
        }
    }
    return satisfied;                                           // the function returns with the truthness of 'satisfied'
}


    // Function that checks the Satisfiability of an argument that will be built on other functions
bool satisfiabilityCheck (bool p) {         // definition of the function and it's parameter
    bool satisfiable = 0;                   // creation of a new variable that will return the satisfiability
    if (p == 1) {                           // if the boolean is true, the argument is satisfiable
        satisfiable = 1;
        cout << "the statement is satisfiable" << endl;
    } else if (p !=  1) {                   // if the boolean is false, the argument is not satisfiable                                                                 (you can replace '!= 1' with '== 0')
        satisfiable = 0;
        cout << "the statement is not satisfiable" << endl;
    }
    return satisfiable;                     // the function returns with the truthness of 'satisfiable'
}
*/
