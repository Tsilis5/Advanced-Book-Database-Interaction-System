#include "database_main.h"

/* Given a binary tree, find a node */
struct Book *search(struct Book *node, char *title) 
{ 
	struct Book *result;

    if(node == NULL) 
        return NULL; 
  
    if(strcmp(node->title, title)==0 && node->year!=-1) {
  		return node;
	}

    /* first recur on left child */
    result = search(node->left, title);
    if(result!=NULL)
    	return result;

    /* now recur on right child */
    result = search(node->right, title); 
    return result;
} 

/* menu_get_book_details():
 *
 * Get details of book from database.
 */
void menu_get_book_details(void)
{
	char title[10000], *pos;
	struct Book *node;

	while(1) {
		fprintf(stderr, "Give title: ");
		fflush(stderr);
		fgets(title, 99999, stdin);
		if ((pos=strchr(title, '\n')) != NULL)
			*pos = '\0';
	
		if (title[0] != '\0')
			break;
	}
	title[101]='\0';

	node = search(book_tree, title);
	if(node==NULL)
	 	fprintf(stderr, "Book not found");
	else {
		/* then print the data of node */
	    printf("Title: %s\n", node->title);   
	    printf("Author: %s\n", node->author);   
	    printf("Year: %d\n", node->year);
	    printf("\n");
	}
}

/* menu_delete_book():
 *
 * Delete new book from database.
 */
void menu_delete_book(void)
{
 	char title[10000], *pos;
	struct Book *node;

	while(1) {
		fprintf(stderr, "Give title: ");
		fflush(stderr);
		fgets(title, 99999, stdin);
		if ((pos=strchr(title, '\n')) != NULL)
			*pos = '\0';
	
		if (title[0] != '\0')
			break;
	}
	title[101]='\0';

	node = search(book_tree, title);
	if(node==NULL)
	 	fprintf(stderr, "Book not found");
	else
		node->year=-1;
}

