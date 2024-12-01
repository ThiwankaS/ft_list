#include <stdio.h>
#include <string.h>
#include "ft_list.h"

// Helper function to free a string
void del_content(void *content)
{
    free(content);
}

// Helper function to print string content
void print_content(void *content)
{
    printf("%s -> ", (char *)content);
}

// Helper function to transform content
void *to_uppercase(void *content)
{
    char *str = (char *)content;
    char *new_str = strdup(str);
    if (!new_str)
        return NULL;
    for (int i = 0; new_str[i]; i++)
        if (new_str[i] >= 'a' && new_str[i] <= 'z')
            new_str[i] -= 32;
    return new_str;
}

int main()
{
    // 1. Create a new list with ft_lstnew
    t_list *list = ft_lstnew(strdup("first"));
    if (!list)
    {
        printf("Error: Failed to allocate memory for the list.\n");
        return 1;
    }

    // 2. Add elements to the front and back
    ft_lstadd_front(&list, ft_lstnew(strdup("zero")));
    ft_lstadd_back(&list, ft_lstnew(strdup("second")));
    ft_lstadd_back(&list, ft_lstnew(strdup("third")));

    // 3. Print the list
    printf("Original list: ");
    ft_lstiter(list, print_content);
    printf("NULL\n");

    // 4. Test ft_lstsize
    printf("List size: %d\n", ft_lstsize(list));

    // 5. Test ft_lstlast
    t_list *last = ft_lstlast(list);
    printf("Last element: %s\n", (char *)last->content);

    // 6. Test ft_lstmap (create a new list with uppercase content)
    t_list *mapped_list = ft_lstmap(list, to_uppercase, del_content);
    if (!mapped_list)
    {
        printf("Error: Failed to map the list.\n");
        ft_lstclear(&list, del_content);
        return 1;
    }

    printf("Mapped list: ");
    ft_lstiter(mapped_list, print_content);
    printf("NULL\n");

    // 7. Clear both lists
    ft_lstclear(&list, del_content);
    ft_lstclear(&mapped_list, del_content);

    printf("Both lists cleared successfully.\n");
    return 0;
}
