#include <iostream>
#include <vector>
#include <string>
struct Lesson;
struct Student;
struct Student
{
    std::string name;
    std::vector<Lesson*> lessons;
};
struct Lesson
{
    std::string less_name;
    std::vector<Student*> students;
};
void spam(Student &studentVec, Lesson &lessonVec)
{
        studentVec.lessons.push_back(&lessonVec);
        lessonVec.students.push_back(&studentVec);
}
void stud(const Lesson& ykaz)
{
    for (auto i : ykaz.students) { std::cout << ((*i).name) << " "; };
}
void less(const Student& ykaz)
{
    for (auto i : ykaz.lessons) { std::cout << ((*i).less_name) << " "; };
}
int main()
{
    Student student1{ "student1" };
    Student student2{ "student2" };
    Lesson lesson1{ "lesson1" };
    Lesson lesson2{ "lesson2" };
    Lesson lesson3{ "lesson3" };

    spam(student1, lesson1);
    spam(student1, lesson2);
    spam(student2, lesson2);
    spam(student2, lesson3);
    stud(lesson3);
    std::cout << "\n";
    less(student1);
}
