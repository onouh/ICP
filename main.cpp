//
//  main.cpp
//  c++
//
//  Created by Omar Nouh on 10/1/24.
//

#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

int isPrime (int x);
double numFactorial (double a);
void numInverter (int h);

int main(int argc, const char * argv[]) {
    // insert code here...
    /*
    int x = 0 ;
    int y = 1 ;
    double z = x * y;
    std:: cout << z << endl ;
    
     
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
    
    //Lab 01
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
    
    //Lab 02
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
    
    //Lab 03
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
    //Lab 05
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
    }
    
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
