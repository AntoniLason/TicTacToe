#include <stdio.h>


int main()
{
    char tab[3][3] = {{'a' ,'b' ,'c'}, {'d' ,'e' ,'f'}, {'g' ,'h' ,'i'}};

    wyswietlanie(tab);
    printf("\n");
    printf("%c", tab[0][0]);

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
void wyswietlanie(char tab[3][3])
{

    for(int i = 0; i <= 2 ; ++i)
    {
        for(int j = 0 ; j<=2 ; ++j)
        {
            printf("%c ", tab[i][j]);
        }
        printf("\n");

    }
    tab[0][0] = 'x';
    printf("\n");

}

//*******************************
///NOTATKI

///& daje wskaźnik, * daje to co jest pod wskaźnikiem
///wszystkie tablice są przekazywanie do funkcji przez referencje

