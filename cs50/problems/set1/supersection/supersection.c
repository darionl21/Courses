#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("Please enter your name: ");
    int age = get_int("PLease enter your age: ");
    long phone = get_long ("Please enter your phone number: ");
    char yn = get_char("Is the next information correct?\n Name: %s\n Age: %i\n Phone number: %ld\n [y/n]\n", name, age, phone);
     if (yn == 'n')
    {
     name = get_string("Please enter your name: ");
     age = get_int("PLease enter your age: ");
     phone = get_long ("Please enter your phone number: ");
     yn = get_char("Is the next information correct?\n Name: %s\n Age: %i\n Phone number: %ld\n [y/n]\n", name, age, phone);
    }
}