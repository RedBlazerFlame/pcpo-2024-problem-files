#include "testlib.h"
using namespace std;
typedef long long ll;

const int max_a = 1'000'000'000ll;

int main(int argc, char** argv) {
    // This line should always come at the start
    registerValidation(argc, argv);

    /*
    The input format is:
    a

    Where "a" is the input number
    */
   // Inf stands for "input file"
   int a = inf.readInt(/*Min value*/1, /*Max value*/ max_a, /*Variable name*/"a");
   
   // This reads the end of a line
   // In other words, it reads a line break ("\n") character
   inf.readEoln();

   // This reads the end of the file
   inf.readEof();

   // Needed in C++ programs
   return 0;
}