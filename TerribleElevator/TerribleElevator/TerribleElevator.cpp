#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <string>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include "Manager.hpp"

using namespace std;

int main(){
    Manager* tempManager = new Manager();
    //tempManager->test();
    tempManager->run();
}
