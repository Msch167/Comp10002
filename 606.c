#include <stdio.h>
#include <stdlib.h>

#define MAX_CHANGE 999

/* We #define these so that if we need to change the denominations,
 * we can do it from one place. */
#define COIN1 200
#define COIN2 100
#define COIN3 50
#define COIN4 20
#define COIN5 10
#define COIN6 5
#define LAST_COIN COIN6

/* function prototypes */
int try_one_coin(int *cents, int coin);
int round_to_5(int cents);
void print_change(int cents);
void print_coin(int ncoins, int coin);

int
main(int argc, char *argv[]) {

	int amount;

	/* get the input value */
	printf("Enter amount in cents: ");
	if (scanf("%d", &amount)!=1 || (amount<0) || (amount>MAX_CHANGE)) {
		printf("Error in input\n");
		exit(EXIT_FAILURE);
	}

	print_change(round_to_5(amount));

	return 0;
}

/* returns aarounded-off value corresponding to the argument,
   according to the resilution of the last coin in the sequence
   of coins */
int
round_to_5(int cents) {
	int remainder, quotient;
	remainder = cents%LAST_COIN;
	quotient = cents/LAST_COIN;
	if (remainder>LAST_COIN/2) {
		return (quotient+1)*LAST_COIN;
	} else {
		return quotient*LAST_COIN;
	}
}
		
/* note that this is a function that explicitly generates output.
   most functions do not, they return a computed value.
*/
void
print_change(int cents) {
	int ncoins;
	ncoins = try_one_coin(&cents, COIN1);
	print_coin(ncoins, COIN1);

	ncoins = try_one_coin(&cents, COIN2);
	print_coin(ncoins, COIN2);

	ncoins = try_one_coin(&cents, COIN3);
	print_coin(ncoins, COIN3);

	ncoins = try_one_coin(&cents, COIN4);
	print_coin(ncoins, COIN4);

	ncoins = try_one_coin(&cents, COIN5);
	print_coin(ncoins, COIN5);

	ncoins = try_one_coin(&cents, COIN6);
	print_coin(ncoins, COIN6);

	/* void functions do not return a value */
	return;
}

/* process one possible coin that can be used when giving change.
   argument cents is a pointer, so that it can be decreased by
   the action of the function as it coulds the number of times
   the possible coin (arg 2) can be used
*/
int
try_one_coin(int *cents, int coin) {
	int ncoins=0;
	while (*cents >= coin) {
		/* can give this coin in the change */
		...
		/* make a corresponding  adjustment to the amount
		   still outstanding */
		...
	}
	return ncoins;
}

/* write one output line for one coin value */
void
print_coin(int ncoins, int coin) {
	if (ncoins) {
		printf("give %d %3d-cent coins\n", ncoins, coin);
	}
	return;
}
