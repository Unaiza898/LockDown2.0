
// C program to print 
// message as colored characters 
// Program compiles data of different boroughs in New York and tells the user about the covid rates in that borough.  
// Dynamic array holds testing facilities in every borough. 
// Tells options for the testing and isolations rooms (data from the files)
// If they test positive, what will happen?


#include "header.h"
#include"borough.h"
#include "Location.h"

void restriction();
void readinFile();
void intro();
void Covidcases();
string* testing_locationstatenIsland();
int cases[5];
const int DIM = 3;
string chessboard[DIM][DIM];
void testingLocation();
void Laughter();

void games();
void initChessBoard(string cb[][DIM]);
void printChessBoard(string cb[][DIM]);
bool putChequer(string cb[][DIM], int i, int j, string x);
bool state(string cb[][DIM], int row, int col, string x);
void craps();
void playMadlibs();
int Diceroll();
void playtictactoe();
using namespace std;



int main() {

    intro();

}


void readinFile() {
    ifstream inData;
    string Address[5];

    inData.open("Covid.txt");

    if (inData.fail()) {
        cerr << "Error Opening file. This program will now terminate." << endl;
        exit(1);
    }
    // use getline
    for (int i = 0; i < 5; i++) {
        inData >> cases[i];
    }
    inData.close();
}
void intro() {
    char temp;
    do {
        system("cls");
        cout << YELLOW << "\n\n\n\tMAIN MENU" << RESET;
        cout << BOLDBLUE << "\n\n\t01. COVID CASES IN NYC";
        cout << "\n\n\t02. TESTING LOCATIONS";
        cout << "\n\n\t03. RESTRICTIONS";
        cout << "\n\n\t04. PLAY A GAME";
        cout << "\n\n\t05. QUARANTINE SURVIVAL CHECKLIST";
        cout << "\n\n\t06. HOW YOU CAN HELP";
        cout << "\n\n\t07. EXIT";
        cout << "\n\n\tSelect Your Option (1-7) ";
        cout << RESET;
        cin >> temp;
        system("cls");
        switch (temp) {
        case '1':

            Covidcases();
            break;
        case '2':
            testingLocation();

            break;
        case '3':
            restriction();

            break;
        case '4':
            games();

            break;
        case '5':
            Laughter();
            break;
        case '6':
            cout << BOLDRED << "***********************" << endl;
            cout << "Wear a mask!\n\n";
            cout << "***********************" << RESET;
            break;
        case '7':
            exit(0);
            break;


        default:
            cout << "\a";
        }
        cin.ignore();
        cin.get();
    } while (temp != '7');
}

void Covidcases() {

    readinFile();
    Borough statenIsland("Staten Island", cases[1]);
    Borough Brox("Bronx", cases[0]);
    Borough Queens("Queens", cases[2]);
    Borough Broklyn("Brooklyn", cases[3]);
    Borough Manhatton("Manhattan", cases[4]);

    int number;
    cout << "Which borough would you like to know the Covid rates for?" << endl;
    cout << "\n\n\t01. STATEN ISLAND";
    cout << "\n\n\t02. BRONX";
    cout << "\n\n\t03. BROOKLYN";
    cout << "\n\n\t04. MANHATTAN";
    cout << "\n\n\t05. QUEENS";

    cout << "\n\n\tSelect Your Option (1-5): ";
    cin >> number;
   

    switch (number) {
    case 1:
        cout << "The Total cases in "<< statenIsland.getName()  <<" are " << statenIsland.getPeopleInfected() << endl;
        break;
    case 2:
        cout << "The Total cases in the " << Brox.getName() <<" are " << Brox.getPeopleInfected() << endl;
        break;
    case 3:
        cout << "The Total cases in " << Broklyn.getName() << " are " << Broklyn.getPeopleInfected() << endl;
        break;
    case 4:
        cout << "The Total cases in" << Manhatton.getName() << " are " << Manhatton.getPeopleInfected() << endl;
        break;
    case 5:
        cout << "The Total cases in " << Queens.getName() << " are " << Queens.getPeopleInfected() << endl;
        break;
    default:
        cout << "\a";
    }
}

string* testing_locationstatenIsland() {
    ifstream in;
    string* name = new string[5];

    in.open("Testing.txt");
    if (in.fail()) {
        cerr << "Error opening file. This program will now terminate." << endl;
        exit(1);
    }


    for (int i = 0; i < 5; i++)
    {
        getline(in, name[i]);

    }

    in.close();
    return name;
};


void testingLocation()
{
    string* name;
    name = testing_locationstatenIsland();
    //Location(string name, string address, string phoneNumber, int openingTime, int closingTime, Site SiteType);

    Location staten(name[0], "1445 Richmond Ave Ste E, Staten Island, NY 10314", "(929)219-0622", "8:00 AM", "9:00 PM", testing);

    Location Bronx(name[3], "2902 3rd Ave., The Bronx, NY 10455", "(718)571-9276", "8:00 AM", "6:30 PM", testing); // regular time
    Location Queens(name[4], "74-25 Grand Ave, Queens, NY 11373", "(718)803-2273", "9:00 AM", "7:30 PM", testing);
    Location Brooklyn(name[1], "5024 5th Ave, Brooklyn, NY 11220", "1(718)571-9251", "8:00 AM", "6:30 PM", testing);
    Location Manhattan(name[2], "343 W 21st St, New York, NY 10011", "1(800)544-9177", "10:00 AM", "4:30 PM", testing);
    int number;
    string response;
    cout << "Which borough would you like to know the Covid Testing location of?" << endl;
    cout << "\n\n\t01. STATEN ISLAND";
    cout << "\n\n\t02. BROOKLYN";
    cout << "\n\n\t03. MANHATTAN";
    cout << "\n\n\t04. BRONX";
    cout << "\n\n\t05. QUEENS";
    cout << endl;
    cout << "select numbers(1-5)" << endl;
    cin >> number;
    switch (number) {
    case 1:
        cout << endl;
        cout << "The testing location for Staten Island is: " << name[0] << endl;
        cout << " Address: " << staten.getAddress() << endl;
        cout << " If you want to contact for appointment details call " << staten.getPhoneNumber() << " The site opens at " << staten.getOpeningTime() << " and closes at " << staten.getClosingTime() << endl;
        cout << "Do you want to book an appointment ? ( yes/no)" << endl;
        cin >> response;
        if (response == "yes")
        {
            cout << "Please visit this website for appointment \n https://www.gohealthuc.com/nyc/staten-island/bulls-head?utm_source=GMB_appointment&utm_medium=organic or call at" << staten.getPhoneNumber() << "for more details";
        }
        break;
    case 2:
        cout << "The testing location for Brooklyn is: " << name[1] << endl;
        cout << " Address: " << Brooklyn.getAddress() << endl;
        cout << " If you want to contact for appointment details call " << Brooklyn.getPhoneNumber() << " The site opens at " << Brooklyn.getOpeningTime() << " and closes at " << Brooklyn.getClosingTime() << endl;

        cout << "Do you want to book an appointment ? ( yes/no)" << endl;

        cin >> response;

        if (response == "yes")
        {
            cout << "Please visit this website for appointment \n https://www.citymd.com/urgent-care-locations/ny/brooklyn/park-slope/211 or call at" << Brooklyn.getPhoneNumber() << "for more details";
        }



        break;
    case 3:
        cout << "The testing location for Manhattan is: " << name[2] << endl;
        cout << " Address: " << Manhattan.getAddress() << endl;
        cout << " If you want to contact for appointment details call " << Manhattan.getPhoneNumber() << " The site opens at " << Manhattan.getOpeningTime() << " and closes at " << Manhattan.getClosingTime() << endl;
        cout << endl;
        cout << "Do you want to book an appointment ? ( yes/no)" << endl;

        cin >> response;

        if (response == "yes")
        {
            cout << "Please visit this website for appointment \n  https://www.citymd.com/urgent-care-locations/ny/manhattan/chambers/037 or call at" << Manhattan.getPhoneNumber() << "for more details";
        }

        break;
    case 4:
        cout << "The testing location for the Bronx is: " << name[3] << endl;
        cout << " Address: " << Bronx.getAddress() << endl;
        cout << " If you want to contact for appointment details call " << Bronx.getPhoneNumber() << " The site opens at " << Bronx.getOpeningTime() << " and closes at " << Bronx.getClosingTime() << endl;
        cout << "Do you want to book an appointment ? ( yes/no)" << endl;

        cin >> response;

        if (response == "yes")
        {
            cout << "Please visit this website for appointment \n  https://www.citymd.com/urgent-care-locations/ny/bronx/south-bronx-the-hub/090  or call at" << Bronx.getPhoneNumber() << "for more details";
        }
        break;
    case 5:
        cout << "The testing location for Queens is: " << name[4] << endl;
        cout << " Address: " << Queens.getAddress() << endl;
        cout << " If you want to contact for appointment details call " << Queens.getPhoneNumber() << " The site opens at " << Queens.getOpeningTime() << " and closes at " << Queens.getClosingTime() << endl;
        break;
        cout << "Do you want to book an appointment ? ( yes/no)" << endl;

        cin >> response;

        if (response == "yes")
        {
            cout << "Please visit this website for appointment \n  https://www.citymd.com/urgent-care-locations/ny/queens/maspeth/209 or call at" << Queens.getPhoneNumber() << "for more details";
        }
    default:
        cout << "\a";
    }
    delete[] name;
    name = nullptr;
}



void games()
{
    int choice;
    cout << "Which games would you like to play" << endl;
    cout << "\n\n\t1- Tic-Tac-Toe" << endl;
    cout << "\n\n\t2- MADLIBS" << endl;
    cout << "\n\n\t3- CRAPS" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
        system("cls");
        playtictactoe();
    case 2:
        system("cls");
        playMadlibs();
    case 3:
        system("cls");
        craps();



    }

}
int pointer;
string Game;
double sumofWinLoss;



void craps()
{
    int sum;
    int countWin = 0;
    int countLose = 0;
    double probability = 0;
    srand(time(NULL));

    cout << "************************" << endl;
    cout << "***WELCOME TO CRAPS!!***" << endl;
    cout << "************************" << endl;
    cout << endl;

   
  
        sum = Diceroll();


        if ((sum == 7) || (sum == 11))
        {
            cout << "Your total sum is: " << sum << endl;
            Game = "Yay!!  You win !!! ";
            cout << Game << endl;
            countWin++;
        }
        else if (sum >= 4 && sum <= 10)
        {
            cout << "Your total sum is: " << sum << endl;
            // continue will continue to roll the dice until u reach the same sum as before or get 7.
            Game = "Continue";
            cout << Game << endl;
            cout << "Dont lose hope , You still have a chance to WIN. " << endl;
            
            pointer = sum;

        }
        else
        {
            cout << "Your total sum is: " << sum << endl;
            Game = " You lose ";
            cout << Game << endl;
            countLose++;
        }

        while (Game == "Continue")
        {
            sum = Diceroll();

            if (sum == pointer)
            {
                Game = " You win";
                cout << "Your total sum is: " << sum << endl;
                Game = "Yay!!  You win !!! ";
                countWin++;

            }
            else if (sum == 7)
            {
                cout << "Your total sum is: " << sum << endl;
                Game = " You lose";
                
                cout << Game << endl;
                countLose++;
            }


        }
   




}

int Diceroll()
{
    int dice1, dice2;

    int Dicesum;


    dice1 = (rand() % 6 + 1);

    dice2 = (rand() % 6 + 1);
    Dicesum = dice1 + dice2;

    //cout << "You rolled " << dice1 << "+"<< dice2  << "=" << Dicesum << endl;

    return Dicesum;


}








void playMadlibs() {
      srand(time(NULL));
    int num;
    num = (rand() % 3 + 1);




    switch(num)
    {
    case 1:
    {
        //Declare variables to store words
        string place1, place2, color, pluralNoun1;
        string pluralNoun2, singularNoun;
        string adverb, adjective;
        string animals, professional;
        string verb, substance, emotion;
        string exclamation;
        //Begin game
        cout << "\t\tWelcome to Mad Libs!" << endl << endl;
        //Prompt user for input
        cout << "Please enter ONE WORD for each of the following:" << endl
            //Single-word strings eliminate the need for the getline function.
            << endl << "2 places (no proper nouns): " << endl << endl;
        cin >> place1;
        cout << endl;
        cin >> place2;
        cout << endl << "A color: " << endl << endl;
        cin >> color;
        cout << endl << "2 plural nouns:" << endl << endl;
        cin >> pluralNoun1;
        cout << endl;
        cin >> pluralNoun2;
        cout << endl << "A singular noun" << endl << endl;
        cin >> singularNoun;
        cout << endl << "An adverb, followed by an adjective: ";
        cout << endl << endl;
        cin >> adverb;
        cout << endl;
        cin >> adjective;
        cout << endl << "A type of animal (plural), followed by a type "
            << "of professional: " << endl << endl;
        cin >> animals;
        cout << endl;
        cin >> professional;
        cout << endl << "A verb, a noun referring to a substance, "
            << "and an emotion : " << endl << endl;
        cin >> verb;
        cout << endl;
        cin >> substance;
        cout << endl;
        cin >> emotion;
        cout << endl << "An exclamation." << endl << endl;
        cin >> exclamation;

        cout << endl << "\tBob went to the " << place1 << " to buy some "
            << color << " " << pluralNoun1 << ". They cost him fifty " << endl
            << pluralNoun2 << ". He loaded them into his " << singularNoun
            << " and " << adverb << " drove them home. When" << endl << "he got to his "
            << place2 << ", he was very " << adjective << ". As he unloaded his "
            << pluralNoun1 << ", however," << endl << "he discovered that his "
            << place2 << " had become infested with " << animals << " in his absence."
            << " Bob " << endl << "called the " << professional << " to get rid of them, "
            << "but she said that she would take five hours" << endl << "to arrive. The "
            << animals << " began to " << verb << " the " << color << " " << pluralNoun1
            << " all over the place, until the " << endl << place2 << " burst into "
            << substance << "! Bob felt so " << emotion << " that he screamed, "
            << "\"" << exclamation << "!\"" << endl << endl;

        break;
       }

    case 2:

    {


        //Holds all variables for Madlibs game
        string firstVerb;
        string animalPlural;
        string plantPlural;
        //Holds 5 adjectives that the user will enter.
        string firstAdj, secondAdj, thirdAdj, fourthAdj, fifthAdj;
        string secondVerb;
        string firstNoun;
        string place;
        string nounPlural;
        string verbPast;

        cout << "Welcome to the MADLIBS game. "
            << "Please enter a verb, an animal (plural), a plant (plural), an adjective, "
            << "a verb, an adjective, a noun, a place, an adjective, another adjective, a noun (Plural), "
            << "an adjective, and a past tense verb in that order: " << std::endl;

        cin >> firstVerb >> animalPlural >> plantPlural >> firstAdj >> secondVerb >> secondAdj >> firstNoun >> place >> thirdAdj >> fourthAdj >> nounPlural
            >> fifthAdj >> verbPast;

        cout << "Yesterday, I went out walking, and somehow ended up in" << place << ". I saw " << plantPlural << " and " << animalPlural
            << " --it was !" << firstAdj << "But I started getting " << fourthAdj << " hungry, and needed to find my way home. But no matter where I, " << verbPast
            << "I couldn't see the path. I decided to go around the " << thirdAdj << firstNoun << " up ahead, and discovered that it led back home! "
            << "I was " << firstVerb << ". At dinner, when I told my " << fifthAdj << " story, my " << nounPlural << " looked at me with " << secondAdj << " expressions."
            << "Then they forbade me from ever " << secondVerb << " again. ";


    }


    case 3:

    {
        string sillyWord, lastName, illness, Pluralnoun, adjective1, adjective2, sillyWord2, place, number, adjective3;

        cout << "Let's play a MADLIBS game! You'll input some nouns, adjectives, and verbs and I'll make a story out of them." << endl;
        cout << "Enter a silly word: "; cin >> sillyWord;
        cout << "Enter a last name: "; cin >> lastName;
        cout << "Enter an illness: "; cin >> illness;
        cout << "Enter a plural noun: "; cin >> Pluralnoun;
        cout << "Enter an adjective: "; cin >> adjective1;
        cout << "Enter an adjective: "; cin >> adjective2;
        cout << "Enter a silly word: "; cin >> sillyWord2;
        cout << "Enter a place: "; cin >> place;
        cout << "Enter a number: "; cin >> number;
        cout << "Enter an adjective: "; cin >> adjective3;

        cout << "                                              Dear School Nurse:" << endl;
        cout << sillyWord;
        cout << ' ';
        cout << lastName;
        cout << " will not be attending school today." << endl;
        cout << " He/she has come down with a case of ";
        cout << illness;
        cout << " and has horrible ";
        cout << Pluralnoun; cout << " and a/an ";
        cout << adjective1; cout << " fever." << endl;
        cout << "We have made an appointment with the ";
        cout << adjective2;
        cout << " Dr.";
        cout << sillyWord2;
        cout << ", whom studied for many years in ";
        cout << place;
        cout << " and has ";
        cout << number;
        cout << " degrees in pediatrics.";
        cout << "\nHe will send you all the information you need." << endl;
        cout << "Thank you!" << endl;
        cout << "Sincerely," << endl;
        cout << "Mrs.";
        cout << adjective3 << endl;



    }
    }
    

}

//games

void playtictactoe()
{
    cout << "Let's play the TIC-TAC TOE GAME!!" << endl;
    int row, col;
    int blanks = DIM * DIM;
    cout << endl;
    initChessBoard(chessboard);
    printChessBoard(chessboard);
    string cur = "MASK";

    cout << "Input the position(row col), (-1 -1) for exit; It is the turn of " << cur << endl;
    cin >> row >> col;

    while (row != -1 && col != -1)
    {
        if (!putChequer(chessboard, row, col, cur))
        {
            cout << "Invalid move" << endl;
            printChessBoard(chessboard);
        }
        else
        {
            --blanks;
            printChessBoard(chessboard);
            if (state(chessboard, row, col, cur))
            {
                cout << cur << " Wins" << endl;
                exit(0);
            };
            if (blanks == 0)
            {
                cout << "Ties" << endl;
                exit(0);
            }
            if (cur == "VIRUS")
            {

                cur = "MASK";


            }
            else
            {

                cur = "VIRUS";
            }
        }
        cout << "Input the position(row col), (-1 -1) for exit; It is the turn of " << cur << endl;
        cin >> row >> col;
    }






}






void initChessBoard(string cb[][DIM])
{
    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {

            cb[i][j] = "BLANK";
        }
    }
    //set all the elements of the ChessBoard to ‘B’
    //Complete this part in the following:

}

//printChessBoard
void printChessBoard(string cb[][DIM])
{
    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {

            cout << " ";
            cout << cb[i][j];

        }
        cout << endl;

    }

    //print all the elements of the chessBoard with each row in one line
    //Complete this part in the following:

}

//putChequer
bool putChequer(string cb[][DIM], int i, int j, string x)
{
    if ((i >= 0 && i < DIM) && (j >= 0 && j < DIM) && (cb[i][j] == "BLANK"))
    {
        cb[i][j] = x;
        return true;
    }
    else
        return false;
    /* if i and j are not out of bound(that is, i and j are in the range of 0 and DIM-1) and cb[i][j] is not occupied(that is, the value of cb[i][j] is ‘B’), set cb[i][j] to be the value of x and return true. Otherwise, return false.*/
    // Complete this part in the following:

}
//judge the state of the game. The player has put x in the position (row, col). 
bool state(string cb[][DIM], int row, int col, string x)
{
    if (cb[0][col] == x && cb[1][col] == x && cb[2][col] == x)
    {
    }
    if (cb[row][0] == x && cb[row][1] == x && cb[row][2] == x)
    {
    }
    if (cb[row][2] == x && cb[row + 1][1] == x && cb[row + 2][0] == x)
    {
    }
    if (cb[row][0] == x && cb[row + 1][1] == x && cb[row + 2][2] == x)
    {
    }

    // If all the elements in this row are x, x wins
    // If all the elements in this column are x, x wins.
    // If x is in the main diagonal, and if all the elements in the main diagonal are x, x wins.
    // If x is in the opposite diagonal, and if all the elements in the opposite diagonal are x, x wins.
    /* We declare four variables count1, count2, count3, count4 to represent the occurrence number of x in row number row, column number col, in the main diagonal, and in the opposite diagonal. If after calculation, count1, count2, count3 or count4 equals to DIM, return true(that is, x wins). */
    int count1 = 0, count2 = 0, count3 = 0, count4 = 0;

    for (int i = 0; i < DIM; ++i)
    {
        // Complete this part in the following:
        // if the element in position (row, i) is x, count1 is increased by 1.
        if (cb[row][i] == x)
        {
            count3++;
        }

        // if the element in position (i, col) is x, count2 is increased by 1.
        if (cb[i][col] == x)
        {
            count2++;
        }
        /* if x is in the main diagonal, and the element in position (i, i) is x, count3 is increased by 1.*/
        if (cb[i][i] == x)
        {
            count1++;
        }

        /* if x is in the opposite diagonal, and the element in position (i, DIM-1-i) is x, count4 is increased by 1.*/
        if (cb[i][DIM - 1 - i] == x)
        {
            count4++;
        }



    }
    return (count1 == DIM || count2 == DIM || count3 == DIM || count4 == DIM);
}

void Laughter()
{
    cout << BOLDGREEN << "TOP 10 THINGS YOU NEED TO SURVIVE THE COVID-19 QUARANTINE:\n\n10. A MASK" << BOLDCYAN << "\n\nSo that no one can see that you have not shaved all week while you were stuck at home.\n\n" << BOLDGREEN << "9. A THERMOMETER\n\n" << BOLDCYAN << "So that you can check whether your computer is overheating from all those Zoom meetings!\n\n" << BOLDGREEN << "8. DUCT TAPE\n\n" << BOLDCYAN << "For when you are stuck at home 24 hours a day with someone who never shuts up voluntarily.\n\n" << BOLDGREEN << "7. BLANKETS\n\n" << BOLDCYAN << "So that no one on the other end of a Zoom meeting can tell that you're not wearing pants!\n\n" << BOLDGREEN << "6.BLEACH\n\n" << BOLDCYAN << "So that you can scrub all those bad memories out of your brain.\n\n" << BOLDGREEN << "5. FLOWER-SCENTED OR MOUNTAIN BREEZE-SCENTED DISINFECTING SPRAY\n\n" << BOLDCYAN << "Not for killing Coronavirus, but for reminding you what the heck the outdoors smells like!\n\n" << BOLDGREEN << "4. BACKUP GENERATOR\n\n" << BOLDCYAN << "Because if the TV loses power, there's nothing to stop you from going stir-crazy and killing each other!\n\n" << BOLDGREEN << "3. WINDOW CLEANER\n\n" << BOLDCYAN << "So that you can keep track of whether it is day or night.\n\n" << BOLDGREEN << "2. A PET\n\n" << BOLDCYAN << "Not for companionship, but just to give you a reason to get out of your chair.\n\n" << BOLDGREEN << "AND THE NUMBER ONE THING YOU NEED TO SURVIVE THE QUARANTINE IS: " << BOLDCYAN << "(drumroll)\n\n...\n\n...\n\n...\n\nThis link: www.ordertoiletpaper.com\n\n" << BOLDRED << "Laughter is the best medicine.\n\n" << RESET;
}





void restriction()
{
    char ans;

    cout << YELLOW << "******" << RESET << "" << YELLOW << "******" << RESET << endl;

    cout << "Fines for the violation of social distancing protocol range from $500 to $1000.\n" << endl;


    cout << "- Gatherings: Non-essential gatherings must be limited to no more than 10 people for both indoor and outdoor settings.\n -Any individual who encourages, promotes or organizes mass gatherings may be fined up to $15,000/day." << endl;

    cout << " Would you like to know what your cluster zone is? (Y/N) " << endl;

    cin >> ans;
    int number;
    if (ans == 'Y')
    {
        cout << BOLDRED << "Select your cluster or area  " << endl;


        cout << CYAN << " 1-Staten Island Cluster \n 2-Queens Cluster - Kew \n 3-Bronx East Cluster  \n 4-Bronx West Cluster \n 5-Brooklyn Cluster \n 6-Manhattan Cluster \n" << endl;
        cout << " Levels of restrictions based on severity: Red Zones = High , Orange Zones = Medium , and Yellow Zones = Low. " << endl;

        cin >> number;


        switch (number)
        {
        case 1:
            cout << BOLDYELLOW << " Parts of Staten Island will transition to an orange warning zone based on increasing 7-day positivity rates,\nnumber of cases, nand hospitalizations that meet the metrics for orange warning zone designation. " << RESET << endl;
            break;

        case 2:

            cout << BOLDCYAN << "The current Queens zone will be expanded to include additional communities which have seen an increase in both positivity\nand cases over the past ten days, and are currently over 2.5% positivity on the 7-day rolling average. Queens is the warning zone." << endl;

            break;
        case 3:
            cout << WHITE << "The Bronx has seen a rise in positive cases, and meets the metrics for a precautionary yellow zone." << endl;
            break;
        case 4:

            cout << GREEN << "The Bronx has seen a rise in positive cases, and meets the metrics for a precautionary yellow zone." << endl;
            break;
        case 5:
            cout << BOLDMAGENTA << "The zone has continued to demonstrate progress, so the orange zone has been changed to a yellow precautionary\nzone, and the current yellow buffer zone has been removed." << endl;
            break;
        case 6:

            cout << BOLDGREEN << "A new Yellow Precautionary Zone in the Washington Heights area went into effect 11/25 for businesses\nand 11/26 for schools due to increasing 7-day positivity rates, number of cases, and hospitalizations. " << endl;

            break;

        }
    }
}