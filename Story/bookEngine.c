#include <stdio.h>
#include <stdlib.h>

struct Page {
    char fileName[20];
    char option1[40];
    char option2[40];
};

void openPage(struct Page page);

int main()
{
    printf("Welcome to Hamza's Choose Your Own Adventure! You will read through the story and select the corresponding number to the decision you want to make. Have fun!\n\n");

    while(1)
    {
        struct Page page;
        int state = 1;
        char c;

        openPage(page);

        if (state == 1 && c == 'a')      state = 2;
        else if (state == 1 && c == 'b') state = 3;
        else if (state == 2 && c == 'a') state = 4;
        else if (state == 2 && c == 'b') state = 5;
        else if (state == 3 && c == 'a') state = 6;
        else if (state == 3 && c == 'b') state = 11;
        else if (state == 4 && c == 'a') state = 7;
        else if (state == 4 && c == 'b') state = 8;
        else if (state == 6 && c == 'a') state = 9;
        else if (state == 6 && c == 'b') state = 10;
        else if (state == 7 && c == 'a') state = 6;
        else if (state == 7 && c == 'b') state = 3;
        else if (state == 9 && c == 'a') state = 12;
        else if (state == 9 && c == 'b') state = 10;

        if (state == 3 || state == 4) break;  // Accepting state

    }

    return 0;
}

void openPage(struct Page page)
{
    FILE *file = fopen(page.fileName, "r");
    if (!file)
    {
        printf("Could not open %s\n", page.fileName);
    }

    while (!feof(file))
    {
        char line[1000];
        fgets(line, 1000, file);
        printf("%s", line);
    }

    fclose(file);
}