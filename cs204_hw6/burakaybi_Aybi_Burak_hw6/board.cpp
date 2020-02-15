#include<iostream>
#include <iomanip>
#include"board.h"

using namespace std;

Board::Board()
		{
			cout<<setw(10)<<"P1"<< setw(20)<<"P2"<<endl;
			for (int row = 0; row < 6; row++)
			{
				for (int col = 0; col<6; col++)
				{
					theBoard[row][col] = 0;
				}
			}
		}

void Board::displayBoard() //setw kullanilcak !!!!
{
	
			for(int row = 0; row < 6; row++)
			{
				for(int col = 0; col < 6; col++)
				{
					cout <<setw(5)<< theBoard[row][col];
					if(col==2)
						cout<<setw(5)<<"|";
				}
				cout << endl;
			}
}

bool Board::putShip(int playerID, int shipID, int row_start, int col_start, int row_end, int col_end)
{
	
	if(row_start >= 6 || row_end >= 6 || row_start < 0 || row_end < 0)				//////////////////////////////////
		return false;

	if(playerID==1)					//												CHECKING INPUTS FOR PLAYERS AND SHIPS		
	{
		if(col_start >= 3 || col_end >= 3 || col_start < 0 || col_end <0) 
			return false;
	}																				///////////////////////////////////////
	else if(playerID==2)
		if(col_start <3 || col_end <3 || col_start >=6 || col_end >=6 )
			return false;
		
	else
		return false;

		
	if(theBoard[row_end][col_start] != 0 || theBoard[row_end][col_end] != 0)	
		return false;
	
	

	if(shipID==1)			//  2X1 OR 1X2 SHIP SHAPE CHECK 
	{
		if((abs(col_start-col_end)==1&& abs(row_start-row_end)==2) || (abs(col_start-col_end)==2&& abs(row_start-row_end)==1)) 
		{
			theBoard[row_start][col_start] = 1;	
			theBoard[row_end][col_end] = 1; 
			return true;
		}
		else 
			return false;

	}
			
	else if(shipID==2)   //1X3 OR 3X1 SHIP CHECK
	{
		if(abs(row_start-row_end)==1)
		{
			if(abs(col_start-col_end) == 3)												
			{
				theBoard[row_start][col_start] = 1;	
				theBoard[row_end][col_end] = 1; 
				return true;}
			else 
				return false;
		}
		else if(abs(col_start - col_end)==3)
		{
			if(abs(row_start-row_end) == 1)			{
				theBoard[row_start][col_start] = 1;	
				theBoard[row_end][col_end] = 1; 
				return true;}
			
		}

	theBoard[row_start][col_start] = 1;	
	theBoard[row_end][col_end] = 1;   
	
	return true;
	}
}

	

bool Board::makeAHit(int row, int col)   // HIT TO OTHER PALYER'S SHIP AND IF IT'S HAPPENED CELL GOES TO BE -1
{
	
			if(theBoard[row][col]=1)
			{
				theBoard[row][col] = -1;
				return true;
			}
			
			if(theBoard[row][col]=0)
			{
				return false;
			}
}

bool Board::checkIfPlayerWon() 
{
	for(int row = 0; row < 6; row++)
		for(int col = 0; col < 6; col++)
			if(theBoard[row][col] = 1)
				return false; //game is not yet won
			
	return true; 
}








