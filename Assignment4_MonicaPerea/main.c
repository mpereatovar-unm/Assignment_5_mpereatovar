//Sources: 

#include <stdio.h>   // Provides printf for displaying output
#include <stdlib.h>  // Provides malloc and free for managing memory
#include <string.h>  // Provides strlen, strcpy, and strcmp
#include "item.h"    // Provides the Item structure

// Adds one grocery item at the specified array index.
// item_list points to the array, and index selects an item in it.
void add_item(Item *item_list, double price, char *sku,
              char *category, char *name, int index)