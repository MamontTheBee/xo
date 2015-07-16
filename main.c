#include <stdio.h>
#include "main.h"



int main(void){

        char grid[3][3], cur = 'X';
        int x, z, px = 0, po = 0;
        cleargrid(grid);
        gridprint(grid, 0);
        output('u');
        while(scanf("%d %d",&x, &z) == 2){
                if(x > 3 || z > 3){
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
                                return 0;
                        }else {
                                gridprint(grid, 0);
                                output('u');
                                if(cur == 'X')
                                px ++;
                                else po++;      
                                }
                        }
                        if(px >= 3 || po >= 3)
                                {
                                if(ifwin(cur, grid) != 'n')
                                        {
                                        output('w');
                                        printf("Winner is %c\n", cur);
                                        gridprint(grid, 1);
                                        return 0;
                                        }
                                }
                        if(cur == 'X')
                                cur = 'O';
                        else cur = 'X';
                }
        return 0;

}
