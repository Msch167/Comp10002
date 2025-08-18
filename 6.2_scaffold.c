/* Exercise 6.09: Calculating change using functions
 * Still an ugly program, but much more elegant than the first version in Ex3.06
 * Alistair Moffat, April 2013.
 * Liam Saliba, December 2021
 * (c) University of Melbourne */

#include <stdio.h>
#include <stdlib.h>

#define MAX_CHANGE 999

#define COIN1     200
#define COIN2     100
#define COIN3     50
#define COIN4     20
#define COIN5     10
#define COIN6     5
#define LAST_COIN COIN6

/* function prototypes */

int try_one_coin(int *cents, int coin);
void try_one_coin_and_print(int *cents, int coin);
int round_to_5(int cents);
void print_change(int cents);

int
main(int argc, char *argv[]) {

    /* get the input value */
    printf("Enter amount in cents: ");
    int amount;
    if (scanf("%d", &amount) != 1 || (amount < 0) || (amount > MAX_CHANGE)) {
        printf("Error in input\n");
        exit(EXIT_FAILURE);
    }

    print_change(round_to_5(amount));

    return 0;
}

/* returns a rounded-off value corresponding to the argument, according to the
   resolution of the last coin in the sequence of coins (5c) */
int
round_to_5(int cents) {
    int remainder = cents % LAST_COIN;
    int quotient = cents / LAST_COIN;

    if (remainder > LAST_COIN / 2) {
        // round up to nearest LAST_COIN
        return (quotient + 1) * LAST_COIN;
    } else {
        // round down to nearest LAST_COIN
        return quotient * LAST_COIN;
    }
    /* or, in one line (thanks Thomas Minuzzo)
         return (cents + 2) / 5 * 5;
       try different values of cents to see why that works.
    */
}

/* greedily reduces cents to 0, printing the denominations used to do so.
 * "greedy" means we start from the largest denomination and try smaller
 * and smaller denominations until we get our solution. */
void
print_change(int cents) {
    try_one_coin_and_print(&cents, COIN1);
    try_one_coin_and_print(&cents, COIN2);
    try_one_coin_and_print(&cents, COIN3);
    try_one_coin_and_print(&cents, COIN4);
    try_one_coin_and_print(&cents, COIN5);
    try_one_coin_and_print(&cents, COIN6);
    /* still room for improvement here, see arrays in Chapter 7. */
}

/* process one possible coin that can be used when giving change.
 * `cents` points to the current amount of cents, and is reduced by `coin`
 * amount as many times as possible.
 * returns the number of coins successfully removed from `cents`
 *
 * eg: *cents = 53, coin = 10  ->  *cents = 3, return value = 5
 *     as 5 x 10 cent coins can be reduced from 53 cents.
 */
int
try_one_coin(int *cents, int coin) {
    ... 
    return ncoins;
}

/* try one coin, then write one output line if successfully used that coin
 * Note: we would not need this function if we used an array, as this would be
 *  the body of a for loop looping over each coin. */
void
try_one_coin_and_print(int *cents, int coin) {
    int ncoins = try_one_coin(cents, coin);
    if (ncoins) {
        printf("give %d %3d-cent coins\n", ncoins, coin);
    }
}
