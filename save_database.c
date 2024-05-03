#include "inverted_search.h"

void save_database( Wlist *head[])
{
    //prompt the user for file name

    char file_name[FNAME_SIZE];
    printf("Enter the file name\n");
    scanf("%s" , file_name);

    //open file
    FILE *fptr = fopen(file_name , "w");
    int i;
    for(i=0; i<27 ; i++)
    {
	if(head[i] != NULL)
	{
	    write_database(head[i] , fptr);
	}
    }
    printf("Database saved\n");
}

void write_databasefile(Wlist *head, FILE* databasefile)
{
    //........TODO........
    // #[index]  :  [word]  :  [file_count]  :  [file_name]    :   [word_count]

    Wlist *current_word = head;
    while (current_word != NULL) {
        Ltable *current_link = current_word->Tlink;
        while (current_link != NULL) {
            fprintf(databasefile, "#[%d]  :  %s  :  %d  :  %s  :  %d\n",
                    current_word->file_count, current_word->word,
                    current_link->word_count, current_link->file_name,
                    current_word->file_count);
            current_link = current_link->table_link;
        }
        current_word = current_word->link;
    }
}





