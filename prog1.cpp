/*
Programmer: Hanna Zelis
Date: 14 September 2021
Program: Program 1 - Team Manager
Filename: ZelisProgram1.cpp 

Description: This program will read in a data file that lists football player's names, position, and other stat info. It will display the roster, determine the player with the highest number of touchdowns and display their name, and then alphabetize the roster so that the players names go from A to Z, including changing the info and stats about each specific player to be on the appropriate, corresponding row to the player's new alphabetized row. The roster can hold a max of 10 players. 

Assistance received from: N/A

Name of input file: TeamData.txt
(or whatever text file you want to use)

How to compile: g++ ZelisProgram1.cpp -o ZelisProgram1.out

How to execute: ./ZelisProgram1.out < TeamData.txt
(you can use another text file, but this text file name is to show a template of how to execute this program with your text file)

*/

#include <iostream>
#include <iomanip>



using namespace std;



const int numPlayers = 10;


//This struct holds the members of specific aspects of the football roster, including their name, the player's position, the number of touchdowns, catches, pass yards rec yards, adn rush yards
  struct rosterType
  {
      string name;
      string position;
      int touchDowns;
      int catches;
      int passYards;
      int recYards;
      int rushYards;
  };

//This creates the array of structs, allowing for easy access throughout the rest of the program
  rosterType players[10];



//function prototype: reads in the roster data from the data file
void readIn(rosterType players[]);

//function protoype: displays the data to the monitor
void displayData(rosterType players[]);

//function prototype: figures out and shows who has the highest number of touchdowns from the roster
void playerHighestTouchDowns(rosterType players[]);

//function prototype: sorts the roster alphabetically, which includes moving each players corresponding stats to where the player is alphabetically
void sort(rosterType players[]);




//The main function that will call the function prototypes from above; the random "cout << endl;" help with spacing when the program is displayed
int main()
{

  readIn(players);

  displayData(players);

  cout << endl;

  playerHighestTouchDowns(players);

  cout << endl;

  cout << "Here is the team roster sorted in alphabetical order:" << endl;

  cout << endl;

  sort(players);

  return 0;
}





//function that reads in the roster data from the data file
void readIn(rosterType players[])
{

  int i;

  //uses a for loop so to input all facts and stats of each player into the array at the appropriate corresponding index
  for (i = 0; i < 10; i++)
  {
    cin >> players[i].name;
    cin >> players[i].position;
    cin >> players[i].touchDowns;
    cin >> players[i].catches;
    cin >> players[i].passYards;
    cin >> players[i].recYards;
    cin >> players[i].rushYards;
  }

}





//function that displays the data to the monitor
void displayData(rosterType players[])
{

  cout << "Here is the team roster:" << endl;

  cout << endl;
  
  //spacing used in a certain way so that it looks like correct output and is spaced properly
  cout << setw(4) << "Name";
  cout << setw(14) << "Position";
  cout << setw(17) << "Touch Downs";
  cout << setw(8) << "Catches";
  cout << setw(12) << "Pass Yards";
  cout << setw(11) << "Rec Yards";
  cout << setw(11) << "Rush Yards" << endl;

  int i;

  
  //this for loop allows each player's info and stats to be printed out in their row before moving onto another row where the next player's info and stats will be displayed
  for (i = 0; i < 10; i++)
  {
    cout << left << setw(10) << players[i].name;
    cout << left << setw(12) << players[i].position;
    cout << right << setw(8) << players[i].touchDowns;
    cout << right << setw(9) << players[i].catches;
    cout << right << setw(12) << players[i].passYards;
    cout << right << setw(10) << players[i].recYards;
    cout << right << setw(12) << players[i].rushYards << endl;
  }

}





//function that determines which player on the roster has the most amount of touchdowns
void playerHighestTouchDowns(rosterType players[])
{

  int i, j;
  string highestNumTD;



  //uses bubble sort to find the player with the greatest number of touchdowns; if player i's touchdown number is greater than player j's touchdown number, then the variable "highestNumTD will replace its value with player i. At the end, the player with the highest number of touchdowns will have its name assigned to the variable "highestNumTD"
  for (i = 0; i < numPlayers; i++)
  {
    for (j = i + 1; j < numPlayers; j++)
    {
      if (players[i].touchDowns > players[j].touchDowns)
        highestNumTD = players[i].name;
    }
  }

  cout << "The player with the most touchdowns is " << highestNumTD << "." << endl;

}




//function that uses bubble sort by looking at the first index of the players name in the players[].name to put into alphabetical order. Because "A" have a lower value than "Z" on the ASCII table, the bubble sort sees whose first letter of their name has a lower index through the "<" sign. If two players' names have the same first letter, the second letter (index 1) of their name will be evaluated
void sort(rosterType players[])
{

  int i, j, tempTouchDowns, tempCatches, tempPassYards, tempRecYards, tempRushYards;
  string tempName, tempPosition;

  for (i = 0; i < 10; i++)
  {
    for (j = i + 1; j < 10; j++)
    {
      if (players[j].name[0] < players[i].name[0]) 
      {
        //which ever players name is at the beginning of the alphabet will have all of their personal stats and info moved to the appropriate and corresponding index (the index to where their name is alphabetically on the roster list)
        tempName = players[i].name;
        players[i].name = players[j].name;
        players[j].name = tempName;

        tempPosition = players[i].position;
        players[i].position = players[j].position;
        players[j].position = tempPosition;

	tempTouchDowns = players[i].touchDowns;
        players[i].touchDowns = players[j].touchDowns;
        players[j].touchDowns = tempTouchDowns;

        tempCatches = players[i].catches;
        players[i].catches = players[j].catches;
        players[j].catches = tempCatches;

        tempPassYards = players[i].passYards;
        players[i].passYards = players[j].passYards;
        players[j].passYards = tempPassYards;

        tempRecYards = players[i].recYards;
        players[i].recYards = players[j].recYards;
        players[j].recYards = tempRecYards;

        tempRushYards = players[i].rushYards;
        players[i].rushYards = players[j].rushYards;
        players[j].rushYards = tempRushYards;

       }
     }
   }


  cout << setw(4) << "Name";
  cout << setw(14) << "Position";
  cout << setw(17) << "Touch Downs";
  cout << setw(8) << "Catches";
  cout << setw(12) << "Pass Yards";
  cout << setw(11) << "Rec Yards";
  cout << setw(11) << "Rush Yards" << endl;


  for (i = 0; i < 10; i++)
  {
    cout << left << setw(10) << players[i].name;
    cout << left << setw(12) << players[i].position;
    cout << right << setw(8) << players[i].touchDowns;
    cout << right << setw(9) << players[i].catches;
    cout << right << setw(12) << players[i].passYards;
    cout << right << setw(10) << players[i].recYards;
    cout << right << setw(12) << players[i].rushYards << endl;
  }
  

}

