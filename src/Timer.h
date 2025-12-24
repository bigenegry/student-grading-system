// src/main_deque.cpp
#include "Timer.h"
#include "FileGenerator.h"
#include "StudentIO.h"
#include "Processor.h"
#include <iostream>
#include <deque>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    try {
        fs::create_directories("data/out/deque");
        const std::vector<std::pair<std::string, std::size_t>> datasets = {
            {"data/in/students_1k.csv",     1000},
            {"data/in/students_10k.csv",    10000},
            {"data/in/students_100k.csv",   100000},
            {"data/in/students_1m.csv",     1000000},
            {"data/in/students_10m.csv",    10000000}
        };

        Timer t;
        for (const auto& [path, count] : datasets) {
            std::cout << "\n=== Dataset (deque): " << path << " ===\n";

            t.start("Read file into deque");
            auto students = StudentIO::readFile<std::deque<Student>>(path);
            Timer::report("Read file into deque", t.stop());

            t.start("Split into failed/passed");
            auto split = splitByThreshold(students, 5.0);
            Timer::report("Split into failed/passed", t.stop());

            t.start("Write failed");
            StudentIO::writeFile("data/out/deque/failed_" + std::to_string(count) + ".csv", split.failed);
            Timer::report("Write failed", t.stop());

            t.start("Write passed");
            StudentIO::writeFile("data/out/deque/passed_" + std::to_string(count) + ".csv", split.passed);
            Timer::report("Write passed", t.stop());
        }

        std::cout << "\nv0.25 (deque) completed.\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
}
