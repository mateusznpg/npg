#include <iostream>
#include "wektor.h"

using namespace std;

int main(){
	
	
        Vector A(5), B(5);
            
        cout << "Wprowadz wektory 5 elementowe" << endl;
        cout << "Podaj wektor A" << endl;
        cin >> A;
            
        cout << "Podaj wektor B" << endl;
        cin >> B;
        
        
        cout << "Wektor A: "<< A << endl;
        cout << "Wektor B: "<< B << endl;
        cout << endl;
        
        cout << A << " + " << B <<" = "<< A+B << endl;
        cout << A << " - " << B <<" = "<< A-B << endl;
        
        cout << A << " * " << B <<" = "<< A*B << endl;
        cout << A << " * " << 2 <<" = "<< A*2 << endl;
        cout << 3 << " * " << B <<" = " << B*3 << endl;

        cout << endl;
        
        cout << A << " == " << B << " -> " << (A==B) << endl;
        cout << A << " != " << B << " -> " << (A!=B) << endl;
        cout << "A[2] = " << A[2] << endl;
        
        
        

	return 0;
	
	
}
