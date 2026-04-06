#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>

#include "RankOneTensorType.h"

using namespace std;

/* void testTensorType()
{
    RankOneTensorType<string> tensor(2);
    tensor[0] = "Hello";
    tensor[1] = "Coen244";
    cout << tensor;
    RankOneTensorType<double> dtensor(2);
    dtensor[0] = 0.15;
    dtensor[1] = 0.30;
    cout << dtensor;
    RankOneTensorType<double> dtensor2(2);
    dtensor2.loadData();
    cout << dtensor2;
    cout << dtensor + dtensor2;
    cout << dtensor;
} */

int main()
{
    time_t now = time(NULL);
    srand(now);

    RankOneTensorType<int> int_tensor;
    int_tensor.set_data_size(5);
    int_tensor.loadData();

    RankOneTensorType<std::string> string_tensor;
    string_tensor.set_data_size(5);
    string_tensor.loadData();

    for (int i = 0; i < string_tensor.get_data_size(); i++)
        printf("%s\n", string_tensor.get_data_element(i).c_str());


    
}