// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

float half(float bill, float tax, float tip);

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    float tip_percent = get_float("Tip percent: ");

    printf("$%.2f\n", half(bill_amount, tax_percent, tip_percent));
}

// TODO: Complete the function
float half(float bill, float tax, float tip)
{
    //Total=Bill+(Bill×Tax Percent)+(Bill×Tip Percent)
    bill = bill + (bill * (tax/100));
    float total = bill + (bill * (tip/100));
    return total / 2;
}
