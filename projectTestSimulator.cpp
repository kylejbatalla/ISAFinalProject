/************************************************************************************** 
   Name: projectTestSimulator.cpp
   Authors: Kyle Batalla, Sergio Garcia, Jose Matamoros, Hector Lopez
   Class: CSS 3 Computer Architecture and Assembly Language Fall 2018
   Purpose: To simulate an ISA using the assembled binary code in ProjecttestCSS3.cpp.
   Description: This file reads the binary code that was assembled in ProjecttestCSS3.cpp and 
   outputted to projectTestOutput.txt, then runs and executes the users instructions and 
   displays the result.
**************************************************************************************/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>
#include <ctime>
using namespace std;

int bin_to_dec(string bin);//function to convert binary to decimal
void clear_list(map<string, int> &temp_map);//function to dellocate and clear registers
int main()
{
    int input;
    srand(time(NULL));

    //Opens binary opcode file with instructions and opcodes
    ifstream fin("projectTestOutput.txt");
    if(fin.fail())
    {
        cout << "File open failed\n";
        exit(0);
    }

    string instruction; //to hold binary instruction
    string opcode; //to hold binary opcode

    map<string, int> reg_map; //A map with 8 elements are created to simulate registers
    reg_map["000"] = 0; //register1
    reg_map["001"] = 0; //register2
    reg_map["010"] = 0; //register3
    reg_map["011"] = 0; //register4
    reg_map["100"] = 0; //register5
    reg_map["101"] = 0; //register6
    reg_map["110"] = 0; //register7
    reg_map["111"] = 0; //register8
    vector<int> array;

    //Loops through opcode file and translates binary to instructions
    while(!fin.eof())
    {
        fin >> instruction;
        opcode = instruction.substr(0,4);
        if(opcode == "0011") //Put instruction
        {
            string n = instruction.substr(4,6);
            int val = bin_to_dec(n); //Converts binary value to decimal value

            string regis = instruction.substr(10,3);//Creates register to hold value
            reg_map[regis] = val;//Assigns decimal value to register
        }
        else if(opcode == "0101") //Sum instruction
        {
            string regisA = instruction.substr(4,3);//Creates register to hold 1st operand
            string regisB = instruction.substr(7,3);//Creates register to hold 2nd operand
            string regisC = instruction.substr(10,3);//Creates register to hold sum

            int sum_result = reg_map[regisA] + reg_map[regisB];//Adds two operands
            reg_map[regisC] = sum_result;//Assigns sum to register

        }
        else if (opcode == "0100")//Array search instruction
        {
            int counter = 0;//to keep count of loop
            int x = 0;//to hold value of array index
            string regisB = instruction.substr(7,3);//assisngs register to input
            reg_map[regisB] = input;
            while( x < array.size())//searches array for x
            {
                if(input == array.at(x))
                {
                    cout << "The number " << array.at(x) << " was found." << endl;
                    counter = 1;
                    break;
                }
                x++;
            }
            if(counter == 0)
            {
                cout << "Sorry, " << input <<  " wasn't found.";
            }
        }
        else if (opcode == "1000")//User input instruction
        {
            cout << "Enter a number: ";
            cin >> input;
            string regisA = instruction.substr(4,3);//Creates register to hold input
            reg_map[regisA] = input;//Assisngs input to register
            cout << endl;
        }
        else if(opcode == "0000") //Clears registers
        {
            clear_list(reg_map);
        }
        else if(opcode == "1100") //Division instruction
        {
            string regisA = instruction.substr(4,3);//Creates register for dividend
            string regisB = instruction.substr(7,3);//Creates register for dividor
            string regisC = instruction.substr(10,3);//Creates register for quotient

            int div_result = reg_map[regisA] / reg_map[regisB];
            reg_map[regisC] = div_result;//Assisngs quotient to register

        }
        else if(opcode == "1010") //Multiplication instruction
        {
            string regisA = instruction.substr(4,3);//Creates register to multiplier
            string regisB = instruction.substr(7,3);//Creates register to multiplicand
            string regisC = instruction.substr(10,3);//Creates register for product

            int mul_result = reg_map[regisA] * reg_map[regisB];
            reg_map[regisC] = mul_result;//Assigns register to product

        }
        else if(opcode == "0111") //Subtraction insturction
        {
            string regisA = instruction.substr(4,3);//Creates register for minuend
            string regisB = instruction.substr(7,3);//Creates register for subtrahend
            string regisC = instruction.substr(10,3);//Creates register for difference

            int sub_result = reg_map[regisA] - reg_map[regisB];
            reg_map[regisC] = sub_result;//Assigns register to difference

        }
        else if(opcode == "1011") //Allocates array and returns sum of all elements
        {
            int temp = 0;
            int total = 0;
            string reg = instruction.substr(4,3);//Assigns register for array size
            int val = reg_map[reg];//Holds value for array size
            array.resize(val);//Creates array with size
            for(int x = 0; x < array.size(); x++)//Inputs values into array
            {
                cout << "What value would you like to input" << endl;
                cin >> array.at(x);
                temp = array.at(x);
                total = array.at(x) + total;
            }
            cout << "The sum of all the numbers is: ";//Displays sum of all numbers in array
            cout << total;
            cout << endl;
        }
        else if(opcode == "0001") //Halt Instruction
        {
            exit(1);
        }
        else if(opcode == "1001") //Allocates fixed array
        {
            string reg = instruction.substr(4,3);//Assigns register to hold array size
            int val = reg_map[reg];//Holds value for array size
            array.resize(val);//Creates array with size
            for(int x = 0; x < array.size(); x++)//Assisngs random numbers into array
            {
                int v2 = rand() % 101;
                array.at(x) = v2;
            }
            cout << "Please enter a number to find: ";
            int z = 0;
            cin >> z;
            for(int x = 0; x < array.size(); x++)//Searches array for number
            {
                if (array.at(x) == z)
                {
                    cout << "Number here!     - Location: ARRAY [";
                    cout << x << "]";
                    break;
                }
                else
                {
                    cout << "Number not here. - Location: ARRAY [";
                    cout << x << "]";
                    cout << endl;
                }
            }
            cout << endl;
            cout << endl;
            cout << "ALL VALUES IN ARRAY:";
            for(int x = 0; x < array.size(); x++)//Prints all elements in array
            {
                cout << "[";
                cout << array.at(x) << "]";
            }
            cout << endl;
        }
        else if(opcode == "1101") //Input instrution
        {
            cout << "What number would you like to input?";
            cout << endl;
            string regis = instruction.substr(4,3);//Assigns register for user input
            cin >> reg_map[regis];
        }
        else if(opcode == "1111") //Output instruction
        {
            string regis = instruction.substr(4,3);//Assigns output register
            cout << reg_map[regis] << endl;
        }

    }

    fin.close();

    return 0;
}

int bin_to_dec(string bin)//Converts binary to decimal value
{
    int num = 0;
    for (int i = 0; i < bin.length(); i++)
        if (bin[i] == '1')
    num += pow(2, bin.length() - 1 - i);

    return num;
}
void clear_list(map<string, int>& temp_map)//Deallocates registers
{
    temp_map["000"] = 0; //register1
    temp_map["001"] = 0; //register2
    temp_map["010"] = 0; //register3
    temp_map["011"] = 0; //register4
    temp_map["100"] = 0; //register5
    temp_map["101"] = 0; //register6
    temp_map["110"] = 0; //register7
    temp_map["111"] = 0; //register8
}
