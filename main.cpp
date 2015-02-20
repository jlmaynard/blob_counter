// Main.cpp
// 
// Data Structures
// 
// Project 2 - Due 7/9/13
// Jason Maynard
// U30503758
//
// Problem 21, ch10, pg581

#include <iostream>
#include <vector>
#include <fstream>
#include <cassert>
#include "Grid.h"
using namespace std;


// Set cells containing a '*' to filled
void setFilled(Grid& g, vector<vector<bool> >& filled);

// Set the filled array to false for all cells in array
void clearFilled(Grid& g, vector<vector<bool> >& filled);

// Set the visited cells to false for all cells in array
void clearVisited(Grid& g, vector<vector<bool> >& visited);

int sizeofBlob(int r, int c, const Grid& g,
               vector<vector<bool> >& filled,
               vector<vector<bool> >& visited); //ref to a grid


int main()
{
   // STEP 1 - READ GRID -------------------------------------------------------
   //
   // Read grid.txt file containing definition of grid
   //
   // First open an input stream to the file and test to make
   // sure it opened properly for reading with assert. 
   //
   ifstream inputFile("grid.txt");
   assert(inputFile.good());   
   
   // Print grid
   
   //
   // Instantiate new grid object from input file "grid.txt"
   //
   Grid g(inputFile);
   
   //
   // Close file connection when done with it.
   //
   inputFile.close();

   //
   // Print the grid so we know what it looks like
   //
   cout << "\nThe grid looks like this: " << endl; 
   g.displayGrid();
   
   // STEP 2 - FIND and COUNT BLOBS --------------------------------------------
   // 
   // Declare "filled" and "visited" vectors 
   //
   
   // Matching table of boolean values showing which cells are filled with '*'s
   
   unsigned long rows = g.getNumRows();
   unsigned long columns = g.getNumCols();
   
   vector<vector<bool> > filled(rows,
                                vector<bool>(columns, false));
   
   // Matching table of boolean values showing which cells have been visited
   vector<vector<bool> > visited(rows,
                                vector<bool>(columns, false));
   //
   // "Clear" visited and set all values to false
   //   
   clearVisited(g, visited);  //initialize visited to all false
   
   //
   // Set filled bool cells to true
   // We use "filled" when we are counting cells in blobs along with visited
   //
   setFilled(g, filled); //initialize filled with cells that are filled with '*'
   
   // To find a blob, traverse the grid
   //
   int blobCount = 0; // count blobs
   
   for (int r = 0; r < g.getNumRows(); r++)
   {
      for (int c = 0; c < g.getNumCols(); c++)
      {
         if (sizeofBlob(r,c, g, filled, visited) > 0) //recursive function
         {
            blobCount++;
         }
      }// end column
   }//end row
   
   // STEP 3 - DISPLAY RESULTS -------------------------------------------------
   //
   cout << "\nThe number of blobs in Grid 1 is: " << blobCount << endl;
   // --------------------------------------------------------------------------

}//end Main



// FUNCTION DEFINITIONS --------------------------------------------------------
//

// Set the filled array to false for all cells in array
void clearFilled(Grid& g, vector<vector<bool> >& filled)
{
   for (int r = 0; r < g.getNumRows(); r++)
      for (int c = 0; c < g.getNumCols(); c++)
      {
         filled[r][c] = false;
      }
}

// Set cells containing a '*' to filled
void setFilled(Grid& g, vector<vector<bool> >& filled)
{
   for (int r = 0; r < g.getNumRows(); r++)
      for (int c = 0; c < g.getNumCols(); c++)
      {
         if (g.getGridCell(r, c) == '*')
            filled[r][c] = true;
      }
}

// Set the visited cells to false for all cells in array
void clearVisited(Grid& g, vector<vector<bool> >& visited)
{
   for (int r = 0; r < g.getNumRows(); r++)
      for (int c = 0; c < g.getNumCols(); c++)
      {
         visited[r][c] = false;
      }
}

int sizeofBlob(int r, int c, const Grid& g,
               vector<vector<bool> >& filled,
               vector<vector<bool> >& visited) 
{
   //
   // Error checking. Don't walk of grid when looking for blobs
   //
   if (r < 0 || r >= g.getNumRows() || c < 0 || c >= g.getNumCols())
   {
      // This position is not in the grid, so there is
      // no blob at this position.  Return a blob size of zero.
      //
      return 0;
   }//end if "don't walk off grid"
   
   //
   // Look for cells that might have a blob.
   //
   if (filled[r][c] == false || visited[r][c] == true) {
      // This square is not part of a blob, or else it has
      // already been counted, so return zero.
      return 0;
   }//end if "not a new blob"
   
   //
   // Mark the square as visited so that we won't count it again during the
   // following recursive calls.
   //
   visited[r][c] = true;
   
   // Count the square at this position, then count the
   // the cells that are connected to this square
   // horizontally or vertically.
   //
   int size = 1; //local size var
   
   size += sizeofBlob(r-1, c, g, filled, visited);
   size += sizeofBlob(r+1, c, g, filled, visited);
   size += sizeofBlob(r, c-1, g, filled, visited);
   size += sizeofBlob(r, c+1, g, filled, visited);
   
   return size;   
   
}

// END - FUNCTION DEFINITIONS --------------------------------------------------


