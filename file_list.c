#include "inverted_search.h"

void file_validation_n_file_list(Flist **f_head, char *argv[])
{
    int i = 1 , empty;
    while(argv[i] != NULL)
    {
	empty = isFileEmpty(argv[i]);
	if(empty == FILE_NOTAVAILABLE)
	{
	    printf("File : %s is not available\n" , argv[i]);
	    printf("Hence we are not adding that file into file linked list\n");
	    i++;
	    continue;
	}
	else if(empty == FILE_EMPTY)
	{
	    printf("File : %s is not having contents in it.\n" , argv[i]);
	    printf("Hence we are not adding that file into file linked list\n");
	    i++;
	    continue;
	}
	else
	{
	    int ret_val = to_create_list_of_files(f_head , argv[i]);

	    if(ret_val == SUCCESS)
	    {
		printf("Successfull : Inserting the file name %s into the file linked list\n" , argv[i]);
	    }
	    else if(ret_val == REPEATATION)
	    {
		printf("This file name : %s is repeated. Do not add the files more than once\n" , argv[i]);
	    }
	    else
	    {
		printf("Failure\n");
	    }
	}
    }
}

// used to check for files availability and to check for file contents
int isFileEmpty(char *filename)
{
    FILE *fptr = fopen(filename , "r");
    if(fptr == NULL)
    {
	if(errno == ENOENT)
	{
	    return FILE_NOTAVAILABLE;
	}
    }

    fseek(fptr , 0, SEEK_END);
    if(ftell(fptr == 0))
    {
	return FILE_EMPTY;
    }
}

//to create list of files
int to_create_list_of_files(Flist **f_head, char *name)
{
   // ..........TODO............
    //Check for duplicate files
    //create a file linked list (insert_last)

	// Check for duplicate files
    Flist *current = *f_head;
    while (current != NULL)
    {
        if (strcmp(current->file_name, name) == 0)
        {
            // Duplicate file found
            return REPEATATION;
        }
        current = current->link;
    }

    // Create a new file node
    Flist *new_file = (Flist *)malloc(sizeof(Flist));
    if (new_file == NULL)
    {
        // Memory allocation failed
        return FAILURE;
    }

    // Copy the file name
    strncpy(new_file->file_name, name, FNAME_SIZE - 1);
    new_file->file_name[FNAME_SIZE - 1] = '\0'; // Ensure null-terminated string

    new_file->link = NULL;

    // If the list is empty, make the new file the head
    if (*f_head == NULL)
    {
        *f_head = new_file;
    }
    else
    {
        // Traverse the list to find the last node
        Flist *last = *f_head;
        while (last->link != NULL)
        {
            last = last->link;
        }

        // Append the new file to the end
        last->link = new_file;
    }

    return SUCCESS;
}















