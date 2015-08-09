#include <stdio.h>
#include "main.h"



int main(void){

        char grid[3][3], cur = 'X', Players[2][10];
        int x, z, px = 0, po = 0, curplayer = 0;

        //username input
        printf("Name of player 1: ");
        getName(Players[0],10);
        printf("Name of player 2: ");
        getName(Players[1],10);
        printf("p1: %s plays with X\n", Players[0]);
        printf("p2: %s plays with O\n", Players[1]);


        //initial grid print
        cleargrid(grid);
        gridprint(grid, 0);
        printf("%s's turn with %c\n", Players[curplayer], cur);
        output('u');
        while(scanf("%d %d",&x, &z) == 2){
                if(x > 3 || z > 3 || x < 1 || z < 1){
                        output('n');
                        output('u');
                        continue;
                } else  if(grid[x-1][z-1] != ' '){
                                output('o');
                                output('u');
                                continue;
                } else  {
                        grid[x-1][z-1] = cur;
                        if (checkgrid(grid) == 0)
                        {
                                gridprint(grid, 1);
                                output('f');
                                output('a');
                                if(playAgain()==1){
                                        cleargrid(grid);
                                        gridprint(grid, 0);
                                        cur = 'X';
                                        curplayer = 0;
                                        printf("%s's turn with %c\n", Players[curplayer], cur);
                                        output('u');
                                        continue;
                                }else {
                                        printf("Bye!\n ");
                                        return 0;
                                }
                                //return 0;
                        }else {
                                gridprint(grid, 0);
                                if(cur == 'X')
                                px ++;
                                else po++;
                                }
                        }
                        if(px >= 3 || po >= 3)
                                {
                                if(ifwin(cur, grid) == 1)
                                        {
                                        output('w');
                                        printf("Winner is %s\n", Players[curplayer]);
                                        gridprint(grid, 1);
                                        output('a');
                                        if(playAgain()==1){
                                                cleargrid(grid);
                                                gridprint(grid, 0);
                                                cur = 'X';
                                                continue;
                                        }else {
                                                printf("Bye!");
                                                return 0;
                                        }
                                        }
                                }
                        if(cur == 'X' && curplayer == 0){
                                cur = 'O';
                                curplayer = 1;
                                //printf("%d %c\n", curplayer, cur);
                        }
                        else {
                                cur = 'X';
                                curplayer = 0;
                        }
                        printf("%s's turn with %c\n", Players[curplayer], cur);
                        output('u');
                }
        return 0;

}
