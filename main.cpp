/*
 Created by Camden Barta on 3/7/19.
 Lab 2
 
 Precondition:
    The user will input a small intger number, preferably smaller than 5, with no negative number's allowed.
 Postcondtion:
    The program will a recursive function to find Fibonacci number's.
 */

#include <iostream>
using namespace std;

int factorial(int n){
    cout << "factorial(" << n << ") is called ./n";
    if(n==0 || n==1 ){
        return 1;
    }
    return n * factorial(n-1);
}

int fibonacci(int n){
    if( n==0 || n== 1){
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

void testEx14(){
    int n;
    cout << "Exerice 14" << endl;
    cout << "Please enter a small positive integer: ";
    cin >> n;
    cout << "Fibonacci Squence at index " << n << " is " << fibonacci(n) << endl;
}

/* Precondition: All n discs are on current.
 Postcondition: All n discs are moved to target */
void hanoi(int n, int current, int tool, int target ){
    if(n==1){
        cout << "Move disc " << n << " from " << current << " to " << target << endl;
        return;
    }
    hanoi(n-1, current, target, tool);
    cout << "Move disc " << n << " from " << current << " to " << target << endl;
    hanoi(n-1, tool, current, target);
}

void testEx15(){
    int n, current, tool, target;
    cout << "Exercise 15" << endl;
    cout << " Enter the number of discs to move: ";
    cin >> n;
    cout << "From which peg (1-3): ";
    cin >> target;
    tool = 6 - current - target;
    hanoi(n, current, tool, target);
}

void rotateLeft(int* a, int len ){
    if (len==1){
        return;
    }
    rotateLeft(a, len-1);
    int tmp = a[len-2];
    a[len-2]= a[len-1];
    a[len-1]= tmp;
}
void testEx16(){
    int n, i;
    int* p;
    cout << "Exercise 16" << endl;
    cout << "Enter the size of the array: ";
    cin >> n;
    if(n<0){
        n = -n;
    }
    p = new int[n];
    cout << "Enter " << n << " numbers please: " ;
    for(i=0; i<n; i++){
        cin >> p[i];
    }
    cout << " Before rotation: ";
    
    for(i=0; i<n; i++){
        cout << p[i] << " ";
    }
    cout << "" << endl;
    rotateLeft(p,n);
    cout << " After rotation: ";
    
    for(i=0; i<n; i++){
        cout << p[i] << " ";
    }
    cout << "" << endl;
    delete[] p;
}

void testEx17(){
    int n, i;
    int m;
    int* p;
    cout << "Exercise 17" << endl;
    cout << "Enter the size of the array: ";
    cin >> n;
    if(n<0){
        n = -n;
    }
    p = new int[n];
    cout << "Enter " << n << " numbers please: " ;
    for(i=0; i<n; i++){
        cin >> p[i];
    }
    for(i= 0; i<n ; i++){
        if(p[i] < p[i+1]){
            m = p[i+1];
        }
        cout << p[i] << " ";
    }
    cout << "The maxium number in this array is " << m << endl;
}

int main(int argc, char** argv){
    cout << "I am Camden Barta. This is lab 2." << endl;
    testEx14();
    
    return 0;
}
