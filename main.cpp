/*
* main.cpp
*
* COSC 051 Spring 2019
* Project #1 (Code)
*
* Due on: February 13, 2019
* Author: jsk142
*
*
* In accordance with the class policies and Georgetown's
* Honor Code, I certify that, with the exception of the
* class resources and those items noted below, I have neither
* given nor received any assistance on this project.
*
* References not otherwise commented within the program source code.
* Note that you should not mention any help from the TAs, the professor,
* or any code taken from the class textbooks.
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

   //Global constants

   const double PRICE_PER_POUND_FOR_PACKING_AND_LOADING_B = 0.065;   
   const double PRICE_PER_POUND_FOR_PACKING_AND_LOADING_W = 0.256;
   const double PRICE_PER_POUND_FOR_PACKING_AND_LOADING_C = 0.459;
   const double PRICE_PER_POUND_PER_MILE_B = 0.0011;
   const double PRICE_PER_POUND_PER_MILE_W = 0.0011;
   const double PRICE_PER_POUND_PER_MILE_C = 0.0012;

int main ()
{
   //Input move type

   string message_welcome, prompt_type;

   message_welcome = "Welcome to the BHMSI Moving price calculator.";
   prompt_type = "Please enter the type of move (B - Basic, W - Wall Pack, C - Complete) : ";
   
   cout << endl << message_welcome << endl << endl;  
   cout << prompt_type;

   char move_type;
 
   cin >> move_type;

   cin.ignore(10, '\n');

   move_type = toupper(move_type);
   
   if (move_type != 'B' && move_type != 'W' && move_type != 'C')
   {   cout << endl << "The move type entered is not valid." << endl; 
       cout << "The program will now end, Goodbye." << endl << endl;
       return 101;
   }

   //Input move distance and calculate minimum weight

   cout << "Please enter the distance from origin to destination [1, 3200]: ";
   
   int move_distance, minimum_weight;

   cin >> move_distance;

   if (move_distance < 1)
   {   move_distance = 1;
       minimum_weight = 1200;
       cout << endl << "The distance entered is less than the minimum of 1 mile." << endl; 
       cout << "We will continue to price this move using the minimum distance." << endl;
       cout << "Note: The minimum weight for a move of " << move_distance << " mile is " 
            << minimum_weight << "." << endl << endl;
   }
   
   else if (move_distance >= 1 && move_distance <= 600)
   {   minimum_weight = 1200;
       cout << endl << "Note: The minimum weight for a move of " << move_distance << " miles is " 
            << minimum_weight << "." << endl << endl;
   }

   else if (move_distance > 600 && move_distance <= 3200)
   {   minimum_weight = 2 * move_distance;
       cout << endl << "Note: The minimum weight for a move of " << move_distance << " miles is " 
            << minimum_weight << "." << endl << endl;
   }

   else
   {   cout << endl << "The distance entered exceeds BHMSI's maximum." << endl 
            << "Please refer this customer to BBMSI." << endl 
            << "The program will now end, Goodbye." << endl << endl;
       return 102;
   }
   
   //Input move weight

   cout << "Please enter the weight of the contents to move [" << minimum_weight << ", 18000] : ";

   int move_weight;

   cin >> move_weight;

   if (move_weight < minimum_weight)
   {   cout << endl << "The weight of " << move_weight << " pounds is less than the minimum of " 
            << minimum_weight << " for a move of " << move_distance << " miles." << endl; 
       cout << "We will continue to price this move using the minimum weight of " 
            << minimum_weight << " pounds." << endl << endl;

       move_weight = minimum_weight;
   }

   else if (move_weight > 18000)
   {   cout << endl << "The weight entered exceeds the BHMSI's maximum." << endl; 
       cout << "Please refer this customer to BBMSI." << endl; 
       cout << "The program will now end, Goodbye." << endl << endl;
       return 103;
   }

   //Input number of pianos

   cout << "Please enter the number of pianos to move [0, 3]: ";

   int move_piano;

   cin >> move_piano;

   if (move_piano > 3)
   {   cout << endl << "The piano count entered exceeds BHMSI's maximum." << endl; 
       cout << "The program will now end, Goodbye." << endl << endl;
       return 104;
   }
   
   //Determine if origin has more than 15 stairs

   cout << "Does this origin of this move have more than 15 stairs? (y/n): ";

   char move_origin;

   cin >> move_origin;

   cin.ignore (10, '\n');
  
   if (move_origin != 'Y' && move_origin != 'y' && move_origin != 'N' && move_origin != 'n')
   {   cout << endl << "Please type y or n as the input for the stairs questions." << endl; 
       cout << "The program wil now end, Goodbye." << endl << endl;
       return 105;
   }

   //Determine if destination has more than 15 stairs

   cout << "Does the destination of this move have more than 15 stairs? (y/n): ";

   char move_destination;

   cin >> move_destination;

   cin.ignore (10, '\n');

   if (move_destination != 'Y' && move_destination != 'y' && move_destination != 'N' && 
       move_destination != 'n')
   {   cout << endl << "Please type y or n as the input for the stairs questions." << endl; 
       cout << "The program wil now end, Goodbye." << endl << endl;
       return 106;
   }

   int move_stairs = 0;

   string answer_origin, answer_destination;

   if (move_origin == 'Y' || move_origin == 'y')
   {   move_stairs += 1;
       answer_origin = "yes";
   }

   if (move_origin == 'N' || move_origin == 'n')
   {   answer_origin = "no";
   }

   if (move_destination == 'Y' || move_destination == 'y')
   {   move_stairs += 1;
       answer_destination = "yes";
   }

    if (move_destination == 'N' || move_destination == 'n')
   {   answer_destination = "no";
   }

   //Calculate output

   double packing_cost, moving_cost, piano_surcharge, stairs_surcharge, total_cost;

   string move_choice;

   if (move_type == 'B' || move_type == 'b')
   {   packing_cost = PRICE_PER_POUND_FOR_PACKING_AND_LOADING_B * move_weight;
       moving_cost = PRICE_PER_POUND_PER_MILE_B * move_weight * move_distance;
       move_choice = "Basic";
   } 

   if (move_type == 'W' || move_type == 'w')
   {   packing_cost = PRICE_PER_POUND_FOR_PACKING_AND_LOADING_W * move_weight; 
       moving_cost = PRICE_PER_POUND_PER_MILE_W * move_weight * move_distance;
       move_choice = "Wall Pack";
   } 

   if (move_type == 'C' || move_type == 'c')
   {   packing_cost = PRICE_PER_POUND_FOR_PACKING_AND_LOADING_C * move_weight;
       moving_cost = PRICE_PER_POUND_PER_MILE_C * move_weight * move_distance;
       move_choice = "Complete";
   } 

   if (move_stairs == 0)
   {   piano_surcharge = move_piano * 275;
       stairs_surcharge = 0;
   }
   
   if (move_stairs == 1)
   {   piano_surcharge = move_piano * 575;
       stairs_surcharge = 132;
   }

   if (move_stairs == 2)
   {   piano_surcharge = move_piano * 1075;
       stairs_surcharge = 264;
   }

   total_cost = packing_cost + moving_cost + piano_surcharge + stairs_surcharge;
   
   cout << endl << "\tYour entries for this move are:" << endl;
   cout << setw(14) << move_type << " - " << move_choice << " move type" << endl;
   cout << setw(14) << move_distance << " - miles from origin to destination" << endl;
   cout << setw(14) << move_weight << " - total pounds of contents to move" << endl;
   cout << setw(14) << move_piano << " - total number of pianos to move" << endl;
   cout << setw(14) << answer_origin << " - there are more than 15 stairs at the move origin" 
        << endl;
   cout << setw(14) << answer_destination 
        << " - there are more than 15 stairs at the move destination" << endl; 
   cout << setw(14) << move_stairs << " - locations with > 15 stairs."; 

   cout << fixed << showpoint << setprecision(2);

   cout << endl << endl << endl << endl; 
   cout << "\tYour cost for a " << move_choice << " move with these values is:" << endl;
   cout << "\t$" << setw(12) << packing_cost << " - packing cost" << endl;
   cout << "\t$" << setw(12) << moving_cost << " - moving cost" << endl; 
   cout << "\t$" << setw(12) << piano_surcharge << " - piano surcharge" << endl;
   cout << "\t$" << setw(12) << stairs_surcharge << " - stairs surcharge" << endl;
   cout << "\t----------------------------------" << endl;
   cout << "\t$" << setw(12) << total_cost << " - TOTAL"<< endl << endl; 
   cout << "Thank you for using the BHMSI price calculator." << endl << endl;  
   
   return 0;
   
}

