#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <sstream>

// Функция инициализации вектора дефолтными входными значениями
void initializeDefault(std::vector<std::string>& names, std::vector<int>& grades) {
    // Дефолтные значения
    std::vector<std::string> defaultNames = {"Alice", "Bob", "Charlie", "David", "Eve", "Frank", "Grace", "Henry", "Ivy", "Jack"};
    std::vector<int> defaultGrades = {75, 80, 90, 85, 95, 70, 85, 92, 88, 95};

    // Копирование значений в векторы
    names = defaultNames;
    grades = defaultGrades;
}

// Функция инициализации вектора случайными входными значениями
void initializeRandom(std::vector<std::string>& names, std::vector<int>& grades) {
    int size;
    std::cout << "Введите желаемый размер выборки: ";
    std::cin >> size;

    // Инициализация вектора случайными значениями
    for (int i = 0; i < size; i++) {
        std::string name;
        int grade;

        std::cout << "Введите имя студента: ";
        std::cin >> name;
        std::cout << "Введите оценку студента: ";
        std::cin >> grade;

        names.push_back(name);
        grades.push_back(grade);
    }
}

// Функция инициализации вектора значениями, введенными пользователем
void initializeUserInput(std::vector<std::string>& names, std::vector<int>& grades) {
    std::cout << "Введите значения имен и оценок студентов в формате 'имя оценка':" << std::endl;
    std::cout << "Введите 'конец' для завершения ввода." << std::endl;

    std::string input;
    while (true) {
        std::getline(std::cin, input);

        // Выход из цикла при вводе "конец"
        if (input == "конец") {
            break;
        }

        // Разделение строки на имя и оценку
        std::istringstream iss(input);
        std::string name;
        int grade;
        iss >> name >> grade;

        names.push_back(name);
        grades.push_back(grade);
    }
}

// Функция вывода содержимого векторов
void printVector(const std::vector<std::string>& names, const std::vector<int>& grades) {
    for (int i = 0; i < names.size(); i++) {
        std::cout << "Имя студента: " << names[i] << ", Оценка: " << grades[i] << std::endl;
    }
}

// Функция подсчета среднего значения оценок
double calculateAverage(const std::vector<int>& grades) {
    int sum = 0;
    for (int grade : grades) {
        sum += grade;
    }

    return static_cast<double>(sum) / grades.size();
}

// Функция подсчета медианы оценок
double calculateMedian(std::vector<int> grades) {
    std::sort(grades.begin(), grades.end());

    if (grades.size() % 2 == 0) {
        int middleIndex = grades.size() / 2;
        return static_cast<double>(grades[middleIndex - 1] + grades[middleIndex]) / 2;
    } else {
        return static_cast<double>(grades[grades.size() / 2]);
    }
}

// Функция подсчета моды оценок
std::vector<int> calculateMode(const std::vector<int>& grades) {
    std::unordered_map<int, int> countMap;
    int maxCount = 0;

    // Подсчет повторений оценок и поиск максимального количества повторений
    for (int grade : grades) {
        countMap[grade]++;
        maxCount = std::max(maxCount, countMap[grade]);
    }

    std::vector<int> modeGrades;

    // Добавление оценок, которые имеют максимальное количество повторений, в вектор моды
    for (const auto& pair : countMap) {
        if (pair.second == maxCount) {
            modeGrades.push_back(pair.first);
        }
    }

    return modeGrades;
}

// Функция вывода результатов анализа
void analyzeGrades(const std::vector<std::string>& names, const std::vector<int>& grades) {
    std::cout << "Список студентов и их оценки:" << std::endl;
    printVector(names, grades);

    double average = calculateAverage(grades);
    double median = calculateMedian(grades);
    std::vector<int> mode = calculateMode(grades);

    std::cout << "Средняя оценка: " << average << std::endl;
    std::cout << "Медиана оценок: " << median << std::endl;
    std::cout << "Мода оценок: ";
    for (int grade : mode) {
        std::cout << grade << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<std::string> names;
    std::vector<int> grades;
    int choice;

    std::cout << "Выберите способ инициализации векторов:" << std::endl;
    std::cout << "1. Демонстрационный анализ с дефолтными входными значениями" << std::endl;
    std::cout << "2. Анализ на случайных входных значениях" << std::endl;
    std::cout << "3. Анализ на входных значениях от пользователя" << std::endl;
    std::cout << "Введите номер выбранного варианта: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            initializeDefault(names, grades);
            analyzeGrades(names, grades);
            break;
        case 2:
            initializeRandom(names, grades);
            analyzeGrades(names, grades);
            break;
        case 3:
            initializeUserInput(names, grades);
            analyzeGrades(names, grades);
            break;
        default:
            std::cout << "Неверный выбор!" << std::endl;
            break;
    }

    return 0;
}

//4 пункт!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
std::vector<int> calculateMode(const std::vector<int>& grades) {
    std::unordered_map<int, int> countMap;

    // Подсчет повторений оценок
    for (int grade : grades) {
        countMap[grade]++;
    }

    std::vector<int> modeGrades;
    int maxCount = 0;

    // Поиск максимального количества повторений
    for (const auto& pair : countMap) {
        maxCount = std::max(maxCount, pair.second);
    }

    // Добавление оценок, которые имеют максимальное количество повторений, в вектор моды
    for (const auto& pair : countMap) {
        if (pair.second == maxCount) {
            modeGrades.push_back(pair.first);
        }
    }

    return modeGrades;
}
