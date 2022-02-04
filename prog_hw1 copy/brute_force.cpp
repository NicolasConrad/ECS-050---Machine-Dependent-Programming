#include<math.h>
#include<string>
#include<vector>
#include<tuple>
#include "brute_force.hpp"
using namespace std;

string createBitString(int num, int size)
{
	string bit = "";

	if(num==0)
	{
		for(int i = 0; i < size; i++)
			bit.insert(0, "0");
	}

	while(num > 0)
	{
		bit.insert(0, to_string(num%2));
		num/=2;
	}

	while(bit.length() < (unsigned)size)
		bit.insert(0,"0");

	return bit;
}

tuple<bool, vector<unsigned>> isSubsetSum(const vector<int>& items, int target)
{
	bool isOptimalSolution = false;
	unsigned int size = items.size();
	vector<unsigned> optimalIndices(size, 0);
	tuple<bool, vector<unsigned>> answer{false, {}};

	string bit;
	int sum = 0;

	vector<unsigned> tempIndices{};

	for(int i = 0; i < pow(2, size); i++)
	{
		//create bit string
		sum = 0;
		tempIndices.clear();

		bit = createBitString(i, size);

		//check which result in target sum
		for(unsigned int j = 0; j < bit.length(); j++)
		{
			if(bit[j] == '1')
			{
				sum += items[j];
				tempIndices.push_back(j);
			}
		}

		//if target sum is met, set answer
		if(sum == target)
		{
			if(!tempIndices.empty())
			{
				isOptimalSolution = true;
				optimalIndices = tempIndices;
			}
		}
	}

	if(isOptimalSolution)
	{
		get<0>(answer) = true;
		get<1>(answer) = optimalIndices;
	}

	return answer;
}

tuple<bool, vector<unsigned>, vector<unsigned>> isSetPartionable(const vector<int>& values)
{
	int size = values.size();
	string bit;
	vector<unsigned> v1;
	vector<unsigned> v2;
	int sum1 = 0;
	int sum2 = 0;
	bool isOptimalSolution = false;
	bool v1HasZero;

	vector<unsigned> optimalV1;
	vector<unsigned> optimalV2;

	tuple<bool, vector<unsigned>, vector<unsigned>> answer{false, {}, {}};

	for(unsigned int i = 0; i < pow(2, size); i++)
	{
		bit = createBitString(i, size);
		v1.clear();
		v2.clear();
		sum1 = 0;
		sum2 = 0;

		for(unsigned int j = 0; j < bit.length(); j++)
		{
			if(bit[j] == '1')
				v1.push_back(j);
			else
				v2.push_back(j);
		}

		for(unsigned int k = 0; k < v1.size(); k++)
			sum1 += values[v1[k]];

		for(unsigned int l = 0; l < v2.size(); l++)
			sum2 += values[v2[l]];

		if(sum1 == sum2)
		{
			isOptimalSolution = true;
			optimalV1 = v1;
			optimalV2 = v2;
		}
	}

	if(isOptimalSolution)
	{
		get<0>(answer) = true;
		for(unsigned int m = 0; m < optimalV1.size();m++)
		{
			if(optimalV1[m] == '0')
				v1HasZero = true;
		}
		if(v1HasZero)
		{
			get<1>(answer) = optimalV1;
			get<2>(answer) = optimalV2;
		}else
		{
			get<2>(answer) = optimalV1;
			get<1>(answer) = optimalV2;
		}
		
 	}

	return answer; 
	
}












