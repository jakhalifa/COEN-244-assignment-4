#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>

#include "RankOneTensorType.h"

using namespace std;

void testTensorType()
{
    RankOneTensorType<string> tensor(2);
    tensor[0] = "Hello";
    tensor[1] = "Coen244";
    cout << "Tensor: " << tensor << endl;
    RankOneTensorType<double> dtensor(2);
    dtensor[0] = 0.15;
    dtensor[1] = 0.30;
    cout << "dTensor: " << dtensor << endl;
    RankOneTensorType<double> dtensor2(2);
    dtensor2.loadData();
    cout << "dTensor2: " << dtensor2 << endl;
    cout << "dtensor + dtensor2: " << dtensor + dtensor2 << endl;
    cout << "dTensor: " << dtensor << endl;
}

int main()
{
    time_t now = time(NULL);
    srand(now);

    testTensorType();
}