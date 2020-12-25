#include <stdio.h>


int main()
{
    char tab[3][3] = {{'a' ,'b' ,'c'}, {'d' ,'e' ,'f'}, {'g' ,'h' ,'i'}};
    char *ws = &tab;
    wyswietlanie(ws);
    printf("%s", *(ws+1));
}


//***********************

void ruchgracza()
{

}

int analizazwycienstwa()
{

}
void ruchkomputera()
{

}
void wyswietlanie(char *tab)
{

    for(int i = 0; i < 2 ; ++i)
    {
        for(int j = 0 ; j> 2 ; ++j)
        {
            int a = *(tab+i);
            printf("%s", a);
        }

    }
    printf("\n");

}

//*******************************
///NOTATKI

///& daje wskaźnik, * daje to co jest pod wskaźnikiem
/*
CO POTRZEBNE

inicjalizacja planszy
ruch gracza
tóch komputera
analiza zwyciêstwa
generowanie ruchy komputera
wyœwietlanie

*/
