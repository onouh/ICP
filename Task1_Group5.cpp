//
//  main.cpp
//  Discrete Maths Tasks
//
//  Created by Omar Nouh.
//

#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
//#include <math.h>

using namespace std;

/*
bool notVar (bool p);
bool varOrvar (bool p, bool q);
bool varAndvar (bool p, bool q);
bool satisfiabilityCheck_VarOrVar (bool p, bool q);
bool satisfiabilityCheck_VarAndVar (bool p, bool q);
bool satisfiabilityCheck (bool p);
*/
//void truthTablefunc(int numOfvariables, vector<string>(nameOfvar));

// function prototype declarations

int numOfvar();                                                             // gets the number of variables from user
vector<string> nameOfvar(int numOfvariables);                               // stores the names of each variable in a vector
    // generates the truth table of the variables (said truth table grows as operations occur)
vector<vector<bool>> TruthTableVar(int numOfvariables, vector<string>(nameOfvar));
    // operates on two variables getting the andding (i⌃j) of them
vector<bool> anddingOfVariables(int firstVariable, int secondVariable);
    // operates on two variables getting the orring (i⌄j) of them
vector<bool> orringOfVariables(int firstVariable, int secondVariable);
vector<bool> nottingOfVariables(int Variable);                         // operates on one variable getting its notting (~i)
    // operates on two variables getting their conditionals (i->j)
vector<bool> conditionnialityOfVariables(int firstVariable, int secondVariable);
    // operates on two variables getting their conditionals (i<->j)
vector<bool> biconditionnialityOfVariables(int firstVariable, int secondVariable);
    // checks if there's at least one possibility in which the premises are true
bool satisfiabilityCheck(int numOfpremises);
void validityCheck();                       // checks in the critical rows if the conclusion remains inline
void opDecider(int numOfstatements);                            // reads the argument and decides the operation to choose
string nameBuilder(int i);
//int argumentDecider();

//struct variable {
//    string varName;
//    vector<bool> varValue;
//};

//vector<vector<bool>>(truthTable);

// Definition of global variables that will be accessed by the functions

int numOfvariables = numOfvar();            // create a variable that carries the func's return to be used on multiple occasions
int possibilities = pow(2, numOfvariables); // calculates directly the possibilities
vector<int> (prem) = {0};                   // the default premise is the tautology (to not interfere)
vector<string> nameOfVar = nameOfvar(numOfvariables);   // create an array with carrying the return of the function
vector<vector<bool>> truthTable = TruthTableVar(numOfvariables, nameOfVar); // the array can be edited and grows
vector<bool> satisfiable;                   // create the array to store the values
string argument;                            // creates the variable that will store the arguments inputed
string newName;                             // creates the variable that will store the new variable
int variable1 = 0, variable2 = 0, variable = 0; // will be used as indexes while operating

int main(int argc, const char * argv[]) {
        // insert code here...
        //    std::cout << "Hello, World!\n";
//    string variables;
    /*//    int numOfvariables = numOfvar();
     //    vector<string> nameOfVar = nameOfvar(numOfvariables);
     //    vector<vector<bool>>truthTable = TruthTableVar(numOfvariables, nameOfVar);*/
//    cout << "please enter your statement" << endl;
//    string argLong;
//    cin.ignore();
//    getline(cin, argLong);
//    cout << "uh oh ERROR" << endl;
    bool newArgument = 0;                                   // set initially to zero
    int numOfstatements = 0;
    do {                                                    // to enter the loop at least once
        cout << "how many statements are you enterring" << endl;
        cin >> numOfstatements;                             // get the response
        opDecider(numOfstatements);                         // decide the operation and take the argument
        cout << "is there another statement?" << endl << "if yes enter Y, if not write N" << endl;
        char answer;                                        // create a variable to store the user's response
        cin >> answer;                                      // get the response
        if (answer == 'Y') {
            newArgument = 1;                                // if the user wants to entere another variable
        } else {
            newArgument = 0;                                // remains at default value
        }
    } while (newArgument == 1);
//    if (newArgument == 1) {
//        cout << "please enter your statement using simplified variables and the following symbols: \" & \"(for and) \" | \"(for or)\" ~ \"(for not)" << endl;
//        goto NewStatement;
//    }
    cout << "how many premises are being checked?" << endl;
    int numOfPrem;                                          // the variablle holds the nnumber of premises
    cin >> numOfPrem;                                       // get the response
    bool sat = satisfiabilityCheck(numOfPrem);              // store the return of the function in the bool
    if (sat == true) {                                      // only enter if satisfiable
        validityCheck();                                    // check for validity if the premises are satisfiable
    }
    
/*//    cout << "which variables would you like to operate on" << endl;
//    cin >> var1 >> var2;
//    vector<bool> andOp = anddingOfVariables(var1, var2, numOfvariables);
//    int i;
//    for (i = 0; i < nameOfVar.size(); i++) {               // test code to see the truth table layout
//        cout << setw(5) << nameOfVar[i] << " ";
//        for (int j = 0; j < truthTable[i].size(); j++) {
//            cout << truthTable[i][j] << " ";
//        }
//        cout << endl;
//    }
//    cout << nameOfVar[var1 - 1] << " ⌃ " << nameOfVar[var2 - 1] << " ";
//    for (int j = 0; j < truthTable[i].size(); j++) {
//        cout << truthTable[i][j] << " ";
//    }
//    cout << endl; */

//    int i;
    for (int i = 1; i < nameOfVar.size(); i++) {               // test code to see the truth table layout
        cout << setw(15) << nameOfVar[i] << " ";
        for (int j = 0; j < truthTable[i].size(); j++) {
            cout << truthTable[i][j] << " ";
        }
        cout << endl;
    }
/*    for (int i = 0; i < truthTable.size(); i++) {
        for (int j = 0; j < truthTable[i].size(); j++) {
            cout << truthTable[i][j] << " ";
        }
        cout << endl;
    } */

    return 0;
}

// A set of statements is Satisfiable if and only if there is at least one interpretation that makes all statements of the set true at the same time.
// The concllusion is only valid if the critical rows (the premises are true) and the the conclusion are both strictly true.

int numOfvar() {
    int numOfvariables;                                         // definition of number of arguments and checker
    bool finalizeDecision;
    do {
        cout << "How many variables are present?" << endl;
        cin >> numOfvariables;                                  // input number of variable that will be created
//        cin.ignore();
        cout << "Are you sure?" << endl <<"If yes type 1, if no type 0 to re-enter the number of values" << endl;
        cin >> finalizeDecision;                                // if changes are needed or wrong input restart the loop
//        cin.ignore();
    } while (finalizeDecision == false);
    return numOfvariables;
}

vector<string> nameOfvar(int numOfvariables) {
//    int numOfvariables = numOfvar();
    numOfvariables++;                                           // we increase by one to account for the creation of the totaulogy
    vector<string>nameOfvar;                                    // creation of array to carry the names
    nameOfvar.resize(numOfvariables);                           // resize the array
    nameOfvar[0] = "t";                                         // naming the first variable
    string name;
    for (int i = 1; i < numOfvariables; i++) {                  // the loop to name each statement
        cout << "enter the variable's letter representative" << endl;
            //        cin >> nameOfvar[i];
        cin >> name;
//        cin.ignore();
        nameOfvar[i] = name;                                    // place the naming in an array
    }
/*    for (int i = 0; i < numOfvariables; i++) {                // test code to check the array
        cout << nameOfvar[i] << endl;
    } */
//    cout << nameOfvar << endl;                              // test code to check the size of the array and values
//    cout << i << endl;                                      // test code to check the value of the array's index
    return nameOfvar;
}

vector<vector<bool>>TruthTableVar(int numOfvariables, vector<string>(nameOfvar)) {
//    int possibilities = pow(2, numOfvariables);
//    cout << "p = " << possibilities << endl;               // test code to check the number of possibilities
    vector<vector<bool>>truthTable;
    
    vector<bool>(tautology);
        // loop to initialize the truth values for the tautology
    for (int i = 0; i < possibilities; i++) {
        bool value = true;                                      // set the value to true
        tautology.push_back(value);                             // fill the row
    }
    truthTable.push_back(tautology);                            // add the row to the truth table
        // loop to seperate each argument name into it's own array that will carry truth values
    for (int k = 0; k < numOfvariables; k++) {
        vector<bool>(row);
        
        // we want here to check k, because depending on which row, you'll know how to fill the truth table (aka every one row switch between T and F, or every 2 rows, or every 4 rows, etc.) change every 2,4,8 (2^k)
        
        int toggle = pow(2, k);                                 // Determines when to toggle true/false
        bool value = true;                                      // Initial value for toggling
        for (int l = 0; l < possibilities; l++) {
            
            if (l % toggle == 0) {
                value = !value;                                 // Toggle the value
            }
            row.push_back(value);                               // fill the row
        }
        truthTable.push_back(row);                              // add the row to the truth table
    }
  /*  for (int i = 0; i < truthTable.size(); i++) {               // test code to see the truth table layout
        cout << nameOfvar[i] << " ";
        for (int j = 0; j < truthTable[i].size(); j++) {
            cout << truthTable[i][j] << " ";
        }
        cout << endl;
    } */
    return truthTable;
}

vector<bool> anddingOfVariables(int firstVariable, int secondVariable) {
    vector<bool>varANDvar;                                                  // create the array to store the values
//    int possibilities = pow(2, numOfvariables);
    for (int l = 0; l < possibilities; l++) {
        bool value = (truthTable[firstVariable][l] && truthTable [secondVariable][l]); // take the and of both variables
        varANDvar.push_back(value);
    }
    truthTable.push_back(varANDvar);
    return varANDvar;
}

vector<bool> orringOfVariables(int firstVariable, int secondVariable) {
    vector<bool>varORvar;                                                   // create the array to store the values
//    int possibilities = pow(2, numOfvariables);
    for (int l = 0; l < possibilities; l++) {
        bool value = (truthTable[firstVariable][l] || truthTable [secondVariable][l]);  // take the or of both variables
        varORvar.push_back(value);
    }
    truthTable.push_back(varORvar);
    return varORvar;
}

vector<bool> nottingOfVariables(int Variable) {
    vector<bool>varNOT;                                                     // create the array to store the values
//    int possibilities = pow(2, numOfvariables);
    for (int l = 0; l < possibilities; l++) {
        bool value = (!truthTable[Variable][l]);                                        // take the not of the variable
        varNOT.push_back(value);
    }
    truthTable.push_back(varNOT);
    return varNOT;
}

vector<bool> conditionnialityOfVariables(int firstVariable, int secondVariable) {
    vector<bool>varIF_THEN;                                                 // create the array to store the values
    for (int l = 0; l < possibilities; l++) {
            // take the not of the first variable and ors it with the second variable
        bool value = ((!truthTable[firstVariable][l]) || truthTable [secondVariable][l]);
        varIF_THEN.push_back(value);
    }
    truthTable.push_back(varIF_THEN);
    return varIF_THEN;
}

vector<bool> biconditionnialityOfVariables(int firstVariable, int secondVariable) {
    vector<bool>varONLY_IF;                                                 // create the array to store the values
    for (int l = 0; l < possibilities; l++) {
            // take the not of the first variable, or's it with the second variable, and's it with the switched
        bool value = (((!truthTable[firstVariable][l]) || truthTable [secondVariable][l]) && ((!truthTable[secondVariable][l]) || truthTable [firstVariable][l]));
        varONLY_IF.push_back(value);
    }
    truthTable.push_back(varONLY_IF);
    return varONLY_IF;
}

bool satisfiabilityCheck(int numOfpremises = 1) {
    bool initialVal = true;                                                 // initially set it to a neutral value
    for (int l = 0; l < possibilities; l++) {
        satisfiable.push_back(initialVal);                                  // fill the array
    }
    cout << "which premises are being checked?" << endl;
    cout << "please enter their positions..." << endl;
    prem.resize(numOfpremises);                                             // resize the array to fit the premises
//    vector<int>* ptrPrem;
    for (int i = 0; i < numOfpremises; i++) {
        cin >> prem[i];                                                     // get each position to register
    }
    
    for (int i = 0; i < numOfpremises; i++) {
        for (int l = 0; l < possibilities; l++) {
                // check the satisfiability by finding the reult's and with each premise
            satisfiable[l] = (satisfiable[l] && truthTable[prem[i]][l]);
        }
    }
    /*
//    for (int l = 0; l < possibilities; l++) {
//        if (truthTable[prem[i]][l] && truthTable[prem[i+1]][l] && truthTable[prem[i+2]][l] && truthTable[prem[i+3]][l] && truthTable[prem[i+4]][l] && truthTable[prem[i+5]][l] && truthTable[prem[i+6]][l]) {
//            cout << "the premises are satisfiable" << endl;
//            satisfiable = true;
//            break;
//        }
//    } */
    bool satisfied = false;                                                 // default is set to not satisfiable
    for (int l = 0; l < possibilities; l++) {
        if (satisfiable[l] == true) {   // if finds one true, exit loop and declare satisfiable
            satisfied = true;
            cout << "the premises are satisfiable" << endl;
            break;
        }
    }
    if (satisfied == false) {   // implies a contradiction in the premises values hence no longer satisfiable all at once
        cout << "the premises are not satisfiable, hence not validatable" << endl;
    }
    return satisfied;
}

void validityCheck() {
    bool valid = true;                                                  // default is set to valid
    cout << "please enter the position of the conclusion" << endl;
    int conc;                                                           // position of the conclusion
    cin >> conc;                                                        // take the position from the user
//    int i = 0;
    for (int l = 0; l < possibilities; l++) {
        if (satisfiable[l] == true) {                                   // only check the validity of the conclusion when the satisfiability is true
            if (!truthTable[conc][l]) {                                 // if the conclusion is false print and exit
                cout << "the conclusion is not valid" << endl;
                valid = false;                                          // change the value
                break;                                                  // exit loop
            }
        }
    }
    if (valid) {                                                        // run the condition if valid and print
        cout << "the conclusion is valid" << endl;
    }
}

void opDecider(int numOfstatements) {
    for (int i = 0; i < numOfstatements; i++) {                                         // step 1 take the arguments to be treated
        cout << "please enter your statement using simplified variables and the following symbols: \" & \"(for and) \" | \"(for or)\" ~ \"(for not) \" > \" (for if then, conditional) \" < \" (for if and only if, biconditional) " << endl;
        cin.ignore();                                                                   // to allow the getline function to properly work
        getline(cin, argument);                                                         // keep reading until the new line
            //    cout << "thank you" << endl;                  // test the code
        for (int i = 0; i < argument.size(); i++) {                                     // loop to ssearch for keywords
                //        cout << "hi" << endl;                 // test the code
            if (argument[i] == '~') {                                                   // find the not operator
                    //            for (int k = 1; k <= numOfvariables; k++) {
                    //                if (argument[i+1] == nameOfVar[k][0]) {
                    //                    variable = k;
                    //                }
                    //            }
                cout << "which variable is being notted" << endl;
                cout << "please reference it's position" << endl;
                cin >> variable;                                                        // take it's position
                /*
                    //                cin.ignore();
//                string* ptr = &nameOfVar[variable];
//                string characterVar = *ptr;
//                string notSign = "~";
//                notSign.append(characterVar);
*/
                nameOfVar.push_back(nameBuilder(i));                                    // get new name
                vector<bool>(notOp) = nottingOfVariables(variable);                     // run operation
//                cout << "the expression " << notSign << " is in the position " << (nameOfVar.size() - 1) << endl;
            } else if (argument[i] == '&') {                                            // find the and operator
                cout << "which variables are being andded" << endl;
                cout << "please reference their position" << endl;
                cin >> variable1 >> variable2;
                /*
                    //            for (int k = 1; k <= numOfvariables; k++) {
                    //                if (argument[i-1] == nameOfVar[k][0]) {
                    //                    var2 = k;
                    //                }
                    //                if (argument[i+1] == nameOfVar[k][0]) {
                    //                    var1 = k;
                    //                }
                    //            }
                    //                cin.ignore();
//                string* ptr1 = &nameOfVar[variable1];
//                string characterVar1 = *ptr1;
//                string andSign = "&";
//                string* ptr2 = &nameOfVar[variable2];
//                string characterVar2 = *ptr2;
//                andSign.append(characterVar2);
//                characterVar1.append(andSign);
*/
                nameOfVar.push_back(nameBuilder(i));                                    // get new name
                vector<bool> andOp = anddingOfVariables(variable1, variable2);          // run operation
//                cout << "the expression " << characterVar1 << " is in the position " << (nameOfVar.size() - 1) << endl;
            } else if (argument[i] == '|') {                                            // find the or operator
                cout << "which variables are being orred" << endl;
                cout << "please reference their position" << endl;
                cin >> variable1 >> variable2;
                /*
                    //            for (int k = 1; k <= numOfvariables; k++) {
                    //                if (argument[i-1] == nameOfVar[k][0]) {
                    //                    var2 = k;
                    //                }
                    //                if (argument[i+1] == nameOfVar[k][0]) {
                    //                    var1 = k;
                    //                }
                    //            }
                    //                cin.ignore();
//                string* ptr1 = &nameOfVar[variable1];
//                string characterVar1 = *ptr1;
//                string orSign = "|";
//                string* ptr2 = &nameOfVar[variable2];
//                string characterVar2 = *ptr2;
//                orSign.append(characterVar2);
//                characterVar1.append(orSign);
*/
                nameOfVar.push_back(nameBuilder(i));                                    // get new name
                vector<bool>(orOp) = orringOfVariables(variable1, variable2);           // run operation
//                cout << "the expression " << characterVar1 << " is in the position " << (nameOfVar.size() - 1) << endl;
            } else if (argument[i] == '>') {                                            // find the condition operator
                cout << "which variables are being conditionned" << endl;
                cout << "please reference their position" << endl;
                cin >> variable1 >> variable2;
                /*
                    //            for (int k = 1; k <= numOfvariables; k++) {
                    //                if (argument[i-1] == nameOfVar[k][0]) {
                    //                    var2 = k;
                    //                }
                    //                if (argument[i+1] == nameOfVar[k][0]) {
                    //                    var1 = k;
                    //                }
                    //            }
                    //                cin.ignore();
//                string* ptr1 = &nameOfVar[variable1];
//                string characterVar1 = *ptr1;
//                string arrowSign = "->";
//                string* ptr2 = &nameOfVar[variable2];
//                string characterVar2 = *ptr2;
//                arrowSign.append(characterVar2);
//                characterVar1.append(arrowSign);
*/
                nameOfVar.push_back(nameBuilder(i));                                    // get new name
                vector<bool> ifthenOp = conditionnialityOfVariables(variable1, variable2);  // run operation
//                cout << "the expression " << characterVar1 << " is in the position " << (nameOfVar.size() - 1) << endl;
            } else if (argument[i] == '<') {                                            // find the bicondition operator
                cout << "which variables are being biconditionned" << endl;
                cout << "please reference their position" << endl;
                cin >> variable1 >> variable2;
                /*
                    //            for (int k = 1; k <= numOfvariables; k++) {
                    //                if (argument[i-1] == nameOfVar[k][0]) {
                    //                    var2 = k;
                    //                }
                    //                if (argument[i+1] == nameOfVar[k][0]) {
                    //                    var1 = k;
                    //                }
                    //            }
                    //                cin.ignore();
//                string* ptr1 = &nameOfVar[variable1];
//                string characterVar1 = *ptr1;
//                string arrowSign = "<->";
//                string* ptr2 = &nameOfVar[variable2];
//                string characterVar2 = *ptr2;
//                arrowSign.append(characterVar2);
//                characterVar1.append(arrowSign);
*/
                nameOfVar.push_back(nameBuilder(i));                                    // get new name
                vector<bool> ifthenOp = biconditionnialityOfVariables(variable1, variable2);    // run operation
//                cout << "the expression " << characterVar1 << " is in the position " << (nameOfVar.size() - 1) << endl;
            }
        }
    }
}

string nameBuilder(int i) {
    if (argument[i] == '~') {                                                   // find the not operator
            // build the new name by appending the seperate elements
        string* ptr = &nameOfVar[variable];
        string characterVar = *ptr;
        string notSign = "~";
        notSign.append(characterVar);
        newName = notSign;
//        nameOfVar.push_back(notSign);
        cout << "the expression " << notSign << " is in the position " << (nameOfVar.size()) << endl;
    } else if (argument[i] == '&') {                                            // find the and operator
            // build the new name by appending the seperate elements
        string* ptr1 = &nameOfVar[variable1];
        string characterVar1 = *ptr1;
        string andSign = "&";
        string* ptr2 = &nameOfVar[variable2];
        string characterVar2 = *ptr2;
        andSign.append(characterVar2);
        characterVar1.append(andSign);
        newName = characterVar1;
        cout << "the expression " << characterVar1 << " is in the position " << (nameOfVar.size()) << endl;
    } else if (argument[i] == '|') {                                            // find the or operator
            // build the new name by appending the seperate elements
        string* ptr1 = &nameOfVar[variable1];
        string characterVar1 = *ptr1;
        string orSign = "|";
        string* ptr2 = &nameOfVar[variable2];
        string characterVar2 = *ptr2;
        orSign.append(characterVar2);
        characterVar1.append(orSign);
        newName = characterVar1;
        cout << "the expression " << characterVar1 << " is in the position " << (nameOfVar.size()) << endl;
    } else if (argument[i] == '>') {                                            // find the condition operator
            // build the new name by appending the seperate elements
        string* ptr1 = &nameOfVar[variable1];
        string characterVar1 = *ptr1;
        string arrowSign = "->";
        string* ptr2 = &nameOfVar[variable2];
        string characterVar2 = *ptr2;
        arrowSign.append(characterVar2);
        characterVar1.append(arrowSign);
        newName = characterVar1;
        cout << "the expression " << characterVar1 << " is in the position " << (nameOfVar.size()) << endl;
    } else if (argument[i] == '<') {                                            // find the bicondition operator
            // build the new name by appending the seperate elements
        string* ptr1 = &nameOfVar[variable1];
        string characterVar1 = *ptr1;
        string arrowSign = "<->";
        string* ptr2 = &nameOfVar[variable2];
        string characterVar2 = *ptr2;
        arrowSign.append(characterVar2);
        characterVar1.append(arrowSign);
        newName = characterVar1;
        cout << "the expression " << characterVar1 << " is in the position " << (nameOfVar.size()) << endl;
    }
    return newName;
}

/*
int argumentDecider() {
    int index = 0;
    for (int i = 0; i < nameOfVar.size(); i++) {
        if (nameOfVar[i] == argument) {
            index = i;
        }
    }
    
//        const string nameofvariable = nameOfVar[i];
//        if (strcmp(&nameOfVar[i], &argument) == 0) {
//            index = i;
//        }
//    }
    return index;
}*/

// previous versions:

/*// version 1

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
/*// version 2 modifications
//        cout << nameOfvar << endl;
//        for (double l = 0; l < possibilities; l++, e++) {            // loop to generate the arrangement of 'T' and 'F' for the argument
//            while (((int)(possibilities / pow(2, ((e))))) < (pow(2, (numOfvariables - e))) ) {  // loop to place the true at the position that switches every power of 2
//                nameOfvar[k][l] = true;
//                cout << nameOfvar[k][l] << endl;
//                nameOfvar[k].at(l) = true;                         // set the position to true
//                l++;                                            // increase position by 1
//            }
//            while (((int)(possibilities / pow(2, ((e))))) >= (pow(2, (numOfvariables - e))) ) { // loop to place the false at the position that switches every power of 2
//                nameOfvar[k][l] = false;
//                nameOfvar[k].at(l) = false;                        // set the position to false
//                l++;                                            // increase position by 1
//            }
//            e++;                                                // variable true/false chunks counter increases
//    for (int j = 0; j < numOfvariables; j++) {
//        cout << nameOfvar.at(j) << endl;
//    } */

    //void truthTablefunc(int numOfvariables, vector<string>(nameOfvar)) {
    //    int possibilities = pow(2, numOfvariables);
    ///*    cout << "p = " << possibilities << endl; */               // test code to check the number of possibilities
    //
    //    vector<vector<bool>>truthTable;
    //    for (int k = 0; k < numOfvariables; k++) {                 // loop to seperate each argument name into it's own array that will carry truth values
    //        vector<bool>(row);
    //
    //        // you want here to check k, because depending on which row, you'll know how to fill the truth table
    //        // (aka every one row switch between T and F, or every 2 rows, or every 4 rows, etc.)
    //        // think about how to model that: change every 2,4,8 (2^k)
    //
    //        int toggle = pow(2, k);                                 // Determines when to toggle true/false
    //        bool value = true;                                      // Initial value for toggling
    //        for (int l = 0; l < possibilities; l++) {
    //
    //            if (l % toggle == 0) {
    //                value = !value;                                 // Toggle the value
    //            }
    //            row.push_back(value);
    //        }
    //        truthTable.push_back(row);
    //    }
    ///*    for (int i = 0; i < truthTable.size(); i++) {               // test code to see the truth table layout
    //        cout << nameOfvar[i] << " ";
    //        for (int j = 0; j < truthTable[i].size(); j++) {
    //            cout << truthTable[i][j] << " ";
    //        }
    //        cout << endl;
    //    } */
    //
    //}
