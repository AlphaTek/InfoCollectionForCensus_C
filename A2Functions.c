#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
#include <time.h>
#include "householdInfo.h"
#include <string.h>


 Household houseInfo [SIZE];
Date date1 [SIZE];

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

   }


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

   void averageHouseholdIncome(){

       int sum = 0;

   for(int i = 0; i < SIZE; i++){

    sum+=houseInfo[i].yearlyIncome/SIZE;
   } // forloop ends

   printf("Average household income: %d", sum);

   } // end of averageHouseholdIncome


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


//    if((strcmp(houseInfo[i].region, "Peel") == 0)) {
//                count++;
//          peel+=  houseInfo[i].yearlyIncome/count;
//            if((strcmp(houseInfo[i].town, "Brampton") == 0)) {
//
//                    brampton+=houseInfo[i].yearlyIncome/count;
//            }
//            if((strcmp(houseInfo[i].town, "Mississauga") == 0)) {
//
//                    mississauga+=houseInfo[i].yearlyIncome/count;
//            }
//        }
//
//
//        if((strcmp(houseInfo[i].region, "York") == 0)) {
//                count++;
//          york+=  houseInfo[i].yearlyIncome/count;
//            if((strcmp(houseInfo[i].town, "Maple") == 0)) {
//                    maple+=houseInfo[i].yearlyIncome/count;
//            }
//            if((strcmp(houseInfo[i].town, "Vaughan") == 0)) {
//                    vaughan+=houseInfo[i].yearlyIncome/count;
//            }
//        }
//
//
//        if((strcmp(houseInfo[i].region, "Durham") == 0)) {
//                count++;
//          durham+=  houseInfo[i].yearlyIncome/count;
//            if((strcmp(houseInfo[i].town, "Whitby") == 0)) {
//                    whitby+=houseInfo[i].yearlyIncome/count;
//            }
//            if((strcmp(houseInfo[i].town, "Oshawa") == 0)) {
//                    oshawa+=houseInfo[i].yearlyIncome/count;
//            }
//        }

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







