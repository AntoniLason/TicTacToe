#include <stdio.h>
#include <conio.h>

///Struktury
//Zapamiętaj, struktury przed funkcjami
struct plansza
{
    int ruch;
    int ocena;                  //ocena ruchu, poprawna i brana pod uwagę tylko dla ruchu wygrywającego, w przeciwnym razie 10
    int glebokosc;              //ilość ruchów które komputer musi wykonać od początku gry do tej planszy
    char obraz[3][3];
    struct plansza *poprzednia;
};

///*********************

///funkcje

void wyswietlanie(char tab[3][3]);
void ruchkomputera(char tab[3][3]);
int analizazwycienstwa(char tab[3][3]);
void ruchgracza(char tab[3][3]);
void wypelnianie(struct plansza *wsk, char tab[3][3]);

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

        if(analizazwycienstwa(tab)==1)
            printf("wygrywa kolko");
        else if(analizazwycienstwa(tab)==0)
            printf("nierozstrzygniete");
        else if(analizazwycienstwa(tab)==-1)
            printf("wygrywa krzyzyk");
        printf("\n");
        ruchkomputera(tab);
        wyswietlanie(tab);

        if(analizazwycienstwa(tab)==1)
            printf("wygrywa kolko");
        else if(analizazwycienstwa(tab)==0)
            printf("nierozstrzygniete");
        else if(analizazwycienstwa(tab)==-1)
            printf("wygrywa krzyzyk");

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

int analizazwycienstwa(char tab[3][3])
{
    for(int i = 0 ; i<3; ++i)
    {
        if(tab[i][0] == 'o' && tab[i][1] == 'o' && tab[i][2]== 'o')
        {

            return 1;
        }
        else if(tab[0][i] == 'o' && tab[1][i] == 'o' && tab[2][i]== 'o')
        {

            return 1;
        }
    }
    if(tab[0][0] == 'o' && tab[1][1] == 'o' && tab[2][2]== 'o')
    {

        return 1;
    }
    else if(tab[2][0] == 'o' && tab[1][1] == 'o' && tab[0][2]== 'o')
    {

        return 1;
    }


    for(int i = 0 ; i<3; ++i)
    {
        if(tab[i][0] == 'x' && tab[i][1] == 'x' && tab[i][2]== 'x')
        {

            return -1;
        }
        else if(tab[0][i] == 'x' && tab[1][i] == 'x' && tab[2][i]== 'x')
        {

            return -1;
        }
    }
    if(tab[0][0] == 'x' && tab[1][1] == 'x' && tab[2][2]== 'x')
    {

        return -1;
    }
    else if(tab[2][0] == 'x' && tab[1][1] == 'x' && tab[0][2]== 'x')
    {

        return -1;
    }
    return 0;
}

void ruchkomputera(char tab[3][3])
{
    pop = malloc(sizeof(struct plansza));
    pop ->poprzednia = NULL;
    pop ->glebokosc = 0;
    for(int i = 0; i<9; i++)        //kopiowanie tablicy do struktury plansza
    {
        pop->obraz[i/3][i%3] = tab[i/3][i%3];
    }
    wypelnianie(pop, tab);
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


void wypelnianie(struct plansza *wsk, char tab[3][3])
{
    struct plansza *h;
    for(int i = 0; i < 9; i++)
    {
        h = malloc(sizeof(struct plansza));
        h ->poprzednia = wsk;
        h ->glebokosc = wsk->glebokosc +1;
        for(int j = 0; j<9; j++)
        {
            h->obraz[j/3][j%3] = (*wsk).obraz[j/3][j%3];
        }
        if((*h).obraz[i/3][i%3]=='-')
        {
            h->obraz[i/3][i%3]='o';
            //wyswietlanie((*h).obraz);
            if(analizazwycienstwa(h->obraz)==1)
            {
                tab[i/3][i%3]='o';
                break;
            }
        }
        else free(h);

    }
}

//*******************************
///NOTATKI

///& daje wskaźnik, * daje to co jest pod wskaźnikiem
///wszystkie tablice są przekazywanie do funkcji przez referencje

