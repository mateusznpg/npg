fffffffffffffffffffffffffffffffff
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "drzewo.h"


int main(){
	struct drzewo *binarne = NULL;

	int i;
	for(i = 0;i <5; ++i)
		PobieranieDanych(&binarne);

	printf("\nKsiążka telefoniczna: \n");
	InOrder(binarne);
	printf("\nPierwszy kontakt: \n");
		MinValue(binarne);
	printf("\nOstatni kontakt: \n");
		MaxValue(binarne);
	printf("\nIlosc kontaktow: %d\n",NumberNodes(binarne));
	printf("\nWysokosc drzewa: %d\n",Height(binarne));
	search(binarne,"mat");

	return 0;
}