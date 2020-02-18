#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>
#include <ctime>
using namespace std;

int bin_to_dec(string bin);
void clear_list(map<string, int> &temp_map);
int main()
{
    int input;
    srand(time(NULL));

    //Opens binary opcode file
    ifstream fin("projectTestOutput.txt");

    if(fin.fail())
    {
        cout << "File open failed\n";
        exit(0);
    }

    string instruction;
    string opcode;

    map<string, int> reg_map; //map to keep track of registers
    reg_map["000"] = 0; //r1
    reg_map["001"] = 0; //r2
    reg_map["010"] = 0; //r3
    reg_map["011"] = 0; //r4
    reg_map["100"] = 0; //r5
    reg_map["101"] = 0; //r6
    reg_map["110"] = 0; //r7
    reg_map["111"] = 0; //r8
    vector<int> array;

    //Loops through opcode file and translates binary to instructions
    while(!fin.eof())
    {
        fin >> instruction;
        opcode = instruction.substr(0,4);
        if(opcode == "0011") //Put instruction
        {
            string n = instruction.substr(4,6);
            int val = bin_to_dec(n);

            string regis = instruction.substr(10,3);
            reg_map[regis] = val;
        }
        else if(opcode == "0101") //Sum instruction
        {
            string regisA = instruction.substr(4,3);
            string regisB = instruction.substr(7,3);
            string regisC = instruction.substr(10,3);

            int sum_result = reg_map[regisA] + reg_map[regisB];
            reg_map[regisC] = sum_result;

        }
        else if (opcode == "0100")//Array search instruction
        {
            int counter = 0;
            int x = 0;
            string regisB = instruction.substr(7,3);
            reg_map[regisB] = input;
            while( x < array.size())
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
            string regisA = instruction.substr(4,3);
            reg_map[regisA] = input;
            cout << endl;
        }
        else if(opcode == "0000") //Clears registers
        {
            clear_list(reg_map);
        }
        else if(opcode == "1100") //Division instruction
        {
            string regisA = instruction.substr(4,3);
            string regisB = instruction.substr(7,3);
            string regisC = instruction.substr(10,3);

            int div_result = reg_map[regisA] / reg_map[regisB];
            reg_map[regisC] = div_result;

        }
        else if(opcode == "1010") //Multiplication instruction
        {
            string regisA = instruction.substr(4,3);
            string regisB = instruction.substr(7,3);
            string regisC = instruction.substr(10,3);

            int mul_result = reg_map[regisA] * reg_map[regisB];
            reg_map[regisC] = mul_result;

        }
        else if(opcode == "0111") //Subtraction insturction
        {
            string regisA = instruction.substr(4,3);
            string regisB = instruction.substr(7,3);
            string regisC = instruction.substr(10,3);

            int sub_result = reg_map[regisA] - reg_map[regisB];
            reg_map[regisC] = sub_result;

        }
        else if(opcode == "1011") //Allocates array and returns sum of all elements
        {
            int temp = 0;
            int total = 0;
            string reg = instruction.substr(4,3);
            int val = reg_map[reg];
            array.resize(val);
            for(int x = 0; x < array.size(); x++)
            {
                cout << "What value would you like to input" << endl;
                cin >> array.at(x);
                temp = array.at(x);
                total = array.at(x) + total;
            }
            cout << "The sum of all the numbers is: ";
            cout << total;
            cout << endl;
        }
        else if(opcode == "0001") //Halt Instruction
        {
            exit(1);
        }
        else if(opcode == "1001") //Allocates fixed array
        {
            string reg = instruction.substr(4,3);
            int val = reg_map[reg];
            array.resize(val);
            for(int x = 0; x < array.size(); x++)
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
            for(int x = 0; x < array.size(); x++)//Prints array
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
            string regis = instruction.substr(4,3);
            cin >> reg_map[regis];
        }
        else if(opcode == "1111") //Output instruction
        {
            string regis = instruction.substr(4,3);
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
    temp_map["000"] = 0; //r1
    temp_map["001"] = 0; //r2
    temp_map["010"] = 0; //r3
    temp_map["011"] = 0; //r4
    temp_map["100"] = 0; //r5
    temp_map["101"] = 0; //r6
    temp_map["110"] = 0; //r7
    temp_map["111"] = 0; //r8
}
