#include "inverted_search.h"

char *fname;
void create_database(Flist *f_head, Wlist *head[])
{
    //traverse through the file list

    while(f_head)
    {
	read_datafile(f_head , head , f_head->file_name);
	f_head = f_head->link;
    }
}
//read contents of file 
Wlist * read_datafile(Flist *file, Wlist *head[], char *filename)
{

    int flag = 1;
    fname = filename;
    //open file in read mode
    FILE *fptr = fopen(filename ,"r");
    
    //declare an array to store words
    char word[WORD_SIZE];

    while(fscanf(fptr , "%s" , word) != EOF)
    {
	//index

	int index = tolower(word[0]) % 97;

	//other than alphabets 
	if(!(index >= 0 && index <= 25))
	{
	    index = 26;
	}
	//check whether words are repeated or not
	if(head != NULL)
	{
	    Wlist *temp = head[index];

	   //compare the words at each node with new word
	    while(temp)
	    {
		if(!strcmp(temp->word , word))
		{
		    update_word_count(&temp , filename);
		    flag = 0;
		    break;
		}
		temp = temp->link;
	    }

	    if(flag == 1)
	    {
		//fun called only when words are not repeated 
		insert_at_last(&head[index] , word);
	    }
	}
    }
}

int update_word_count(Wlist ** head, char * file_name)
{
    //...............TODO..............
    //check whether words are repeated in same file or not
    //if same file --> increment word_count
   //if different files -----> increment file_count , create new Ltable 
   Wlist *current = *head;

    // Traverse the word list
    while (current != NULL)
    {
        // Check if the word is found in the current node
        if (strcmp(current->word, file_name) == 0)
        {
            // Word found in the same file, increment word count
            current->file_count++;
            return SUCCESS;
        }

        // Move to the next node
        current = current->link;
    }

    // Word not found in the current list, create a new node
    Wlist *new_word_node = (Wlist *)malloc(sizeof(Wlist));
    if (new_word_node == NULL)
    {
        perror("Memory allocation error");
        return FAILURE;
    }

    // Initialize the new node
    strcpy(new_word_node->word, file_name);
    new_word_node->file_count = 1;
    new_word_node->Tlink = NULL;
    new_word_node->link = NULL;

    // Add the new node to the end of the list
    if (*head == NULL)
    {
        // The list is empty, make the new node the head
        *head = new_word_node;
    }
    else
    {
        // Traverse to the end of the list
        current = *head;
        while (current->link != NULL)
        {
            current = current->link;
        }

        // Add the new node to the end
        current->link = new_word_node;
    }

    return SUCCESS;
} 











