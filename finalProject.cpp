/*#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include <cmath>
using namespace std;

string dec_to_binary(int dec);
string reg_to_bin(string reg);
int bin_to_dec(string bin);
int bin_to_reg(string bin);


int main()
{
ifstream fin("emojiTest.txt");
ofstream out("emoji.txt");

if(fin.fail())
{
cout << "File open failed\n";
exit(0);
}

string opcode;
string banana = "🍌";
string grape = "🍇";
string strawberry = "🍓";
int num;
string regis;

while(!fin.eof())
{
fin >> opcode;
cout << opcode << endl;
if(opcode == banana)
{
out << "0011 ";
fin >> num;
out << dec_to_binary(num);
fin >> regis;
out << reg_to_bin(regis);
out << endl;
}
else if(opcode == grape)
{
out << "0101 ";
for(int i = 0; i < 3; i++)
{
fin >> regis;
out << reg_to_bin(regis);
}
out << endl;
}
else if(opcode == strawberry)
{
out << "1111 ";
fin >> regis;
out << reg_to_bin(regis);
out << " 00000";
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
return "000 ";
else if(reg == "R2")
return "001 ";
else if(reg == "R3")
return "010 ";
else if(reg == "R4")
return "011 ";
else if(reg == "R5")
return "100 ";
else if(reg == "R6")
return "101 ";
else if(reg == "R7")
return "110 ";
else if(reg == "R8")
return "111 ";
else
{
cout << "Error\n";
return 0;
}
}

int bin_to_dec(string bin)
{
ifstream fin("sum.o");

if(fin.fail())
{
cout << "File open failed\n";
exit(0);
}

string instruction;
string opcode;
map<string, int> reg_map;
reg_map["000"] = 0; //r1
reg_map["001"] = 0; //r2
reg_map["010"] = 0; //r3
reg_map["011"] = 0; //r4
reg_map["100"] = 0; //r5
reg_map["101"] = 0; //r6
reg_map["110"] = 0; //r7
reg_map["111"] = 0; //r8

while(!fin.eof())
{
fin >> instruction;
opcode = instruction.substr(0,4);
if(opcode == "0011 ") //PUT
{
string n = instruction.substr(4,6);
int val = bin_to_dec(n);

string regis = instruction.substr(10,3);
reg_map[regis] = val;
}
else if(opcode == "0101 ") //SUM
{
string regisA = instruction.substr(4,3);
string regisB = instruction.substr(7,3);
string regisC = instruction.substr(10,3);

int sum_result = reg_map[regisA] + reg_map[regisB];
reg_map[regisC] = sum_result;

}
else if(opcode == "1111 ") //OUT
{
string regis = instruction.substr(4,3);
cout << reg_map[regis] << endl;
}

}

fin.close();

return 0;
}

int bin_to_reg(string bin)
{
int num = 0;
for (int i = 0; i < bin.length(); i++)
if (bin[i] == '1')
num += pow(2, bin.length() - 1 - i);

return num;
}*/


