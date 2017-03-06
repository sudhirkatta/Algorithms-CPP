#include <fstream>
#include <iostream>
#include <string>

class Encodedecodestream {

public:
  // encode() must read a single specified file/message from disk and place
  // your encoded version of the message in a provided ostream.
  // Sequential calls to encode() with the same ostream must be supported.
  void encode(const std::string &inputFilename, std::ostream &out) {

    std::filebuf filebuffer;
    if (filebuffer.open(inputFilename, std::ios::in)) {
      std::istream istream(&filebuffer);
      while (istream) {
        // std::cout << char(istream.get());
        out << char(istream.get());
      }
      filebuffer.close();
    } else {
      std::cout << "Could not open input file\n";
    }
  }

  // decode() must read a single encoded message from the provided istream
  // and write it to the specified file. The contents of the file written
  // by decode() for a given message should be identical to the
  // corresponding file read by encode().
  void decode(std::istream &in, const std::string &outputFilename) {
    std::filebuf filebuffer;
    if (filebuffer.open(outputFilename, std::ios::out)) {
      std::ostream outstream(&filebuffer);
      while (in) {
        // std::cout << char(in.get());
        outstream << char(in.get());
      }
      filebuffer.close();
    } else {
      std::cout << "Could not open output file\n";
    }
  }
};

int main(int argc, char *argv[]) {

  // check for two argc
  if (argc != 3) {
    // We print argv[0] assuming it is the program name
    std::cout << "usage: " << argv[0] << " <input filename>"
              << " <output filename>\n";
  } else {

    Encodedecodestream encodedecode;

    // encode
    // read argument 1
    std::filebuf fb;
    if (fb.open(argv[1], std::ios::in)) {
      std::ostream outstream(&fb);
      encodedecode.encode(argv[1], outstream);
    } else {
      std::cout << "Could not open input file\n";
    }

    // decode
    // read argument 2
    std::filebuf fb1;
    if (fb1.open(argv[2], std::ios::out)) {
      std::istream instream(&fb);
      encodedecode.decode(instream, argv[2]);
    } else {
      std::cout << "Could not open output file\n";
    }

    // The following code is to test the concept using left for refrence
    /*
        // argv[1] is a filename to open
        std::ifstream inputfile;
        inputfile.open(argv[1], std::ios::in);
        // check if the file opening succeeded
        if (!inputfile.is_open())
          std::cout << "Could not open file\n";
        else {
          // argv[2] is a output filename
          std::ofstream outputfile(argv[2], std::ios::out | std::ios::binary);

          if (!outputfile.is_open())
            std::cout << "Could not open output file\n";
          else {
            inputfile.seekg(std::ios::beg);

            char x;
            // inputfile.get ( x ) returns false if the end of the file is
       reached
            // or an error occurs
            while (inputfile.get(x)) {
              outputfile << x;
            }
          }
          outputfile.close();
        }*/
    // inputfile is closed implicitly here
    // inputfile.close();
  }
}
