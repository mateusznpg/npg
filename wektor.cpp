#include "wektor.h"
#include <iomanip>

Vector::Vector(int size) {                                  //konstruktor tworzy i wypelnia zerami
	
	//cout<<"konstruktor"<<endl;
	
	element = new int[size];
	if(element == NULL){
		
		rozmiar = 0;
	}
	else{
		
		rozmiar = size;
		for(int i = 0; i < size; ++i)
		element[i] = 0;
	}
	
}

Vector::~Vector() {                                         //destruktor usuwa
	
	//cout<<"destruktor"<<endl;
	
	delete[] element;
}

Vector::Vector(const Vector &B) {                           // kostruktor kopiujacy
	
	//cout << "Kopia" << endl;
	if (B.rozmiar < 1) {
	 rozmiar = 0;
	 element = NULL;
	}
	else{
	 
            element = new int[B.rozmiar];
            
            if(element == NULL){
                rozmiar = 0;
            }else{  
                rozmiar = B.rozmiar;
                for (int i = 0; i < rozmiar; ++i)
                    element[i] = B.element[i];
            }
	}
 
	
}

Vector & Vector::operator= (const Vector &prawy) {          // operator =
   
   if( &prawy != this )
    {
		if ( prawy.rozmiar < 1 || prawy.element ==  NULL){
			
			delete [] element;
			element = NULL;
			rozmiar = 0;
		}
		else{
			
			if (rozmiar == prawy.rozmiar) {
				for (int i = 0; i < rozmiar; ++i)
					element[i] = prawy.element[i];
			}
			else{
	   
				delete [] element;
				element = new int[prawy.rozmiar];
			
				if (element !=  NULL){
					
					rozmiar = prawy.rozmiar;
					
					for (int i = 0; i < rozmiar; ++i)
						element[i] = prawy.element[i];

				}
				else {
				
					rozmiar = 0;
				}	
			}
		}
	}
	
    return *this;
}

Vector Vector::operator+ (const Vector &B) const {          // operator +
	
	int max_size = (rozmiar > B.rozmiar)  ? rozmiar : B.rozmiar;  
	
	Vector C(max_size);
	if ( C.element !=  NULL) {
	 
		for (int i = 0; i < max_size; ++i) {
			
			if (i < rozmiar )
				C.element[i] += element[i];
			
			if ( i < B.rozmiar)
				C.element[i] += B.element[i];
		
		}
	}
 
	return C;
	
}

Vector Vector::operator- (const Vector &B) const {          // operator -
	
	int max_size = (rozmiar > B.rozmiar)  ? rozmiar : B.rozmiar;  
	
	Vector C(max_size);
	if ( C.element !=  NULL) {
	 
		for (int i = 0; i < max_size; ++i) {
			
			if (i < rozmiar )
				C.element[i] += element[i];
			
			if ( i < B.rozmiar)
				C.element[i] -= B.element[i];
		
		}
	}
 
	return C;
}

int Vector::operator* (const Vector &B) {                   // operator *
	
	int skalar = 0;
	
	if (rozmiar == 0 || element == NULL)
		return 0;
	if (B.rozmiar == 0 || B.element == NULL)
		return 0;
	
	int min_size = (rozmiar > B.rozmiar)  ? B.rozmiar : rozmiar;
	
	for (int i = 0; i < min_size; ++i)
	 skalar += element[i] *B.element[i];
	 
	return skalar;
	
}

Vector Vector::operator* (const int &liczba) {              // operator * - liczba z prawej strony
	
	
	if (rozmiar  == 0 || element == NULL) 
	 return *this;
	 
	Vector C(rozmiar);
	
	if(C.element != NULL) {
		for (int i = 0; i < rozmiar; ++i)
			C.element[i] = liczba * element[i];
	}
	else{
		
		return *this;
	}

	return C;
}

Vector operator* ( const int &liczba, const Vector &B) {    // operator * - liczba z lewej strony

    if (B.rozmiar  == 0 || B.element == NULL) 
	 return B;
	 
	Vector C(B.rozmiar);
    
	if(C.element != NULL) {
            
            for (int i = 0; i < B.rozmiar; ++i)
                C.element[i] = liczba * B.element[i];
        }else{
            
            return B;
        }
        
	return C;
}

bool Vector::operator== (const Vector &B) const {           // operator ==
	
	if (rozmiar !=  B.rozmiar)
		return false;
		
	for (int i = 0; i < rozmiar;++i)
		if (element[i] != B.element[i])
			return false;
	
	return true;
}

bool Vector::operator!= (const Vector &B) const {           //operator != 
	
	if (rozmiar !=  B.rozmiar)
		return true;
		
	for (int i = 0; i < rozmiar;++i)
		if (element[i] != B.element[i])
			return true;
	
	return false;
}

ostream & operator<<(ostream & wyj,  const Vector &B) {     // operator <<
  
  if (B.rozmiar != 0 && B.element !=  NULL){
            
                
		wyj << "[";
		for (int i = 0; i < B.rozmiar; ++i) {
		
			wyj << setw(2) << B.element[i];
			if ((B.rozmiar-1) > i)
				wyj << ",";
		}
		
		wyj << "]";
  }
	return wyj;
}

istream & operator>>(istream & wej,  const Vector &B) {     // operator >>

	if (B.rozmiar != 0 && B.element !=  NULL){
		for (int i = 0; i < B.rozmiar; ++i) 
			wej >> B.element[i];
	}
	return wej;
}

const int Vector::operator[] (const int& indeks) const {    // operator []
	
	return element[indeks];
}

Vector & Vector::operator+= (const Vector &B ) {            // operator +=
	
	
	if ( B.rozmiar != 0 && B.element !=  NULL) {
			
		int max_size = (rozmiar > B.rozmiar)  ? rozmiar : B.rozmiar;
		
		Vector Tym(max_size);
		
		for (int i = 0; i < max_size; ++i) {
			
			if (i < rozmiar )
				Tym.element[i] += element[i];
			
			if ( i < B.rozmiar)
				Tym.element[i] += B.element[i];
		
		}
		
		delete [] element;
		element = new int[max_size];
		
		if (element !=  NULL){
					
			rozmiar = max_size;
			
			for (int i = 0; i < rozmiar; ++i)
				element[i] = Tym.element[i];

		}
		else {
				
			rozmiar = 0;
		}	
		
	}
	
    return *this;
}

Vector & Vector::operator-= (const Vector &B ) {            // operator -=
	
	if ( B.rozmiar != 0 && B.element !=  NULL) {
			
		int max_size = (rozmiar > B.rozmiar)  ? rozmiar : B.rozmiar;
		
		Vector Tym(max_size);
		
		for (int i = 0; i < max_size; ++i) {
			
			if (i < rozmiar )
				Tym.element[i] += element[i];
			
			if ( i < B.rozmiar)
				Tym.element[i] -= B.element[i];
		
		}
		
		delete [] element;
		element = new int[max_size];
		
		if (element !=  NULL){
					
			rozmiar = max_size;
			
			for (int i = 0; i < rozmiar; ++i)
				element[i] = Tym.element[i];

		}
		else {
				
			rozmiar = 0;
		}	
		
	}
	
    return *this;
}

Vector & Vector::operator*= (const int &liczba ) {          // operator *=

	if (rozmiar  == 0 || element == NULL) 
	 return *this;
	 
	for (int i = 0; i < rozmiar; ++i)
		element[i] = liczba * element[i];

	return *this;

}



