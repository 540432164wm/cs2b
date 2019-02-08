/*
 Mian Wei
 Assignmnet3.1
 10/15
 this is some test function
 99
 99
 0x7fff5fbff60c
 -300
 99-300
 0
 99
 after nonegstive0
 after nonegstive99
 Q16---0
 Q17---0x7fff5fbff6f0
 Q18---0x7fff5fbff6f0
 Q20---99
 Q20---0
 Q22---99
 Q22---0
 Q22---0
 Q22---99
 Q23---0
 Q23---99
 Program ended with exit code: 0
 */
#include <iostream>
using namespace std;

void noNegatives(int *x);
void swap(int *p3, int *p4);

int main()
{
    int x = 10 ,y = 17;
    int *p1;
    p1 = &x;
    *p1 = 99;
    cout << x << endl;
    cout << *p1 << endl;
    cout << p1 << endl;
    
    p1 = &y;
    *p1 = -300;
    cout << *p1 << endl;
   
    int  temp;
    int *p2;
    p2 = &x;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    cout << *p1 << *p2 << endl;

    noNegatives( &x);
    noNegatives( &y);
    cout << "after nonegstive" << x << endl;
    cout << "after nonegstive" << y << endl;
    
    int  int2 = 0;
    int int1;
    int a[2] = {int1, int2};
    p2 = &a[0];
    *p2 = x;
    
    cout << "Q16---" << a[0] << endl;
    cout << "Q17---" << p2 << endl;
    // now value of p2 is 0
    
    *p2 = y;
    cout << "Q18---" << p2 << endl;
    // now value of p2 is 99
    
    p2 = a;
    p1 = &a[1];
    cout << "Q20---" << *p2 << endl;
    cout << "Q20---" << *p1 << endl;
    
    swap( &x, &y);
    swap(&a[0], &a[1]);
    cout << "Q23---" << a[0] << endl;
    cout << "Q23---" << a[1] << endl;
}

void noNegatives(int *x){
    if(*x < 0){
        *x = 0;
    }
    cout << *x <<endl;
}

void swap(int *p3, int *p4){
    
    int temp;
    temp = *p3;
    *p3 = *p4;
    *p4 = temp;
    cout << "Q22---" << *p3 << endl;
    cout << "Q22---" << *p4 << endl;
    
}
