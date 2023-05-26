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

    char exeFilePath[MAX_PATH];
    GetModuleFileName(NULL, exeFilePath, MAX_PATH);

    std::string newExeFilePath = exeFilePath;
    size_t lastSlashIndex = newExeFilePath.find_last_of('\\');
    newExeFilePath = newExeFilePath.substr(0, lastSlashIndex + 1) + randomName + ".exe";

    int result = rename(exeFilePath, newExeFilePath.c_str());

    if (result == 0) {
        std::cout << "Имя исполняемого файла было изменено на: " << randomName << ".exe" << std::endl;
    } else {
        std::cout << "Не удалось изменить имя исполняемого файла." << std::endl;
    }

    // Остальная логика вашего приложения...

    return 0;
}
