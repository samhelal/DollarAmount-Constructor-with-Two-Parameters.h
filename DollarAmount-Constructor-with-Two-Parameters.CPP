#include <iostream>
#include <string>
#include <iomanip>
#include "DollarAmount-Constructor-with-Two-Parameters.h"
using namespace std;

int main()
{
    DollarAmount d1{123,45};
    DollarAmount d2{15,76};

    cout << " After adding d2 (" << d2.to_string() << " ) into d1("
         << d1.to_string() << ").d1 = ";
    d1.add(d2);
    cout << d1.to_string() << "\n ";
    cout << "After sutracting d2 (" << d2.to_string() << ") from d1 ("
         << d1.to_string() << ") d1 =";
    d1.subtract(d2);
    cout << d1.to_string() << "\n";

    cout << " After subtracting d1 (" << d1.to_string() << ") from d2 ("
         <<d2.to_string() <<") d2 = " ;
    d2.subtract(d1) ;
    cout << d2.to_string() << "\n \n" ;

    cout<< "Enter integer interest rate and divisor for example \n"
        << "for    2%,enter:     2 100\n" 
        << "for   2.3,enter:    23 1000\n"
        << "for  2.37,enter:   237 10000\n"
        << "for 2.375,enter:  2375 100000\n" ;
    int rate (0);
    int divisor(0);
    cin>> rate >> divisor ;
    DollarAmount balance(1000,00) ;
    cout << "\nIntianl balance :" << balance.to_string() << endl ;
    cout <<"\nYear" << setw(20) << "Amount on deposite" << endl ;

    for(unsigned int year(1) ; year <=10 ; year++)
    {
        balance.addInterest(rate , divisor) ;
        cout << setw(4) << year << setw(20) << balance.to_string() << endl ;
    }

}
