#include <stdio.h>
#include <conio.h>

///funkcje

void wyswietlanie(char tab[3][3]);
void ruchkomputera(char tab[3][3]);
void analizazwycienstwa(char tab[3][3]);
void ruchgracza(char tab[3][3]);

///*********************

///Struktury

typedef struct plansza{
int ocena;                  //ocena ruchu, poprawna i brana pod uwagę tylko dla ruchu wygrywającego, w przeciwnym razie 10
int glebokosc;              //ilość ruchów które komputer musi wykonać od początku gry do tej planszy
char plansza[3][3];
struct plansza *nastepna;
struct plansza *poprzednia;
} plansza;

///*********************

///Zmienne globalne
plansza* first;
///*********************
int main()
{
    first = malloc(sizeof(plansza));
    first ->poprzednia = NULL;
    first ->nastepna = NULL;

    char tab[3][3] = {{'-' ,'-' ,'-'}, {'-' ,'-' ,'-'}, {'-' ,'-' ,'-'}};
    while(1)
    {
    ruchgracza(tab);
    wyswietlanie(tab);
    analizazwycienstwa(tab);
    ruchkomputera(tab);
    wyswietlanie(tab);
    analizazwycienstwa(tab);
    printf("\n");
    }


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

void analizazwycienstwa(char tab[3][3])
{
        for(int i = 0 ; i<3; ++i)
    {
    if(tab[i][0] == 'o' && tab[i][1] == 'o' && tab[i][2]== 'o')
        printf("Wygrywa kulko");
    else if(tab[0][i] == 'o' && tab[1][i] == 'o' && tab[2][i]== 'o')
        printf("Wygrywa kulko");
    }
    if(tab[0][0] == 'o' && tab[1][1] == 'o' && tab[2][2]== 'o')
        printf("Wygrywa kulko");
    else if(tab[2][0] == 'o' && tab[1][1] == 'o' && tab[0][2]== 'o')
        printf("Wygrywa kulko");


    for(int i = 0 ; i<3; ++i)
    {
    if(tab[i][0] == 'x' && tab[i][1] == 'x' && tab[i][2]== 'x')
        printf("Wygrywa krzyzyk");
    else if(tab[0][i] == 'x' && tab[1][i] == 'x' && tab[2][i]== 'x')
        printf("Wygrywa krzyzyk");
    }
    if(tab[0][0] == 'x' && tab[1][1] == 'x' && tab[2][2]== 'x')
        printf("Wygrywa krzyzyk");
    else if(tab[2][0] == 'x' && tab[1][1] == 'x' && tab[0][2]== 'x')
        printf("Wygrywa krzyzyk");
}

void ruchkomputera(char tab[3][3])
{

}

void wyswietlanie(char tab[3][3])
{

    for(int i = 0; i <= 2 ; ++i)
    {
        for(int j = 0 ; j <= 2 ; ++j)
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

