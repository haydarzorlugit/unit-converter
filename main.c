#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unit_converter.h"

#define MAX_COMMAND_COUNT 5

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printHelp();
        return 1;
    }

    if (strncmp(argv[1], "--help", 8) == 0)
    {
        printHelp();
        return 1;
    }

    if (argc != MAX_COMMAND_COUNT)
    {
        printHelp();
        return 1;
    }

    char type[20] = "", from[20] = "", to[20] = "";
    double value = 0;

    for (int i = 1; i < argc; i++)
    {
        if (strncmp(argv[i], "--type=", 7) == 0)
            strcpy(type, argv[i] + 7);
        else if (strncmp(argv[i], "--from=", 7) == 0)
            strcpy(from, argv[i] + 7);
        else if (strncmp(argv[i], "--to=", 5) == 0)
            strcpy(to, argv[i] + 5);
        else if (strncmp(argv[i], "--value=", 8) == 0)
            value = atof(argv[i] + 8);
        else
        {
            printf("Unknown argument: %s\n", argv[i]);
            return 1;
        }
    }

    double result = 0;

    if (strcmp(type, "length") == 0)
    {
        if (strcmp(from, "meter") == 0 && strcmp(to, "inch") == 0)
            result = meterToInch(value);
        else if (strcmp(from, "inch") == 0 && strcmp(to, "meter") == 0)
            result = inchToMeter(value);
        else if (strcmp(from, "km") == 0 && strcmp(to, "mile") == 0)
            result = kmToMile(value);
        else if (strcmp(from, "mile") == 0 && strcmp(to, "km") == 0)
            result = mileToKm(value);
        else
        {
            printf("Unknown converter: %s --> %s\n", from, to);
            return 1;
        }

        printf("Conclusion: %.4lf %s\n", result, to);
    }
    else if (strcmp(type, "weight") == 0)
    {
        if (strcmp(from, "kg") == 0 && strcmp(to, "lb") == 0)
            result = kgToPound(value);
        else if (strcmp(from, "lb") == 0 && strcmp(to, "kg") == 0)
            result = poundToKg(value);
        else if (strcmp(from, "gr") == 0 && strcmp(to, "ons") == 0)
            result = gToOunce(value);
        else if (strcmp(from, "ons") == 0 && strcmp(to, "gr") == 0)
            result = ounceToG(value);
        else
        {
            printf("Unknown converter: %s --> %s\n", from, to);
            return 1;
        }

        printf("Conclusion: %.4lf %s\n", result, to);
    }
    else if (strcmp(type, "temperature") == 0)
    {
        if (strcmp(from, "C") == 0 && strcmp(to, "F") == 0)
            result = cToF(value);
        else if (strcmp(from, "F") == 0 && strcmp(to, "C") == 0)
            result = fToC(value);
        else if (strcmp(from, "C") == 0 && strcmp(to, "K") == 0)
            result = cToK(value);
        else if (strcmp(from, "K") == 0 && strcmp(to, "C") == 0)
            result = kToC(value);
        else
        {
            printf("Unknown converter: %s --> %s\n", from, to);
            return 1;
        }

        printf("Conclusion: %.4lf %s\n", result, to);
    }
    else if (strcmp(type, "currency") == 0)
    {
        result = convertCurrency(from, to, value);
        if (result < 0)
            return 1;

        printf("Conclusion: %.4lf %s\n", result, to);
    }
    else
    {
        printf("Unknown type: %s\n", type);
        return 1;
    }

    return 0;
}

