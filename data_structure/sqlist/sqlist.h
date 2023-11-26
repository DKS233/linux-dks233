#ifndef SQLIST_H__
#define SQLIST_H__
#define DATASIZE 1024

typedef struct sqlist
{
    int last; // 最后一个有效元素位置
    int data[DATASIZE];
} sqlist;

/**
 * @description: 顺序表创建方式1
 * @return {顺序表指针}
 */
sqlist *sqlist_create_method_1();

/**
 * @description: 顺序表创建方式2
 * @param {sqlist} * 顺序表二级指针
 * @return {无返回值}
 */
void sqlist_create_method_2(sqlist **sqlist_ptr_ptr);

/**
 * @description: 向顺序表中插入元素
 * @param {sqlist} *sqlist 顺序表指针
 * @param {int} index 待插入的位置
 * @param {int} *data_ptr 待插入元素的指针
 * @return {插入成功返回0}
 */
int sqlist_insert(sqlist *sqlist, int index, int *data_ptr);

/**
 * @description: 从顺序表中删除元素
 * @param {sqlist} *sqlist 顺序表指针
 * @param {int} index 待删除的位置
 * @return {删除成功返回0}
 */
int sqlist_delete(sqlist *sqlist, int index);

/**
 * @description: 从顺序表中查找元素，查找成功返回索引
 * @param {sqlist} *sqlist 顺序表指针
 * @param {int} *data_ptr 数据指针
 * @return {查找成功返回索引}
 */
int sqlist_find(sqlist *sqlist, int *data_ptr);

/**
 * @description: 判断顺序表是否为空
 * @param {sqlist} *sqlist 顺序表指针
 * @return {为空返回1, 否则返回0}
 */
int sqlist_isempty(sqlist *sqlist);

/**
 * @description: 打印顺序表中的元素
 * @param {sqlist} *sqlist 顺序表指针
 * @return {无返回值}
 */
void sqlist_display(sqlist *sqlist);

/**
 * @description: 销毁顺序表
 * @param {sqlist} *sqlist 顺序表指针
 * @return {销毁成功返回0}
 */
int sqlist_destroy(sqlist *sqlist);

/**
 * @description: 顺序表合并，讲sqlist2合并到sqlist1末尾
 * @param {sqlist} *sqlist1 顺序表1指针
 * @param {sqlist} *sqlist2 顺序表2指针
 * @return {合并成功返回0}
 */
int sqlist_union(sqlist *sqlist1, sqlist *sqlist2);

#endif