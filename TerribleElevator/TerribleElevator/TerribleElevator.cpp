#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Manager.hpp"

using namespace std;

int main(){
    cout << "Hello World!\n";
    Manager* tempManager = new Manager();
    //tempManager->test();
    tempManager->run();
}
