#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    int cent = 0;
    while (cent <= 0)
    {
        cent = get_int("Cents: ");
    }
    return cent;
}

int calculate_quarters(int cents)
{
    int quarters = 0;
    for (int i = 25; cents >= i; i += 25)
    {
        quarters++;
    }
    return quarters;
}

int calculate_dimes(int cents)
{
    // 10
    int dimes = 0;
    for (int i = 10; cents >= i; i += 10)
    {
        dimes++;
    }
    return dimes;
}

int calculate_nickels(int cents)
{
    // 5
    int nickels = 0;
    for (int i = 5; cents >= i; i += 5)
    {
        nickels++;
    }
    return nickels;
}

int calculate_pennies(int cents)
{
    // 1
    int pennies = 0;
    for (int i = 1; cents >= i; i++)
    {
        pennies++;
    }
    return pennies;
}
