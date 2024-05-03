#include "inverted_search.h"

void search( Wlist *head, char *word)
{
// Check if the list is empty
    if (head == NULL)
    {
        printf("Search is not possible, list is empty\n");
        return;
    }

    // Traverse the list
    while (head)
    {
        // Compare the search word with the available words
        if (!(strcmp(head->word, word)))
        {
            printf("Word %s is present in %d file/s\n", word, head->file_count);
            Ltable *Thead = head->Tlink;

            while (Thead)
            {
                printf("In file: %s   %d time/s\n", Thead->file_name, Thead->word_count);
                Thead = Thead->table_link;
            }

            printf("\n");
            return;
        }

        head = head->link;
    }

    printf("Search word is not present in the list\n");
}






