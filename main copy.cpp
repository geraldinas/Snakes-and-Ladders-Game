//
//  main.cpp
//  practice miny array project
//
//  Created by Geraldina Alvarez Garcia on 10/27/14.
//  Copyright (c) 2014 Geraldina Alvarez Garcia. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;


int main ()

{
    //Declaring variables
    int p; //player, will be inside player array
    int n;//board dimmensions
    char type;
    int offset;
    int pos;
    int dice;
    string text;
    
    
    srand(time(NULL));
    
    //The program is opening the text file
    fstream inputStream;
    inputStream.open ("input.txt"); //opens file
    
    // if (! inputStream)
    // cout<<"file"<<endl;
    
    
    //inputStream is getting the first 3 values in the text file
    inputStream >> n; //board
    inputStream >> p; //players
    inputStream >> dice;
    
    cout << "Hello this is a "<< p <<" Player, "<< n <<"x"<< n << " Snake and Ladders Game\n";
    
    
    int boardsize [145]; //establishes board size as array
    int players[5]; //establishes players as array
    
    for (int i = 0; i<p; i++) //sets players position 0
        players[i]=0;
    
    for (int i=0; i<145; i++) //sets board cells to 0
        boardsize[i]=0;
    
    while (inputStream >>type>>pos>>offset) {//getting information for last info on text file, retreving the Snakes and Ladders
        if (type =='S')  //The offset has to be set to be negative if the player gets a Snake
            boardsize[pos]= (offset * -1);
        if (type == 'L')
            boardsize[pos]= offset;
        //cout<<type<<" "<<pos<<" "<<offset<< endl;
        
    }
    inputStream.close();
    
    //game begins
    
    bool lose= true;
    //WHILE LOOP UNTIL SOMEONE WINS
    while (lose){
        for (int i = 0; i < p; i++) //adding dice and position
        {
            cout << "It is player " << i+1 << "'s turn" << endl;
            int totalRoll = 0;      //initiating dice value and total dice value
            int diceRoll = 0;
            
            
            do{
                
                diceRoll = (rand () % dice ) +1; //randome dice roll
                cout << "-- Rolled a " << diceRoll << endl;
                //totalRoll = totalRoll + diceRoll; //dice is rolling until diceroll is not =to 6
                players[i] = players[i] + diceRoll; //new position  of player //
                
                
                if( boardsize[players[i]] != 0){//jump to correct cell if S or L,,,, print if board size is <0 if >0
                    //cout<< ",board test "<< boardsize[players[i]]<<endl;
                    if (boardsize[players[i]] >0)
                        cout<<"You have landed on a ladder, please move up "<<boardsize[players[i]]<<" cells"<<endl;
                    if(boardsize[players[i]] <0)
                        cout<< "You have landed on a snake, please move back "<<boardsize[players[i]]<< "cells" <<endl;
                    
                    
                    cout << "current position = " <<players[i]<<endl;
                    players[i] = players[i]+ boardsize[players[i]];
                    //cout<< "offset "<< boardsize[players[i]]<<endl;
                    
                }
                cout <<"player "<< i << " "<<"is at cell " << players[i] <<endl;
                
                if (players[i] >= n*n){
                    lose = false;
                    cout << "Player " << i+1 << " in position: " << players[i] <<" "<<"WINS!!"<<" "<< endl;// players pos
                }
                
            }
            while(diceRoll == 6 && lose!=false);
            
            if (players[i]>=n*n)
                cout<<players[i]<<endl;
            //cout<< "This game is over" <<endl;
        }
        
        
        //END OF WHILE
        
        
        for(int i = 0; i < p; i++)
            if (players[i] >= n*n){
                cout << "Player " << i << " is at " << players[i] << endl;
                
                
            }
    }
    return 0;
    
}



