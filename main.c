#include <stdio.h>
#include <stdlib.h>

int airfare();
int ticket();
int profile();

struct airport
{
    int age, *ptr1, choice, customerID, baggageWt, distance, fare, ageDiscount, chg, taxamt, clubDiscount, total_fare;
    char gender, source, destination, clubMember;
} s;

int main()
{
    struct airport s;
    printf("\n============================================================\n");
    printf("\t\t      Airways Program\t\t\t");
    printf("\n============================================================\n");
    printf("Enter customer ID: ");
    scanf("%d", &s.customerID);
    printf("Enter age: ");
    scanf("%d", &s.age);
    printf("Enter gender (M/F): ");
    scanf(" %c", &s.gender);
    printf("Enter Source (C-Cochin, D-Delhi, B-Bangalore): ");
    scanf(" %c", &s.source);
    printf("Enter destination (C-Cochin, D-Delhi, B-Bangalore): ");
    scanf(" %c", &s.destination);
    printf("Enter distance in Km: ");
    scanf("%d", &s.distance);
    printf("Enter baggage weight in Kg: ");
    scanf("%d", &s.baggageWt);
    printf("Do you have club card membership? (Y/N): ");
    scanf(" %c", &s.clubMember);
    printf("\n");

    do
    {
        printf("\n============================================================\n");
        printf("\t\t      Airways Menu\t\t");
        printf("\n============================================================\n");
        printf("1.Passenger Profile\n");
        printf("2.Airfare Calculation\n");
        printf("3.E-Ticket\n");
        printf("4.Exit");
        printf("\n============================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &s.choice);
        printf("============================================================\n");

        switch (s.choice)
        {
        case 1:
            profile(s);
            break;
        case 2:
            // Lab 2 (calculations)
            airfare(s);
            break;
        case 3:
            ticket(s);
            break;
        case 4:
            break;
        default:
            printf("Invalid input! Please choose from 1-4!");
            break;
        }
    } while (s.choice != 4);
    return 0;
}

int profile(struct airport s)
{
    FILE *fptr;
    fptr = fopen("passenger_profile.txt", "w");
    s.ptr1 = &s.age;

    fprintf(fptr, "\n============================================================\n");
    fprintf(fptr, "                      Passenger Profile                         ");
    fprintf(fptr, "\n============================================================\n\n");
    fprintf(fptr, "CustomerID: %d", s.customerID);
    fprintf(fptr, "\t\tGender: %c \n\n", s.gender);
    fprintf(fptr, "Age: %d", *s.ptr1);
    fprintf(fptr, "\n\nSource: %c", s.source);
    fprintf(fptr, "\t\t\tDestination: %c\n", s.destination);

    fclose(fptr);
}

int airfare(struct airport s)
{
    s.fare = s.distance * 150 + (s.distance * 150) / 10;

    if (s.age >= 60)
    {
        s.ageDiscount = (40 * s.fare) / 100;
    }
    else
    {
        s.ageDiscount = 0;
    }

    if (s.baggageWt > 15)
    {
        s.chg = 20;
        s.taxamt = (s.baggageWt - 15) * s.chg;
    }
    else
    {
        s.taxamt = 0;
    }

    if (s.clubMember == 'y' || s.clubMember == 'Y')
    {
        s.clubDiscount = (5 * s.fare) / 100;
    }
    else
    {
        s.clubDiscount = 0;
    }

    s.total_fare = s.fare + s.taxamt - s.ageDiscount - s.clubDiscount;
    printf("\n============================================================\n");
    printf("\t\t      Airfare Calculation ");
    printf("\n============================================================\n");
    printf("\nBase fare: %d", s.fare);
    printf("\nMembership discount: %d", s.clubDiscount);
    printf("\nAge discount: %d", s.ageDiscount);
    printf("\nBaggage charge: %d", s.taxamt);
    printf("\n---------------------------");
    printf("\nTotal fare: %d", s.total_fare);
    printf("\n---------------------------\n");
}

int ticket(struct airport s)
{
    s.fare = s.distance * 150 + (s.distance * 150) / 10;

    if (s.age >= 60)
    {
        s.ageDiscount = (40 * s.fare) / 100;
    }
    else
    {
        s.ageDiscount = 0;
    }

    if (s.baggageWt > 15)
    {
        s.chg = 20;
        s.taxamt = (s.baggageWt - 15) * s.chg;
    }
    else
    {
        s.taxamt = 0;
    }

    if (s.clubMember == 'y')
    {
        s.clubDiscount = (5 * s.fare) / 100;
    }
    else if (s.clubMember == 'Y')
    {
        s.clubDiscount = (5 * s.fare) / 100;
    }
    else
    {
        s.clubDiscount = 0;
    }

    s.total_fare = s.fare + s.taxamt - s.ageDiscount - s.clubDiscount;

    printf("\n============================================================\n");
    printf("\t\t      E-Ticket ");
    printf("\n============================================================\n");
    printf("CustomerID: %d", s.customerID);
    printf("\t\tGender: %c \n\n", s.gender);
    printf("Age: %d", s.age);
    printf("\n\nSource: %c", s.source);
    printf("\t\t\tDestination: %c\n\n", s.destination);
    printf("Distance: %dKm", s.distance);
    printf("\t\t\tBaggage Weight: %dKg\n\n", s.baggageWt);
    printf("Club Card: %c\n", s.clubMember);
    printf("\n---------------------------\n");
    printf("Total fare: %d", s.total_fare);
    printf("\n---------------------------\n");
}
