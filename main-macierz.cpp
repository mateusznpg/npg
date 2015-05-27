#include <iostream>
#include <iomanip>
#include "macierz.h"


using namespace std;

int main(){
	
	
        Macierz A(3,3), B(3,3);
            
        cout << "Wprowadz wektory 3 elementowe" << endl;
        cout << "Podaj Macierz A" << endl;
        cin >> A;
            
        cout << "Podaj Macierz B" << endl;
        cin >> B;
        
        
        cout << "Macierz A: "<< endl << A << endl;
        cout << "Macierz B: "<< endl << B << endl;
        cout << endl;
        
        cout << A << endl <<setw(6)<< " + " << endl << endl << B << endl << setw(6)<< " = " << endl<< endl << A+B << endl;
        cout << "-----------------------------"<<endl;
        cout << A << endl <<setw(6)<< " - " << endl << endl << B << endl << setw(6)<< " = " << endl<< endl << A-B << endl;
        cout << "-----------------------------"<<endl;
        cout << A << endl <<setw(6)<< " * " << endl << endl << B << endl << setw(6)<<" = "<< endl<< endl <<setw(6)<< A*B << endl;
        cout << "-----------------------------"<<endl;
        cout << "A*2 ="<< endl<< A*2 << endl;
        cout << "-----------------------------"<<endl;
        cout << "3*B = "  << endl << B*3 << endl;
        cout << "-----------------------------"<<endl;
        
        cout << " A == B"; cout<< (A==B) << endl;
        cout << "-----------------------------"<<endl;
        cout << " A != B"; cout<< (A!=B) << endl;
        cout << "-----------------------------"<<endl;
        cout << "A[2][1] = " << A[2][1] << endl;
        
        
        

	return 0;
	
	
}
