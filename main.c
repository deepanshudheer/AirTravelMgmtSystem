#include <stdio.h>
#include <conio.h>

int airfare();
int ticket();
int profile();

int choice, customerID, age, baggageWt, distance, fare, ageDiscount, chg, taxamt, clubDiscount, total_fare;
char gender, source, destination, clubMember;

int main()
{
    printf("\n============================================================\n");
    printf("                      Airways Program             ");
    printf("\n============================================================\n");
    printf("Enter customer ID: ");
    scanf("%d", &customerID);
    printf("Enter age: ");
    scanf("%d", &age);
    printf("Enter gender (M/F): ");
    scanf(" %c", &gender);
    printf("Enter Source (C-Cochin, D-Delhi, B-Bangalore): ");
    scanf(" %c", &source);
    printf("Enter destination (C-Cochin, D-Delhi, B-Bangalore): ");
    scanf(" %c", &destination);
    printf("Enter distance in Km: ");
    scanf("%d", &distance);
    printf("Enter baggage weight in Kg: ");
    scanf("%d", &baggageWt);
    printf("Do you have club card membership? (Y/N): ");
    scanf(" %c", &clubMember);
    printf("\n");

    do
    {
        printf("\n============================================================\n");
        printf("                        Airways Menu                ");
        printf("\n============================================================\n");
        printf("1.Passenger Profile\n");
        printf("2.Airfare Calculation\n");
        printf("3.E-Ticket\n");
        printf("4.Exit");
        printf("\n============================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("============================================================\n");

        // Lab 3 (menu driven using switch case)

        switch (choice)
        {
        case 1:
            profile();
            break;
        case 2:
            // Lab 2 (calculations)
            airfare();
            break;
        case 3:
            ticket();
            break;
        }
    } while (choice != 4);
    return 0;
}

// functions

int profile()
{
    printf("\n============================================================\n");
    printf("                      Passenger Profile             ");
    printf("\n============================================================\n\n");
    printf("CustomerID: %d", customerID);
    printf("\t\tGender: %c \n\n", gender);
    printf("Age: %d", age);
    printf("\n\nSource: %c", source);
    printf("\t\t\tDestination: %c\n", destination);
}

int airfare()
{
    fare = distance * 150 + (distance * 150) / 10;

    if (age >= 60)
    {
        ageDiscount = (40 * fare) / 100;
    }
    else
    {
        ageDiscount = 0;
    }

    if (baggageWt > 15)
    {
        chg = 20;
        taxamt = (baggageWt - 15) * chg;
    }
    else
    {
        taxamt = 0;
    }

    if (clubMember == 'y' || clubMember == 'Y')
    {
        clubDiscount = (5 * fare) / 100;
    }
    else
    {
        clubDiscount = 0;
    }

    total_fare = fare + taxamt - ageDiscount - clubDiscount;
    printf("\n============================================================\n");
    printf("                      Airfare Calculation             ");
    printf("\n============================================================\n");
    printf("\nBase fare: %d", fare);
    printf("\nMembership discount: %d", clubDiscount);
    printf("\nAge discount: %d", ageDiscount);
    printf("\nBaggage charge: %d", taxamt);
    printf("\n---------------------------");
    printf("\nTotal fare: %d", total_fare);
    printf("\n---------------------------\n");
}

int ticket()
{
    fare = distance * 150 + (distance * 150) / 10;

    if (age >= 60)
    {
        ageDiscount = (40 * fare) / 100;
    }
    else
    {
        ageDiscount = 0;
    }

    if (baggageWt > 15)
    {
        chg = 20;
        taxamt = (baggageWt - 15) * chg;
    }
    else
    {
        taxamt = 0;
    }

    if (clubMember == 'y')
    {
        clubDiscount = (5 * fare) / 100;
    }
    else if (clubMember == 'Y')
    {
        clubDiscount = (5 * fare) / 100;
    }
    else
    {
        clubDiscount = 0;
    }

    total_fare = fare + taxamt - ageDiscount - clubDiscount;

    printf("\n============================================================\n");
    printf("                      E-Ticket             ");
    printf("\n============================================================\n");
    printf("CustomerID: %d", customerID);
    printf("\t\tGender: %c \n\n", gender);
    printf("Age: %d", age);
    printf("\n\nSource: %c", source);
    printf("\t\t\tDestination: %c\n\n", destination);
    printf("Distance: %dKm", distance);
    printf("\t\t\tBaggage Weight: %dKg\n\n", baggageWt);
    printf("Club Card: %c\n", clubMember);
    printf("\n---------------------------\n");
    printf("Total fare: %d", total_fare);
    printf("\n---------------------------\n");
}