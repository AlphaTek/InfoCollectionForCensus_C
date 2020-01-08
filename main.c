#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
#include <time.h>
#include "householdInfo.h"
#include <string.h>

Household houseInfo [SIZE];
Date date1 [SIZE];

int main()
{



   char buffer[100];

   char choice;
   int count = 0;
   int items = 0;


   char regions[][10] = {"Peel", "York", "Durham"};
   char peelTowns[][20] = {"Brampton","Mississauga"};
   char yorkTowns[][20] = {"Maple","Vaughan"};
   char durhamTowns[][20] = {"Whitby","Oshawa"};
   char race[][20] = {"Caucasian", "Indigenous", "African American", "Asian", "Other"};

    for(int i = 0; i < 0; i++) {

            // I HAVE COMMENTED THE DATE CAPTURE BECAUSE FOR SOME REASON WHEN THE DATE IS TAKEN IT ENDS THE PROGRAM
//
//          while(items != 3){
//            printf("\nPlease enter todays date as mm dd yy\n");
//            //fgets(buffer, sizeof(buffer), stdin);
//           // buffer[strcspn(buffer, "\n")] = '\0'; // removing '\n' character
//            //items = sscanf(buffer,"%d%d%d", date1[i].mm, date1[i].dd, date1[i].yy );
//            }
//            items = 0;

             printf("\nPlease enter information for household # %d\n", i + 1);

// GETTING THE REGION and TOWN
             printf("Enter your Region exactly as either Peel, York or Durham\n");
             fgets(buffer, sizeof(buffer), stdin);
             buffer[strcspn(buffer, "\n")] = '\0'; // removing '\n' character from first name
             strcpy(houseInfo[i].region,buffer);

             if((strcmp(houseInfo[i].region, "Peel") == 0 )){

                printf("Please enter your town exactly as either Brampton or Mississauga\n");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = '\0'; // removing '\n' character from first name
                strcpy(houseInfo[i].town,buffer);

             }
             else if((strcmp(houseInfo[i].region, "York") == 0 )){

                printf("Please enter your town exactly as either Maple or Vaughan\n");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = '\0'; // removing '\n' character from first name
                strcpy(houseInfo[i].town,buffer);

             }
             else if((strcmp(houseInfo[i].region, "Durham") == 0 )){

                printf("Please enter your town exactly as either Whitby or Oshawa\n");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = '\0'; // removing '\n' character from first name
                strcpy(houseInfo[i].town,buffer);

             }


//  GETTING THE RACE:

             printf("\nEnter the race of the head of Household\n");
             printf("You must enter it exactly as either Caucasian, Indigenous, African American, Asian, Other\n");
             fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = '\0'; // removing '\n' character from first name
                strcpy(houseInfo[i].race,buffer);


// GETTING NUMBER OF RESIDENTS

             while(houseInfo[i].numOfResidents <=0) {

        printf("\nEnter the number of household members residing at this address. Value must be more than 0\n");
             fgets(buffer,sizeof(buffer), stdin);
             sscanf(buffer, "%d",&houseInfo[i].numOfResidents);
             }

// GETTING YEARLY INCOME

                while (items != 1){
             printf("\nEnter the household Yearly income\n");
             fgets(buffer,sizeof(buffer), stdin);
             items = sscanf(buffer, "%d",&houseInfo[i].yearlyIncome);
             } //inner while loop ends
              items = 0; // resetting value of items

             } // end of forloop to collect data

// PRINTING THE MANUALLY ENTERED INFORMATION FOR 3 HOUSEHOLDS

//        printf("\n%20s%20s%20s%20s%20s\n\n", "Region", "Town", "Race", "Residents", "Yearly Income");
//
//     for (int i = 0; i < 3; i++)
//    {
//        printf("%20s%20s%20s%20d%20d%20d\n", houseInfo[i].region, houseInfo[i].town, houseInfo[i].race, houseInfo[i].numOfResidents, houseInfo[i].yearlyIncome, houseInfo[i].date);
//
//    } // end of forloop to display data




// THIS IS WHERE THE RANDOM GENERATOR BEGINS

srand(time(NULL));

    for( int i=0; i < SIZE; i++) {

    // randomly generating date as dd-mm-yy
        date1[i].mm = rand() % 12 + 1;
        date1[i].dd = rand() % 31;
        date1[i].yy = 18;

 // randomly generating regions and towns
        strcpy(houseInfo[i].region, regions[rand() % (sizeof(regions)/sizeof(regions[0]))]);
        if((strcmp(houseInfo[i].region, "Peel") == 0)) {
            strcpy(houseInfo[i].town, peelTowns[rand() % (sizeof(peelTowns)/sizeof(peelTowns[0]))]);
                    }
         if((strcmp(houseInfo[i].region, "York") == 0)) {
            strcpy(houseInfo[i].town, yorkTowns[rand() % (sizeof(yorkTowns)/sizeof(yorkTowns[0]))]);
        }
         if((strcmp(houseInfo[i].region, "Durham") == 0)) {
            strcpy(houseInfo[i].town, durhamTowns[rand() % (sizeof(durhamTowns)/sizeof(durhamTowns[0]))]);
        }

        // randomly generating race
        strcpy(houseInfo[i].race, race[rand() % (sizeof(race)/sizeof(race[0]))]);

        // randomly generating the number of residents from 1 to 11
        houseInfo[i].numOfResidents = rand() % 10 + 1;

        // randomly generating yearly income as minimum 5000 and max 105000
        houseInfo[i].yearlyIncome = rand() % 100000 + 5000;

        }

        // PRINTING RANDOMLY GERNERATED DATA TO ENSURE ITS BEING SAVED IN THE STRUCTURE
    printf("\n%20s%20s%20s%20s%20s%15s\n\n", "Region", "Town", "Race", "Residents", "Yearly Income", "Date");

     for (int i = 0; i < SIZE; i++)
    {
        printf("%20s%20s%25s%15d%20d%20d%s%d%s%d\n", houseInfo[i].region, houseInfo[i].town, houseInfo[i].race, houseInfo[i].numOfResidents, houseInfo[i].yearlyIncome, date1[i].dd, "-", date1[i].mm, "-", date1[i].yy);

    } // end of forloop to display data


// SWITCH STATEMENT FOR THE MENU DRIVEN SYSTEM
while (choice != 0)  {
    puts(" \nChoose one of the following letters from the menu to display its related information\n");

    puts("1. Total Households Surveyed per region");
    puts("2. Total Households Surveyed per Race");
    puts("3. Average Household Income");
    puts("4. Average Household Income by town and region");
    puts("5. Average Household Income by race");
    puts("6. Percentage below Poverty");
    puts("7. Percentage below Poverty by town and region");
    puts("8. Percentage below Poverty by race");
    puts("0. Exit");
    scanf("%d", &choice);
    puts("");

switch(choice){
case 0:
exit(1);
break;

case 1:
surveyPerRegion();
break;

case 2:
surveyPerRace();
break;

case 3:
averageHouseholdIncome();
break;

case 4:
avgIncomeByRegion();
break;

case 5:
avgIncomeByRace();
break;

case 6:
belowPoverty();
break;

case 7:
belowPovertyByRegion();
break;

case 8:
belowPovertyByRace();
break;

default:
    puts("Invalid Entry");
} // switch ends
 } // while loop ends



// POINTER DID NOT WORK FOR ME SO I USED SWITCH STATEMENT INSTEAD

//        void (*ptrFuncs[9])();
//
//          ptrFuncs[0] = exit;
//          ptrFuncs[1] = surveyPerRegion;
//          ptrFuncs[2] = surveyPerRace;
//          ptrFuncs[3] = averageHouseholdIncome;
//          ptrFuncs[4] = avgIncomeByRegion;
//          ptrFuncs[5] = avgIncomeByRace;
//          ptrFuncs[6] = belowPoverty;
//          ptrFuncs[7] = belowPovertyByRegion;
//          ptrFuncs[8] = belowPovertyByRace;
//
//            (*ptrFuncs[choice])();



            // pointer to function approach

//void (*ptrFuncs[choice]) (int x, int y);
//
//ptrFuncs[0] = sum;
//ptrFuncs[1] = difference;
//ptrFuncs[2] = product;
//
//(*ptrFuncs[choice]) (num1,num2);
//// TODO (Muhammad#1#): comment the above switch-case construct and replace it by ...
////pointers to functions


   } // main ends



// SURVEY PER REGION
   void surveyPerRegion() {


   int peel = 0;
   int brampton = 0;
   int mississauga = 0;

   int york = 0;
   int maple = 0;
   int vaughan = 0;

   int durham = 0;
   int whitby = 0;
   int oshawa = 0;

   for (int i = 0; i < SIZE; i++){

        if((strcmp(houseInfo[i].region, "Peel") == 0)){
            peel++;
            if((strcmp(houseInfo[i].town, "Brampton") == 0)){
               brampton++;
            } if((strcmp(houseInfo[i].town, "Mississauga") == 0)){
                mississauga++;
            }

        } else if((strcmp(houseInfo[i].region,"York") == 0)){
            york++;
            if((strcmp(houseInfo[i].town, "Maple") == 0)){
            maple++;
            } if((strcmp(houseInfo[i].town, "Vaughan") == 0)) {
            vaughan++;
            }

        } else if((strcmp(houseInfo[i].region, "Durham") == 0)){
           durham++;
            if((strcmp(houseInfo[i].town, "Whitby") == 0)){
               whitby++;
            } if((strcmp(houseInfo[i].town, "Oshawa") == 0)){
               oshawa++;
            }

        }

   } // forloop ends

   printf("The total Household Surveyed in Peel: %d\n", peel);
   printf("Brampton: %d\n", brampton);
   printf("Mississauga: %d\n", mississauga);
puts("");
   printf("The total Household Surveyed in York: %d\n", york);
   printf("Maple: %d\n", maple);
   printf("Vaughan: %d\n", vaughan);
puts("");
   printf("The total Household Surveyed in Durham: %d\n", durham);
   printf("Whitby: %d\n", whitby);
   printf("Oshawa: %d\n", oshawa);
puts("");

   } // end of survey per region


   // SURVEY PER RACE
   void surveyPerRace() {

   int cauc = 0;
   int indi = 0;
   int afAmer = 0;
   int asi = 0;
   int oth = 0;

   for (int i = 0; i < SIZE; i++){

   if((strcmp(houseInfo[i].race, "Caucasian") == 0)){
    cauc++;
   }
   if((strcmp(houseInfo[i].race, "Indigenous") == 0)){
    indi++;
   }
     if((strcmp(houseInfo[i].race, "African American") == 0)){
    afAmer++;
   }
     if((strcmp(houseInfo[i].race, "Asian")==0)){
    asi++;
   }
     if((strcmp(houseInfo[i].race, "Other") == 0)){
    oth++;
   }

      }
    printf("Households surveyed per Race: \n");
    printf("Caucasian: %d\n", cauc);
    printf("Indigenous: %d\n", indi);
    printf("African American: %d\n", afAmer);
    printf("Asian: %d\n", asi);
    printf("Other: %d\n", oth);


   } // end of surveyPerRace

   // AVERAGE HOUSEHOLD INCOME
   void averageHouseholdIncome(){

       int sum = 0;

   for(int i = 0; i < SIZE; i++){

    sum+=houseInfo[i].yearlyIncome/SIZE;
   } // forloop ends

   printf("Average household income: %d", sum);

   } // end of averageHouseholdIncome


   // Average Income by Regions
   void avgIncomeByRegion(){
   int count = 0;
   int sum = 0;
   int peel = 0;
   int brampton = 0;
   int mississauga = 0;

   int york = 0;
   int maple = 0;
   int vaughan = 0;

   int durham = 0;
   int whitby = 0;
   int oshawa = 0;
    for(int i = 0; i < SIZE; i++){

        if((strcmp(houseInfo[i].region, "Peel") == 0)) {
                count++;
          peel+=  houseInfo[i].yearlyIncome/count;
            if((strcmp(houseInfo[i].town, "Brampton") == 0)) {

                    brampton+=houseInfo[i].yearlyIncome/count;
            }
            if((strcmp(houseInfo[i].town, "Mississauga") == 0)) {

                    mississauga+=houseInfo[i].yearlyIncome/count;
            }
        }


        if((strcmp(houseInfo[i].region, "York") == 0)) {
                count++;
          york+=  houseInfo[i].yearlyIncome/count;
            if((strcmp(houseInfo[i].town, "Maple") == 0)) {
                    maple+=houseInfo[i].yearlyIncome/count;
            }
            if((strcmp(houseInfo[i].town, "Vaughan") == 0)) {
                    vaughan+=houseInfo[i].yearlyIncome/count;
            }
        }


        if((strcmp(houseInfo[i].region, "Durham") == 0)) {
                count++;
          durham+=  houseInfo[i].yearlyIncome/count;
            if((strcmp(houseInfo[i].town, "Whitby") == 0)) {
                    whitby+=houseInfo[i].yearlyIncome/count;
            }
            if((strcmp(houseInfo[i].town, "Oshawa") == 0)) {
                    oshawa+=houseInfo[i].yearlyIncome/count;
            }
        }

   } // forloop ends

   printf("Average household income by Town and Region: \n");
   printf("Peel: %d\n", peel);
   printf("Brampton: %d\n", brampton );
   printf("Mississauga: %d\n", mississauga);
puts("");
   printf("York: %d\n", york );
   printf("Maple: %d\n", maple );
   printf("Vaughan: %d\n", vaughan );
puts("");
   printf("Durham: %d\n", durham );
   printf("Whitby: %d\n", whitby );
   printf("Oshawa: %d\n", oshawa );


}    // end of average income by region


// AVERAGE INCOME BY RACE
   void avgIncomeByRace(){

   int count = 0;
   int cauc = 0;
   int indi = 0;
   int afAmer = 0;
   int asi = 0;
   int oth = 0;

   for(int i = 0; i < SIZE; i++) {

     if((strcmp(houseInfo[i].race, "Caucasian") == 0)){
            count++;
    cauc+= houseInfo[i].yearlyIncome/count;
   }
      if((strcmp(houseInfo[i].race, "Indigenous") == 0)){
            count++;
    indi+= houseInfo[i].yearlyIncome/count;
   }
     if((strcmp(houseInfo[i].race, "African American") == 0)){
            count++;
    afAmer+= houseInfo[i].yearlyIncome/count;
   }
     if((strcmp(houseInfo[i].race, "Asian")==0)){
            count++;
    asi+= houseInfo[i].yearlyIncome/count;
   }
     if((strcmp(houseInfo[i].race, "Other") == 0)){
            count++;
    oth+= houseInfo[i].yearlyIncome/count;
   }

   } //forloop ends

    printf("Average income by Race: \n");
    printf("Caucasian: %d\n", cauc);
    printf("Indigenous: %d\n", indi);
    printf("African American: %d\n", afAmer);
    printf("Asian: %d\n", asi);
    printf("Other: %d\n", oth);



   } // end of average income by race


   //PERCENTAGE BELOW POVERTY
   void belowPoverty(){
       int count = 0;

       for(int i = 0; i < SIZE; i++){
   if((houseInfo[i].numOfResidents == 1) && (houseInfo[i].yearlyIncome < 15000)){
    count++;
   }
   if((houseInfo[i].numOfResidents == 2) && (houseInfo[i].yearlyIncome < 20000)){
    count++;
   }
   if((houseInfo[i].numOfResidents == 3) && (houseInfo[i].yearlyIncome < 25000)){
    count++;
   }
   if((houseInfo[i].numOfResidents == 4) && (houseInfo[i].yearlyIncome < 30000)){
    count++;
   }
   if((houseInfo[i].numOfResidents == 5) && (houseInfo[i].yearlyIncome < 40000)){
    count++;
   }
       } // forloop ends


   printf("The percentage of Households below poverty: %d Percent", count);

   } // end of percentage below poverty


   //PERCENTAGE BELOW POVERTY BY REGION
   void belowPovertyByRegion(){

      int count = 0;

   int sum = 0;
   int peel = 0;
   int brampton = 0;
   int mississauga = 0;

   int york = 0;
   int maple = 0;
   int vaughan = 0;

   int durham = 0;
   int whitby = 0;
   int oshawa = 0;

       for(int i = 0; i < SIZE; i++){


        if((strcmp(houseInfo[i].town, "Brampton") == 0)) {
           if((houseInfo[i].numOfResidents == 1) && (houseInfo[i].yearlyIncome < 15000)){
            brampton++;
           }
           if((houseInfo[i].numOfResidents == 2) && (houseInfo[i].yearlyIncome < 20000)){
            brampton++;
           }
           if((houseInfo[i].numOfResidents == 3) && (houseInfo[i].yearlyIncome < 25000)){
            brampton++;
           }
           if((houseInfo[i].numOfResidents == 4) && (houseInfo[i].yearlyIncome < 30000)){
            brampton++;
           }
           if((houseInfo[i].numOfResidents == 5) && (houseInfo[i].yearlyIncome < 40000)){
            brampton++;
           }
        }


               if((strcmp(houseInfo[i].town, "Mississauga") == 0)) {
           if((houseInfo[i].numOfResidents == 1) && (houseInfo[i].yearlyIncome < 15000)){
            mississauga++;
           }
           if((houseInfo[i].numOfResidents == 2) && (houseInfo[i].yearlyIncome < 20000)){
            mississauga++;
           }
           if((houseInfo[i].numOfResidents == 3) && (houseInfo[i].yearlyIncome < 25000)){
            mississauga++;
           }
           if((houseInfo[i].numOfResidents == 4) && (houseInfo[i].yearlyIncome < 30000)){
            mississauga++;
           }
           if((houseInfo[i].numOfResidents == 5) && (houseInfo[i].yearlyIncome < 40000)){
            mississauga++;
           }
 }

 peel = brampton + mississauga;


  if((strcmp(houseInfo[i].town, "Maple") == 0)) {
           if((houseInfo[i].numOfResidents == 1) && (houseInfo[i].yearlyIncome < 15000)){
            maple++;
           }
           if((houseInfo[i].numOfResidents == 2) && (houseInfo[i].yearlyIncome < 20000)){
            maple++;
           }
           if((houseInfo[i].numOfResidents == 3) && (houseInfo[i].yearlyIncome < 25000)){
            maple++;
           }
           if((houseInfo[i].numOfResidents == 4) && (houseInfo[i].yearlyIncome < 30000)){
            maple++;
           }
           if((houseInfo[i].numOfResidents == 5) && (houseInfo[i].yearlyIncome < 40000)){
            maple++;
           }

 }
   if((strcmp(houseInfo[i].town, "Vaughan") == 0)) {
           if((houseInfo[i].numOfResidents == 1) && (houseInfo[i].yearlyIncome < 15000)){
            vaughan++;
           }
           if((houseInfo[i].numOfResidents == 2) && (houseInfo[i].yearlyIncome < 20000)){
            vaughan++;
           }
           if((houseInfo[i].numOfResidents == 3) && (houseInfo[i].yearlyIncome < 25000)){
            vaughan++;
           }
           if((houseInfo[i].numOfResidents == 4) && (houseInfo[i].yearlyIncome < 30000)){
            vaughan++;
           }
           if((houseInfo[i].numOfResidents == 5) && (houseInfo[i].yearlyIncome < 40000)){
            vaughan++;
           }

 }

 york = maple + vaughan;


    if((strcmp(houseInfo[i].town, "Whitby") == 0)) {
           if((houseInfo[i].numOfResidents == 1) && (houseInfo[i].yearlyIncome < 15000)){
            whitby++;
           }
           if((houseInfo[i].numOfResidents == 2) && (houseInfo[i].yearlyIncome < 20000)){
            whitby++;
           }
           if((houseInfo[i].numOfResidents == 3) && (houseInfo[i].yearlyIncome < 25000)){
            whitby++;
           }
           if((houseInfo[i].numOfResidents == 4) && (houseInfo[i].yearlyIncome < 30000)){
            whitby++;
           }
           if((houseInfo[i].numOfResidents == 5) && (houseInfo[i].yearlyIncome < 40000)){
            whitby++;
           }

 }


  if((strcmp(houseInfo[i].town, "Oshawa") == 0)) {
           if((houseInfo[i].numOfResidents == 1) && (houseInfo[i].yearlyIncome < 15000)){
            oshawa++;
           }
           if((houseInfo[i].numOfResidents == 2) && (houseInfo[i].yearlyIncome < 20000)){
            oshawa++;
           }
           if((houseInfo[i].numOfResidents == 3) && (houseInfo[i].yearlyIncome < 25000)){
            oshawa++;
           }
           if((houseInfo[i].numOfResidents == 4) && (houseInfo[i].yearlyIncome < 30000)){
            oshawa++;
           }
           if((houseInfo[i].numOfResidents == 5) && (houseInfo[i].yearlyIncome < 40000)){
            oshawa++;
           }

 }
 durham = whitby + oshawa;


   } // forloop ends

   printf("Percentage below Poverty by Town and Region: \n");
   printf("Peel: %d\n", peel);
   printf("Brampton: %d\n", brampton );
   printf("Mississauga: %d\n", mississauga);
puts("");
   printf("York: %d\n", york );
   printf("Maple: %d\n", maple );
   printf("Vaughan: %d\n", vaughan );
puts("");
   printf("Durham: %d\n", durham );
   printf("Whitby: %d\n", whitby );
   printf("Oshawa: %d\n", oshawa );

   } // end of below poverty by region and town


   //BELOW POVERTY BY RACE
   void belowPovertyByRace(){

   int cauc = 0;
   int indi = 0;
   int afAmer = 0;
   int asi = 0;
   int oth = 0;

   for(int i = 0; i < SIZE; i++) {

     if((strcmp(houseInfo[i].race, "Caucasian") == 0)){

            if((houseInfo[i].numOfResidents == 1) && (houseInfo[i].yearlyIncome < 15000)){
            cauc++;
           }
           if((houseInfo[i].numOfResidents == 2) && (houseInfo[i].yearlyIncome < 20000)){
            cauc++;
           }
           if((houseInfo[i].numOfResidents == 3) && (houseInfo[i].yearlyIncome < 25000)){
            cauc++;
           }
           if((houseInfo[i].numOfResidents == 4) && (houseInfo[i].yearlyIncome < 30000)){
            cauc++;
           }
           if((houseInfo[i].numOfResidents == 5) && (houseInfo[i].yearlyIncome < 40000)){
            cauc++;
           }


     }


      if((strcmp(houseInfo[i].race, "Indigenous") == 0)){

            if((houseInfo[i].numOfResidents == 1) && (houseInfo[i].yearlyIncome < 15000)){
            indi++;
           }
           if((houseInfo[i].numOfResidents == 2) && (houseInfo[i].yearlyIncome < 20000)){
            indi++;
           }
           if((houseInfo[i].numOfResidents == 3) && (houseInfo[i].yearlyIncome < 25000)){
            indi++;
           }
           if((houseInfo[i].numOfResidents == 4) && (houseInfo[i].yearlyIncome < 30000)){
            indi++;
           }
           if((houseInfo[i].numOfResidents == 5) && (houseInfo[i].yearlyIncome < 40000)){
            indi++;
           }


     }

           if((strcmp(houseInfo[i].race, "African American") == 0)){

            if((houseInfo[i].numOfResidents == 1) && (houseInfo[i].yearlyIncome < 15000)){
            afAmer++;
           }
           if((houseInfo[i].numOfResidents == 2) && (houseInfo[i].yearlyIncome < 20000)){
            afAmer++;
           }
           if((houseInfo[i].numOfResidents == 3) && (houseInfo[i].yearlyIncome < 25000)){
            afAmer++;
           }
           if((houseInfo[i].numOfResidents == 4) && (houseInfo[i].yearlyIncome < 30000)){
            afAmer++;
           }
           if((houseInfo[i].numOfResidents == 5) && (houseInfo[i].yearlyIncome < 40000)){
            afAmer++;
           }


     }

           if((strcmp(houseInfo[i].race, "Asian") == 0)){

            if((houseInfo[i].numOfResidents == 1) && (houseInfo[i].yearlyIncome < 15000)){
            asi++;
           }
           if((houseInfo[i].numOfResidents == 2) && (houseInfo[i].yearlyIncome < 20000)){
            asi++;
           }
           if((houseInfo[i].numOfResidents == 3) && (houseInfo[i].yearlyIncome < 25000)){
            asi++;
           }
           if((houseInfo[i].numOfResidents == 4) && (houseInfo[i].yearlyIncome < 30000)){
            asi++;
           }
           if((houseInfo[i].numOfResidents == 5) && (houseInfo[i].yearlyIncome < 40000)){
            asi++;
           }

     }

           if((strcmp(houseInfo[i].race, "Other") == 0)){

            if((houseInfo[i].numOfResidents == 1) && (houseInfo[i].yearlyIncome < 15000)){
            oth++;
           }
           if((houseInfo[i].numOfResidents == 2) && (houseInfo[i].yearlyIncome < 20000)){
            oth++;
           }
           if((houseInfo[i].numOfResidents == 3) && (houseInfo[i].yearlyIncome < 25000)){
            oth++;
           }
           if((houseInfo[i].numOfResidents == 4) && (houseInfo[i].yearlyIncome < 30000)){
            oth++;
           }
           if((houseInfo[i].numOfResidents == 5) && (houseInfo[i].yearlyIncome < 40000)){
            oth++;
           }
     }

   } //forloop ends

    printf("Percentage below Poverty by Race: \n");
    printf("Caucasian: %d\n", cauc);
    printf("Indigenous: %d\n", indi);
    printf("African American: %d\n", afAmer);
    printf("Asian: %d\n", asi);
    printf("Other: %d\n", oth);


  } //end of belowPovertyByRace







