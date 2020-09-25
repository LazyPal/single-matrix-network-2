// SIngleMatrixNetwork.cpp : Defines the entry point for the console application.
//

#include "stdAfx.h"
#include "Network.h"
#include <math.h>
#include <stdio.h>

int main(int argc, char* argv[])
{

	//etwork khepera("Ian_Test_Network_Changing_Inputs.txt"); //Ian_Test_Network_Equal_Vary_Inputs.txt
	//Network DynamicsTest(2, 2, 1, "DynamicsTest.txt");

	Network DynamicsTest("SingleUnit4.txt");
//	Network DynamicTest(1, 2, 2, "SingleUnit3.txt")

    double inputs[100];
	int i = 0;
	int divider = 10;
	int arrsize = 100;
	int total_time_step = 100;
	int input_on = 1;
	int input_off = 0;


	for(int y = 1; y < arrsize; y++) {
        inputs[y] = 0;
        if(y % divider == input_off) {
            inputs[y] = input_on;
        }
	}

	while (i < total_time_step) {

		DynamicsTest.setNetworkInput(&inputs[i]);


        //DynamicsTest.squashingFunction(1, 1, -2 ,0);
		DynamicsTest.writeNetworkSquashedOutputStateToFile("SampleSquashed36-34.txt");
		DynamicsTest.printNetworkOutputState();
		DynamicsTest.writeNetworkOutputStateToFile("SampleTest36-34.txt");
		DynamicsTest.cycleNetwork();

		i++;
	}

	return 0;

}
