#include "inverted_search.h"

int insert_at_last(Wlist **head, data_t *data)
{
    // Create node
    Wlist *new = malloc(sizeof(Wlist));
    if (new == NULL)
    {
        return FAILURE;
    }

    // Update the node fields
    new->file_count = 1;
    strncpy(new->word, data, WORD_SIZE - 1);
    new->word[WORD_SIZE - 1] = '\0'; // Ensure null-terminated string
    new->Tlink = NULL;
    new->link = NULL;

    // Call function to update link table
    update_link_table(&new);

    // Check if Wlist is empty or not
    if (*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }

    // NON EMPTY
    Wlist *temp = *head;

    // Traverse
    while (temp->link)
    {
        temp = temp->link;
    }
    temp->link = new;
    return SUCCESS;
}

int update_link_table(Wlist **head)
{
    // Create a new link table node
    Ltable *new = malloc(sizeof(Ltable));
    if (new == NULL)
    {
        return FAILURE;
    }

    new->word_count = 1;
    strncpy(new->file_name, (*head)->word, FNAME_SIZE - 1); // Use (*head)->word instead of fname
    new->file_name[FNAME_SIZE - 1] = '\0'; // Ensure null-terminated string
    new->table_link = NULL;

    // Update the link table in the Wlist node
    (*head)->Tlink = new;

    return SUCCESS;
}
