#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include <cmath>
using namespace std;

string dec_to_binary(int dec);
string reg_to_bin(string reg);


int main()
{
ifstream fin("projectTestInput.txt");
ofstream out("projectTestOutput.txt");

if(fin.fail())
{
cout << "File open failed\n";
exit(0);
}

string opcode;//to hold value for opcode
//the following emojis are the only possible opcode instructions
string banana = "🍌"; //hardcode input-GOOD
string coconut = "🥥"; //User-Input-GOOD
string grape = "🍇"; //div-GOOD
string strawberry = "🍓"; //sum-GOOD
string eggplant = "🍆"; //sub-GOOD
string pineapple = "🍍"; //ARRAY
string lemon = "🍋" ; // out-GOOD
string apple = "🍎"; // mult-GOOD
string kiwi = "🥝"; // INPUT-GOOD
string repeat = "🔁"; // Make array and display sum-GOOD
string clear = "✖️"; // Clear-good
string halt = "🚫"; // Halt-GOOD
string potato = "🥔"; // Array Num Search - GOOD

int num;
string regis;

while(!fin.eof())
{
fin >> opcode;

if(opcode == banana)
{
out << "0011";
fin >> num;
out << dec_to_binary(num);
fin >> regis;
out << reg_to_bin(regis);
out << endl;
}
else if(opcode == potato)
{
    out << "0100";
    fin >> regis;
    out << reg_to_bin(regis);
    out << "000000\n";
}
else if(opcode == coconut)
{
    out << "1000";
    fin >> regis;
    out << reg_to_bin(regis);
    out << "000000";
    out << endl;
}
else if(opcode == grape)
{
out << "1100";
for(int i = 0; i < 3; i++)
{
fin >> regis;
out << reg_to_bin(regis);
}
out << endl;
}
else if(opcode == strawberry)
{
out << "0101";
for(int i = 0; i < 3; i++)
{
fin >> regis;
out << reg_to_bin(regis);
}
out << endl;
}
else if(opcode == eggplant)
{
out << "0111";
for(int i = 0; i < 3; i++)
{
fin >> regis;
out << reg_to_bin(regis);
}
out << endl;
}
else if(opcode == repeat)
{
    out << "1011";
    fin >> regis;
    out << reg_to_bin(regis);
    out << "000000";
    out << endl;
}
else if(opcode == apple)
{
out << "1010";
for(int i = 0; i < 3; i++)
{
fin >> regis;
out << reg_to_bin(regis);
}
out << endl;
}
else if(opcode == kiwi)
{
    out << "1101";
    fin >> regis;
    out << reg_to_bin(regis);
    out << "000000";
    out << endl;
}
else if(opcode == lemon)
{
out << "1111";
fin >> regis;
out << reg_to_bin(regis);
out << "000000\n";
}
else if(opcode == halt)
{
out << "0001";
out << "000000000";
out << endl;
}
else if(opcode == pineapple)
{
    out << "1001";
    fin >> regis;
    out << reg_to_bin(regis);
    out << "000000";
    out << endl;
}
else if(opcode == clear)
{
out << "0000";
out << "000000000";
out << endl;
}
else
{
cout << "ERROR: INSTRUCTION DOESN'T EXIST\n";
exit(0);
}
}

fin.close();
out.close();


return 0;
}

string dec_to_binary(int dec)
{
string bin = "";

if(dec == 0)
return "0000000";

while(dec / 2 != 0)
{
bin = to_string(dec % 2) + bin;
dec /= 2;
}

bin = "1" + bin;

while(bin.size() < 6)
bin = "0" + bin;

return bin;
}

string reg_to_bin(string reg)
{
if(reg == "R1")
return "000";
else if(reg == "R2")
return "001";
else if(reg == "R3")
return "010";
else if(reg == "R4")
return "011";
else if(reg == "R5")
return "100";
else if(reg == "R6")
return "101";
else if(reg == "R7")
return "110";
else if(reg == "R8")
return "111";
else if(reg == "A1")
return "000";
else if(reg == "A2")
return "111";
else
{
cout << "Error\n";
return 0;
}
}

