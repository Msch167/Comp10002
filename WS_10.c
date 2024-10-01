/* Exercises 4-7 in lec07 slides Foundations of Algorithms (COMP10002)
   Introduction to memory management.
   Andrew Chester, October 2012
*/

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>

char *string_dupe(char *s);
char **string_set_dupe(char **S);
void string_set_free(char **S);

int
main(int argc, char** argv) {
    char *dup;
    char **dups;
    int i;

    if (argc<2) {
        printf("Usage: %s test strings\n", argv[0]);
        return 1;
    }

    /* NOTE: for these tests, we haven't actually checked to see if we copied
       them. To do so, we would need to modify one version and see if the
       change appears in the other copy - if it does, something is wrong. */

    /* Testing string_dupe */
    printf("string is:\n\t%s\n", argv[1]);
    dup = string_dupe(argv[1]);
    printf("duplicate is:\n\t%s\n", dup);

    /* Testing string set dupe */
    printf("string set is (1 per line):\n");
    for(i=1; i<argc; i++) {
        printf("\t%s\n", argv[i]);
    }

    dups = string_set_dupe(argv);

    printf("duplicated string set is:\n");
    for(i=1; dups[i]; i++) {
        printf("\t%s\n", dups[i]);
    }

    /* Freeing the memory */
    free(dup);
    dup = NULL;
    string_set_free(dups);
    dups = NULL;

    /* Try to free argv - uncomment it to see the results. This is because
       the memory allocated for argv was not allocated by you, so you are
       not allowed to free it. */
    /*string_set_free(argv);*/

    return 0;
}

/* Exercise 4: duplicate a single string. Since we don't know in advance how
   long the string will be, we need to allocate the memory ourselves.*/
char
*string_dupe(char *s) {
    /* strlen returns a size_t, and we add 1 for the null byte */
    /* 1. create a pointer to the duplicate */
    
    /* 2. allocate memory */
    
    /* 3. It is good practice to check if malloc succeded */
    
    /* 4. Copy the string to the duplicate (We could use our own function here, but why bother?) */
    
    return duplicate;
}

/* Exercise 5: duplicates a set of strings. We use our previous function for
   each individual string, but we must allocate more memory to point to them
   all. */
char
**string_set_dupe(char **S) {
    /* create a pointer to the array of strings */ 
    
    
    /* get the number of strings in the set */

   
    /* add 1 to the length to hold the sentinal NULL pointer 
    and allocate memory */

    /* check if malloc succeded */
    
    /* Duplicate each string (use our function from exercise 4) */

   
    /* add a pointer sentinel */
    duplicates[i] = NULL;
    /* and return pointer to the array of pointers */
    return duplicates;
}

/* Exercise 6: Frees all the memory used by the set of strings. Note, each 
   string must be freed individually, and then S itself must be freed as well.
   This gives us one call to free for every call to malloc, which is a good
   sign. */
void
string_set_free(char **S) {
    /* iterate through the array and free each string */
   
        /* Remember to set freed memory to NULL to prevent illegal accesses*/
        
    }
    free(S);
    
    return;
}
