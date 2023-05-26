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
    std::string randomName = GenerateRandomName(10); // Задайте желаемую длину случайного имени
    std::string command = "wmic process where name='";
    command += std::string(argv[0]) + "' call rename name='" + randomName + ".exe'";

    system(command.c_str());

    std::cout << "Название приложения было изменено на: " << randomName << std::endl;

    // Остальная логика вашего приложения...

    return 0;
}
