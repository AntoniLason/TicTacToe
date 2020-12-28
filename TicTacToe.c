#include <stdio.h>
#include <conio.h>

///Struktury

struct plansza
{
    int ocena;                  //ocena ruchu, poprawna i brana pod uwagę tylko dla ruchu wygrywającego, w przeciwnym razie 10
    int glebokosc;              //ilość ruchów które komputer musi wykonać od początku gry do tej planszy
    char obraz[3][3];
    struct plansza *poprzednia;
};

///*********************

///funkcje

void wyswietlanie(char tab[3][3]);
void ruchkomputera(char tab[3][3]);
void analizazwycienstwa(char tab[3][3]);
void ruchgracza(char tab[3][3]);
void losowewypelnianie(struct plansza *wsk, char tab1[3][3]);

///*********************

///Zmienne globalne

struct plansza *pop;

///*********************
int main()
{

    char tab[3][3] = {{'-','-','-'}, {'-','-','-'}, {'-','-','-'}};
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
    pop = malloc(sizeof(struct plansza));
    pop ->poprzednia = NULL;
    for(int i = 0; i<9; i++)        //kopiowanie tablicy do struktury plansza
    {
        pop->obraz[i/3][i%3] = tab[i/3][i%3];
    }
    losowewypelnianie(pop, tab);
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


void losowewypelnianie(struct plansza *wsk, char tab1[3][3])
{
    struct plansza *h;
    for(int i = 0; i < 9; i++)
    {
        h = malloc(sizeof(struct plansza));
        h ->poprzednia = wsk;
        for(int j = 0; j<9; j++)
        {
            h->obraz[j/3][j%3] = tab1[j/3][j%3];
        }
        if((*h).obraz[i/3][i%3]=='-')
        {
            h->obraz[i/3][i%3]='o';
        }
        wyswietlanie((*h).obraz);
    }
}

//*******************************
///NOTATKI

///& daje wskaźnik, * daje to co jest pod wskaźnikiem
///wszystkie tablice są przekazywanie do funkcji przez referencje

