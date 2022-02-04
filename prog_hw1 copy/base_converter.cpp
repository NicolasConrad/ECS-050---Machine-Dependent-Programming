#include<iostream>
#include<string>
using namespace std;

string convertBase(int initial, string initialrep, int desired)
{
	
	if(initial==desired)
		return initialrep;

	int result=0;

	if(initial!=10)
	{
		int multiplier = 1;
		int a = 0;
		for(int i = initialrep.length()-1; i >= 0; i--)
		{
			if(isalpha(initialrep[i]))
				a = (int)initialrep[i] - 55;
			else
				a = (int)initialrep[i] - 48;

			result += a * multiplier;
			multiplier = multiplier * initial;
		}
	}else
		result=stoi(initialrep);
	
	if(desired==10)
		return to_string(result);


	string final="";
	while(result != 0)
	{	
		int remainder=result%desired;
		if(remainder >= 10)
		{
			if(remainder==10)
				final.insert(0, "A");
			else if(remainder==11)
				final.insert(0, "B");
			else if(remainder==12)
				final.insert(0, "C");
			else if(remainder==13)
				final.insert(0, "D");
			else if(remainder==14)
				final.insert(0, "E");
			else
				final.insert(0, "F");
		}else
			final.insert(0, to_string(remainder));

		result/=desired;
	}

	return final;
}

int main()
{
	int inbase;
	string rep;
	int desbase;
	cout << "Enter initial base: ";
	cin >> inbase;
	cout << "Enter base-" << inbase << " representation: ";
	cin >> rep;
	cout << "Enter desired base: ";
	cin >> desbase;
	cout << "Base-" << desbase << " representation: " << convertBase(inbase, rep, desbase) << "\n";
	return 0;
}

