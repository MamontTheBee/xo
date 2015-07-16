#include <stdio.h>
#include <ctype.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void gridprint(char pos[3][3], int color)
{
        int i,j;
        if (color == 1)
        	printf(ANSI_COLOR_RED" ----------- \n");
        else printf(" ----------- \n");

        for(i = 0; i < 3; i++){
                for(j =0; j < 3; j++){
                        printf("| ");
                        printf("%c ",pos[i][j]);
                }
                printf("|\n");
        }
        printf(" ----------- \n"  ANSI_COLOR_RESET);    
}

int checkgrid(char pos[3][3])
{
		int i, j;
	    for(i = 0; i < 3; i++){
                for(j =0; j < 3; j++){
                	if(pos[i][j] == ' ')
                		return 1;
                }
            }
                return 0;
}

void cleargrid(char grid[3][3])
{
        int k,l;
        for(k = 0; k < 3; k++){
                for(l =0; l < 3; l++){
                        grid[k][l] = ' ';
	                }
                }
}

void output(char c){
	if(isupper(c))
		tolower(c);
	switch(c)
	{
		case 'u': //usage
			printf("Usage: Raw, Colon\nSelectPosition: ");
			break;
		case 'c': //character out of range
			printf("only x or o characters are accepted\n");
			break;
		case 'n': 
			printf("Maximum position numver = 3\n");
			break;
		case 'o': //occupied
			printf(ANSI_COLOR_RED "Occupied... Choose Another" ANSI_COLOR_RESET "\n");
			break;
		case 'w':
			printf(ANSI_COLOR_RED "We've got a Winner!!!" ANSI_COLOR_RESET "\n");
			break;
		case 'f':
			printf(ANSI_COLOR_RED "It's a Tie :(" ANSI_COLOR_RESET "\n");
				break;
		default:
			printf("Usage: Xpos, Ypos\nSelectPosition: ");
	}
}

char ifwin(char ch, char grid[3][3]){
	char winner;
	if((grid[0][0] == ch && grid[0][1] == ch && grid[0][2] == ch) || 
		(grid[0][0] == ch && grid[1][0] == ch && grid[2][0] == ch) ||
		(grid[0][1] == ch && grid[1][1] == ch && grid[2][1] == ch) || 
		(grid[0][2] == ch && grid[1][2] == ch && grid[0][2] == ch) ||
		(grid[1][0] == ch && grid[1][1] == ch && grid[1][2] == ch) ||
		(grid[2][0] == ch && grid[2][1] == ch && grid[2][2] == ch) ||
		(grid[0][0] == ch && grid[1][1] == ch && grid[2][2] == ch))
	{
		winner = 'w';
	} else 
		winner = 'n';
	return winner;
}




