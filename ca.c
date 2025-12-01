#include <stdio.h>
#include <stdlib.h>

struct vadhuvarsuchak {
    int profile_id;
    char name[50];
    int age;
    float income;
};

void search_profile(struct vadhuvarsuchak profile[], int n, int search_id) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (profile[i].profile_id == search_id) {
            printf("\nPROFILE ID: %d\n", profile[i].profile_id);
            printf("NAME: %s\n", profile[i].name);
            printf("AGE: %d\n", profile[i].age);
            printf("INCOME: %.2f\n", profile[i].income);
            printf("\n----------------------------------------\n");
            found = 1;
            break;
        }
    }
    if (!found) printf("\nProfile not found\n");
}

void sort_by_income_ascending(struct vadhuvarsuchak profile[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (profile[j].income > profile[j + 1].income) {
                struct vadhuvarsuchak temp = profile[j];
                profile[j] = profile[j + 1];
                profile[j + 1] = temp;
            }
        }
    }
}

void sort_by_income_descending(struct vadhuvarsuchak profile[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (profile[j].income < profile[j + 1].income) {
                struct vadhuvarsuchak temp = profile[j];
                profile[j] = profile[j + 1];
                profile[j + 1] = temp;
            }
        }
    }
}

void display_profiles(struct vadhuvarsuchak profile[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nPROFILE ID: %d\n", profile[i].profile_id);
        printf("NAME: %s\n", profile[i].name);
        printf("AGE: %d\n", profile[i].age);
        printf("INCOME: %.2f\n", profile[i].income);
        printf("\n----------------------------------------\n");
    }
}

int main() {
    int n;
    printf("VADHUVAR SUCHAK \nEnter number of profiles: ");
    scanf("%d", &n);
    struct vadhuvarsuchak profile[n];

    for (int i = 0; i < n; i++) {
        printf("\nProfile %d:\n", i + 1);
        printf("Profile ID: ");
        scanf("%d", &profile[i].profile_id);
        printf("NAME: ");
        scanf("%s", profile[i].name);
        printf("AGE: ");
        scanf("%d", &profile[i].age);
        printf("INCOME: ");
        scanf("%f", &profile[i].income);
    }

    sort_by_income_descending(profile, n);
    printf("\nProfiles Sorted by Income (Highest first):\n");
    display_profiles(profile, n);

    while (1) {
        int c;
        printf("\nVADHUVAR SUCHAK MENU\n1. Search profile\n2. Sort income asc\n3. Sort income desc\n4. Exit\nChoice: ");
        scanf("%d", &c);

        switch (c) {
            case 1: {
                int search_id;
                printf("Enter profile ID: ");
                scanf("%d", &search_id);
                search_profile(profile, n, search_id);   
                break;
            }
            case 2:
                sort_by_income_ascending(profile, n);
                printf("\nSorted by Income (Low to High):\n");
                display_profiles(profile, n);
                break;
            case 3:
                sort_by_income_descending(profile, n);
                printf("\nSorted by Income (High to Low):\n");
                display_profiles(profile, n);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
