#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
struct DailyCost
{
    int dd;
    int mm;
    int yy;
    char CostType[100];
    int CostPrice;
    char CostDescription[200];

} Day;
FILE *fp;
void add_dailycost();
void display();
void mainmenue();
void clear_data();
int main()
{

    int j;
    fp = fopen("fileE.txt", "a+");
    rewind(fp); // /home/mohit/projects/c/gedit_Dailyost/TextFiles/fileE.txt
    mainmenue();
    return 0;
}
void mainmenue()
{
    struct DailyCost day1;
    int j;
    printf("\\*#*************************Welcome To Daily Cost************************#*//");
    printf("\nEnter 1 to add Daily cost || enter 2 Display Daily Cost|| enter 3 Clear ALL Data || enter 4 Exit\n");
    if (fp == NULL)
    {
        printf("\nNo Daily Cost written Yet\n");
    }
    scanf("%d", &j);
    switch (j)
    {
    case 1:
        add_dailycost(&day1);
        break;
    case 2:
        display(&day1);
        break;
    case 3:
        clear_data(&day1);
        break;
    case 4:
        printf("\nThank you");
        fclose(fp);
        exit(0);
        break;
    }
}
void add_dailycost(struct DailyCost *Day)
{
    fseek(fp, 0L, SEEK_END);
    int j;
    printf("Enter Day = ");
    scanf("%d", &Day->dd);
    printf("Enter Month = ");
    scanf("%d", &Day->mm);
    printf("Enter Year = ");
    scanf("%d", &Day->yy);
    printf("Enter Cost Type = ");
    scanf("%s", Day->CostType);
    printf("Enter Cost Price = ");
    scanf("%d", &Day->CostPrice);
    printf("Enter Cost Description = ");
    scanf("%s", Day->CostDescription);

    fwrite(Day, sizeof(struct DailyCost), 1, fp);
    printf("If menmenue press 1 and exit press 0 = ");
    scanf("%d", &j);
    if (j == 1)
    {
        mainmenue();
    }
    else
    {
        printf("\nThank you");
        fclose(fp);
        exit(0);
    }
}
void display(struct DailyCost *Day)
{
    rewind(fp);
    while (fread(Day, sizeof(struct DailyCost), 1, fp))
    {
        printf("Day =   %d\n", Day->dd);
        printf("Month =   %d\n", Day->mm);
        printf("Year =   %d\n", Day->yy);
        printf("Cost Type =   %s\n", Day->CostType);
        printf("Cost Price =   Rs.%d\n", Day->CostPrice);
        printf("Cost Description =   %s\n", Day->CostDescription);
    }
    fclose(fp);
}
void clear_data(struct DailyCost *Day)
{
    int i, rmv;
    fp = fopen("fileE.txt", "wb+");
    rewind(fp); // /home/mohit/projects/c/gedit_Dailyost/TextFiles/fileE.txt
    fclose(fp);
    rmv = remove("fileE.txt");
    printf("\nAll Daily Cost Data is Cleared\n");
    printf("\nIf you like to continue press 1 and if exit press 0\n");
    scanf("%d", &i);
    if (i == 1)
    {
        mainmenue();
    }
    else
    {
        printf("\nThank you\n");
        fclose(fp);
        exit(0);
    }
}
