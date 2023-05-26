#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <windows.h>

std::string GenerateRandomName(int length) {
    std::string name;
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    int size = sizeof(alphanum) - 1;
    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < length; ++i) {
        name += alphanum[rand() % size];
    }

    return name;
}

int main() {
    std::string randomName = GenerateRandomName(10); // Задайте желаемую длину случайного имени (Set the desired length of the random name)

    wchar_t exeFilePath[MAX_PATH];
    GetModuleFileNameW(NULL, exeFilePath, MAX_PATH);

    std::wstring newExeFilePath = exeFilePath;
    size_t lastSlashIndex = newExeFilePath.find_last_of(L'\\');
    newExeFilePath = newExeFilePath.substr(0, lastSlashIndex + 1) + std::wstring(randomName.begin(), randomName.end()) + L".exe";

    int result = _wrename(exeFilePath, newExeFilePath.c_str());

    if (result == 0) {
        std::wcout << L"The name of the executable file has been changed to: " << newExeFilePath << std::endl;
    }
    else {
        std::cout << "Unable to change executable file name." << std::endl;
    }

    // The rest of the logic of your application...

    return 0;
}
