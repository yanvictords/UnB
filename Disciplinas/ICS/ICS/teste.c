#include <stdlib.h>
#include <stdio.h>
#include <curses.h>


int main(void) {
    
    WINDOW * mainwin, * secondwin;
    int      a, flag1 = 0, flag2=0;


    /*  Set the dimensions and initial
	position for our child window   */

    int      width = 23, height = 7;
    int      rows  = 25, cols   = 80;
    int      x = (cols - width)  / 2;
    int      y = (rows - height) / 2;


    /*  Initialize ncurses  */
    mainwin = initscr();
 /*  if ( (mainwin = initscr()) == NULL ) {
	fprintf(stderr, "Error initialising ncurses.\n");
	exit(EXIT_FAILURE);
    }*/
    

    /*  Switch of echoing and enable keypad (for andrrow keys)  */


    noecho();
    keypad(mainwin, TRUE);


    /*  Make our child window, and add
	a border and some text to it.   */

    secondwin = subwin(mainwin, height, width, y, x);
    /*box(secondwin, 0, 0);*/

    /*mvwaddstr(secondwin, 1, 4, "eu ");
    mvwaddstr(secondwin, 2, 2, "sou ");
    mvwaddstr(secondwin, 3, 6, "uma");
    mvwaddstr(secondwin, 5, 3, "cobra");*/
    mvwaddstr(mainwin, 1, 4, "OOOO");
    refresh();


   while ( (a= getch()) != 's' ) {
	if (a== KEY_UP){
		if ( y > 0 ){ 
			--y;	
		flag1=0;
		}	
	}

	if (a==KEY_DOWN){
	    if ( y < (rows - height) ) flag1=1;++y;
		
	}

	if (a==KEY_LEFT){
	    if ( x > 0 ) --x;
	
	}

	if(a==KEY_RIGHT){
	    if ( x < (cols - width) ) ++x;

	}

	mvwaddstr(mainwin, y, x,"OOOO");
	/*wrefresh(secondwin);*/
    wrefresh(mainwin);
if(flag1==1)
move(y-1, 1);
if(flag1==0)
move(y+1, 1);
wclrtoeol(mainwin	);
if(flag1==1)
move(y+1, 1);
if(flag1==0)
move(y-1, 1);


    }


     /*Clean up after ourselves  */

    delwin(secondwin);
    delwin(mainwin);
    endwin();
    refresh();

    return EXIT_SUCCESS;
}
