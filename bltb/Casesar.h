#include<string>


void Casesar(std::string str, int n) {
    char* cstr = new char[str.length() + 1];
    int* a = new int[str.length() + 1];

    char m[] = { 'A',   'B','C','D','E',    'F',    'G',    'H',    'I',    'J',
        'K',    'L',    'M',    'N' ,'O'    ,'P'    ,'Q'    ,'R'    ,'S'    ,'T'    ,'U'    ,'V'    ,'W'    ,'X'    ,'Y'    ,'Z' };

    strcpy(cstr, str.c_str());
    for (int i = 0; i < str.length(); i++) {
        if (int(cstr[i]) == 32)
            continue;
        if (65 >= int(cstr[i]) <= 87) {
            a[i] = int(cstr[i]);
            a[i] += n;
        }
        if (int(cstr[i]) >= 88) {
            a[i] = int(m[i]) + n - 1;
        }
        cstr[i] = char(a[i]);
    }

    for (int i = 0; i < str.size(); i++) {
        std::cout << cstr[i];
    }

    delete[] cstr;
    delete[] a;
}