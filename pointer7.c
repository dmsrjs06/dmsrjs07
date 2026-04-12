#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 100

struct student {
    char name[20];
    int schoolid;
    int grade;
};

int main() {
    FILE* fp = fopen("C:\\Users\\Kimeu\\Downloads\\name_list.txt", "r");
    if (fp == NULL) {
        return 0;
    }

    int n;
    scanf("%d", &n);
    printf("\n");

    if (n > N) {
        fclose(fp);
        return 0;
    }

    struct student* download = (struct student*)malloc(sizeof(struct student) * n);
    if (download == NULL) {
        fclose(fp);
        return 0;
    }

    char namelist[N][50];
    int namecount = 0;

    while (fgets(namelist[namecount], sizeof(namelist[namecount]), fp) != NULL) {
        namecount++;
    }
    fclose(fp);

    srand((int)time(NULL));

    for (int i = 0; i < n; i++) {
        strncpy(download[i].name, namelist[rand() % namecount], sizeof(download[i].name) - 1);
        download[i].name[sizeof(download[i].name) - 1] = '\0';
        download[i].schoolid = i + 1;
        download[i].grade = rand() % 100 + 1;
    }

    int low_std = 0;
    int high_std = 0;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += download[i].grade;
        if (download[i].grade < download[low_std].grade) low_std = i;
        if (download[i].grade > download[high_std].grade) high_std = i;
    }

    double average = (double)sum / n;

    printf("Name: %sID: %d, Grade: %d\n", download[low_std].name, download[low_std].schoolid, download[low_std].grade);
    printf("\n");
    printf("Name: %sID: %d, Grade: %d\n", download[high_std].name, download[high_std].schoolid, download[high_std].grade);
    printf("\n");
    printf("Average: %.2f\n", average);

    free(download);

    return 0;
}