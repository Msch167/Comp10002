/* Show the use of function arguments and lists.
 * Jianzhong Qi, April 2020
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "listops.h"

#define NUM_INT 10

int
main(int argc, char *argv[]) {
	list_t *list = make_empty_list();
	data_t head_value; 
	int i = 0;
	int num;
	
	/* insert into list */
	printf("Enter 10 integers:\n");
	while (i < NUM_INT) {
		scanf("%d", &num);
		list = insert_at_foot(list, num);
		i++;
	}

	/* print out the list */
	printf("Integers in list:\n");
	list_t *p = list;
	while(list->head) {
		head_value = get_head(list);
		printf("%d", head_value);
		list = get_tail(list);
		if (list->head) {
			printf(" ");
		} else {
			printf("\n");
		}
	}

	/* clean list */
	free_list(p);
	printf("Cleaned list.\n");

	list = make_empty_list();
	/* insert into ordered list */
	printf("Enter the same 10 integers again:\n");
	i = 0;
	while (i < NUM_INT) {
		scanf("%d", &num);
		list = insert_in_order(list, num, int_ascending);
		i++;
	}

	/* print out the list */
	printf("Integers in list:\n");
	p = list;
	while(list->head) {
		head_value = get_head(list);
		printf("%d", head_value);
		list = get_tail(list);
		if (list->head) {
			printf(" ");
		} else {
			printf("\n");
		}
	}
	
	/* clean list */
	free_list(p);

	return 0;
}
