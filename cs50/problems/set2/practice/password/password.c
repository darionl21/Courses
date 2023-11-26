// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    int anumero;
    bool uppercase;
    bool lowercase;
    bool number;
    bool symbol;
    for (int i = 0; i < strlen(password); i++)
    {
        anumero = password[i];
        if (anumero >= 65 && anumero <= 90)
        {
            uppercase = true;
        }
        if (anumero >= 97 && anumero <= 122)
        {
            lowercase = true;
        }
        if (anumero >= 48 && anumero <= 57)
        {
            number = true;
        }
        if ((anumero >= 33 && anumero <= 47) || (anumero >= 58 && anumero <= 64) || (anumero >= 91 && anumero <= 96) || (anumero >= 123 && anumero <= 126))
        {
            symbol = true;
        }

    }
    if (uppercase == true && lowercase == true && number == true && symbol == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
