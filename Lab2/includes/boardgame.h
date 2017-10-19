/**
 * Stores basic BoardGame information
*/
typedef struct boardgame{
  char *name;
  double price;
  char *brandName;
} BoardGame;

/**
 * [createBoadGame description]
 * @param     name static string of name
 * @param     price double
 * @param     name static string of brand name
 * @return    a dynamically created BoardGame.
 */
BoardGame* createBoardGame(char *name, char *brandName, double price);

/**
 * Get price of BoardGame
 * @param   b BoardGame
 * @return  Double price
 */
double getBoardGamePrice( BoardGame *b );

/**
 * Return a BoardGame's name
 * @param    b BoardGame
 * @return   char* string of name
 */
char* getBoardGameName( BoardGame *b );

/**
 * Display a BoardGame's name and price.
 * @param   b BoardGame
 */
void printBoardGame( void *b );
