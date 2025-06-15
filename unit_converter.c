#include <stdio.h>
#include <string.h>
#include "unit_converter.h"

/* LENGTH FUNCTIONS */
double meterToInch(double m) { return m * 39.3701; }
double inchToMeter(double inch) { return inch / 39.3701; }
double kmToMile(double km) { return km * 0.621371; }
double mileToKm(double mil) { return mil / 0.621371; }

/* WEIGHT FUNCTIONS */
double kgToPound(double kg) { return kg * 2.20462; }
double poundToKg(double lb) { return lb / 2.20462; }
double gToOunce(double g) { return g * 0.035274; }
double ounceToG(double oz) { return oz / 0.035274; }

/* TEMPERATURE FUNCTIONS */
double cToF(double c) { return (c * 9.0/5.0) + 32.0; }
double fToC(double f) { return (f - 32.0) * 5.0/9.0; }
double cToK(double c) { return (c + 273.15); }
double kToC(double k) { return k - 273.15; }

/* CURRENCY CONVERTER */
double convertCurrency(const char *from, const char *to, double amount) {
    double rates[4] = { USD_TO_TRY, EUR_TO_TRY, GBP_TO_TRY, TRY_TO_TRY }; // USD, EUR, GBP, TRY

    int idxFrom = -1, idxTo = -1;

    if (strcmp(from, "USD") == 0) idxFrom = 0;
    else if (strcmp(from, "EUR") == 0) idxFrom = 1;
    else if (strcmp(from, "GBP") == 0) idxFrom = 2;
    else if (strcmp(from, "TRY") == 0) idxFrom = 3;

    if (strcmp(to, "USD") == 0) idxTo = 0;
    else if (strcmp(to, "EUR") == 0) idxTo = 1;
    else if (strcmp(to, "GBP") == 0) idxTo = 2;
    else if (strcmp(to, "TRY") == 0) idxTo = 3;

    if (idxFrom == -1 || idxTo == -1) {
        printf("Unknown currency: %s -> %s\n", from, to);
        return -1;
    }

    double inTRY = amount * rates[idxFrom];
    return inTRY / rates[idxTo];
}

/* Auxilary Functions */
void printHelp()
{
    printf("Usage:\n");
    printf("unit-converter.exe --type=TYPE --from=UNIT1 --to=UNIT2 --value=NUM\n");
    printf("ex: unit-converter.exe --type=weight --from=kg --to=pound --value=5\n");
    printf("Supported types: length, weight, temperature, currency\n");
    printf("Supported length units: meter, inch, km, mile\n");
    printf("Supported weight units: kg, lb, gr, ons\n");
    printf("Supported temperature units: C, K, F\n");
    printf("Supported currency units: USD, EUR, GBP, TRY\n");
}

