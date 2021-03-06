#include <stdio.h> 
void Barline(int x, char pat);                
void menurefresh(void);
void ShowBoard(void);
void refresh(void);
void StartOver(void);
int count, menunum, winsp1, winsp2, draws, player, reply; //Total of 9 global variables (both int and char)
char mark;
char square[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}; //Declaration of an array: An Array is a variable that can store multiple values/char. I have declared an array: Square (of char type, its size is 10, so I can hold/store 10 characters from '0' to '9' in it.)
    //I used square[10] and '0' as the first element so that later, square[1] gives '1' and square[9] gives '9', which makes it less confusing. (Even though I do not make use of square[0] or '0' at all.)
    //If I used square[9], I would have to use '1' as square[0], and '9' as square[8], since arrays have 0 as first index. This might make it a bit more confusing.
void main(void)   
{ 
    int choice; //declaring variable of integer type
    char mark;   //declaring variable of character type
                                                                   
    menunum = 0; // This ensures that when I run this, it would enter the loop first, as it fulfils the condition (menunum == 0).
    
    winsp1 = 0;    winsp2 = 0;     draws = 0;  //I put this initialization outside the menu. If it was within the while (menunum == 0), whenever user goes back to menu page, the scores restarts to 0.
    
    while (menunum == 0) //Loop for all menunums. I use menunum = 0 for going back to the main menu.
    {
        Barline(60, '*'); //Calls barline function and chooses pattern.
        printf("\n\t\t WELCOME TO TIC-TAC-TOE.\n"); Barline(60, '*');
        printf("\n\n\n\nCHOOSE ONE:"); // Displays Menu page and choices.
        printf("\n\n\n\t\t[1] PlAY MULTIPLAYER\n\t\t[2] SEE HIGHSCORE\n\t\t[3] EXIT\n\n");
        Barline(60, '~'); printf("\n");
        fflush(stdin);                                                                                                                              
        scanf("%d", &menunum);    // User inputs choice if they want multiplayer, against computer, see highscore, or exit.
        Barline(60, '~');
        if (menunum == 1)         // If user inputs or chooses 1 (Multiplayer)
        {
            player = 1;                   //start player at 1
            count  = 0;                   //start count at 0
       
            while (count < 9)             // enters loop as long as condition is satisfied (less than 9). This limits total number of moves to 9.
            {
                // THE BOARD
                printf("\n\t\tPlayer 1 is X and Player 2 is O \n\n\n\n");                      
                printf("\t\t\t  %c | %c | %c  \n", square [1], square [2], square [3]);     // Print the values of square [1], square [2] etc. which shows the tic tac toe board.
                printf("\t\t\t ------------\n");
                printf("\t\t\t  %c | %c | %c  \n", square [4], square [5], square [6]);
                printf("\t\t\t ------------\n");
                printf("\t\t\t  %c | %c | %c  \n\n", square [7], square [8], square [9]);
        
                // USER INPUT:
                printf("Player %d\nEnter a number: ", player);   // User Input: Player enters a number which would later appear as marked on the tic-tac-toe square.
                fflush(stdin);
                scanf("%d", &choice);                            //Stores what number or square the player chooses as "choice".
    
                // MARKING THE SQUARES:
    
                if (player == 1)
                    mark = 'X' ; 
                if (player == 2)                                 //Player 1 marks X, Player 2 marks O. 
                    mark = 'O';
                if (choice == 1 && square[1] == '1')             // If player 1/2 inputs 1 AND if square 1 displays character 1, then it will mark square 1 using X or O respectively. If square 1 already has X or O, and the player still chooses square 1, it would skip to else block and display 'invalid moves'.
                    square [1] = mark; 
    
                else if (choice == 2 && square[2] == '2')        // Must use else-ifs instead of if-ifs. If I use if-if, it will display 'invalid move' for the ifs above, as it goes thru everything, takes the latest if-else if, and ignores all the ifs above.
                    square [2] = mark;
    
                else if (choice == 3 && square[3] == '3')
                    square [3] = mark;
    
                else if (choice == 4 && square [4] == '4')
                    square [4] = mark;
    
                else if (choice == 5 && square [5] == '5')
                    square [5] = mark;
    
                else if (choice == 6 && square [6] == '6')
                    square [6] = mark;
    
                else if (choice == 7 && square [7] == '7')
                    square [7] = mark;
    
                else if (choice == 8 && square [8] == '8')
                    square [8] = mark;
    
                else if (choice == 9 && square [9] == '9')
                    square [9] = mark;
               
                // DATA VALIDATION:
                else                           //if moves are invalid (marking an already marked square or entering a number other than 1-9)
                {
                    printf("\n\t\t\tINVALID MOVE!\n\t\t   Restart the game? (y/n): "); //USER EXIT: If user gave an invalid move, display message and ask if want to restart, go back to main menu or exit.
                    fflush(stdin);                                         
                    scanf("%c", &reply);
                    if (reply == 'y')         //if reply is yes, it clears all squares from Xs and Os to give char '1' to '9' again. (It "Refreshes": See function)
                    {
                        refresh();           //calls void refresh(void) function to refresh the squares back to 1-9.
                        count  = -1;        //set count to -1 so that (for the count below (as it goes thru this loop)) when -1+1, count is 0 (just like the original one above/outside of loop).
                        player = 2;        //set player to 2 because when new count is 0, it goes to else block (under Taking Turns), and player = 2-1= 1 (just like original). Does not matter which player it is now, since I am already assigning a value to count and player.
                    }
                    else
                    {    
                        printf("\n\t\t   Back to Main Menu? (y/n): ");
                        fflush(stdin);
                        scanf("%c", &reply);
                        if (reply == 'y')
                        {
                            menurefresh();                                                      //USER EXIT: If yes, goes back to menu, calls void menurefresh(void) function.
                        }
                        else
                            count = 100;                                                        //USER EXIT: If not, exits all loops, both 'while (count < 9)' using count = 100, and 'while(menunum == 0)' since menunum is already 1 here at this point.
                    }    
                } 
                count = count + 1;                                                              //increase count by 1 everytime a move is made, and later goes to the start to the loop to see if condition can be satisfied again.
                if (count >= 1 && count <=9)                                                    //So it will not show things like Move #101.
                {
                    printf("Move #%d\n", count);                                                // Shows total number of moves made.
                }
                //TAKING TURNS BETWEEN PLAYERS 1 AND 2: (This determines who the next player is)
                if (count == 1 || count == 3 || count == 5 || count == 7)                       //Since Player 1 starts first, it is his/her turn only when the count is 0/2/4/6/8. For Player 2, it would be when the new count is 1/3/5/7. 
                {    
                    player = player + 1;                                                        //Hence, Player 1+1=2 if Count is 1/3/5/7 after [count = count + 1]. This switches to Player 2.
                }
                else
                {    
                    player = player - 1;                                                        // If Count is not 1/3/5/7 (after the turn for Player 2), it is the turn for player 1. So Player 2-1=1. This switches to Player 1. This ensures the players switch between 1 and 2 only. (Note: Even if new count = 9, it goes to else block, player becomes 0. But it does not matter - it will not re-enter the loop later anymore. It will either be a win or draw (count/player can reset if win/draw).) 
                }
                //DIFFERENT WINNING COMBINATIONS AND DISPLAY:
                if (square [1] == square [2] && square [2] == square [3]                        // If squares 1,2,3 match (either upper horizontal win XXX or OOO).
                    || square [1] == square [4] && square [4] == square [7]                     // If squares 1,4,7 match (left vertical win --> XXX or OOO).
                    || square [1] == square [5] && square [5] == square [9]                     // If squares 1,5,9 match (Diagonal win ---> XXX or OOO).
                    || square [2] == square [5] && square [5] == square [8]
                    || square [3] == square [6] && square [6] == square [9]
                    || square [3] == square [5] && square [5] == square [7]
                    || square [4] == square [5] && square [5] == square [6]
                    || square [7] == square [8] && square [8] == square [9])                       
                {    
                    if (count == 5 || count == 7 || count == 9)                                 // At this very instant, if current count is 5/7/9, it MUST be after Player 1 has marked 3/4/5 times respectively (XXX).   Displays Player 1 wins and game over. Ask if want to replay.
                    {   
                        printf("\n\t\t\tPlAYER 1 WINS! \n\n\t\t      G A M E    O V E R\n\n"); 
                        winsp1 = winsp1 + 1;                                                    //Adds 1 win for player 1.
                        // CALLS FUNCTION TO SHOW THE BOARD
                        ShowBoard(); 
                        printf("\n\t\t      Start Over? (y/n): ");                              //USER EXIT: Ask for user input if want to start over, go to main menu or exit.
                        StartOver();                                                            //calls function: void StartOver(void)
                    }
                    else                                                                        // At this point, if current count is 6/8, it MUST be after Player 2 has marked 3/4 times respectively (OOO).  Displays Player 2 wins and Game Over.  Ask if want to replay.
                    {   
                        printf("\n\t\t\tPlAYER 2 WINS! \n\n\t\t      G A M E    O V E R\n\n"); 
                        winsp2 = winsp2 + 1;                                                    //Adds 1 win for player 2.
                        // CALLS FUNCTION TO SHOW THE BOARD  
                        ShowBoard();
                        printf("\n\t\t      Start Over? (y/n): ");                              //USER EXIT: Ask for user input if want to start over, go to main menu or exit.
                        StartOver();                                                            //calls function: void StartOver(void)
                    }                                                        
                }  
                // DRAW GAMES, USER EXIT AND CONTINUE:
                if (count == 9)                                                                 // If the above does not apply, if all 9 moves are made (after going through the above codes/If there are no wins at 9th move): It is a draw.
                {    
                    printf("\n\t\tA DRAW!\n");                                                  // Tells players it is a draw. 
                    draws = draws + 1;                                                          // Adds 1 draw.
                    // CALLS FUNCTION TO SHOW THE BOARD         
                    ShowBoard();
                    printf("\n\t\tWant to play again? (y/n): ");                                //USER EXIT: Ask for user input if user wants to keep playing, go to main menu or exit.
                    StartOver();                                                                //calls function: void StartOver(void)
                }            
            } //Loops back if count is still < 9
        } //End of if (menunum = 1)
 
        else if (menunum == 2)
        {
            printf("\n\t\tHIGHSCORES: \n\t\tPLAYER 1: %d \n\t\tPLAYER 2: %d \n\t\tDRAWS: %d\n\n\n\n\n", winsp1, winsp2, draws);
            printf("Back? (y/n): ");
            fflush(stdin);
            scanf("%c", &reply);
            if (reply == 'y')
            {
                menunum = 0;
                printf("\n\n\n");
            }
        }
        else if (menunum == 3)   //USER EXIT
        {
            printf("\n\t\tARE YOU SURE? (y/n): ");
            fflush(stdin);
            scanf("%c", &reply);
            if (reply != 'y')
                menunum = 0;    //If reply is not yes, user goes back to main menu. If reply is yes, it will automatically exit the loop since menunum is already 4.
        }
        else  //DATA VALIDATION
        {
            printf("\nInvalid Input! \n\n");
            menunum = 0;
        }
    } // end of while (menunum == 0). Exits menu.
    printf("\n\t\t             BYE\n\n\n\n\n");        //Message displayed when all loops are exited.
} //end of void main(void)
//functions:
void menurefresh(void)
{
    count   = 100;      //exits loop for (count < 9)
    menunum = 0;        //assigning this exits 'if (menunum == 1)' and goes back to Main Menu. Stays in While (menunum == 0) loop.
    refresh();          //function within a function, to refresh/renew the squares back to original.
    printf("\n\n\n");
} 
void refresh(void)
{  
    square[1] = '1'; square[2] = '2'; square[3] = '3'; square[4] = '4'; square[5] = '5'; square[6] = '6'; square[7] = '7'; square[8] = '8'; square[9] = '9'; //clears all squares from Xs and Os to give characters '1' to '9' again.
}
void Barline(int x, char pat) //Function accepts 2 arguments and there are 2 formal parameters: x for length of line, pat for pattern of line.
{
    int i = 0;
    while (i < x)
    {
        printf("%c", pat);
        i = i + 1;
    }
}
void ShowBoard(void)
{
    Barline(80, '+');   //function within a function, calls barline
    printf("\n\t\t\t  %c | %c | %c  \n", square [1], square [2], square [3]); 
    printf("\t\t\t ------------\n");
    printf("\t\t\t  %c | %c | %c  \t\t      Player 1 Won: %d\n", square [4], square [5], square [6], winsp1);    
    printf("\t\t\t ------------\n");
    printf("\t\t\t  %c | %c | %c  \t\t      Player 2 Won: %d\n", square [7], square [8], square [9], winsp2);
    printf("\n\t\t\t\t\t\t\t  Draws: %d\n\n", draws);
    Barline(80, '+');
}
void StartOver(void)  //START OVER OR USER EXIT.
{
    fflush(stdin);
    scanf("%c", &reply);
    if (reply == 'y')
    {    
        refresh();
        count  = 0;
        player = 1;                                   // If reply is yes, it clears all squares from Xs and Os to give characters '1' to '9' again. It resets count back to 0 and player to 1 so it enters the loop again, just like before.
    }
    else                                              // If reply is anything else, user chooses if he/she wants to go back to main menu or exit.
    {
        printf("\n\t\t  Back to Main Menu? (y/n): ");
        fflush(stdin);
        scanf("%c", &reply);
        if (reply == 'y')                             //If yes, back to menu.
            menurefresh();   
        else
            count = 100;                              //If no, exits all loops, both 'while(count < 9)' using count = 100, and 'while(menunum ==0)' since menunum is already 1 here at this point.
    }
}

