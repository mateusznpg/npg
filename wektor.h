#ifndef VECTOR
#define VEKTOR

#include <iostream>

using namespace std;

class Vector {
	
        private:
	int rozmiar;
	int* element;
	
	public:
		Vector(int size = 2);                                     // konstruktor
		~Vector();                                                // destruktor
		Vector(const Vector &B);                                  // konstruktor kopiujący
		
		Vector & operator= (const Vector & prawy);                // przeciezenie opearatora =
		Vector operator+ (const Vector &B) const;                 // przeciazenie operatora +
		Vector operator- (const Vector &B) const;                 // przeciazenie operator -
		int operator* (const Vector &B);                          // przeciazenie operatora * - mnozenie wektorow
		Vector operator* (const int &liczba);                     // przeciazenie operatora * - mnozenie wektora przez liczbe z prawej strony
		friend Vector operator* ( const int &liczba, const Vector &B);  // przeciazenie operatora * - liczba z lewej strony
		
		bool operator== (const Vector &B) const;                  // przeciezenie operatora ==
		bool operator!= (const Vector &B) const;                  // przeciezenie operatora !=
		const int operator[] (const int& indeks) const;           // przeciezenie operatora []
		Vector & operator+= (const Vector &B );                   // przeciazenie operatora +=
		Vector & operator-= (const Vector &B );                   // przeciazenie operatora -=
		Vector & operator*= (const int &liczba );                 // przeciezenie operatora *=
		
		friend  ostream & operator<<(ostream & wyj,  const Vector &B);    // przeciazenie operatora wyjscia <<
		friend  istream & operator>>(istream & wej,  const Vector &B);    // przeciezenie operatora wejscia >>
	
};

#endif