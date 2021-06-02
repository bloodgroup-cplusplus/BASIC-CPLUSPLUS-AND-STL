#include<math.h>
#include<complex>
#include<vector>
#include<iostream>
#include<iomanop>

std::vector<std::complex<double>> dft(std::vector<std::complex<double>>X)
{
	//determine the number of samples
	int N=X.size();
	int K=N;
	
	//Allocate memory for internals
	
	std::complex<double> intSum;
	
	//Allocate memory for the output
	
	std::vector<std::complex<double>> output;
	output.reserve(K);
	
	// loop through each k
	
	for(int k=0;k<K;++k)
	{
		//loop thorugh each n
		intSum=std::complex<double> (0,
		do
		
