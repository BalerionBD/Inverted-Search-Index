#include "inverted_search.h"

int main(int argc , char *argv[])
{
    system("clear");

    Wlist *head[27] = {NULL};

    //validate CLA
    if(argc <= 1)
    {
	printf("Enter valid no of arg\n");
	printf("./.Slist.exe f1.txt f2.txt.....\n");
	return 0;
    }
    //create file linked list 
    //declare head pointer

    Flist *f_head = NULL;

    //validate the files
    file_validation_n_file_list(&f_head , argv);

    if(f_head == NULL)
    {
	printf("No files are available in the file linked list\n");
	printf("Hence the process terminated\n");
	return 1;
    }

	/*............TODO................
	   prompt the user for choice
	Select your choice among following options:
		1. Create DATABASE
		2. Display Database
		3. Update DATABASE
		4. Search
		5. Save Database
	Enter your choice
	*/
    // create database
    create_database(f_head , head);

    //display database
    display_database(head);

    //update_database
    update_database(head , &f_head);

    //search

    char word[WORD_SIZE];
    printf("Enter the word\n");
    scanf("%s" , word);

    search(head[tolower(word[0]) % 97] , word);

    //save database

    save_database(head);































