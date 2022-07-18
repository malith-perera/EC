
    if (var != NULL)                                        \
    {                                                       \
        if (var != list->first)                             \
        {                                                   \
            if (var != list->last)                          \
            {                                               \
                var->previous->next = var->next;            \
                free (var);                                 \
            }                                               \
            else                                            \
            {                                               \
                list->last = var->previous;                 \
                var->previous->next = NULL;                 \
                free (var);                                 \
            }                                               \
        }                                                   \
        else                                                \
        {                                                   \
            if (var != list->last)                          \
            {                                               \
                list->first = var->next;                    \
                free (var);                                 \
            }                                               \
            else                                            \
            {                                               \
                list->first = NULL;                         \
                list->last = NULL;                          \
                free (var);                                 \
            }                                               \
        }                                                   \
    }                                                       \
