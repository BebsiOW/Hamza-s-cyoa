#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Page {
    char fileName[40];
    char option1[40];
    char option2[40];
};

void openPage(struct Page page);

int main()
{
    printf("Welcome to Hamza's Choose Your Own Adventure!\nYou will read through the story and select the corresponding number to the decision you want to make. Have fun!\n\n");

    struct Page page;
    int state = 1;
    char c;

    strcpy(page.fileName, "Story/1.txt");

    while(1)
    {
        
        openPage(page);

        printf("\nChoice (a/b): ");
        scanf(" %c", &c);
        printf("\n");

        if (state == 1 && c == 'a') {strcpy(page.fileName, "Story/2.txt"); state = 2;}
        else if (state == 1 && c == 'b') {strcpy(page.fileName, "Story/3.txt"); state = 3;}
        else if (state == 2 && c == 'a') {strcpy(page.fileName, "Story/4.txt"); state = 4;}
        else if (state == 2 && c == 'b') {strcpy(page.fileName, "Story/5.txt"); state = 5;}
        else if (state == 3 && c == 'a') {strcpy(page.fileName, "Story/6.txt"); state = 6;}
        else if (state == 3 && c == 'b') {strcpy(page.fileName, "Story/11.txt"); state = 11;}
        else if (state == 4 && c == 'a') {strcpy(page.fileName, "Story/7.txt"); state = 7;}
        else if (state == 4 && c == 'b') {strcpy(page.fileName, "Story/8.txt"); state = 8;}
        else if (state == 6 && c == 'a') {strcpy(page.fileName, "Story/9.txt"); state = 9;}
        else if (state == 6 && c == 'b') {strcpy(page.fileName, "Story/10.txt"); state = 10;}
        else if (state == 7 && c == 'a') {strcpy(page.fileName, "Story/6.txt"); state = 6;}
        else if (state == 7 && c == 'b') {strcpy(page.fileName, "Story/3.txt"); state = 3;}
        else if (state == 9 && c == 'a') {strcpy(page.fileName, "Story/12.txt"); state = 12;}
        else if (state == 9 && c == 'b') {strcpy(page.fileName, "Story/10.txt"); state = 10;}

        if (state == 5 || state == 8 || state == 10 || state == 11 || state == 12) 
        {
            openPage(page);
            printf("\n");
            break;
        }
    }
    
    return 0;
}

void openPage(struct Page page)
{
    FILE *file = fopen(page.fileName, "r");
    if (!file)
    {
        printf("Could not open %s\n", page.fileName);
        return;
    }

    char line[1000];

    while (fgets(line, sizeof(line), file))
    {
        printf("%s", line);
    }

    fclose(file);
}