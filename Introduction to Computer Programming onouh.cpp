//
//  main.cpp
//  c++
//
//  Created by Omar Nouh on 10/1/24.
//

#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

struct Student {
    string ID;
    string Name;
    Date DOB;
    vector<double> grades;
    double total;
};

struct Students {
    vector<Student> students;
};
int numS = 0;


/*inline*/ int isPrime (int x);
double numFactorial (double a);
void numInverter (int h);
int smallestNum ();
int frequencyNum ();
void firstLetter ();
void longestWord ();
void Matrix ();
int sumSquareMat ();
void transposeMatrix ();
void largestNumRow ();
bool matrixSymmetry ();
Date getDate ();
Student input_student ();
double calcTotal (Student student);
void displayStudent ();
Students input_students (int numS);
double calcTotals (Students student, int i);
void displayStudents ();
int* IntergralDataSet (int* Data);
int numOfVal = 0;
int findMax (const int* data, int numOfVal);
int my_strlen (const char* data);
void reversed (char*  data, int n);



int main(int argc, const char * argv[]) {
    // insert code here...
    /*
    int x = 0 ;
    int y = 1 ;
    double z = x * y;
    cout << z << endl ;
    
     
    cout << "Please enter the first value" << endl ;
    cin >> x;
    cout << "Please enter the second value" << endl ;
    cin >> y;
    z = x * y;
    cout << "The resulting multiplication gives " << z << endl ;
    */
    /*
    cout << "Please enter the first value" << endl ;
    cin >> x;
    cout << "Please enter the second value" << endl ;
    cin >> y;
    z = pow(x, y) ;
    cout << "The resulting exponent gives z = x ^ y is " << z << endl ;
    */
    /*
    cout << "Please enter the first value" << endl ;
    cin >> x;
    cout << "Please enter the second value" << endl ;
    cin >> y;
    z = (pow(x, y)) - 1 ;
    cout << "The equation z = (x ^ y) - 1 gives " << z << endl ;
    std::cout << "Hello, World!\n";
    */
    
    // Lecture Practice
    /*
    const int numOfEmployees = 5;
    double tax, salary[numOfEmployees] = {0};
    for (int i = 1; i <= numOfEmployees; i++) {
        cout << "enter your salary" << endl;
        cin >> salary[i-1];
        if (salary[i-1] > 6000) {
            tax = 10;
        } else if (salary[i-1] >= 4000) {
            tax = 7;
        } else {
            tax = 5;
        }
    } */
    /*
    const int elements = 10;
    int value[elements] = {0};
    cout << "enter a value" << endl;
    for (int i = 0; i < elements; i++) {
        cin >> value[i];
    }
    cout << setw(25) << "Elements" << setw(25) << "Value" << setw(25) << "Histogram" << endl;
    for (int i = 0; i < elements; i++) {
        cout << setw(25) << i << setw(25) << value[i] << setw(25);
        for (int k = 0; k < value[i]; k++) {
            cout << '~';
        }
        cout << endl;
    } */

    
    // Lab 01
    /*
    int a = 0, b = 0, c;
    cout << "Please enter the first value" << endl ;
    cin >> a;
    cout << "Please enter the second value" << endl ;
    cin >> b;
    c = a * b;
    cout << "The resulting multiplication gives " << c << endl ;
    */
    /*
    string first_name;
    string last_name;
    string department;
    double hs_grade;
    
    cout << "Please enter your first name" << endl ;
    cin >> first_name;
    cout << "Please enter your last name" << endl ;
    cin >> last_name;
    cout << "Please enter your department" << endl ;
    cin >> department;
    cout << "Please enter your high school grade" << endl ;
    cin >> hs_grade;
    
    cout << "You are " << first_name << " " << last_name << endl;
    cout << "You study " << department << " at Ain Shams University" << endl;
    cout << "You graduated highschool with a grade of " << hs_grade << endl;
    
    cout << "Thank you" << endl;
    */
    
    // Lab 02
    /*
    double distance_ft = 0.0 ;
    double distance_m = 0.0 ;
    cout << "enter a distance " ;
    cin >> distance_ft ;
    cout << "ft" << endl ;
    distance_m = 0.3048*distance_ft ;
    cout << "you entered " << distance_m << " m" << endl ;
    */
    /*
    double angle_1 =  0.0, angle_2  = 0.0, angle_3 = 0.0 ;
    cout << "enter the first angle " ;
    cin >> angle_1 ;
    cout << endl ;
    cout << "enter the second angle " ;
    cin >> angle_2 ;
    cout << endl ;
    angle_3 = 180 - (angle_1 + angle_2) ;
    cout << "the last angle to complete the triangle is " << angle_3 << endl ;
    */
    /*
    double a = 0, b = 0, x = 0, y = 0 ;
    cout << "enter a first number " ;
    cin >> a ;
    cout << endl << "you have entered first x = " << a << endl ;
    cout << "enter a second number " ;
    cin >> b ;
    cout << endl << "you have entered second y = " << b << endl ;
    x = b ;
    y = a ;
    cout << "oops your numbers switched x = " << x << ", y = " << y << endl ;
    */
    /*
    double alpha = 0 ;
    cout << "please enter a number: " ;
    cin >> alpha ;
    cout << endl ;
    if (alpha == 0)
        cout << "your number " << alpha << " is zero " << endl ;
    else if (alpha > 0)
        cout << "your number " << alpha << " is positive " << endl ;
    else if (alpha < 0)
        cout << "your number " << alpha << " is negative " << endl ;
    */
    /*
    double temperature = 0 ;
    char degree ;
    cout << "write the temperature then the degree it is in,\n c for celsius and f for farenheit" << endl ;
    cin >> temperature >> degree ;
    if (degree == 'c') {
        temperature = (temperature * (9/5)) + 32 ;
        degree = 'f';
    }
    else if (degree == 'f') {
        temperature = (temperature - 32) * (5/9) ;
        degree = 'f';
    }
    cout << endl << temperature << " " << degree << endl ;
    */
    
    // Lab 03
    /*
    double l = 0, L = 0 ;
    cout << "please enter a value for your width and length" << endl ;
    cin >> l >> L ;
    cout << endl ;
    if (l == L) {
        cout << "your width and length create a square" << endl ;
    }
    else {
        cout << "your  dimensions create a rectangle" << endl ;
    }
    */
    /*
    double a = 0 , b = 0 , c = 0 ;
    cout << "please enter three different values " << endl ;
    cin >> a >> b >> c ;
    if (a > b && a > c) {
        cout << a << " is the largest number" << endl ;
    }
    else if (b > a && b > c) {
        cout << b << " is the largest number" << endl ;
    }
    else if (c > a && c > b) {
        cout << c << " is the largest number" << endl ;
    }
    else {
         cout << "all three are equal" << endl ;
    }
    */
    /*
    char letter ;
    cout << "please enter a character" << endl ;
    cin >> letter ;
    if (letter >= 'a' && 'z' >= letter) {
        cout << letter << " is lowercase L" << endl ;
    }
    else if (letter >= 'A' && 'Z' >= letter) {
        cout << letter << " is uppercase U" << endl ;
    }
    else {
        cout << letter << " is a special character X" << endl ;
    }
    */
    /*
    double yearsOfservice , salary , bonus ;
    cout << "enter the years of service " << endl ;
    cin >> yearsOfservice ;
    cout << "enter the salary " << endl ;
    cin >> salary ;
    if (yearsOfservice > 5.0) {
        cout << "you have a bonus of 5%" << endl ;
        bonus = .05 * salary ;
        salary = salary * 1.05 ;
        cout << salary << "here's your new salary" << endl ;
    }
    else {
        cout << "according to your years of service, you do not qualify for 5% bonus \n your salary is " << salary << endl ;
    }
    */
    /*
    int classesHeld , classesAttended ;
    cout << "please write the number of classes held " << endl ;
    cin >> classesHeld ;
    cout << "please write the number of classes attended " << endl ;
    cin >> classesAttended ;
    if (classesAttended > classesHeld) {
        cout << "you have entered more attended classes than held classes \nerror invalid inputs" << endl ;
        break;
    }
    
    if ((((double) classesAttended / classesHeld ) * 100) >= 75 ) {
        cout << "you can sit in the exam" << endl ;
    }
    else {
        cout << "you can not sit in the exam" << endl ;
    }
    */
    /*
    string student1 , student2 ;
    double grade1 , grade2 ;
    cout << "please write the name followed by the grade of each student" << endl ;
    cin >> student1 >> grade1 >> student2 >> grade2 ;
    if (grade1 < 0 || grade2 < 0) {
        cout << "invalid grades" << endl ;
        return 0;
    }
    else if (student1 == "haya" || student1 == "Haya" || student2 == "haya" || student2 == "Haya") {
        cout << "Haya is better" << endl ;
    }
    else {
        if (grade1 > grade2) {
               cout << student1 << " is higher with " << grade1 << endl ;
           }
           else if (grade2 > grade1) {
               cout << student2 << " is higher with " << grade2 << endl ;
           }
           else if (grade1 == grade2) {
               cout << "both are equal" << endl ;
           }
    }
    */
    /*
    double a , b , c ;
    cout << "enter the lenght of each side of the triangle" << endl ;
    cin >> a >> b >> c ;
    if (a > 0 && b > 0 && c > 0) {
        if (a == b && a == c) {
            cout << "your triangle is equilateral of side length " << a << endl ;
        } else if (a == b || a == c || c == b || c == a || a == b || b == c) {
            cout << "your triangle is isoceles " << endl ;
        } else {
            cout << "your triangle is scalene " << endl ;
        }
    }
    else {
        cout << "error invalid lengths " << endl ;
        return 0;
    }
    */
    /*
    int numGrades , i ;
    double stdntGrd ;
    string stdntName ;
    bool finalInput ;
    do {
        cout << "please enter the number of grades you have " << endl ;
        cin >> numGrades ;
        cout << "you have " << numGrades << " grades to enter, is that correct?" << endl << "if yes please enter 1, if not enter 0" << endl ;
        cin >> finalInput ;
    }
    while (finalInput == 0) ;
    if (finalInput == 1) {
        for (i = 0; i < numGrades; i++) {
            cout << "please enter your student's name then grade out if 100 " << endl ;
            cin >> stdntName >> stdntGrd ;
            cout << stdntName << "got " ;
            if (stdntGrd > 100) {
                cout << "ERROR \n invalid input \n grade exceeds limit" << endl ;
                return 0 ;
            }
            else if (stdntGrd >= 90) {
                cout << "A+" << endl ;
            }
            else if (stdntGrd < 90 && stdntGrd >= 85) {
                cout << "A" << endl ;
            }
            else if (stdntGrd < 85 && stdntGrd >= 80) {
                cout << "A-" << endl ;
            }
            else if (stdntGrd < 80 && stdntGrd >= 75) {
                cout << "B+" << endl ;
            }
            else if (stdntGrd < 75 && stdntGrd >= 70) {
                cout << "B" << endl ;
            }
            else if (stdntGrd < 70 && stdntGrd >= 65) {
                cout << "C+" << endl ;
            }
            else if (stdntGrd < 65 && stdntGrd >= 60) {
                cout << "C" << endl ;
            }
            else if (stdntGrd < 60 && stdntGrd >= 55) {
                cout << "D+" << endl ;
            }
            else if (stdntGrd < 55 && stdntGrd >= 50) {
                cout << "D" << endl ;
            }
            else if (stdntGrd < 50 && stdntGrd >= 40) {
                cout << "E" << endl ;
            }
            else if (stdntGrd < 40) {
                cout << "F" << endl ;
            }
        }
    }
    */
    
    // Lab 04
    /*
    int x , i , n , count = 0 ;
    cin >> n ;
    for (i = 0 ; i < n ; i++) {
        cin >> x ;
        if ((x % 2) == 0) {
            ++count ;
        }
    }
    while (i < n) {
        cin >> x ;
        i++ ;
        if ((x % 2) == 0) {
            ++count ;
        }
    }
    */
    /*
    double Sn = 0 , n , i = 0 ;
    cout << "please write the number \n Sn = 1^2 + 2^2 + ... + n^2" << endl ;
    cin >> n ;
    while (i <= n) {
        Sn = Sn + pow(i, 2) ;
        cout << Sn << endl ;
        i++ ;
    }
    cout << "the value of the series is S" << n << Sn << endl ;
    */
    /*
    double Sn = 0 , n , a , b , i = 0 ;
    cout << "please write the last number in the series" << endl << "Sn = 1/a + 1/(a + b) + ... + 1/(a + nb)" << endl ;
    cin >> n ;
    cout << "please write a" << endl ;
    cin >> a ;
    cout << "please write b" << endl ;
    cin >> b ;
    cout << endl ;
    while (i <= n) {
        Sn = Sn + (1.0 / (a + (i * b))) ;
        cout << Sn << endl ;
        i++ ;
    }
    cout << "the value of the series is S" << n << " " << Sn << endl ;
    */
    /*
    bool isPrime = 0 ;
    int x , i ;
    cout << "please write a whole number" << endl ;
    cin >> x ;
    for (i = 2; i < x; i++) {
        if ((x % i) == 0) {
            isPrime = 0 ;
            break ;
        } else if ((x % i) != 0) {
            isPrime = 1 ;
        }
    }
    if (x <= 1 || isPrime == 0) {
        cout << "your number " << x << " is not prime" << endl ;
    } else if (isPrime ==  1) {
        cout << "your number " << x << " is prime" << endl ;
    }
    */
    /*
    int Sn = 0 , i ;
    for (i = 1; i <= 100; i++) {
        if (((i % 2) == 0) || ((i % 3) == 0)) {
            Sn = Sn + i ;
            cout << Sn << endl ;
        }
    }
    */
    
    //Assignment
    // a = p * ( 1 + n )^r
    /*
    double total = 0, investment, ROI, years ;
    int i = 0, n = 0 ;
    cout << "how much are you investing" << endl ;
    cin >> investment ;
    cout << "at what interest rate (ROI)" << endl ;
    cin >> ROI ;
    cout << "over how many years" << endl ;
    cin >> years ;
    *//*
    while (i <= years) {
        investment *= (pow((1.0 + (ROI/100.0)), i)) ;
        cout << "your compound interest on your investment is " << investment << endl ;
        i++ ;
    }
    *//*
    while (n <= years) {
        total = (investment * (pow((1.0 + (ROI/100.0)), n))) ;
        cout << "your net interest on your investment is " << total << endl ;
        i++ ;
    }
    */
    
    /*
    int x = 10;
    cout << (++x + x++) << endl;
    */
    /*
     
    int i = 1;
    int x = ++i *2;
    cout << x  << i << endl;
    i = 1;
    x = i++ *2;
    cout << x <<i << endl;
     
    int i = 1;
    int x = ++i + ++i;
    cout << x << endl;
    */
    /*
    int x = 5, a, b;
    // x = (x++ + (++x * x--));
    ++x ;
    a = x * x;
    b = a + x;
    x++;
    x--;
    cout << b << endl;
    */
    /*
    int x = 5;
    int y = 0;
    int i;
    for (i = 1; i <= x; i++)
        if (i % 3 == 0) {
            continue;
        }
    y += i;
    cout << y << endl;
    */
    /*
    int x = 5;
    cout << x << endl;
    cout << x++ << endl;
    cout << x << endl;
    */
    
    // Lab 05
    /*
    int x;
    cout << "please write a whole number" << endl ;
    cin >> x ;
    if (x == 2 || isPrime(x) ==  1) {
        cout << "your number " << x << " is prime" << endl ;
    } else if (x <= 1 || isPrime(x) == 0) {
        cout << "your number " << x << " is not prime" << endl ;
    }
    */
    /*
    int a;
    cout << "please write a whole number" << endl ;
    cin >> a ;
    cout << "your number " << a << "'s factorial is " << numFactorial(a) << endl ;
    */
    /*
    int p;
    cout << "please write a whole number" << endl ;
    cin >> p ;
    cout << "your number " << p << "'s inversion is " ;
    numInverter(p);
    cout << endl ;
    */
    
    // Lab 06
    /*
    int numArray[5], i, val;
    for (i = 0; i < 5; i++) {
        cout << "please write a number" << endl;
        cin >> numArray[i];
    }
    cout << "please write the number you are looking for" << endl;
    cin >> val;
    for (i = 0; i < 5; i++) {
        if (val == numArray[i]) {
            cout << "the number " << numArray[i] << "is located at the position " << i << "of the list" << endl;
            break;
        }
    }
    if (i == 6) {
        cout << "the number " << numArray[i] << "is not located in the list" << endl;
    }
    */
    /*
    int x[10], evenSum = 0, i;
    for (i = 0; i < 10; i++) {
        cout << "please write a number" << endl;
        cin >> x[i];
        if ((x[i] % 2) == 0) {
            evenSum += x[i];
        } else {
            continue;
        }
    }
    cout << "the sum of the even values entered is " << evenSum << endl;
    */
    /*
    int x[7], largestNum = 0, i;
    for (i = 0; i < 7; i++) {
        cout << "please write a number" << endl;
        cin >> x[i];
        if (i == 0) {
             largestNum = x[i];
        }
        if (x[i] >= largestNum) {
            largestNum = x[i];
        } else {
            continue;
        }
    }
    cout << "the sum of the even values entered is " << largestNum << endl;
    */
    /*
    int x[5], y[5], arraySum[5], i;
    for (i = 0; i < 5; i++) {
        cout << "please write two numbers" << endl;
        cin >> x[i] >> y[i];
        arraySum[i] = 0;
        arraySum[i] += (x[i] + y[i]);
        cout << "the sum of your arrays is " << arraySum[i] << endl;
    }
    */
    /*
    int x[10], y[10], i, o = 0, h = 9;
    for (i = 0; i < 10; i++) {
        cout << "please write a number" << endl;
        cin >> x[i];
        if ((x[i] % 2) == 0 ) {
            y[o] = x[i];
            o++;
        } else if ((x[i] % 2) == 1 ) {
            y[h] = x[i];
            h--;
        }
    }
    for (i = 0; i < 10; i++) {
        cout  << y[i] << endl;
    }
    */
    /*
    int x[10], y[10], i;
    for (i = 0; i < 10; i++) {
        cout << "please write a number" << endl;
        cin >> x[i];
        if ((x[i] % 2) == 0 ) {
            y[i] = x[i];
        } else if ((x[i] % 2) == 1 ) {
            y[(9-i)] = x[i];
        }
    }
    for (i = 0; i < 10; i++) {
        cout  << y[i] << endl;
    } */
    /*
//    cout << time(0);
//    unsigned seed;
    cout << "Enter seed: ";
    srand(time(0));  // seed random number generator

    // loop 10 times
    for (int counter = 1; counter <= 10; counter++)
    {
        // pick random number from 1 to 6 and output it
        cout << setw(10) << (1 + rand() % 6);
        // if counter divisible by 5, begin new line of output
        if (counter % 5 == 0)
            cout << endl;
    } // end for */
    /*
    enum Status {
        Lose,
        Win,
    };
    Status game = Win;
    
    const int size = 5;
    int a[size];
     
    :: z = 5; // see global scope
    
    char sentence[100];
    cin.getline(sentence, 80, '\t');
    char otherSentence[] = "Hello World ";
//    strcpy(sentence, otherSentence);
//    strcat(sentence, otherSentence);
    cout << sentence;
    */
    
    // Lab 07
    /*
    string input;
    getline(cin, input);
    long x = input.size();
    int i = 0;
    do {
        if (i == 0) {
            if (input[i] == ' ') {
                continue;
            } else if (input[i] != ' ') {
                cout << input[i];
            }
        } else if (input[i] == ' ') {
            cout << input[i+1];
        }
        i++;
    } while (i < x);
    cout << endl;
    */
    /*
//    cout << smallestNum() << endl;
//    cout << frequencyNum() << endl;
//    firstLetter();
//    longestWord();
   */
     
    // Lab 08
    /*
//    Matrix();
//    sumSquareMat();
//    transposeMatrix();
//    largestNumRow();
//  cout  <<  matrixSymmetry();
*/
    
    // Lab 09
    /*
//    for (int i = 0; i < numS; i++) {
//        cout << "here" << endl;
//        Students student = input_students();
//        cout << "Here" << endl;
//        for (int i = 0; i < student.students.size(); i++) {
//            cout << "HERE" << endl;
//            student.students[i].total = calcTotals(student, i);
//            cout << "HEllo" << endl;
//        }
//        cout << "Student ID " << student.students[i].ID << "has a total grade " << student.students[i].total << endl;
//    }
    cout << "enter number of students" << endl;
    cin >> numS;
    displayStudents(); */
    
    // Lab 10
    
    /*
    int Data[8];
    int* ret = IntergralDataSet(Data);
    cout << *ret << endl;
    int max = findMax(ret, numOfVal);
    cout << Data+max << endl << *(Data+max) << endl; // Data[max]
    */
    /*
    char word[100];
    cin.getline(word, 100, '\n');
    cout << my_strlen(word) << endl;*/
    
    char word[100];
    cin.getline(word, 100, '\n');
    reversed (word, my_strlen(word));
    
    return 0;
}


int isPrime (int x) {
    bool isPrime = 0 ;
    int i ;
    for (i = 2; i < x; i++) {
        if ((x % i) == 0) {
            isPrime = 0 ;
            break ;
        } else if ((x % i) != 0) {
            isPrime = 1 ;
        }
    }
    return isPrime;
}

double numFactorial (double a) {
    double numFactorial = 1, i ;
    for (i = a; i > 0; i--) {
        numFactorial *= i;
    }
    return numFactorial ;
}

void numInverter (int h) {
    int i = 0, a = h, x ;
    for (i = 0; i <= a; i++) {
        x = h % 10;
        if (x == 0) {
            break;
        }
        cout << x ;
        h /= 10;
    }
}

int smallestNum () {
    const int size = 7;
    int arrayOfnum[size];
    int h = arrayOfnum[0];
    for (int i = 0; i < size; i++) {
        cout << "enter number " << (i+1) << endl;
        cin >> arrayOfnum[i];
        if (arrayOfnum[i] < h) {
            h = arrayOfnum[i];
        }
    }
    return h;
}

int frequencyNum () {
    const int size = 8;
    int arrayOfnum[size];
    int frequency[size] = {0}, h = 0, value = 0;
    while (h < size) {
        cout << "enter a number" << endl;
        cin >> arrayOfnum[h];
        for (int j = 0; j < h; j++) {
            if (arrayOfnum[h] == arrayOfnum[j]) {
                frequency[h]++;
            }
        }
        h++;
    }
    int l = 0;
    for (int i = 0; i < size; i++) {
        if (frequency[i] > l) {
            l = frequency[i];
            value = arrayOfnum[i];
        }
    }
    cout << "the most frequent number is " << endl;
    return value;
}

void firstLetter () {
    string input;
    getline(cin, input);
    long x = input.size();
    int i = 0;
    do {
        if (i == 0) {
            if (input[i] == ' ') {
                continue;
            } else if (input[i] != ' ') {
                cout << input[i];
            }
        } else if (input[i] == ' ') {
            cout << input[i+1];
        }
        i++;
    } while (i < x);
    cout << endl;
}

void longestWord () {
    string theBiggestword;
    getline(cin,theBiggestword);
    int z = 0, h = 0, u = 0;
    for(int i = 0; i < theBiggestword.length(); i++)
    {
        if(theBiggestword[i] != ' ')
        {
            z++;
        }
        else if(theBiggestword[i] == ' ')
        {
            if(z > h) {
                h = z;
                u = i - h;
            }
           z = 0;
        }
    }
    cout << "The number of letters are:" << h << endl;
    cout<<"The biggest word is:";
    for(int j = u; j < (h + u); j++) {
        cout << theBiggestword[j];
    }
    cout << endl;
    /*
    cout << "enter a sentence" << endl;
    string input;                                              // sentence to test the code "hi my name is Lightning"
    getline (cin, input);
    int counter = 0, index = 0, i = 0, j = 0, l = 0, s = 0, pos = 0, posInd;
    while (i < input.size()) {
        if (input[i] == ' ') {
            s++;
        }
        i++;
    }
    cout << "there are " << s << " spaces in your sentence" << endl; // runs until here
    for (int i = 0; i <= s; i++) {
        if (input[index] == '\0') {
            break;
        }
        if (input[index] == ' ') {
            index++;
        }
        while (input[index] != ' ') {
            counter++;
            index++;
        }
        if (l < counter) {
            l = counter;
            pos = i;
        }
        
    }
    cout << "the longest word is at the space number " << pos << endl;
    for (posInd = 0; j < pos; posInd++) {
        while (input[posInd] != ' ') {
            posInd++;
        }
        j++;
    }
    if (pos == 0) {
        for (int i = 0; input[i] != ' '; i++) {
            cout << input[i];
        }
    } else {
        for (int i = posInd; input[i] != ' '; i++) {
            cout << input[i];
        }
    }
    */
}

void Matrix (/*int rows, int columns*/) {
    const int rows = 10, columns = 10;
    int Rows, Columns;
    cout << "enter the number of rows ";
    cin >> Rows;
    cout << "enter the number of columns ";
    cin >> Columns;
    int array2D[rows][columns];
    for (int r = 0; r < Rows; r++) {
        for (int c = 0; c < Columns; c++) {
            cin >> array2D[r][c];
        }
    }
    for (int r = 0; r < Rows; r++) {
        for (int c = 0; c < Columns; c++) {
            cout << array2D[r][c];
        }
        cout << endl;
    }
}

int sumSquareMat () {
    const int Size = 10;
    int size;
    cout << "enter the size of the array ";
    cin >> size;
    int array2D[Size][Size];
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            cin >> array2D[r][c];
        }
    }
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            cout << array2D[r][c];
        }
        cout << endl;
    }
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array2D[i][i];
    }
    cout << sum << endl;
    return sum;
}

void transposeMatrix () {
    const int rows = 10, columns = 10;
    int Rows, Columns;
    cout << "enter the number of rows ";
    cin >> Rows;
    cout << "enter the number of columns ";
    cin >> Columns;
    int arrayOne[rows][columns], arrayTwo[columns][rows];
    for (int r = 0; r < Rows; r++) {
        for (int c = 0; c < Columns; c++) {
            cin >> arrayOne[r][c];
        }
    }
    for (int r = 0; r < Rows; r++) {
        for (int c = 0; c < Columns; c++) {
            cout << arrayOne[r][c];
        }
        cout << endl;
    }
    cout << endl;
    for (int c = 0; c < Columns; c++) {
        for (int r = 0; r < Rows; r++) {
            arrayTwo[c][r] = arrayOne[r][c];
        }
    }
    for (int r = 0; r < Rows; r++) {
        for (int c = 0; c < Columns; c++) {
            cout << arrayTwo[r][c];
        }
        cout << endl;
    }
}

void largestNumRow () {
    const int rows = 10, columns = 10;
    int Rows, Columns;
    cout << "enter the number of rows ";
    cin >> Rows;
    cout << "enter the number of columns ";
    cin >> Columns;
    int array[rows][columns];
    for (int r = 0; r < Rows; r++) {
        for (int c = 0; c < Columns; c++) {
            cin >> array[r][c];
        }
    }
    for (int r = 0; r < Rows; r++) {
        for (int c = 0; c < Columns; c++) {
            cout << array[r][c];
        }
        cout << endl;
    }
    for (int r = 0; r < Rows; r++) {
        int l = 0;
        for (int c = 0; c < Columns; c++) {
            if (array[r][c] > l) {
                l = array[r][c];
            }
        }
        cout << l << endl;
    }
}

bool matrixSymmetry () {
    const int rows = 10, columns = 10;
    int Rows, Columns;
    cout << "enter the number of rows ";
    cin >> Rows;
    cout << "enter the number of columns ";
    cin >> Columns;
    int array[rows][columns];
    for (int r = 0; r < Rows; r++) {
        for (int c = 0; c < Columns; c++) {
            cin >> array[r][c];
        }
    }
    for (int r = 0; r < Rows; r++) {
        for (int c = 0; c < Columns; c++) {
            cout << array[r][c];
        }
        cout << endl;
    }
    bool symmetrical = false;
    for (int r = 0; r < Rows; r++) {
        for (int c = 0; c < Columns; c++) {
            if (array[r][c] == array[c][r]) {
                symmetrical = true;
            }
            else {
                symmetrical = false;
            }
        }
    }
    return symmetrical;
}

Date getDate () {
    Date today;
    cout << "enter day" << endl;
    cin >> today.day;
    cout << "enter month" << endl;
    cin >> today.month;
    cout << "enter year" << endl;
    cin >> today.year;
    cout << "the date you entered is: " << today.day << "/" << today.month << "/" << today.year << endl;
    return today;
}

Student input_student () {
    Student student;
    cout << "enter student ID" << endl;
    cin >> student.ID;
    cout << "enter name" << endl;
    cin >> student.Name;
    cout << "enter date of birth" << endl;
    student.DOB = getDate();
    cout << "enter the number of grades" << endl;
    int numG = 0;
    cin >> numG;
    student.grades.resize(numG);
    for (int i = 0; i < numG; i++) {
        double value = 0.0;
        cout << "enter grade" << endl;
        cin >> value;
        student.grades.push_back(value);
    }
    return student;
}

double calcTotal (Student student) {
    double tot = 0.0;
    for (int i = 0; i < student.grades.size(); i++) {
        tot += student.grades[i];
        student.total = tot;
    }
//    cout << student.total << endl;
    return tot;
}

void displayStudent () {
    Student student = input_student();
    student.total = calcTotal(student);
    cout << "Student ID " << student.ID << " has a total grade " << student.total << endl;
}

Students input_students (int numS) {
    Students student;
    student.students.resize(numS);
    for (int i = 0; i < numS; i++) {
        cout << "enter student ID" << endl;
        cin >> student.students[i].ID;
        cout << "enter name" << endl;
        cin >> student.students[i].Name;
        cout << "enter date of birth" << endl;
        student.students[i].DOB = getDate();
        cout << "enter the number of grades" << endl;
        int numG = 0;
        cin >> numG;
        for (int j = 0; j < numG; j++) {
            double value;
            cout << "enter grade" << endl;
            cin >> value;
            student.students[i].grades.push_back(value);
        }
    }
    
    return student;
}

double calcTotals (Students student, int i) {
        double tot = 0.0;
        for (int j = 0; j < student.students[i].grades.size(); j++) {
            tot += student.students[i].grades[j];
            student.students[i].total = tot;
        }
    return student.students[i].total;
}

void displayStudents () {
    Students student = input_students(numS);
    for (int j = 0; j < student.students.size(); j++) {
        student.students[j].total = calcTotals(student, j);
        cout << "Student ID " << student.students[j].ID << "has a total grade " << student.students[j].total << endl;
    }
}

int* IntergralDataSet (int* Data) {
   // vector<int>(Data);
    cout << "how many integers are being enterred" << endl;
    cin >> numOfVal;
    cout << "please enter the integers" << endl;
    for (int i = 0; i < numOfVal; i++) {
        int data;
        cin >> data;
        Data[i] = data;
    }
    int* ptrData = &Data[0]; //Data
    return ptrData;
}

int findMax (const int* data, int numOfVal) {
    int Max = 0;
    int index=0;
    for (int i = 0; i < numOfVal; i++) {
        cout<<data[i]<<endl;
        if (Max < data[i]) {
            Max = data[i]; // *(data+i);
            index = i;

        }
        //data++;
    }
    
    return index;
}

int my_strlen (const char* data) {
    int index = 0;
    for (int i = 0; *(data + i) != '\0'; i++) {
        index++;
    }
    return index;
}

void reversed (char*  data, int n) {
    char temp;
    for (int i = 0; i < (n/2); i++) {
        temp = *(data + i);
//        cout << data[i] << endl;
        data[i] = data[n-i-1];
//        cout << data[i] << endl;
//        cout << data[n-i-1] << endl;
        data[n-i-1] = temp;
//        cout << data[n-i-1] << endl;
    }
    cout << data << endl;
}



/*
int* matrix () {
    int rows, columns;
    cout << "enter the number of rows ";
    cin >> rows;
    cout << "enter the number of columns ";
    cin >> columns;
    int array2D[rows][columns];
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++) {
            cin >> array2D[r][c];
        }
    }
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++) {
            cout << array2D[r][c];
        }
        cout << endl;
    }
    return* array2D;
} */
