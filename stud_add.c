#include"as_header.h"

void stud_add(stu **hptr)
{
        stu *a=malloc(sizeof(stu));
        printf("Enter student name :\t");
        scanf(" %s",a->name);
        printf("Enter student marks :\t");
        scanf("%f",&a->marks);
        a->rollno=roll_allocate();
        a->next=0;
        studentcount++;
        if(*hptr==0)
        {
                *hptr=a;
                printf("%ss",(*hptr)->name);
                return;
        }
        stu *loop=*hptr;
        while(loop->next)
        {loop=loop->next;}
        loop->next=a;
        printf("%s",loop->next->name);
}
