#include <iostream>
using namespace std;

int arrayFun(int* inArray, int sizeOfArray, int& min, int& max);
int recSum(int* inArray, int sizeOfArray);

int main(int argc, char** argv) {
	int aa[]={10,-20,25,16,30,88,-100};
	int bb[5];
	int* cc; // integer pointer;
	int maxium=0, minimum=0;
	int sumOfArray = 0;
	cout << "Before: minimun = " << minimum << ", maxium = " << maxium;
	cout << "sum = " << sumOfArray << endl;
	sumOfArray = arrayFun(aa, 7 , minimum, maxium);
	cout << "After: minimun = " << minimum << ", maxium = " << maxium;
	cout << "sum = " << sumOfArray << endl;
	cout << "Sum again: " << recSum(aa, 7) << endl;

	cc = new int[4];
	cc[0]= 25; cc[1]= 32; cc[2]= -46; cc[3]= 52;
	
	cout<< "Sum of CC: " << arrayFun(cc, 4, minimum, maxium) << endl;
	cout << "cc=" << cc << ", *cc=" << (*cc) << endl;
	delete [] cc;
	return 0;
}

int arrayFun(int* inArray, int sizeOfArray, int& min, int& max){
	int sum=0;
	min = inArray[0];
	max = inArray[0];

	for (int i =0; i < sizeOfArray; i++){
		if (inArray[i] < min){
			min = inArray[i];
		}
		if (inArray[i] > max){
			max = inArray[i];
		}
		sum += inArray[i];
	}
}

int recSum(int* inArray, int sizeOfArray){
	if(sizeOfArray == 1){
		return inArray[0];
	}
	if (sizeOfArray >1){
		return inArray[sizeOfArray -1] + recSum(inArray, sizeOfArray - 1);
	}
	return -1; //error
}







