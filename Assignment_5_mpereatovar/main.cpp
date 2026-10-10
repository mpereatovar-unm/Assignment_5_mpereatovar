#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "pixel.h"

int main( int argc, char* argv[])

{
    if argc !=2)
    {
        std: : cerr <<"Usage: " << argv [0] << "pixels.dat\n";

        return 1; // Exit the program with an error code
    }

    std::string filename = argv[1]; // stores the command-line filename
    std::ifstream input_file(filename); // Open the input file for reading

    if (!input_file.is_open())
    {
        std::cerr << "Error opening file: " << filename << "\n";
        return 1; // Exit the program with an error code
    }
    std::vector<Pixel> pixels_list; // Create an empty list of pixels
    std::string line;

    while (std::getline(input_file, line))
    {
        std::string values[5]; //array holds the five values
        std::size_t start = 0; //index for parsing the line

        for (int i= 0; i < 4; i++) 
        { 
            std::size_t comma = line.find(',', start);
            values[i] = line.substr(start, comma - start);
            start = comma + 1; //Move past the comma to the next value.

        }



    return 0;
}

