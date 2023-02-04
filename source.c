#include<stdlib.h>
#include <stdio.h>
#include<string.h>

struct node
{
    int usn;
    char name[50];
    int presence;
    struct node* next;
};
struct node* start = NULL;

void extract_from_file()
{
    FILE* fp;
    struct node* temp=0, * ptr;
    char sname[50];
    int roll_no;
    fp = fopen("sample.txt", "r");  \\create file name sample.txt
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(0);
    }
    while (fscanf(fp, "Name: %s\t\tRoll no:%d\n", &sname, &roll_no) != EOF)
    {
        printf("\nName :%s\t\t Roll No: %d\n", sname, roll_no);
        if (start == NULL)
        {
            temp = (struct node*)malloc(sizeof(struct node));
            if (temp == NULL)
            {
                printf("\nOut of Memory Space:\n");
                exit(0);
            }
            temp->next = NULL;
            strcpy(temp->name, sname);
            temp->usn = roll_no;
            start = temp;
        }
        else
        {
            ptr = start;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            temp = (struct node*)malloc(sizeof(struct node));
            if (temp == NULL)
            {
                printf("\nOut of Memory Space:\n");
                exit(0);
            }
            temp->next = NULL;
            strcpy(temp->name, sname);
            temp->usn = roll_no;
            ptr->next = temp;
        }
    }
    fclose(fp);
    printf("\nextract successful...\n");
}

void attendence()
{
    struct node* ptr;
    if (start == NULL)
    {
        printf("!!!! please extract from file first.......!");
        return;
    }
    else
    {
        printf("\n(0 for absent ,1 for present)\n");
        ptr = start;
        while (ptr->next!= NULL)
        {
            printf("Name :%s\t\t Roll No: %d\n", ptr->name, ptr->usn);
            printf("Student with roll.no %d is :  ", ptr->usn);
            scanf("%d", &ptr->presence);
            ptr = ptr->next;
        }
        printf("Name :%s\t\t Roll No: %d\n", ptr->name, ptr->usn);
        printf("The presence of student %d is : ", ptr->usn);
        scanf("%d", &ptr->presence);
    }
}

void display()
{
    struct node* ptr;
    if (start == NULL)
    {
        printf("nList is empty:n");
        return;
    }
    else
    {
        ptr = start;
        while (ptr != NULL)
        {
            printf("Name :%s\t\t Roll No: %d\t\tPresence : %d\n", ptr->name, ptr->usn,ptr->presence);
            ptr = ptr->next;
        }
    }
}

int main()
{
    int choice;
    while (1) {

        printf("\n-----------------MENU----------------\n");
        printf("\n 1.Read from file.. \n");
        printf("\n 2.Attendance...   \n");
        printf("\n 3.Display       \n");
        printf("\n 4.Exit       \n");
        printf("\n--------------------------------------\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            extract_from_file();
            break;
        case 2:
            attendence();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        }
    }
    
    return 0;
}
