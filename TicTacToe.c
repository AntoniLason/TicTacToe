#include <stdio.h>
#include <conio.h>

void wyswietlanie(char tab[3][3]);
void ruchkomputera(char tab[3][3]);
int analizazwycienstwa(char tab[3][3]);
void ruchgracza(char tab[3][3]);

int main()
{
    char tab[3][3] = {{'-' ,'-' ,'-'}, {'-' ,'-' ,'-'}, {'-' ,'-' ,'-'}};
    ruchgracza(tab);
    wyswietlanie(tab);
    printf("\n");

}


//***********************

void ruchgracza(char tab[3][3])
{
    int c = getch();
    c-=49;
    printf("%d\n", c);
    if(tab[c/3][c%3]=='-')
    {
        tab[c/3][c%3]='x';
    }
    else
    {
        printf("ruch niemozliwy, sproboj ponownie\n");
        ruchgracza(tab);
    }

}

int analizazwycienstwa(char tab[3][3])
{

}

void ruchkomputera(char tab[3][3])
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

}

//*******************************
///NOTATKI

///& daje wskaźnik, * daje to co jest pod wskaźnikiem
///wszystkie tablice są przekazywanie do funkcji przez referencje

