#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <filesystem>

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

    std::string currentPath = std::filesystem::current_path().string();
    std::string exeFilePath = currentPath + "\\" + argv[0];

    std::string newExeFilePath = currentPath + "\\" + randomName + ".exe";

    bool success = std::filesystem::rename(exeFilePath, newExeFilePath);

    if (success) {
        std::cout << "Имя исполняемого файла было изменено на: " << randomName << ".exe" << std::endl;
    } else {
        std::cout << "Не удалось изменить имя исполняемого файла." << std::endl;
    }

    // Остальная логика вашего приложения...

    return 0;
}
