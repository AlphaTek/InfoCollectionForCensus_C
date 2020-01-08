#ifndef HOUSEHOLDINFO_H_INCLUDED
#define HOUSEHOLDINFO_H_INCLUDED



typedef struct date{
int mm;
int dd;
int yy;
} Date;
typedef struct household {
   // Date date;
    char region[20];
    char town[20];
    char race[20];
    int numOfResidents;
    int yearlyIncome;
    } Household;


   void surveyPerRegion();
   void surveyPerRace();
   void belowPovertyByRegion();
   void belowPovertyByRace();
   void belowPoverty();
   void avgIncomeByRace();
   void avgIncomeByRegion();
   void averageHouseholdIncome();

#endif // HOUSEHOLDINFO_H_INCLUDED
