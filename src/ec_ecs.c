#include <stdio.h>
#include "ec_ecs.h"




Entity *
New_Entity (int n, int max)
{
    Entity *entity_list = (Entity *) malloc (sizeof(Entity) * n);
    entity_list->n = n;
    entity_list->i = Get_Entity_i();
    ec_entity_i += n;
    entity_list->next = NULL;
    ec_entity_max += max;

    return entity_list;
}


int
Get_Entity_i ()
{
    return ec_entity_i;
}


void
EC_Entity_Reset ()
{
}


void print_list_for(Entity * head) {
    Entity * current = head;

    while (current != NULL) {
        printf("%d\n", current->i);
        current = current->next;
    }
}


void push(Entity * head, int val) {
    Entity * current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    /* now we can add a new variable */
    current->next = (Entity *) malloc(sizeof(Entity));
    current->next->i = val;
    current->next->next = NULL;
}


void push_begin(Entity ** head, int val) {
    Entity * new_node;
    new_node = (Entity *) malloc(sizeof(Entity));

    new_node->i = val;
    new_node->next = *head;
    *head = new_node;
}


int pop(Entity ** head) {
    int retval = -1;
    Entity * next_node = NULL;

    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->i;
    free(*head);
    *head = next_node;

    return retval;
}


int remove_last(Entity * head) {
    int retval = 0;
    /* if there is only one item in the list, remove it */
    if (head->next == NULL) {
        retval = head->i;
        free(head);
        return retval;
    }

    /* get to the second to last node in the list */
    Entity * current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    /* now current points to the second to last item of the list, so let's remove current->next */
    retval = current->next->i;
    free(current->next);
    current->next = NULL;
    return retval;

}


int remove_by_index(Entity ** head, int n) {
    int i = 0;
    int retval = -1;
    Entity * current = *head;
    Entity * temp_node = NULL;

    if (n == 0) {
        return pop(head);
    }

    for (i = 0; i < n-1; i++) {
        if (current->next == NULL) {
            return -1;
        }
        current = current->next;
    }

    if (current->next == NULL) {
        return -1;
    }

    temp_node = current->next;
    retval = temp_node->i;
    current->next = temp_node->next;
    free(temp_node);

    return retval;

}

/* void */
/* Entity_Change_Amount (Entity *entity, int n) */
/* { */
/*     int remaining_entity_amount = entity->n + n; */

/*     if (remaining_entity_amount <= entity->max && remaining_entity_amount >= 0) */
/*     { */
/*         entity->n = remaining_entity_amount; */
/*     } */
/*     else */
/*     { */
/*         if (remaining_entity_amount > 0) */
/*             printf ("Warning: changing entity amount %d is greater than entity->max", remaining_entity_amount); */
/*         else */
/*             printf ("Warning: changing entity amount %d is lower than 0", remaining_entity_amount); */
/*     } */
/* } */
