/**
 * Stores basic book information.
 */
typedef struct book {
    double price;
    char *name;
} Book;

/**
 * Creates a struct book and populates it with given parameters
 * @param  title static string of title
 * @param  price double
 * @return a dynamically created Book.
 */
Book* createBook( char * title, double price );

/**
 * Get price of book
 * @param   b Book
 * @return  Double price
 */
double getPrice( Book * b );

/**
 * Return a books name
 * @param  b Book
 * @return   char* string of name
 */
char* getName( Book *b );

/**
 * Display a book's name and price.
 * @param b [Book]
 */
void printBook( void * b );
