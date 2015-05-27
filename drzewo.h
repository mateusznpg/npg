#ifndef drzewo_h
#define drzewo_h

#include <stdio.h>
#include <stdlib.h>

#define ROZMIAR 100

struct drzewo{

	char imie[ROZMIAR];
	char nazwisko[ROZMIAR];
	int nr_tel_1;
	int nr_tel_2;

	struct drzewo *prawo;
	struct drzewo *lewo;
};

void Insert(struct drzewo **binarne, struct drzewo *dane);
int CompareStrings(char *BasicValue, char *NewValue);
void InOrder(struct drzewo *wsk);
void MinValue(struct drzewo *wsk);
void MaxValue(struct drzewo *wsk);
int NumberNodes(struct drzewo *wsk);
int Height(struct drzewo *wsk);
void search(struct drzewo *wsk,char *key);
void PobieranieDanych(struct drzewo **binarne);
void WypisywanieDanych(struct drzewo *dane);





#endif