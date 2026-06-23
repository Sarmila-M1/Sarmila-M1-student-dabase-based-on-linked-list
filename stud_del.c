#include"as_header.h"
void stud_del(stu **hptr)
{
        if(*hptr==0)
        {
                printf("No student record found\n");
                return;
        }
        printf("R/r : enter roll to del\nN/n : enter namae to del\n");
        char ch;
        scanf(" %c",&ch);
        if((ch=='R')||(ch=='r'))
        {
                int rn;
                printf("Enter roll number\n");
                scanf("%d",&rn);
                stu *search=*hptr;
                stu *copy=*hptr;
                while(search)
                {
                        if((search->rollno)==rn)
                        {
                                studentcount--;
                                roll[rn-1]=0;
                                if(*hptr==search)
                                {
                                        stu * del=search;
                                        *hptr=del->next;
                                        free(del);
                                        printf("deleted successfully...\n");
                                        return;
                                }
                                stu *del=search;
                                copy->next=search->next;
                                free(del);
                                printf("deleted successfully...\n");
                                return;
                        } copy=search;
                        search=search->next;
                }
                printf("No such roll number found...\n");
        }
        else if((ch=='n')||(ch=='N'))
        {
                int count=0;
                printf("enter the name\n");
                char name[20];
                stu * del=*hptr;
                stu * copy=*hptr;
                scanf("%s",name);
                stu * ptr=*hptr;
                while(ptr)
                {
                        if(strcmp((ptr->name),name)==0)
                        {
                                printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
                                count++;
                                del=ptr;
                        }
                        if(count==0)
                                copy=ptr;
                        ptr=ptr->next;
                }
                if(count==0)
                {
                        printf("No such student name found...\n");
                        return;
                }
                else if(count==1)
                {
                        studentcount--;
                        roll[(del->rollno)-1]=0;
                        printf("deleted successfully...\n");
			 if(del==*hptr)
                        {
                                *hptr=del->next;
                                free(del);
                                return;
                        }
                        copy->next=del->next;
                        free(del);
                        return;
                }
                else
                {
                        printf("Many student name are same with the given name so try to delete using roll number\n");
                        return;
                }
        }
        else
        {
                printf("You entered an in valid choice\n");
                return;
        }
}

