#ifndef UNIT_CONVERTER_H
#define UNIT_CONVERTER_H

/* Constants */

/* LENGTH */
#define METER_TO_INCH    1
#define INCH_TO_METER    2
#define KM_TO_MILE       3
#define MILE_TO_KM       4

/* WEIGHT */
#define KG_TO_POUND     1
#define POUND_TO_KG     2
#define GR_TO_OUNCE     3
#define OUNCE_TO_GR     4

/* TEMPERATURE */
#define C_TO_F          1
#define F_TO_C          2
#define C_TO_K          3
#define K_TO_C          4

/* CURRENCY RATES (TRY bazlı) */
#define USD_TO_TRY 32.50
#define EUR_TO_TRY 35.00
#define GBP_TO_TRY 41.00
#define TRY_TO_TRY 1.00


/* Length */
double meterToInch(double m);
double inchToMeter(double inch);
double kmToMile(double km);
double mileToKm(double mil);

/* Weight */
double kgToPound(double kg);
double poundToKg(double lb);
double gToOunce(double g);
double ounceToG(double oz);

/* Temperature */
double cToF(double c);
double fToC(double f);
double cToK(double c);
double kToC(double k);

/* Currency */
double convertCurrency(const char *from, const char *to, double amount);


void printHelp(void);

#endif


