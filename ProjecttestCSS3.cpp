/************************************************************************************** 
   Name: ProjecttestCSS3.cpp
   Authors: Kyle Batalla, Sergio Garcia, Jose Matamoros, Hector Lopez
   Class: CSS 3 Computer Architecture and Assembly Language Fall 2018
   Purpose: To file serves as the assembler part of the project.
   Description: This file reads the reads instructions and opcodes in projectTestIntput.txt
   then converts them into binary instructions then is outputted to projectTestOutput.txt
   so the simulator can read and execute the instructions and opcodes.
**************************************************************************************/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include <cmath>
using namespace std;

string dec_to_binary(int dec);//function to convert decimal to binary
string reg_to_bin(string reg);//function to convert register declarations to binary


int main()
{
ifstream fin("projectTestInput.txt");//opens .txt file with instructions and opcodes
ofstream out("projectTestOutput.txt");//assembles instruction and opcodes into binary in this file

if(fin.fail())
{
cout << "File open failed\n";
exit(0);
}

string opcode;//to hold value for opcode
//the following emoji declarations are the only possible opcode instructions
string banana = "🍌"; //Hardcode input
string coconut = "🥥"; //User-Input
string grape = "🍇"; //Division
string strawberry = "🍓"; //Addition
string eggplant = "🍆"; //Subtraction
string pineapple = "🍍"; //Allocate array and input values
string lemon = "🍋" ; //Output
string apple = "🍎"; //Multiplication
string kiwi = "🥝"; //User Input
string repeat = "🔁"; //Allocate array and display sum
string clear = "✖️"; //Clear registers
string halt = "🚫"; //Halt
string potato = "🥔"; // Array Num Search

int num;//to hold value of all decimal numbers
string regis;//to hold all register allcations

while(!fin.eof())//reads projectTestInput.txt
{
fin >> opcode;

if(opcode == banana)//converts banana instruction and operands into binary
{
out << "0011";
fin >> num;
out << dec_to_binary(num);
fin >> regis;
out << reg_to_bin(regis);
out << endl;
}
else if(opcode == potato)//converts potato instruction into binary
{
    out << "0100";
    fin >> regis;
    out << reg_to_bin(regis);//assigns instruction to register
    out << "000000\n";
}
else if(opcode == coconut)//converts coconut instruction into binary
{
    out << "1000";
    fin >> regis;
    out << reg_to_bin(regis);//assigns instruction to register
    out << "000000";
    out << endl;
}
else if(opcode == grape)//converts grape instruction and operands into binary 
{
out << "1100";
for(int i = 0; i < 3; i++)//creates 3 registers
{
fin >> regis;
out << reg_to_bin(regis);//assigns operands and result to registers
}
out << endl;
}
else if(opcode == strawberry)//converts strawberry instruction and operands into binary
{
out << "0101";
for(int i = 0; i < 3; i++)//creates 3 registers
{
fin >> regis;
out << reg_to_bin(regis);//assigns operands and result to registers
}
out << endl;
}
else if(opcode == eggplant)//converts eggplant instruction and operands into binary
{
out << "0111";
for(int i = 0; i < 3; i++)//creates 3 registers
{
fin >> regis;
out << reg_to_bin(regis);//assisngs operands and result to registers
}
out << endl;
}
else if(opcode == repeat)//converts repeat instruction into binary
{
    out << "1011";
    fin >> regis;
    out << reg_to_bin(regis);//assigns instruction to register
    out << "000000";
    out << endl;
}
else if(opcode == apple)//converts apple instruction and operands into binary
{
out << "1010";
for(int i = 0; i < 3; i++)//creates 3 registers
{
fin >> regis;
out << reg_to_bin(regis);//assigns operands and result to registers
}
out << endl;
}
else if(opcode == kiwi)//converts kiwi instruction and operands into binary
{
    out << "1101";
    fin >> regis;
    out << reg_to_bin(regis);//assigns instruction to register
    out << "000000";
    out << endl;
}
else if(opcode == lemon)//converts lemon instruction and operands into binary
{
out << "1111";
fin >> regis;
out << reg_to_bin(regis);//assigns instruction to register
out << "000000\n";
}
else if(opcode == halt)//converts halt instruction into binary
{
out << "0001";
out << "000000000";
out << endl;
}
else if(opcode == pineapple)//converts pineapple instruction into binary
{
    out << "1001";
    fin >> regis;
    out << reg_to_bin(regis);//assigns instruction to register
    out << "000000";
    out << endl;
}
else if(opcode == clear)//converts clear instruction into binary
{
out << "0000";
out << "000000000";
out << endl;
}
else//outputs error if instruction is not recognized
{
cout << "ERROR: INSTRUCTION DOESN'T EXIST\n";
exit(0);
}
}

fin.close();
out.close();


return 0;
}

string dec_to_binary(int dec)//function to convert decimal to binary
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

string reg_to_bin(string reg)//converts register allocations into binary
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

