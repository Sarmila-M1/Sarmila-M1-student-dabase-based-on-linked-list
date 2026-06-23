#include"as_header.h"

void stud_mod(stu **hptr)
{
	if(*hptr==0)
	{
		printf("no student record found...\n");
		return;
	}
        printf("Enter which record to search for modification\nR/r : to search a rollno\nN/n : to search a name\np/p : percentage based\n");
        char ch;
        stu *search=*hptr;
        scanf(" %c",&ch);
        if((ch=='R')||(ch=='r'))
        {
                printf("enter the roll number : ");
                int rn;
                scanf("%d",&rn);
                if(((*hptr)->rollno)==rn)
                {
                        printf("\nEnter the modified name : ");
                        scanf("%s",(*hptr)->name);
                        printf("\nEnter the modified marks : ");
                        scanf("%f",&((*hptr)->marks));
                        return;
                }
                while(search)
                {
                        if((search->rollno)==rn)
                        {
                                printf("\nEnter the modified name : ");
                                scanf("%s",search->name);
                                printf("\nEnter the modified marks : ");
                                scanf("%f",&(search->marks));
                                return;
                        }
			search=search->next;
                }
                printf("\nNo such roll number found...\n");
                return;
        }
	 else if((ch=='N')||(ch=='n'))
        {
                printf("enter the name : ");
                char name[20];
                int count=0;
                scanf("%s",name);
                while(search)
                {
                        if(strcmp((search->name),name)==0)
                                count++;
			search=search->next;
                }
		search=*hptr;
                if(count==0)
                {
                        printf("no such name found\n");
                        return;
                }
                if(count==1)
                {
                        if(strcmp(((*hptr)->name),name)==0)
                        {
                                printf("\nEnter the modified name : ");
                                scanf("%s",(*hptr)->name);
                                printf("\nEnter the modified marks : ");
                                scanf("%f",&((*hptr)->marks));
                                return;
                        }
                        while(search)
                        {
                               if(strcmp((search->name),name)==0)
                               {
                                       printf("\nEnter the modified name : ");
                                       scanf("%s",search->name);
                                       printf("\nEnter the modified marks : ");
                                       scanf("%f",&(search->marks));
                                       return;
                               }
			       search=search->next;
                        }
                }

		  if(count>1)
                {
                        printf("\n%d records available with same name...\n",count);
                        printf("Enter the roll number to modify : ");
                        int rn;
                        scanf("%d",&rn);
                        if((((*hptr)->rollno)==rn)&&(strcmp(((*hptr)->name),name)==0))
                        {
                            printf("\nEnter the modified name : ");
                            scanf("%s",(*hptr)->name);
                            printf("\nEnter the modified marks : ");
                            scanf("%f",&((*hptr)->marks));
                            return;
                        }
                        while(search)
                        {
                            if(((search->rollno)==rn)&&(strcmp((search->name),name)==0))
                            {
                                printf("\nEnter the modified name : ");
                                scanf("%s",search->name);
                                printf("\nEnter the modified marks : ");
                                scanf("%f",&(search->marks));
                                return;
                            }
			    search=search->next;
                         }
                printf("\nNo such roll number found associate with the given name...\n");
                return;
                }

        }
        else if((ch=='p')||(ch=='P'))
        {
                printf("enter the marks : ");
                float marks;
                int count=0;
                scanf("%f",&marks);
                while(search)
		{
                        if((search->marks)==marks)
                                count++;
			search=search->next;
                }
		search=*hptr;
                if(count==0)
                {
                        printf("no such mark found\n");
                        return;
                }
                if(count==1)
                {
                        if(((*hptr)->marks)==marks)
                        {
                                printf("\nEnter the modified name : ");
                                scanf("%s",(*hptr)->name);
                                printf("\nEnter the modified marks : ");
                                scanf("%f",&((*hptr)->marks));
                                return;
                        }
                        while(search)
                        {
                               if((search->marks)==marks)
                               {
                                       printf("\nEnter the modified name : ");
                                       scanf("%s",search->name);
                                       printf("\nEnter the modified marks : ");
                                       scanf("%f",&(search->marks));
                                       return;
                               }
			       search=search->next;
                        }
                }
                if(count>1)
                        {
                        printf("\n%d records available with same name...\n",count);
                        printf("Enter the roll number to modify : ");
                        int rn;
                        scanf("%d",&rn);
			 if((((*hptr)->rollno)==rn)&&(((*hptr)->marks)==marks))
                        {
                            printf("\nEnter the modified name : ");
                            scanf("%s",(*hptr)->name);
                            printf("\nEnter the modified marks : ");
                            scanf("%f",&((*hptr)->marks));
                            return;
                        }
                        while(search)
                        {
                            if(((search->rollno)==rn)&&((search->marks)==marks))
                            {
                                printf("\nEnter the modified name : ");
                                scanf("%s",search->name);
                                printf("\nEnter the modified marks : ");
                                scanf("%f",&search->marks);
                                return;
                            }
			    search=search->next;
                         }
                         printf("\nNo such roll number found with the given percentage...\n");
                         return;
                         }
        }
        else
        {
                printf("invalid option...\n");
                return;
        }
}
