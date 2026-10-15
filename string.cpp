#include <iostream>
#include <cctype>
using namespace std;

class String
{
    char str[100];
    int len;

public:

    // Default Constructor
    String()
    {
        str[0] = '\0';
        len = 0;
    }

    // Parameterized Constructor
    String(const char *s)
    {
        len = 0;

        while(s[len] != '\0' && len < 99)
            len++;

        for(int i = 0; i < len; i++)
            str[i] = s[i];

        str[len] = '\0';
    }

    // Copy Constructor
    String(const String &obj)
    {
        len = obj.len;

        for(int i = 0; i < len; i++)
            str[i] = obj.str[i];

        str[len] = '\0';
    }

    // Assignment Operator
    String& operator=(const String &obj)
    {
        if(this != &obj)
        {
            len = obj.len;

            for(int i = 0; i < len; i++)
                str[i] = obj.str[i];

            str[len] = '\0';
        }

        return *this;
    }

    // Addition Operator
    String operator+(const String &obj) const
    {
        String temp;

        temp.len = len + obj.len;

        if(temp.len > 99)
            temp.len = 99;

        int i = 0;

        while(i < len && i < 99)
        {
            temp.str[i] = str[i];
            i++;
        }

        int j = 0;

        while(i < temp.len && j < obj.len)
        {
            temp.str[i] = obj.str[j];
            i++;
            j++;
        }

        temp.str[i] = '\0';
        temp.len = i;

        return temp;
    }

    // Subscript Operator
    char& operator[](int index)
    {
        return str[index];
    }

    // GETDATA
    char *getData()
    {
        return str;
    }

    // Comparison Operators
    bool operator>(const String &obj) const
    {
        return mystrcmp(*this, obj) > 0;
    }

    bool operator<(const String &obj) const
    {
        return mystrcmp(*this, obj) < 0;
    }

    bool operator>=(const String &obj) const
    {
        return mystrcmp(*this, obj) >= 0;
    }

    bool operator<=(const String &obj) const
    {
        return mystrcmp(*this, obj) <= 0;
    }

    bool operator!=(const String &obj) const
    {
        return mystrcmp(*this, obj) != 0;
    }

    bool operator==(const String &obj) const
    {
        return mystrcmp(*this, obj) == 0;
    }

    // Friend Stream Operators
    friend ostream& operator<<(ostream &, const String &);
    friend istream& operator>>(istream &, String &);

    // Friend String Functions
    friend void mystrcpy(String &, const String &);
    friend void mystrncpy(String &, const String &, int);
    friend int mystrcmp(const String &, const String &);
    friend int mystrncmp(const String &, const String &, int);
    friend void mystrcat(String &, const String &);
    friend void mystrncat(String &, const String &, int);
    friend void mystrrev(String &);
    friend void mystrupr(String &);
    friend void mystrlwr(String &);
    friend char* mystrchr(const String &, char);
    friend char* mystrrchr(const String &, char);
    friend char* mystrstr(String &, char *);
    friend int mystrlen(const String &);

    // No destructor needed because str is a fixed array
};


// OUTPUT OPERATOR
ostream& operator<<(ostream &out, const String &obj)
{
    out << obj.str;
    return out;
}


// INPUT OPERATOR
istream& operator>>(istream &in, String &obj)
{
    char temp[100];

    in >> temp;

    obj.len = 0;

    while(temp[obj.len] != '\0' && obj.len < 99)
        obj.len++;

    for(int i = 0; i < obj.len; i++)
        obj.str[i] = temp[i];

    obj.str[obj.len] = '\0';

    return in;
}


// STRCPY
void mystrcpy(String &s2, const String &s1)
{
    s2.len = s1.len;

    for(int i = 0; i < s1.len; i++)
        s2.str[i] = s1.str[i];

    s2.str[s2.len] = '\0';
}


// STRNCPY
void mystrncpy(String &s2, const String &s1, int n)
{
    int count = 0;

    while(count < n && count < s1.len)
        count++;

    s2.len = count;

    for(int i = 0; i < count; i++)
        s2.str[i] = s1.str[i];

    s2.str[count] = '\0';
}


// STRCMP
int mystrcmp(const String &s1, const String &s2)
{
    int i = 0;

    while(s1.str[i] != '\0' && s2.str[i] != '\0')
    {
        if(s1.str[i] != s2.str[i])
            return s1.str[i] - s2.str[i];

        i++;
    }

    return s1.str[i] - s2.str[i];
}


// STRNCMP
int mystrncmp(const String &s1, const String &s2, int n)
{
    int i = 0;

    while(i < n)
    {
        if(s1.str[i] != s2.str[i])
            return s1.str[i] - s2.str[i];

        if(s1.str[i] == '\0')
            return 0;

        i++;
    }

    return 0;
}


// STRCAT
void mystrcat(String &s2, const String &s1)
{
    int oldlen = s2.len;
    int i = 0;

    while(i < s1.len && oldlen + i < 99)
    {
        s2.str[oldlen + i] = s1.str[i];
        i++;
    }

    s2.len = oldlen + i;
    s2.str[s2.len] = '\0';
}


// STRNCAT
void mystrncat(String &s2, const String &s1, int n)
{
    int count = 0;

    while(count < n && count < s1.len && s2.len + count < 99)
        count++;

    for(int i = 0; i < count; i++)
        s2.str[s2.len + i] = s1.str[i];

    s2.len = s2.len + count;
    s2.str[s2.len] = '\0';
}


// STRREV
void mystrrev(String &s)
{
    int i = 0;
    int j = s.len - 1;

    while(i < j)
    {
        char temp;

        temp = s.str[i];
        s.str[i] = s.str[j];
        s.str[j] = temp;

        i++;
        j--;
    }
}


// STRUPR
void mystrupr(String &s)
{
    for(int i = 0; i < s.len; i++)
    {
        if(s.str[i] >= 'a' && s.str[i] <= 'z')
            s.str[i] = s.str[i] - 32;
    }
}


// STRLWR
void mystrlwr(String &s)
{
    for(int i = 0; i < s.len; i++)
    {
        if(s.str[i] >= 'A' && s.str[i] <= 'Z')
            s.str[i] = s.str[i] + 32;
    }
}


// STRCHR
char* mystrchr(const String &s, char ch)
{
    for(int i = 0; i < s.len; i++)
    {
        if(s.str[i] == ch)
            return const_cast<char*>(&s.str[i]);
    }

    return NULL;
}


// STRRCHR
char* mystrrchr(const String &s, char ch)
{
    for(int i = s.len - 1; i >= 0; i--)
    {
        if(s.str[i] == ch)
            return const_cast<char*>(&s.str[i]);
    }

    return NULL;
}


// STRSTR
char* mystrstr(String &s, char *sub)
{
    int sublen = 0;

    while(sub[sublen] != '\0')
        sublen++;

    if(sublen == 0)
        return s.str;

    if(sublen > s.len)
        return NULL;

    for(int i = 0; i <= s.len - sublen; i++)
    {
        int j;

        for(j = 0; j < sublen; j++)
        {
            if(s.str[i + j] != sub[j])
                break;
        }

        if(j == sublen)
            return &s.str[i];
    }

    return NULL;
}


// STRLEN
int mystrlen(const String &s)
{
    return s.len;
}


// MAIN
int main()
{
    int choice;
    int n;
    int index;
    char ch;
    char sub[100];

    do
    {
        cout << "\n========== STRING MENU ==========\n";

        cout << "1.  Default Constructor\n";
        cout << "2.  Parameterized Constructor\n";
        cout << "3.  Copy Constructor\n";
        cout << "4.  Assignment Operator\n";
        cout << "5.  Addition Operator\n";
        cout << "6.  Subscript Operator\n";
        cout << "7.  > Comparison\n";
        cout << "8.  < Comparison\n";
        cout << "9.  >= Comparison\n";
        cout << "10. <= Comparison\n";
        cout << "11. == Comparison\n";
        cout << "12. != Comparison\n";
        cout << "13. strcpy\n";
        cout << "14. strncpy\n";
        cout << "15. strcmp\n";
        cout << "16. strncmp\n";
        cout << "17. strcat\n";
        cout << "18. strncat\n";
        cout << "19. strrev\n";
        cout << "20. strupr\n";
        cout << "21. strlwr\n";
        cout << "22. strchr\n";
        cout << "23. strrchr\n";
        cout << "24. strstr\n";
        cout << "25. strlen\n";
        cout << "26. Input / Output\n";
        cout << "27. Exit\n";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                String s;

                cout << "Default String = [" << s << "]" << endl;

                break;
            }

            case 2:
            {
                char a[100];

                cout << "Enter string: ";
                cin >> a;

                String s(a);

                cout << "String = " << s << endl;

                break;
            }

            case 3:
            {
                char a[100];

                cout << "Enter string: ";
                cin >> a;

                String s1(a);
                String s2(s1);

                cout << "Original = " << s1 << endl;
                cout << "Copy     = " << s2 << endl;

                break;
            }

            case 4:
            {
                char a[100];

                cout << "Enter string: ";
                cin >> a;

                String s1(a);
                String s2;

                s2 = s1;

                cout << "Original = " << s1 << endl;
                cout << "Assigned = " << s2 << endl;

                break;
            }

            case 5:
            {
                char a[100];
                char b[100];

                cout << "Enter first string: ";
                cin >> a;

                cout << "Enter second string: ";
                cin >> b;

                String s1(a);
                String s2(b);

                String s3 = s1 + s2;

                cout << "Result = " << s3 << endl;

                break;
            }

            case 6:
            {
                char a[100];

                cout << "Enter string: ";
                cin >> a;

                String s(a);

                cout << "Enter index: ";
                cin >> index;

                int length = mystrlen(s);

                if(index >= 0 && index < length)
                    cout << "Character = " << s[index] << endl;
                else
                    cout << "Invalid index" << endl;

                break;
            }

            case 7:
            {
                char a[100];
                char b[100];

                cout << "Enter first string: ";
                cin >> a;

                cout << "Enter second string: ";
                cin >> b;

                String s1(a);
                String s2(b);

                if(s1 > s2)
                    cout << "First string is Greater";
                else
                    cout << "First string is Not Greater";

                break;
            }

            case 8:
            {
                char a[100];
                char b[100];

                cout << "Enter first string: ";
                cin >> a;

                cout << "Enter second string: ";
                cin >> b;

                String s1(a);
                String s2(b);

                if(s1 < s2)
                    cout << "First string is Smaller";
                else
                    cout << "First string is Not Smaller";

                break;
            }

            case 9:
            {
                char a[100];
                char b[100];

                cout << "Enter first string: ";
                cin >> a;

                cout << "Enter second string: ";
                cin >> b;

                String s1(a);
                String s2(b);

                if(s1 >= s2)
                    cout << "First string is Greater or Equal";
                else
                    cout << "First string is Smaller";

                break;
            }

            case 10:
            {
                char a[100];
                char b[100];

                cout << "Enter first string: ";
                cin >> a;

                cout << "Enter second string: ";
                cin >> b;

                String s1(a);
                String s2(b);

                if(s1 <= s2)
                    cout << "First string is Smaller or Equal";
                else
                    cout << "First string is Greater";

                break;
            }

            case 11:
            {
                char a[100];
                char b[100];

                cout << "Enter first string: ";
                cin >> a;

                cout << "Enter second string: ";
                cin >> b;

                String s1(a);
                String s2(b);

                if(s1 == s2)
                    cout << "Strings are Equal";
                else
                    cout << "Strings are Not Equal";

                break;
            }

            case 12:
            {
                char a[100];
                char b[100];

                cout << "Enter first string: ";
                cin >> a;

                cout << "Enter second string: ";
                cin >> b;

                String s1(a);
                String s2(b);

                if(s1 != s2)
                    cout << "Strings are Not Equal";
                else
                    cout << "Strings are Equal";

                break;
            }

            case 13:
            {
                char a[100];
                char b[100];

                cout << "Enter source string: ";
                cin >> a;

                cout << "Enter destination string: ";
                cin >> b;

                String s1(a);
                String s2(b);

                mystrcpy(s2, s1);

                cout << "After strcpy = " << s2 << endl;

                break;
            }

            case 14:
            {
                char a[100];
                char b[100];

                cout << "Enter source string: ";
                cin >> a;

                cout << "Enter destination string: ";
                cin >> b;

                cout << "Enter n: ";
                cin >> n;

                String s1(a);
                String s2(b);

                mystrncpy(s2, s1, n);

                cout << "After strncpy = " << s2 << endl;

                break;
            }

            case 15:
            {
                char a[100];
                char b[100];
                int result;

                cout << "Enter first string: ";
                cin >> a;

                cout << "Enter second string: ";
                cin >> b;

                String s1(a);
                String s2(b);

                result = mystrcmp(s1, s2);

                if(result == 0)
                    cout << "Both String Equal" << endl;
                else if(result > 0)
                    cout << "First String Greater" << endl;
                else
                    cout << "First String Smaller" << endl;

                break;
            }

            case 16:
            {
                char a[100];
                char b[100];
                int n, result;

                cout << "Enter first string: ";
                cin >> a;

                cout << "Enter second string: ";
                cin >> b;

                cout << "Enter n: ";
                cin >> n;

                String s1(a);
                String s2(b);

                result = mystrncmp(s1, s2, n);

                if(result == 0)
                    cout << "Both String Equal" << endl;
                else if(result > 0)
                    cout << "First String Greater" << endl;
                else
                    cout << "First String Smaller" << endl;

                break;
            }

            case 17:
            {
                char a[100];
                char b[100];

                cout << "Enter first string: ";
                cin >> a;

                cout << "Enter second string: ";
                cin >> b;

                String s1(a);
                String s2(b);

                mystrcat(s1, s2);

                cout << "After strcat = " << s1 << endl;

                break;
            }

            case 18:
            {
                char a[100];
                char b[100];

                cout << "Enter first string: ";
                cin >> a;

                cout << "Enter second string: ";
                cin >> b;

                cout << "Enter n: ";
                cin >> n;

                String s1(a);
                String s2(b);

                mystrncat(s1, s2, n);

                cout << "After strncat = " << s1 << endl;

                break;
            }

            case 19:
            {
                char a[100];

                cin.ignore(1000, '\n');

                cout << "Enter string: ";
                cin.getline(a, 100);

                String s(a);

                mystrrev(s);

                cout << "Reverse = " << s << endl;

                break;
            }

            case 20:
            {
                char a[100];

                cin.ignore(1000, '\n');

                cout << "Enter string: ";
                cin.getline(a, 100);

                String s(a);

                mystrupr(s);

                cout << "Uppercase = " << s << endl;

                break;
            }

            case 21:
            {
                char a[100];

                cin.ignore(1000, '\n');

                cout << "Enter string: ";
                cin.getline(a, 100);

                String s(a);

                mystrlwr(s);

                cout << "Lowercase = " << s << endl;

                break;
            }

            case 22:
            {
                char a[100];

                cin.ignore(1000, '\n');

                cout << "Enter string: ";
                cin.getline(a, 100);

                cout << "Enter character: ";
                cin >> ch;

                String s(a);

                char *p = mystrchr(s, ch);

                if(p != NULL)
                {
                    cout << "Character found = " << *p << endl;
                    cout << "Index = " << p - s.getData() << endl;
                }
                else
                    cout << "Character not found" << endl;

                break;
            }

            case 23:
            {
                char a[100];

                cin.ignore(1000, '\n');

                cout << "Enter string: ";
                cin.getline(a, 100);

                cout << "Enter character: ";
                cin >> ch;

                String s(a);

                char *p = mystrrchr(s, ch);

                if(p != NULL)
                {
                    cout << "Last occurrence = " << *p << endl;
                    cout << "Index = " << p - s.getData() << endl;
                }
                else
                    cout << "Character not found" << endl;

                break;
            }

            case 24:
            {
                char a[100];

                cin.ignore(1000, '\n');

                cout << "Enter string: ";
                cin.getline(a, 100);

                cout << "Enter substring: ";
                cin.getline(sub, 100);

                String s(a);

                char *p = mystrstr(s, sub);

                if(p != NULL)
                {
                    cout << "Substring found = ";

                    int i = 0;

                    while(sub[i] != '\0')
                    {
                        cout << p[i];
                        i++;
                    }

                    cout << endl;
                    cout << "Index = " << p - s.getData() << endl;
                }
                else
                    cout << "Substring not found" << endl;

                break;
            }

            case 25:
            {
                char a[100];

                cin.ignore(1000, '\n');

                cout << "Enter string: ";
                cin.getline(a, 100);

                String s(a);

                cout << "Length = " << mystrlen(s) << endl;

                break;
            }

            case 26:
            {
                String s;

                cout << "Enter string: ";
                cin >> s;

                cout << "Entered string = " << s << endl;

                break;
            }

            case 27:
            {
                cout << "Program terminated" << endl;

                break;
            }

            default:
            {
                cout << "Invalid choice" << endl;
            }
        }

    } while(choice != 27);

    return 0;
}

