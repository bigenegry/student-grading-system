#include "Person.h"
#include <algorithm>
#include <numeric>

Person::Person() = default;

Person::Person(const std::string& first, const std::string& last)
    : firstName_(first), lastName_(last) {}

Person::Person(const Person& other)
    : firstName_(other.firstName_),
      lastName_(other.lastName_),
      homework_(other.homework_),
      exam_(other.exam_),
      finalGrade_(other.finalGrade_) {}

Person& Person::operator=(const Person& other) {
    if (this != &other) {
        firstName_ = other.firstName_;
        lastName_ = other.lastName_;
        homework_ = other.homework_;
        exam_ = other.exam_;
        finalGrade_ = other.finalGrade_;
    }
    return *this;
}

Person::~Person() = default;

double Person::averageHW() const {
    if (homework_.empty()) return 0.0;
    double sum = std::accumulate(homework_.begin(), homework_.end(), 0.0);
    return sum / static_cast<double>(homework_.size());
}

double Person::medianHW() const {
    if (homework_.empty()) return 0.0;
    std::vector<int> tmp = homework_;
    std::sort(tmp.begin(), tmp.end());
    size_t n = tmp.size();
    if (n % 2 == 1) return tmp[n / 2];
    return (tmp[n / 2 - 1] + tmp[n / 2]) / 2.0;
}

void Person::calculateFinalGrade(bool useAverage) {
    double hw = useAverage ? averageHW() : medianHW();
    finalGrade_ = 0.4 * hw + 0.6 * static_cast<double>(exam_);
}

std::ostream& operator<<(std::ostream& os, const Person& p) {
    os << p.firstName_ << " " << p.lastName_ << " " << p.finalGrade_;
    return os;
}
