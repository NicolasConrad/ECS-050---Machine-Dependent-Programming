#include<iostream>
#include<string>
using namespace std;

string twosComplement(int i)
{
	string result = "";
	int original = i;

	if(i < 0)
		i *= -1;

	while(i > 0)
	{
		result.insert(0, to_string(i%2));
		i/=2;
	}

	while(result.length() < 32)
		result.insert(0, "0");
	
	if(original>=0)
		return result;

	for(unsigned int i = 0; i < result.length(); i++)
	{
		if(result[i] == '0')
			result[i] = '1';
		else if(result[i] == '1')
			result[i] = '0';
	}

	for(unsigned int i = result.length()-1; i >= 0; i--)
	{
		if(result[i]=='0')
		{
			result[i] = '1';
			break;	
		}else
			result[i] = '0';
	}

	return result;
}

string signedMagnitude(int i)
{
	string result = "";
	int original = i;

	if(i < 0)
		i *= -1;

	while(i > 0)
	{
		result.insert(0, to_string(i%2));
		i/=2;
	}

	while(result.length() < 32)
	{
		if(result.length() == 31)
		{
			if(original < 0)
			{
				result.insert(0, "1");
				break;
			}
		}
		result.insert(0, "0");
	}
	
	return result;

}

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		cerr << "Wrong number of command-line arguments.\n";
		return 1;
	}
	cout << "2's complement: " << twosComplement(stoi(argv[1])) << "\n";
	cout << "Signed magnitude: " << signedMagnitude(stoi(argv[1])) << "\n";
}