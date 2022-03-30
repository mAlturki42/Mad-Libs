
/*
    File Name: program4.cpp
    Author: Mohammed Alturki
    Date: November 9, 2020
    Purpose: Mad libs game. Taking answers from user and printing story.
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//function to print menu and get user choice and validating it then return choice
int showMenuGetChoice(){
    int choice;
    
    cout << "\n\nLet's Play some MADLIBS!!" << endl << endl;
    cout << "1. The Power of the Force (Star Wars Mad Libs)" << endl;
    cout << "2. Dog Days (Dog Ate My Mad Libs)" << endl;
    cout << "3. Talk Like a Pirate (Pirates Mad Libs)" << endl;
    cout << "4. END GAME" << endl << endl;
    cout << "CHOOSE 1-4:  ";
    cin >> choice;
    //validating user choice
    while(choice < 1 || choice > 4 )
    {
        cout << "Invalid Entry. Please choose 1-4: ";
        cin >> choice;
    }
    return choice;
}

//function to dynamically allocate a new string of this size then return arr
string *createStringArray(int size){
    string *arr = NULL;
    arr = new string[size];
    return arr;
}

//function to print questions and taking anwers from user
void getInfoFromUser(string *question, string *answer, int size){
    cout << "\nPlease give a response for each request: " << endl << endl;
    for(int i=0; i<size; i++){
        cout << *(question+i) << " ---> " ;
        getline(cin,*(answer+i));
    }
}

//function to print the story
void printStory(int choice, string *answer, int size){
    ifstream file;
    string str;
    int i=0;
    
    cout << endl;

    if(choice == 1){
        file.open("starWarsText.txt");
        if(!file){
            cout << "Could not open file." << endl;
        }
        
        while(getline(file,str)){
            //Print each line followed by its respective answers
            cout << str << *(answer+i);
            i++;
        }
        file.close();
    }

    else if(choice == 2){
        file.open("dogText.txt");
        if(!file){
            cout << "Could not open file." << endl;
        }

        while(getline(file,str)){
            cout << str << *(answer+i);
            i++;
        }
        file.close();
    }

    else if(choice == 3){
        file.open("pirateText.txt");
        if(!file){
            cout << "Could not open file." << endl;
        }

        while(getline(file,str)){
            cout << str << *(answer+i);
            i++;
        }
        file.close();
    }
    cout << endl;
}

int main(){
    int size;
    int i=0;
    ifstream file;
    string line; //to read questions line by line
    string temp;
    string *question;
    string *answer;
    int choice;
    bool runAgain = false;

    do{
        i=0;
        choice = showMenuGetChoice();
        switch(choice){
            case 1:
            file.open("starWars.txt");
            if(!file){
                cout << "Could not open file." << endl;
                break;
            }
            
            //temp will read first line in a string format
            getline(file,temp);
            //this will take the string form of integer and convert to integer
            size = stoi(temp); 
            cin.ignore();
            question = createStringArray(size); 
            
            while(!file.eof()){
                getline(file,line);
                *(question+i) = line;
                i++;
            }
            file.close();
        
            answer = createStringArray(size);
            getInfoFromUser(question, answer, size);
            printStory(choice,answer,size);
            break;

            case 2:
            file.open("dog.txt");
            if(!file){
                cout << "Could not open file." << endl;
                break;
            }

            //temp will read first line in a string format
            getline(file,temp);
            //this will take the string form of integer and convert to integer
            size = stoi(temp); 
            cin.ignore();
            question = createStringArray(size); 

            while(!file.eof()){
                getline(file,line);
                *(question+i) = line;
                i++;
            }
            file.close();

            answer = createStringArray(size);
            getInfoFromUser(question, answer, size);
            printStory(choice,answer,size);
            break;

            case 3:
            file.open("pirate.txt");
            if(!file){
                cout << "Could not open file." << endl;
                break;
            }

            //temp will read first line in a string format
            getline(file,temp);
            //this will take the string form of integer and convert to integer
            size = stoi(temp); 
            cin.ignore();
            question = createStringArray(size);  

            while(!file.eof()){
                getline(file,line);
                *(question+i) = line;
                i++;
            }
            file.close();

            answer = createStringArray(size);
            
            getInfoFromUser(question, answer, size);
            printStory(choice,answer,size);
            break;

            case 4:
            cout << "Game Ending." << endl;
            runAgain = false;
        } 
    }while(choice == 1 || choice == 2 || choice == 3);
}
