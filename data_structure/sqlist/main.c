#include <stdio.h>
#include <stdlib.h>
#include "sqlist.h"

void sqlist_test_method_1()
{
    sqlist *list;
    list = sqlist_create_method_1();
    if (list == NULL)
    {
        fprintf(stderr, "sqlist_test_method_1 create failed\n");
        exit(1);
    }
    int data[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < sizeof(data) / sizeof(*data); i++)
    {
        if (sqlist_insert(list, i, &data[i]) != 0)
        {
            fprintf(stderr, "sqlist_test_method_1 insert failed\n");
            exit(1);
        }
    }
    sqlist_display(list);
    sqlist_delete(list, 0);
    sqlist_display(list);
    sqlist *list2 = sqlist_create_method_1();
    int data2[5] = {2, 4, 6, 7, 1};
    for (int i = 0; i < sizeof(data2) / sizeof(*data2); i++)
    {
        sqlist_insert(list2, i, &data2[i]);
    }
    sqlist_union(list, list2);
    sqlist_display(list);
    sqlist_destroy(list);
    sqlist_destroy(list2);
}

void sqlist_test_method_2()
{
    sqlist *list;
    sqlist_create_method_2(&list);
    if (list == NULL)
    {
        fprintf(stderr, "sqlist_test_method_1 create failed\n");
        exit(1);
    }
    int data[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < sizeof(data) / sizeof(*data); i++)
    {
        if (sqlist_insert(list, i, &data[i]) != 0)
        {
            fprintf(stderr, "sqlist_test_method_1 insert failed\n");
            exit(1);
        }
    }
    sqlist_display(list);
    sqlist_delete(list, 0);
    sqlist_display(list);
    sqlist *list2;
    sqlist_create_method_2(&list2);
    int data2[5] = {2, 4, 6, 7, 1};
    for (int i = 0; i < sizeof(data2) / sizeof(*data2); i++)
    {
        sqlist_insert(list2, i, &data2[i]);
    }
    sqlist_union(list, list2);
    sqlist_display(list);
    sqlist_destroy(list);
    sqlist_destroy(list2);
}

int main()
{
    sqlist_test_method_1();
    sqlist_test_method_2();
    return 0;
}