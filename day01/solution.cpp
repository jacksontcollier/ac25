#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
   if (argc != 2) {
      cout << "Usage: ./solution input.txt\n";
      return 0;
   }

   string infile = argv[1];
   ifstream fin;

   fin.open(infile, fstream::in);

   if (!fin.is_open()) {
      cout << "Failed to open " << infile << " for reading\n";
      return 0;
   }

   string line;
   char direction;
   int distance;
   int position = 50;
   int numtimes_zero_ending = 0;
   int numtimes_zero_total = 0;
   
   while (getline(fin, line)) {
      direction = line[0];
      distance = atoi(line.substr(1).c_str());

      if (direction == 'L') {
         distance = -distance;
      }

      while (distance != 0) {
         if (distance < 0) {
            //Left turn
            if (position > 0) {
               if (abs(distance) >= abs(position)) {
                  distance += position;
                  position = 0;
                  numtimes_zero_total++;
               } else {
                  position += distance;
                  distance = 0;
               }
            } else {
               if (abs(distance) < 100) {
                  position = 100 + distance;
                  distance = 0;
               } else {
                  distance += 100;
                  numtimes_zero_total++;
               }
            }
         } else {
            // Right turn
            if (distance + position > 99) {
               distance -= (100 - position);
               position = 0;
               numtimes_zero_total++;
            } else {
               position += distance;
               distance = 0;
            }
         }
      }

      if (position == 0) {
         numtimes_zero_ending++;
      }
   }

   cout << "Part 1 answer is " << numtimes_zero_ending << "\n";
   cout << "Part 2 answer is " << numtimes_zero_total << "\n";
   return 0;
}
