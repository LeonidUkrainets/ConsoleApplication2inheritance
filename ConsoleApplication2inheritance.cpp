#include <iostream>
#include <vector>
using namespace std;
// клас Особи
class Person {
protected:
    unsigned long int id; // унікальний ідентифікатор
    string name;          // ім’я;
    string surname;       // прізвище;
    string pasnumber;     // номер паспорта;
    string dateofbirth; // дата народження;
public:
    Person()
    {
        cout << "Спрацював конструктор класу Особи за замовчуванням. " << endl;
    }
    Person (unsigned long int id, string name, string surname, string pasnumber, string date_of_birth)
    {
        this->id = id;
        this->name = name;
        this->surname = surname;
        this->pasnumber = pasnumber;
        this->dateofbirth = date_of_birth;
        cout << "Спрацював конструктор класу Особи. " << endl;
    }
    ~Person()
    {
        cout << "Спрацював деструктор класу Особи. " << endl;
    }
    void Show()
    {
        cout << "ідентифікатор    : " << id << endl;
        cout << "ім’я             : " << name << endl;
        cout << "прізвище         : " << surname << endl;
        cout << "номер паспорта   : " << pasnumber << endl;
        cout << "дата народження  : " << dateofbirth << endl;
    }
    void Set(unsigned long int id, string name, string sur, string pass, string date)
    {
        this->id = id;
        this->name = name;
        this->surname = sur;
        this->pasnumber = pass;
        this->dateofbirth = date;
    }
};
// успадкування класу публічне
class Student : public Person
{
protected:
    // безпосередні поля класу Студентів
    string school;     // навчальний заклад
    string specialty;  // спеціальність
    string group;      // група
public:
    Student(unsigned long int id, string name, string surname, string pasnumber, string dateofbirth, string school, string specialty, string group)
        :Person(id, name, surname, pasnumber, dateofbirth)
    {
        this->school = school;
        this->specialty = specialty;
        this->group = group;
        cout << "Спрацював конструктор класу Студенти." << endl;
    }
    ~Student()
    {
        cout << "Спрацював деструктор класу Студенти." << endl;
    }
    void Show()
    {
        Person::Show();
        cout << "навчальний заклад: " << school << endl;
        cout << "спеціальність    : " << specialty << endl;
        cout << "група            : " << group << endl;
    }
    void Set(unsigned long int id, string name, string sur, string pass, string date, string sch, string sp, string grp)
    {
        Person::Set(id, name, sur,  pass, date);
        this->school = sch;
        this->specialty = sp;
        this->group = grp;
    }
};
// окрема функція

int main()
{
    system("chcp 1251>nul");
    Student* st = new Student(2935511838, "Леонід", "Українець", "КР888888", "27.04.1980", "ЧНУ", "Інформатика", "507");
    //cout << "Спрацював рядок 89." << endl;
    vector <Student> students;
    //cout << "Спрацював рядок 91." << endl;
    students.push_back(*st);
    //cout << "Спрацював рядок 93." << endl;
    st = new Student(1234567890, "Ольга", "Войчик", "КР777777", "03.11.2002", "ІТЕА", "С++", "2307");
    //cout << "Спрацював рядок 95." << endl;
    students.push_back(*st);
    //cout << "Спрацював рядок 97." << endl;
    /*
    for (Student student : students)
    {
        student.Show();
        cout << endl;
    }
    */
    for (auto it= students.begin(); it!= students.end(); it++)
    {
        it->Show();
        cout << endl;
    }
    delete st;
}