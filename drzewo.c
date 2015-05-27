#include "drzewo.h"

void Insert(struct drzewo **binarne, struct drzewo *dane){

    struct drzewo *wsk, *wsk2;
    wsk = (struct drzewo *)malloc(sizeof(struct drzewo));
	wsk2 = *binarne;
    if(wsk != NULL)
    {
		*wsk = *dane;
		wsk->prawo = NULL;
		wsk->lewo = NULL;

        if(*binarne == NULL)
		{
			*binarne = wsk;

		}
		else{

			while(wsk2 != NULL){

				if(CompareStrings(wsk2->nazwisko,wsk->nazwisko) > 0){

					if(wsk2->lewo == NULL){
						wsk2->lewo = wsk;
						break;
					}
					else{

						wsk2 = wsk2->lewo;
					}
				}
				else{

					if(wsk2->prawo == NULL){
						wsk2->prawo = wsk;
						break;
					}
					else{

						wsk2 = wsk2->prawo;
					}
				}
			}

		}
	}
}
int CompareStrings(char *BasicValue, char *NewValue){

	int i = 0;
	char str1[ROZMIAR] = {};
	char str2[ROZMIAR] = {};
	/*
	 * >0 -> lewo
	 * 0< -> prawo
	 */

	while(BasicValue[i] != '\0')
	{
		if(BasicValue[i] == '\n'){

			str1[i] = '\0';
			break;
		}else{

			str1[i] = tolower(BasicValue[i]);
		}
		++i;
	}
	i = 0;
	while(NewValue[i] != '\0')
	{
		if(NewValue[i] == '\n'){

			str2[i] = '\0';
			break;
		}else{

			str2[i] = tolower(NewValue[i]);
		}
		++i;
	}
	return strcmp(str1,str2);

}

void InOrder(struct drzewo *wsk){

	if(wsk->lewo != NULL)
		InOrder(wsk->lewo);

	WypisywanieDanych(wsk);

	if(wsk->prawo != NULL)
		InOrder(wsk->prawo);

}
void MinValue(struct drzewo *wsk){

	if(wsk->lewo == NULL)
		WypisywanieDanych(wsk);
	else
		MinValue(wsk->lewo);
}
void MaxValue(struct drzewo *wsk){

	if(wsk->prawo == NULL)
		WypisywanieDanych(wsk);
	else
		MaxValue(wsk->prawo);
}
int NumberNodes(struct drzewo *wsk){

	if(wsk == NULL)
		return 0;
	else
	{
		int il_l = NumberNodes(wsk->lewo);
		int il_p = NumberNodes(wsk->prawo);
		return il_l+il_p+1;
	}


}
int Height(struct drzewo *wsk){

	if(wsk == NULL)
		return 0;
	else
	{
		int il_l = Height(wsk->lewo);
		int il_p = Height(wsk->prawo);
		if(il_l > il_p)
			return ++il_l;
		else
			return ++il_p;
	}

}
void search(struct drzewo *wsk,char *key){

	if(wsk->lewo != NULL && strcmp(wsk->nazwisko,key) != 0)
		search(wsk->lewo,key);

	if(CompareStrings(wsk->nazwisko,key) == 0)
		WypisywanieDanych(wsk);

	if(wsk->prawo != NULL && strcmp(wsk->nazwisko,key) != 0)
		search(wsk->prawo,key);
}


void PobieranieDanych(struct drzewo **binarne){

	struct drzewo *dane = (struct drzewo *)malloc(sizeof(struct drzewo));;
	char wybor;
	if(dane != NULL){

		printf("Podaj imie: \n");
		fgets(dane->imie,ROZMIAR,stdin);

		printf("Podaj nazwisko: \n");
		fgets(dane->nazwisko,ROZMIAR,stdin);

		printf("Podaj numer telefonu: \n");
		scanf("%d",&(dane->nr_tel_1));
		getchar();

		printf("Czy chcesz podac drugi numer telefonu? ( T -> TAK, N -> NIE)\n");
			wybor = getchar();
			getchar();

		if(wybor == 'T' || wybor == 't'){

			printf("Podaj drugi numer telefonu: \n");
			scanf("%d",&(dane->nr_tel_2));
			getchar();
		}else{

			dane->nr_tel_2 = 0;
		}

		Insert(binarne,dane);
		free(dane);
	}
	else
		printf("Nie mozna przydzielic pamieci");
}

void WypisywanieDanych(struct drzewo *dane){

	if(dane != NULL){

		printf("Nazwisko:  ");
		fputs(dane->nazwisko,stdout);

		printf("Imie:      ");
		fputs(dane->imie,stdout);

		printf("Nr tel:    %d\n",dane->nr_tel_1);
		if(dane->nr_tel_2 != 0)
			printf("Nr tel(2): %d\n",dane->nr_tel_2);

	}
}


