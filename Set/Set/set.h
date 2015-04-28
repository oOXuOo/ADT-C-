/*
 * filename: set.h
 * author: zhm
 * date: 2013-01-06
 */
#ifndef SET_H
#define SET_H

#include <stdlib.h>
#include "list.h"

typedef List Set; //将链表经typedef重命名为Set集合类型


/* public interface */
void set_init(Set *set, int (*match)(const void *key1, const void *key2), 
        void (*destroy)(void *data)); //集合初始化操作
#define set_destroy list_destroy      //集合销毁,重命名链表的销毁操作
int set_insert(Set *set, const void *data); //将某一数据插入至集合中
int set_remove(Set *set, void **data);  //从集合中移除某一数据
int set_union(Set *setu, const Set *set1, const Set *set2);  //集合的并操作，即setu = set1 并 set2
int set_difference(Set *setd, const Set *set1, const Set *set2); //集合的差操作, 即setd = set1-set2
int set_intersection(Set *seti, const Set *set1, const Set *set2); //集合的交操作：即seti = set1 交 set2
int set_is_member(const Set *set, const void *data); //判断某一数据是否在集合中
int set_is_subset(const Set *set1, const Set *set2); //集合set1是否为set2的子集，是则返1,否则0
int set_is_equal(const Set *set1, const Set *set2);  //set1是否等于set2，是否返1，否则0

#define set_size(set) ((set)->size)  //返回集合中元数据大小

#endif
