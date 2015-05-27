#include "macierz.h"
#include <iomanip>

Macierz::Macierz(int rows, int cols) {                   //kostruktor
    
    kolum = cols;
    wiersz = rows;
    Matrix = new Vector[rows];
    
    for(int i = 0; i < rows; ++i)
        Matrix[i] = Vector(cols);
    
}

Macierz::~Macierz(){                                       //destruktor
     
    delete [] Matrix;
}

Macierz::Macierz(const Macierz &M){                        //konstruktor kopiujący
    
    if( M.Matrix == NULL || M.kolum == 0 || M.wiersz == 0 ){
        
        kolum = 0;
        wiersz = 0;
        Matrix = NULL;
        
    }else{
        
        Matrix = new Vector[M.wiersz];
        
        if(Matrix == NULL){
        
            kolum = 0;
            wiersz = 0;
            
        }else{
            
            kolum = M.kolum;
            wiersz = M.wiersz;
            
            for(int i = 0; i < wiersz; ++i)
                Matrix[i] = M.Matrix[i];
        }
        
    }
    
}

Macierz & Macierz::operator= (const Macierz &prawy) {          // operator =
   
   if( &prawy != this )
    {
		if( prawy.Matrix == NULL || prawy.kolum == 0 || prawy.wiersz == 0 ){
			
			delete [] Matrix;
			Matrix = NULL;
			wiersz = 0;
            kolum = 0;
		}
		else{
			
			if (wiersz == prawy.wiersz && kolum == prawy.kolum) {
				for (int i = 0; i < wiersz; ++i)
					Matrix[i] = prawy.Matrix[i];
			}
			else{
	   
				delete [] Matrix;
				Matrix = new Vector[prawy.wiersz];
			
				if (Matrix !=  NULL){
					
					wiersz = prawy.wiersz;
                    kolum = prawy.kolum;
					
					for (int i = 0; i < wiersz; ++i)
						Matrix[i] = prawy.Matrix[i];

				}
				else {
				
					wiersz = 0;
                    kolum = 0;
				}	
			}
		}
	}
	
    return *this;
}
//taki sam wymiar
Macierz Macierz::operator+ (const Macierz &B) const {          // operator +
	
    if(wiersz == B.wiersz && kolum == B.kolum ){
        
        Macierz C(wiersz,kolum);
        if ( C.Matrix !=  NULL) {
        
            for (int i = 0; i < wiersz; ++i)
                C.Matrix[i] = Matrix[i] + B.Matrix[i];
        }
        return C;
    
    }else{
        
        cout<<"Zle wymiary macierzy"<<endl;
        return *this; // w razie błedu zwraca pierwsza macierz    
    } 
	
}


Macierz Macierz::operator- (const Macierz &B) const {                // przeciazenie operator -

    if(wiersz == B.wiersz && kolum == B.kolum ){
        
        Macierz C(wiersz,kolum);
        if ( C.Matrix !=  NULL) {
        
            for (int i = 0; i < wiersz; ++i)
                C.Matrix[i] = Matrix[i] - B.Matrix[i];
        }
        return C;
    }else{
        
        cout<<"Zle wymiary macierzy"<<endl;
        return *this; // w razie błedu zwraca pierwsza macierz    
    }
}

int Macierz::operator* (const Macierz &B){                          // przeciazenie operatora *

    int skalar = 0;
	
	if(wiersz == B.wiersz && kolum == B.kolum ){
	
        for (int i = 0; i < wiersz; ++i){
            for(int k = 0; k < kolum; ++k)
                skalar += Matrix[i][k] *B.Matrix[k][i];
        }
    }
    
	return skalar;
}

Macierz Macierz::operator* (const int &liczba) {              // operator * - liczba z prawej strony
	
	
	if(wiersz == 0 || kolum == 0  ||  Matrix == NULL) 
        return *this;
	 
	Macierz M(wiersz,kolum);
	
	if(M.Matrix != NULL) {
		for (int i = 0; i < wiersz; ++i)
			M.Matrix[i] = liczba * Matrix[i];
	}
	else{
		
		return *this;
	}

	return M;
}

Macierz operator* ( const int &liczba, const Macierz& B) {    // operator * - liczba z lewej strony

    if(B.wiersz == 0 || B.kolum == 0  ||  B.Matrix == NULL) 
        return B;
	 
	Macierz M(B.wiersz,B.kolum);
	
	if(M.Matrix != NULL) {
		for (int i = 0; i < B.wiersz; ++i)
			M.Matrix[i] = liczba * B.Matrix[i];
	}
	else{
		
		return B;
	}
	return M;
}

bool Macierz::operator== (const Macierz &B) const {           // operator ==
	
	if (wiersz !=  B.wiersz)
		return false;
    
    if (kolum !=  B.kolum)
		return false;
		
	for (int i = 0; i < wiersz; ++i)
		if (Matrix[i] != B.Matrix[i])
			return false;
	
	return true;
}

bool Macierz::operator!= (const Macierz &B) const {           //operator != 
	
	if (wiersz !=  B.wiersz)
		return true;
    
    if (kolum !=  B.kolum)
		return true;
		
	for (int i = 0; i < wiersz;++i)
		if (Matrix[i] != B.Matrix[i])
			return true;
	
	return false;
}

const Vector & Macierz::operator[] (const int& indeks) const {    // operator []
	
	return Matrix[indeks];
}


Macierz & Macierz::operator+= (const Macierz &B ) {            // operator +=
	
    
    
    if(wiersz == B.wiersz && kolum == B.kolum ){
        
        if ( B.Matrix !=  NULL) {
        
            for (int i = 0; i < wiersz; ++i)
                Matrix[i] += B.Matrix[i];
        }
        return *this;
    
    }else{
        
        cout<<"Zle wymiary macierzy"<<endl;
        return *this; // w razie błedu zwraca pierwsza macierz    
    } 
	
}

Macierz & Macierz::operator-= (const Macierz &B ) {            // operator -=
	
	if(wiersz == B.wiersz && kolum == B.kolum ){
        
        if ( B.Matrix !=  NULL) {
        
            for (int i = 0; i < wiersz; ++i)
                Matrix[i] -= B.Matrix[i];
        }
        
        return *this;
        
    }else{
        
        cout<<"Zle wymiary macierzy"<<endl;
        return *this; // w razie błedu zwraca pierwsza macierz    
    }
}

Macierz & Macierz::operator*= (const int &liczba ) {          // operator *=

	if(wiersz == 0 || kolum == 0  ||  Matrix == NULL) 
        return *this;
	 
	for (int i = 0; i < wiersz; ++i)
        Matrix[i] *= liczba;
	
	return *this;

}



ostream & operator<<(ostream & wyj,  const Macierz &B) {     // operator <<
  
  if (B.wiersz != 0 && B.Matrix !=  NULL && B.kolum != 0 ){
	  
		for (int i = 0; i < B.wiersz; ++i)
            wyj << B.Matrix[i] << endl;		
  }
	return wyj;
}

istream & operator>>(istream & wej,  const Macierz &B) {     // operator >>

	if (B.wiersz != 0 && B.Matrix !=  NULL && B.kolum != 0 ){
        
		for (int i = 0; i < B.wiersz; ++i) 
			wej >> B.Matrix[i];
	}
	return wej;
}
