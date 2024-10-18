#include <iostream>
using namespace std;

class String
{
private:
    char* string;
    int size;
public:
    static int stringCount;
    String() : string{ new char[80] }, size{ 80 } { stringCount++; }
    String(int size) : string{ new char[size] }, size{ size } { stringCount++; }
    String(const char* string, int size) : string{ new char[size] }, size{ size } {
        strcpy_s(String::string, size, string);
        stringCount++;
    }
    ~String()
    {
        delete[] string;
        stringCount--;
    }

    void inputString() {
        cout << "Введите строку: ";
        cin >> this->string;
    }
    void outputString() {
        for (int i = 0; i < strlen(this->string); i++) {
            cout << this->string[i];
        }
        cout << endl;
    }
    static int getCount() {
        return stringCount;
    }
};

int String::stringCount = 0;
int main()
{
    setlocale(LC_ALL, "rus");
    String string;
    string.inputString();
    string.outputString();
    cout << string.stringCount;
}

