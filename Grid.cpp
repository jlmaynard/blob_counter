//
//  Grid.cpp
//
//  Implements Grid.h
//

#include <iostream>
#include <fstream>
#include <vector>

#include "Grid.h"

using namespace std;

// Constructors -------------------------------------------------------
Grid::Grid () // Default constructor
{
   // Create empty grid object
}

// Creates grid object by passing a reference to input file stream
Grid::Grid(ifstream& f)
{
   // Read the character from the file stream
   _c = f.get();
   
   // If the char is not the end of file then... 
   while (_c != EOF)
   {
      vector<char> row; // Create an temp row to fill with chars
      
      // If the char is not a new line then.. 
      while (_c != '\n')
      {
         //
         // fill the first row
         //
         if (_c == '1')
         {
            //change the '1's from the input file to '*' for printing
            _c = '*';
            //push the value to the end of the row
            row.push_back(_c);
            _c = f.get();
         }
         else if (_c == '0')
         {
            //change the '0's from the input file to ' ' for printing
            _c = ' ';
            //push the value to the end of the row
            row.push_back(_c);
            _c = f.get();
         }
         else if (_c == ' ')
         {
            // do nothing
            _c = f.get();
         }
         else if (_c != '0' && _c != '1' && _c != ' ' && _c != -1)
         {
            // If chars aren't '1', '0', ' ', or '\n' break out
            cout << "\n*** ERROR BUILDING GRID - BAD CHAR ***" << endl;
            break;
         }
         else
         {
            break; 
         }
         
      }//end while (c!='\n')
      
      //
      // We now have a row filled with '*'s and ' 's. Push the row on the
      // grid and get the next char to start building the next row.
      //
      _aGrid.push_back(row);
      _c = f.get();
      
   }//end while (!eof)   
   
   // Potential enhancement - Perform check to make esure all columns are
   // same size, if not return error. For now we assume a well formed grid
   // as an input per Catrain's email 7/6/13
   
}
// End Constructors ------------------------------------------------------------


// Getters & setters -----------------------------------------------------------
unsigned long Grid::getNumRows() const
{
   return _aGrid.size(); 
}

unsigned long Grid::getNumCols() const
{   
   //
   // Returns the size of the first row
   // This assumes that each row has the same size as row 0
   // More error checking could be done to validat that all
   // rows are the same size but assume the input file
   // has a gird in which all rows are of equal size.
   //
   return _aGrid[0].size();
}

char Grid::getGridCell(int r, int c)
{
   return _aGrid[r][c];
}

// End Getters & setters -------------------------------------------------------

// print the grid to the console screen showing the size, rows, cols
// and filled cells
void Grid::displayGrid()
{
   for (int r = 0; r < getNumRows(); r++)
      for (int c = 0; c < getNumCols(); c++)
      {
         cout << _aGrid[r][c];
         if (c == (getNumCols() - 1))
            cout << endl; 
      }
}

