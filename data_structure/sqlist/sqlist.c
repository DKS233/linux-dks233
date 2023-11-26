#include "sqlist.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @description: 顺序表创建方式1
 * @return {顺序表指针}
 */
sqlist *sqlist_create_method_1()
{
    sqlist *list;
    list = malloc(sizeof(*list));
    if (list == NULL)
    {
        return NULL;
    }
    list->last = -1;
    return list;
}

/**
 * @description: 顺序表创建方式2
 * @param {sqlist} * 顺序表二级指针
 * @return {无返回值}
 */
void sqlist_create_method_2(sqlist **sqlist_ptr_ptr)
{
    *sqlist_ptr_ptr = malloc(sizeof(**sqlist_ptr_ptr));
    if (*sqlist_ptr_ptr == NULL)
    {
        return;
    }
    (*sqlist_ptr_ptr)->last = -1;
    return;
}

/**
 * @description: 向顺序表中插入元素
 * @param {sqlist} *sqlist 顺序表指针
 * @param {int} index 待插入的位置
 * @param {int} *data_ptr 待插入元素的指针
 * @return {插入成功返回0}
 */
int sqlist_insert(sqlist *sqlist, int index, int *data_ptr)
{
    if (index < 0 || index > sqlist->last + 1)
    {
        return -1;
    }
    if (sqlist->last == DATASIZE - 1)
    {
        return -2;
    }
    // index及其之后的元素依次后移
    for (int j = sqlist->last; index <= j; j--)
    {
        sqlist->data[j + 1] = sqlist->data[j];
    }
    sqlist->data[index] = *data_ptr;
    sqlist->last++;
    return 0;
}

/**
 * @description: 从顺序表中删除元素
 * @param {sqlist} *sqlist 顺序表指针
 * @param {int} index 待删除的位置
 * @return {删除成功返回0}
 */
int sqlist_delete(sqlist *sqlist, int index)
{
    if (sqlist_isempty(sqlist))
    {
        return -1;
    }
    if (index < 0 || index > sqlist->last)
    {
        return -2;
    }
    // index之后的元素依次前移
    for (int j = index + 1; j <= sqlist->last; j++)
    {
        sqlist->data[j - 1] = sqlist->data[j];
    }
    sqlist->last--;
    return 0;
}

/**
 * @description: 从顺序表中查找元素，查找成功返回索引
 * @param {sqlist} *sqlist 顺序表指针
 * @param {int} *data_ptr 数据指针
 * @return {查找成功返回索引}
 */
int sqlist_find(sqlist *sqlist, int *data_ptr)
{
    if (sqlist_isempty(sqlist))
    {
        return -1;
    }
    for (int index = 0; index <= sqlist->last; index++)
    {
        if (sqlist->data[index] == *data_ptr)
        {
            return index;
        }
    }
    return -2;
}

/**
 * @description: 判断顺序表是否为空
 * @param {sqlist} *sqlist 顺序表指针
 * @return {为空返回1, 否则返回0}
 */
int sqlist_isempty(sqlist *sqlist)
{
    return sqlist->last == -1 ? 1 : 0;
}

/**
 * @description: 打印顺序表中的元素
 * @param {sqlist} *sqlist 顺序表指针
 * @return {无返回值}
 */
void sqlist_display(sqlist *sqlist)
{
    if (sqlist->last == -1)
    {
        return;
    }
    for (int index = 0; index <= sqlist->last; index++)
    {
        printf("%d ", sqlist->data[index]);
    }
    printf("\n");
    return;
}

/**
 * @description: 销毁顺序表
 * @param {sqlist} *sqlist 顺序表指针
 * @return {销毁成功返回0}
 */
int sqlist_destroy(sqlist *sqlist)
{
    free(sqlist);
    return 0;
}

/**
 * @description: 顺序表合并，讲sqlist2合并到sqlist1末尾
 * @param {sqlist} *sqlist1 顺序表1指针
 * @param {sqlist} *sqlist2 顺序表2指针
 * @return {合并成功返回0}
 */
int sqlist_union(sqlist *sqlist1, sqlist *sqlist2)
{
    if (sqlist1->last == DATASIZE - 1)
    {
        return -1;
    }
    for (int index = 0; index <= sqlist2->last; index++)
    {
        if (sqlist_find(sqlist1, &sqlist2->data[index]) < 0)
        {
            if (sqlist_insert(sqlist1, sqlist1->last + 1, &sqlist2->data[index]) != 0)
            {
                fprintf(stderr, "sqlist_union union failed\n");
                exit(1);
            }
        }
    }
    return 0;
}