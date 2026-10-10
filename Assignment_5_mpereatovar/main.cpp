#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "pixel.h"
#include <algorithm> // provided std:: sort() to order the pixels.

void average_colors(std::vector<Pixel> &pixels_list);
void flip_vertically(std::vector<Pixel> &pixels_list);


int main(int argc, char* argv[])

{
    if (argc != 2)
    {
        std::cerr <<"Usage: " << argv [0] << "pixels.dat\n";

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

        for (int i = 0; i < 4; i++) 
        { 
            std::size_t comma = line.find(',', start);
            values[i] = line.substr(start, comma - start);
            start = comma + 1; //Move past the comma to the next value.

        }
        values[4] = line.substr(start); // Get the last value after the last comma
        
        Pixel pixel; // Create a Pixel object for this line
       
        pixel.x = std::stoi(values[0]);
        pixel.y = std::stoi(values[1]);
        pixel.red = std::stoi(values[2]);
        pixel.green = std::stoi(values[3]);
        pixel.blue = std::stoi(values[4]);

        pixels_list.push_back(pixel); // Add the pixel to the list

    }

    /*Notes for me, program in C++
     reads the input file one line at a time using getline ().
    Each line contains five comma-separated values in order x, y, red, green, blue.
    A loop uses find () to locate the first four commas and substr() to extract the text between them.
    After each comma, the starting index moves to the next value. The stoi() function converts the x and y strings
    to integers, and stof () converts the red, green, and blue strings to floating-point numbers. These
    numbers assigned to a Pixel object, which is added to the end of the pixel_list vector.
    */
   
    input_file.close(); // Close the input file after reading all lines

    average_colors(pixels_list);
    flip_vertically(pixels_list);

    std::cout << "Pixel read: " << pixels_list.size() << "\n";

    /* Notes for me: sort() orders the pixels using the comparsion inside[]
    this unnamed function is called a lambda function. It compares pixels a and b,
    returning true when a should come first. It sorts by x first, then by y.
    The colors stay attached to each pixel as they are sorted.
    */


    std::sort(pixels_list.begin(), pixels_list.end(),
    [](const Pixel &a, const Pixel &b)
    {
        if (a.x != b.x) 
        {
            return a.x < b.x; //Smaller column comes first
        }
        return a.y < b.y; // Within a column, smaller row comes first
        
    });

    std::ofstream output_file("flipped.dat"); //Open the output file

        if (!output_file.is_open())
        {
            std::cerr << "Error to open output file: flipped.dat\n";

            return 1; 
        }

    output_file.precision (9);

    for (std:: size_t i = 0; i < pixels_list.size(); i++)
    {
        output_file 
        << pixels_list[i].x << "," 
        << pixels_list[i].y << "," 
        << pixels_list[i].red << "," 
        << pixels_list[i].green << "," 
        << pixels_list[i].blue << "\n";
    }

    output_file.close();
    
    if (!output_file)
    {
        std::cerr << "Error to close output file: flipped.dat\n";
        return 1;
    }
    
    std::cout << "Saved flipped.dat\n";    

    return 0; // Exit the program successfully
}

void average_colors(std::vector<Pixel> &pixels_list)
{
    if (pixels_list.empty())
    {
        std::cout << "No pixels to average.\n";
        return; // Exit the function if the list is empty

    }

    double red = 0, green = 0, blue = 0;
    for (std::size_t i = 0; i < pixels_list.size(); i++)
    {
        red += pixels_list[i].red;
        green += pixels_list[i].green;
        blue += pixels_list[i].blue;
    }


    std::cout << "Average red: " << red/ pixels_list.size() << '\n';
    std::cout << "Average green: " << green/ pixels_list.size() << '\n';
    std::cout << "Average blue: " << blue/ pixels_list.size() << '\n';

}

void flip_vertically(std::vector<Pixel> &pixels_list)

{
    
    for (std::size_t i = 0; i < pixels_list.size(); i++)
    {
        pixels_list[i].y = 255 - pixels_list[i].y; // Flip the y-coordinate vertically
    }    
}





