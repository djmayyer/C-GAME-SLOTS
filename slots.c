#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>


//BOLD COLORS
void green()
{
    printf("\033[1;32m");
}

void reset()
{
    printf("\033[0m");
}

void yellow()
{
    printf("\033[1;33m");
}

void red()
{
    printf("\033[1;31m");
}

void blue()
{
    printf("\033[1;34m");
}

void cyan()
{
    printf("\033[1;36m");
}

//REEL SHOWING
void reelShowing(int a)
{
    if(a == 0) 
    {   
        yellow();
       printf("bell");
        reset();
    }
    if(a == 1) 
    {
        green();
        printf("melons");
        reset();
    }
    if(a == 2)
    {   
        red();
        printf("cherry");
        reset();
    }
    if(a == 3) 
    {
        blue();
        printf("horseshoe");
        reset();
    }
}

int jackpot(int x, int y, int z)
{
    if(x == y && y == z) return 1;
    return 0;
}

int smallWin(int x, int y, int z)
{
    if(x == y || y == z || z==x) return 1;
    return 0;
}


int main()
{
    int reel[4];
    int i, bet;
    srand(time(NULL));
    int credit = 100;
    int game = 1;

    printf("CREDITS: %d \n",credit);

   while(game == 1)
   {  

       //inserting the bet
        printf("insert the bet:");
        scanf("%d", &bet);
        printf("\n");
        credit -= bet;

        //showing the paying 
        cyan();
        printf("-------------------3ELEMENTS WINS-------------------\n");
        reset();
        printf("3 x ELEMENTS = %d x 10 = %d \n", bet, bet*10);
        cyan();
        printf("-------------------2ELEMENTS WINS-------------------\n");
        reset();
        printf("2 x ELEMENTS = %d x 2 = %d\n", bet, bet*2);
        printf("---------------------FRUIT SLOTS--------------------\n");

        //random reel generator
        for(i = 0; i < 3; i++)
                reel[i] = rand() % 4;

        //printing the reels
        for(i = 0 ;i < 3; i++)
        {
                reelShowing(reel[i]);
                if(i < 2) printf(" - ");
        }
        printf("\n\n");

        //prize
            if(jackpot(reel[0], reel[1], reel[2]))
             {
                printf("!!!JACKPOT!!! \n");
                credit += bet * 10;
             }
                else if( smallWin(reel[0], reel[1], reel[2]))  
                    {
                        printf("SMALL WIN \n");
                        credit += bet * 2;
                    }
                        else printf("LOST \n");
    
        printf("\n");
        //credits
        printf("CREDITS: %d", credit);
        printf("\n");
        
         //credits verify
        if(credit <= 0) 
        {
            game = 0;
            printf("NO MORE CREDITS \n");
        }
        else
        {   
            //still plaing?
            printf("PLAY MORE ? \n");
            printf("1 - YES \n");
            printf("0 - NO\n");
            printf("ANSWER: ");
            scanf("%d", &game);
        }

    }

    //things to do
    /*  
            cleaning screen
    */


    return 0;
}