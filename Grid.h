//
//  Grid.h
//  mrBlob
//
// This is the header file defining the grid to be used in the problem
// The grid is a 2 dim dynamic array of characters holding either ' ' or '*'.
// The '*'s will be considered filled cells used to create blobs of
// linked cells

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#ifndef mrBlob_Grid_h
#define mrBlob_Grid_h

class Grid
{
public:
   // Constructors -------------------------------------------------------------
   Grid (); // Default constructor - Empty grid
   
   // Creates grid object by passing a reference to input file stream
   Grid (ifstream& f);
   
   // Getters & setters --------------------------------------------------------
   unsigned long getNumRows() const;
   void setNumRows();
   
   unsigned long getNumCols() const;
   // void setNumCols();
   
   // Gets the individusal cells within the grid
   char getGridCell(int r, int c);
   
   // Methods ------------------------------------------------------------------
   //
   // Print the grid to the console screen showing the size, rows, cols
   // and filled cells
   //
   void displayGrid();
   
private:
   // Data members -------------------------------------------------------------
   //
   // Can be accessed through the public getters and setters.
   // Private data members start with an _underscore.
   //
   // unsigned long used here to match return type of vector.size()
   // 
   char _c; // temp storage for reading characters from file
   
   //
   // Construct aGrid as an empty 2-dimensional vector
   // This is a vector [row] of vectors [col] (pg. 500 of book)
   //
   vector< vector<char> > _aGrid;
      
};//end class Grid

#endif
