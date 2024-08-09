#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char name[20];
    int id;
    struct student *next;
} *new, *head, *tail, *temp, *i, *j;
int pos = 0;
void insert() {
    char ch;
    do {
        char name[20];
        int id;
        new = malloc(sizeof(struct student));
        printf ("Enter student's name: ");
        fflush(stdin);
        gets(name);
        printf ("Enter student's ID: ");
        scanf ("%d", &id);
        // new->name = name;
        strcpy(new->name, name);
        new->id = id;
        new->next = NULL;

        if (head == NULL) {
            head = new;
            tail = new;
        } else {
            tail->next = new;
            tail = new;
            printf ("Name: [%s], ID: [%d] inserted\n", new->name, new->id);
        }
        printf ("y -> Add another student\nn -> back\n");
        fflush(stdin);
        scanf ("%c", &ch);
    } while (ch == 'y');
}

int display() {
    int serial = 0;
    temp = head;
    if (temp == NULL) {
        printf ("List is empty!\n");
        return 0;
    };
    printf( "\t-------------------------\n"
            "\tSERIAL\tNAME\tID\n"
            "\t-------------------------\n");
    while (temp != NULL) {
        ++serial;
        printf ("\t%d\t%s\t%d\n", serial, temp->name, temp->id);
        temp = temp->next;
    }
}

int delete() {
    temp = head;
    int pos;
    if (temp == NULL) {
        printf ("List is empty!\n");
        return 0;
    }

    printf ("Enter position you want to delete: ");
    scanf ("%d", &pos);
        if (pos == 1) {
            head = head->next;
            temp->next = NULL;
            printf ("Name: [%s]\nID: [%d]\tDeleted!\n", temp->name, temp->id);
            return 0;
        }
        for (int i = 1; i < pos-1; i++)
            temp = temp->next;

        printf ("Name: [%s], ID: [%d] Deleted!\n", temp->next->name, temp->next->id);
        temp->next = temp->next->next;      // OUT OF LOOP
    }

int edit() {
    temp = head;
    int oldID, newID;
    char newName[20];

    printf ("Enter student id to start edit: ");
    scanf ("%d", &oldID);

    if (temp == NULL)
        printf ("List is empty!");
    while (temp != NULL) {
        if (temp->id == oldID) {
            printf( "\t-----------\n"
                    "\tNAME\tID\n"
                    "\t-----------\n");
            printf ("\t%s\t%d\n", temp->name, temp->id);
            printf ("Enter new name: ");
            fflush(stdin);
            gets(newName);
            strcpy(temp->name, newName);
            printf ("Enter new id: ");
            scanf ("%d", &newID);
            temp->id = newID;
            printf ("\nUPDATE SUCCESSFUL!\n");
            printf( "\t-----------\n"
                    "\tNAME\tID\n"
                    "\t-----------\n");
            printf ("\t%s\t%d\n", temp->name, temp->id);
            return 0;
        }
        temp = temp->next;
    }
    printf ("Student not found!\n");
}


int search() {
    temp = head;
    int id;
    printf ("Enter student id to search: ");
    scanf ("%d", &id);
    if (temp == NULL)
        printf ("List is empty!");
    while (temp != NULL) {
        if (temp->id == id) {
            printf( "\t-----------\n"
                    "\tNAME\tID\n"
                    "\t-----------\n");
            printf ("\t%s\t%d\n", temp->name, temp->id);
            return 0;
        }
        temp = temp->next;
    }
    printf ("Student not found!\n");
}

void sort() {
    int swapID;
    char swapName[20];
    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->id > j->id) {
                swapID = i->id;
                i->id = j->id;
                j->id = swapID;
                strcpy(swapName, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, swapName);
            }
        }
    }
    display();
}

int main() {
    char choice;
    while(1) {
    printf( "\t       MAIN MENU\n"
            "\t-------------------------\n"
            "\tSTUDENT MANAGEMENT SYSTEM\n"
            "\t-------------------------\n"
            "\t1. Insert Student Detail\n"
            "\t2. Delete Student Detail\n"
            "\t3. Edit Student Detail\n"
            "\t4. Search Student\n"
            "\t5. Sort Student by ID\n"
            "\t6. Display All Student Info\n"
            "\t7. Exit\n"
            "\t-------------------------\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: insert();
                    break;
            case 2: delete();
                    break;
            case 3: edit();
                    break;
            case 4: search();
                    break;
            case 5: sort();
                    break;
            case 6: display();
                    break;
            case 7: printf ("Exit Successful!");
                    exit (0);
            default:printf ("Invalid Choice!\n");
                    break;
        }
    };
    return 0;
}