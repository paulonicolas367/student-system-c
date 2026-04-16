#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    char name[80];
    int age;
    int registration;
    int course;
};

int main(){
    struct Student *st = NULL;
    int qnt = 0;
    char *courses[] = {"Medicine","Computing","Law School"};
    int option;
    printf("\nWelcome\n");
    do
    {
       
        printf("[1] Register new Student\n");
        printf("[2] List Students\n");
        printf("[3] Delete Student\n");
        printf("[0] Exit\n");
        printf("Option: ");
        scanf("%d",&option);

        if(option == 1){
            struct Student *temp = realloc(st, (qnt +1) * sizeof(struct Student));

            if(temp == NULL){
                printf("Memory error!\n");
                continue;
            }

            st = temp;

            getchar(); 

            printf("Name: ");
            fgets(st[qnt].name, 80, stdin);
            st[qnt].name[strcspn(st[qnt].name, "\n")] = 0;

            printf("Age: ");
            scanf("%d", &st[qnt].age);

            printf("Registration: ");
            scanf("%d", &st[qnt].registration);

            printf("Course:\n1-Medicine\n2-Computing\n3-Law\n");
            scanf("%d", &st[qnt].course);

            if(st[qnt].course < 1 || st[qnt].course > 3){
                printf("Invalid course!\n");
                continue;
            }

            printf("Student registered successfully!\n");
            qnt++;
        }

        else if(option == 2){
            if(qnt == 0){
                printf("No students registered.\n");
            } else {
                for(int i = 0; i < qnt; i++){
                    printf("\n--- Student %d ---\n", i+1);
                    printf("Name: %s\n", st[i].name);
                    printf("Age: %d\n", st[i].age);
                    printf("Registration: %d\n", st[i].registration);
                    printf("Course: %s\n", courses[st[i].course - 1]);
                }
            }
        }else if(option == 3){
            if(qnt == 0){
                printf("No Students to delete!");
                continue;
            }else{
                printf("Which do you want to erase?");
                for(int i = 0; i < qnt; i++){
                    printf("\n--- Student %d ---\n", i+1);
                    printf("Name: %s\n", st[i].name);
                    printf("Age: %d\n", st[i].age);
                    printf("Registration: %d\n", st[i].registration);
                    printf("Course: %s\n", courses[st[i].course - 1]);
                }
                scanf("%d",&option);
                if(option < 1 || option > qnt ){
                    printf("Invalid Option");
                    continue;
                }
                int index = option -1;

                for(int i = index; i < qnt -1; i++){
                    st[i] = st[i + 1];
                }
                qnt--;
                struct Student *temp = realloc(st, qnt * sizeof(struct Student));
                if(temp != NULL||qnt == 0){
                    st = temp;
                }
                printf("Student deleted which sucessfull!");
            }
        }

    } while (option != 0);

    free(st);
     
    return 0;
}