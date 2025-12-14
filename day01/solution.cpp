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
   int combination = 0;
   while (getline(fin, line)) {
      cout << line << "\n";
      direction = line[0];
      distance = atoi(line.substr(1).c_str());

      if (direction == 'L') {
         distance = -distance;
      }

      cout << distance << "\n";

      while (distance != 0) {
         if ((distance + position > 99)) {
            distance -= (100 - position);
            position = 0;
         } else if (distance + position < 0) {
            distance += (position + 1);
            position = 99;
         } else {
            position += distance;
            distance = 0;
         }
         cout << "distance is " << distance << "\n";
      }

      if (position == 0) {
         combination++;
      }
   }

   cout << "Combination is " << combination << "\n";
   return 0;
}
