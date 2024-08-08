#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
using namespace std;


int main()
{
	vector<int> elements; 
	int key,i,j,n,ele;
	
	ifstream inputFile("descending_10000.txt");
	
	inputFile >> n;
	for (i = 0; i < n; i++){
		inputFile >> ele;
		elements.push_back(ele);
	}
	
	inputFile.close();
	
	clock_t tStart = clock();
	for(j=1;j<n;j++){
		key = elements[j];
		i = j-1;
		while((i>=0)&&(elements[i]>key)){
			elements[i+1] = elements[i];
			i = i-1;
		}
		elements[i+1] = key;
	}
	
	double time1=(double)(clock() - tStart)/CLOCKS_PER_SEC;
	cout << "Time taken is " << time1 << endl;
}
