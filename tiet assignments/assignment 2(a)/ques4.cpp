/*(a) Write a program to concatenate one string to another string.*/
#include <iostream>
using namespace std;

int main() {
    char str1[100] = "Hello ";
    char str2[] = "World!";
    int i = 0, j = 0;

    while (str1[i] != '\0') i++;

    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }

    str1[i] = '\0';

    cout << "Concatenated string: " << str1 << endl;
    return 0;
}

/* (b) Write a program to reverse a string. */
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[] = "Hello";
    int n = 0;

    while (str[n] != '\0') n++;

    for (int i = n - 1; i >= 0; i--) {
        cout << str[i];
    }
    cout << endl;
    return 0;
}


/* (c) Write a program to delete all the vowels from the string.*/
#include <iostream>
using namespace std;

int main() {
    char str[] = "Hello World";
    char result[100];
    int i = 0, j = 0;

    while (str[i] != '\0') {
        char ch = str[i];
        if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u' &&
            ch != 'A' && ch != 'E' && ch != 'I' && ch != 'O' && ch != 'U') {
            result[j] = ch;
            j++;
        }
        i++;
    }

    result[j] = '\0';

    cout << "String without vowels: " << result << endl;
    return 0;
}


/*  (d) Write a program to sort the strings in alphabetical order. */
#include <iostream>
using namespace std;

int main() {
    char str[] = "dcba";
    int n = 0;

    while (str[n] != '\0') n++;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }

    cout << "Sorted string: " << str << endl;
    return 0;
}

/*(e) Write a program to convert a character from uppercase to lowercase.*/
#include <iostream>
using namespace std;

int main() {
    char ch = 'G';

    if (ch >= 'A' && ch <= 'Z') {
        ch = ch + ('a' - 'A');
    }

    cout << "Lowercase: " << ch << endl;
    return 0;
}

