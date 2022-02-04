#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
using namespace std;

int binToDec(string binary)
{
	int multiplier = 1;
	int a = 0;
	int result = 0;
	for(int i = binary.length()-1; i >= 0; i--)
	{
		a = (int)binary[i]-48;

		result += a * multiplier;
		multiplier = multiplier * 2;
	}

	return result;
}

int main(int argc, char* argv[])
{
	string line;
	ifstream inFile(argv[1]);

	string first;
	string second;
	string third;

	unsigned int expLen;
	unsigned int manLen;
	int sign = 1;
	int bias = 0;

	string exp = "";
	string man = "";

	int lineNum = 1;

	while(getline(inFile, line))
	{
		if(lineNum==1)
		{
			if(line.substr(0, 4) == "sign")
				first = "sign";
			else if(line.substr(0, 3) == "exp")
			{
				first = "exp";
				expLen = stoi(line.substr(4, line.length()-4));
			}else
			{
				first = "man";
				manLen = stoi(line.substr(4, line.length()-4));
			}
		}else if(lineNum==2)
		{
			if(line.substr(0, 4) == "sign")
				second = "sign";
			else if(line.substr(0, 3) == "exp")
			{
				second = "exp";
				expLen = stoi(line.substr(4, line.length()-4));
			}else
			{
				second = "man";
				manLen = stoi(line.substr(4, line.length()-4));
			}
		}else if(lineNum==3)
		{
			if(line.substr(0, 4) == "sign")
				third = "sign";
			else if(line.substr(0, 3) == "exp")
			{
				third = "exp";
				expLen = stoi(line.substr(4, line.length()-4));
			}else
			{
				third = "man";
				manLen = stoi(line.substr(4, line.length()-4));
			}
		}


		lineNum++;
	}

	inFile.close();

	string bit;

	while(bit.length() != (unsigned)1+expLen+manLen)
	{
		cout << "Enter bit string: ";
		cin >> bit;

		if(bit.length() != (unsigned)1+expLen+manLen)
			cout << "Wrong number of bits.\n";
	}
	
	
	if(first == "sign")
	{
		if(bit[0]=='1')
			sign = -1;
		else 
			sign = 1;
	}else if(first == "exp")
		exp = bit.substr(0, expLen);
	else
		man = bit.substr(0, manLen);


	if(second == "sign")
	{
		if(first == "exp")
		{
			if(bit[expLen]=='1')
				sign=-1;
			else 
				sign=1;
		}else
		{
			if(bit[manLen]=='1')
				sign=-1;
			else 
				sign=1;
		}
	}else if(second == "exp")
	{
		if(first == "sign")
			exp = bit.substr(1, expLen);
		else
			exp=bit.substr(manLen, expLen);
	}else
	{
		if(first == "sign")
			man = bit.substr(1, manLen);
		else
			man=bit.substr(expLen, manLen);
	}

	if(third=="sign")
	{
		if(bit[expLen+manLen] == '1')
			sign=-1;
		else 
			sign=1;
	}else if(third=="exp")
		exp=bit.substr(1+manLen, expLen);
	else
		man=bit.substr(1+expLen, manLen);

	bias = pow(2, expLen-1) - 1;
	int expDec = binToDec(exp);

	int finExp = expDec-bias;
	
	string finalBit = "1" + man;

	int multiplier = -1*manLen + finExp;
	float sum = 0;

	for(int i = finalBit.length()-1; i >= 0; i--)
	{
		sum += (int)(finalBit[i]-48)*pow(2, multiplier);
		multiplier+=1;
	}

	sum*=sign;

	cout << "Value: " << sum << "\n";
	
}
















