/**
 * Stores an item
*/
typedef struct store{
  void* container;
  void (*printFunc)(void *container);
  //Takes in void *container so it can be typecasted to any print function requirement
} Store;

/**
 * Creates and populates a store
 * @param pointer to a struct
 * @param pointer to a function that prints the struct
 * @return pointer to a Store
 */
Store *createStore(void *container, void (*functionPointer)(void *container));

/**
 * Takes in a pointer to a store and displays the information using the Store's contents
 * @param pointer to a store
 */
void displayStore(Store* s);

/**
 * Rebrands a store's item and function pointer
 * @param the store pointer to rebrandStore
 * @param the new struct to put inside the store
 * @param the new print function to print the store with
 */
void rebrandStore(Store *s, void *container, void (*functionPointer)(void *container));
