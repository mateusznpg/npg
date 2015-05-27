#ifndef MACIERZ
#define MACIERZ

#include <iostream>
#include "wektor.h"

using namespace std;

class Macierz { //wektory sa poziomo ulozone w macierzy

    private:
        int kolum;
        int wiersz;
        
    public:
        Vector* Matrix;
        
        Macierz(int rows = 2, int cols = 2);                              //konstruktor
        ~Macierz();                                                       //destruktor
        Macierz(const Macierz &M);                                        //konstruktor kopiujący
        
        Macierz & operator= (const Macierz & prawy);                      // przeciezenie opearatora =
        Macierz operator+ (const Macierz &B) const;                       // przeciazenie operatora +
        Macierz operator- (const Macierz &B) const;                       // przeciazenie operator -
        int operator* (const Macierz &B);                                 // przeciazenie operatora * - mnozenie macierzy
        Macierz operator* (const int &liczba);                            // przeciazenie operatora * - mnozenie wektora przez liczbe z prawej strony
		friend Macierz operator* ( const int &liczba, const Macierz &B);  // przeciazenie operatora * - liczba z lewej strony
        
        
        bool operator== (const Macierz &B) const;                         // przeciezenie operatora ==
        bool operator!= (const Macierz &B) const;                        // przeciezenie operatora !=
        const Vector & operator[] (const int& indeks) const;                   // przeciezenie operatora []
		
        Macierz & operator+= (const Macierz &B );                   // przeciazenie operatora +=
        Macierz & operator-= (const Macierz &B );                   // przeciazenie operatora -=
        Macierz & operator*= (const int &liczba );                 // przeciezenie operatora *=
        
        friend  ostream & operator<<(ostream & wyj,  const Macierz &B);   // przeciazenie operatora wyjscia <<
        friend  istream & operator>>(istream & wej,  const Macierz &B);   // przeciezenie operatora wejscia >>
        
};

#endif