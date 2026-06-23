#include"as_header.h"

void stud_reverse(stu **hptr)
{
	if(*hptr==0)
	{
		printf("No student records found..\n");
		return;
	}
	stu **list=malloc(sizeof(stu*)*(studentcount));
	stu *tem=*hptr;
	int i=0;
	while(tem)
	{
		list[i++]=tem;
		printf("%s",list[i-1]->name);
		tem=tem->next;
	}
	(*hptr)->next=0;
	*hptr=(list[i-1]);
	//(*hptr)->next=0;
	//tem=*hptr;
	//*hptr=(list[i-1]);
	tem=*hptr;
	for(i=i-2;i>=0;i--)
	{
		tem->next=list[i];
		tem=tem->next;
	}
}

void stud_del_allnode(stu **hptr)
{
	stu *tem;
	while(*hptr)
	{
		tem=(*hptr)->next;
		free(*hptr);
		*hptr=tem;
	}
	return;
}
void stud_sort(stu *pt)
{
	if(pt==0)
	{
		printf("no student record found..\n");
		return;
	}
	printf("Enter\nN/n : sort with name\nP/P : sort with percentage\n");
	char ch;
	scanf(" %c",&ch);
	stu *fi=pt;
	stu *se;
	stu tem;
	if((ch=='n')||(ch=='N'))
	{
		while(fi)
		{
			se=fi->next;
			while(se)
			{if(strcmp((fi->name),(se->name))>0)
				{
					tem=*se;
					*se=*fi;
					*fi=tem;
					tem.next=se->next;
					se->next=fi->next;
					fi->next=tem.next;
					
				}
			 se=se->next;
			}
			fi=fi->next;
		}
	
	}
	else if((ch=='p')||(ch=='P'))
	{
		 while(fi)
                {
                        se=fi->next;
                        while(se)
                        {if((fi->marks)>(se->marks))
                                {
                                        tem=*se;
                                        *se=*fi;
                                        *fi=tem;
					tem.next=se->next;
                                        se->next=fi->next;
                                        fi->next=tem.next;

                                }
                         se=se->next;
                        }
                        fi=fi->next;
                }
	}
	else
	{
		printf("you entered an invalid choise...\n");
		return;
	}
}
  
void stud_save(stu *pt)
{
	printf("Enter\nS/s : save and exit\nE/e : exit without saving\n");
	char ch;
	scanf(" %c",&ch);
	if((ch=='e')||(ch=='E'))
	{
		printf("exit withou saving...\n");
		return;
	}
	else if((ch=='s')||(ch=='S'))
	{
	if(pt==0)
	{
		printf("no student record found...\n");
		return;
	}
	FILE *fp=fopen("student.dat","w+");
	fprintf(fp,"%d %d\n",studentcount,meall);
	for(int i=0;i<meall;i++)
	{fprintf(fp,"%d ",roll[i]);}
	fprintf(fp,"\n");
	while(pt)
	{
		fprintf(fp,"%d %s %f\n",pt->rollno,pt->name,pt->marks);
		pt=pt->next;
	}
	fclose(fp);
	return;
	}
	else
	{
		printf("You entered an invalid choise...\n");
		return;
	}
}
void stu_updatefile(stu **hptr)
{

        FILE *fp=fopen("student.dat","r");
	if(fp==0)
		return;
        fscanf(fp,"%d %d\n",&studentcount,&meall);
	roll=malloc(sizeof(int*)*meall);
        for(int i=0;i<meall;i++)
        {
		fscanf(fp,"%d ",&(roll[i]));
	}
        fscanf(fp,"\n");
	*hptr=malloc(sizeof(stu));
        fscanf(fp,"%d %s %f\n",&(*hptr)->rollno,(*hptr)->name,&(*hptr)->marks);
	stu *a=*hptr;
        for(int i=1;i<studentcount;i++)
	{
		a->next=malloc(sizeof(stu));
		a=a->next;
		fscanf(fp,"%d %s %f\n",&(a->rollno),a->name,&a->marks);
        }
	a->next=0;
        fclose(fp);
}


	
