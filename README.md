# blob_counter
C++ implementation of a "blob counter"

The project was from Data Structures Summer '13, USF. Project requirements given:

Please see mrBlob_project2_maynard.pdf for overview. 

********************************************************

Assume that you will read in an input file "grid.txt" (in the same directory as your code) that contains 0s (empty cells) and 1s (asterisk-filled cells) in a rectangular 2D grid shape. You should read in this file, create the grid with asterisks in the appropriate places, and draw it in the terminal window. (You do not have to draw grid lines, just the asterisks separated by empty spaces, as appropriate). The size of this grid could vary, to you will have to use dynamic memory allocation. 

Your program should then determine the number of blobs in the grid with a recursive function. One way to do this is to iterate through the grid until you find an asterisk, and then use recursive depth-first search (DFS) to "explore" the blob, marking each asterisk as a member of that blob (e.g. by replacing the asterisk with the current blob number). Output the total number of blobs to the terminal.

Submit your code along with a makefile on Blackboard. The binary object file that your makefile creates should be named "blobCount", so that I can test each project by running your make file and then executing ./blobCount

Grading will be based on your project's ability to solve several different input grids, including its ability to catch error conditions. Projects that do not compile will receive a grade of 0. If you would like the option of disputing your grade for any reason, you must do so during office hours within one week of receiving your grade, and you must make sure that your submitted code is well-commented. Sanity is a precious thing, and mine will not be squandered on uncommented code.

I'll be grading in a Linux environment, so please make sure your project will compile in Linux. It probably will, regardless, but double-checking never hurt anyone.
