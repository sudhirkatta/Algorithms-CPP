instructions to run on Linux OS with gcc, c++11 and cmake(optional)

open terminal and navigate to encodedecode folder

to generate ASCII random test file use this command
$base64 /dev/urandom | head -c 10000000 > inputfile.txt
note in this case 10000000 is the number of ASCII characters and it will generate 10MB file

g++ -std=c++11 main.cpp -o encodedecode
./encodedecode inputfile.txt outputfile

I have included cmake file
do this
cmake .
make