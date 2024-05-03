#include "inverted_search.h"

 void update_database( Wlist *head[], Flist **f_head)
{
char file_name[FNAME_SIZE];

    // Prompt the user
    printf("Enter the new file name for updating the database\n");
    scanf("%s", file_name);

    // Validate the file name
    // ........TODO......

    Flist *current_file = *f_head;

    while (current_file != NULL)
    {
        if (!(strcmp(current_file->file_name, file_name)))
        {
            create_database(current_file, head);
        }
        current_file = current_file->link;
    }
}


