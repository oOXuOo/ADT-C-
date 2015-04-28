/*
 * filename: main.c
 * author:zhm
 * date: 2012-12-06
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "list.h"
#include "set.h"

/* destroy */
void destroy(void *data)
{
    printf("in destroy\n");
    free(data);
    return;
}

/* compare */
int compare(const void *key1, const void *key2)
{
    if( *(int *)key1 == *(int *)key2 )
    {
        return 1;
    }

    return 0;
}

/* main */
int main(int argc, char **argv)
{
    int ret, i;
    int *int_ptr = NULL;
    ListElmt *member = NULL;
    /* set1 = {1,2,3,4,5}
     * set2 = {1,2,3,4,5,8,9}
     */
    Set set1, set2;
    Set setu, setd, seti; //union, difference, intersection

    /* initialize sets:set1,set2 */
    set_init(&set1, compare, destroy);
    set_init(&set2, compare, destroy);

    /* insert the data:1-5 into set1 and set2*/
    for( i = 1; i <= 5; i++ )
    {
        int_ptr = NULL;
        int_ptr = (int *)malloc(sizeof(int));
        if( int_ptr == NULL )
            return -1;

        *int_ptr = i;
        set_insert(&set1, (void *)int_ptr);
        set_insert(&set2, (void *)int_ptr);
    }

    /* insert the data: 8,9 into set2 */
    for( i = 1; i <= 2; i++ )
    {
        int_ptr = NULL;
        int_ptr = (int *)malloc(sizeof(int));
        if( int_ptr == NULL )
            return -1;
        *int_ptr = 7+i;
        set_insert(&set2, (void *)int_ptr);
    }

    /* display the size for the sets :set1, set2 */
    printf("size of set1 = %d\n", set_size(&set1));
    printf("size of set2 = %d\n\n", set_size(&set2));
    
    ret = set_is_subset(&set1, &set2);
    if( ret == 1 )
    {
        printf("set1 belong to set2\n");
    }
    
    ret = set_is_equal(&set1, &set2);
    if( ret != 0 )
    {
        printf("set1 not equal set2\n");
    }

    ret = set_union(&setu, &set1, &set2);
    if( ret != 0 )
        return -1;
    
    printf("setu = {");
    for( member = list_head(&setu); member != NULL; member = list_next(member) )
    {
        printf("%d ,", *(int*)list_data(member));    
    }
    printf("}\n");

    ret = set_intersection(&seti, &set1, &set2);
    if( ret != 0 )
        return -1;
    
    printf("seti = {");
    for( member = list_head(&seti); member != NULL; member = list_next(member) )
    {
        printf("%d ,", *(int*)list_data(member));    
    }
    printf("}\n");

    ret = set_difference(&setd, &set1, &set2);
    if( ret != 0 )
        return -1;
       
    printf("setd = {");
    for( member = list_head(&setd); member != NULL; member = list_next(member) )
    {
        printf("%d ,", *(int*)list_data(member));    
    }
    printf("}\n");
    
    set_destroy(&setu);
    set_destroy(&seti);
    set_destroy(&setd);
    set_destroy(&set1);
    set_destroy(&set2);
    return 0;
}