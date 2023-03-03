#include <iostream>

using namespace std;

// string DSA

int validate(string s)
{
    int i = 0;
    int j = s.length() - 1;
    while (i < j)
    {
        if (s[i] != s[j])
            return 0;
        i++;
        j--;
    }
    return 1;
}

void swap(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}

int permute(string s1, string s2)
{
    int i, j;
    int H[26] = {0};
    for (i = 0; s1[i] != '\0'; i++)
    {
        H[s1[i] - 97]++;
    }
    for (i = 0; s2[i] != '\0'; i++)
    {
        H[s2[i] - 97]--;
        if (H[s2[i] - 97] < 0)
            return 0;
    }
    return 1;
}

int reverseString(string s)
{
    int i = 0;
    int j = s.length() - 1;
    while (i < j)
    {
        swap(s[i], s[j]);
        i++;
        j--;
    }
    return 1;
}

int reverseString2(string s)
{
    int i = 0;
    int j = s.length() - 1;
    while (i < j)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
    return 1;
}

int reverseString3(string s)
{
    int i = 0;
    int j = s.length() - 1;
    while (i < j)
    {
        s[i] = s[i] + s[j];
        s[j] = s[i] - s[j];
        s[i] = s[i] - s[j];
        i++;
        j--;
    }
    return 1;
}

int length(string s)
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

int changingCase(string s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] >= 65 && s[i] <= 90)
            s[i] += 32;
        else if (s[i] >= 97 && s[i] <= 122)
            s[i] -= 32;
        i++;
    }
    return 1;
}

int FindingDuplicate(string s)
{
    int i, j;
    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i + 1; s[j] != '\0'; j++)
        {
            if (s[i] == s[j])
                return 1;
        }
    }
    return 0;
}

int FindingDuplicate2(string s)
{
    int H[26] = {0};
    int i;
    for (i = 0; s[i] != '\0'; i++)
    {
        H[s[i] - 97]++;
    }
    for (i = 0; i < 26; i++)
    {
        if (H[i] > 1)
            return 1;
    }
    return 0;
}

int FindingDuplicate3(string s)
{
    int H[26] = {0};
    int i;
    for (i = 0; s[i] != '\0'; i++)
    {
        H[s[i] - 97]++;
        if (H[s[i] - 97] > 1)
            return 1;
    }
    return 0;
}

int FindingDuplicate4(string s)
{
    int H[26] = {0};
    int i;
    for (i = 0; s[i] != '\0'; i++)
    {
        H[s[i] - 97]++;
    }
    for (i = 0; s[i] != '\0'; i++)
    {
        if (H[s[i] - 97] > 1)
            return 1;
    }
    return 0;
}

int palindrome(string s)
{
    int i = 0;
    int j = s.length() - 1;
    while (i < j)
    {
        if (s[i] != s[j])
            return 0;
        i++;
        j--;
    }
    return 1;
}

int main()
{
    string s = "madam";
    cout << validate(s) << endl;
    cout << reverseString(s) << endl;
    cout << reverseString2(s) << endl;
    cout << reverseString3(s) << endl;
    cout << length(s) << endl;
    cout << changingCase(s) << endl;
    cout << FindingDuplicate(s) << endl;
    cout << FindingDuplicate2(s) << endl;
    cout << FindingDuplicate3(s) << endl;
    cout << FindingDuplicate4(s) << endl;
    cout << palindrome(s) << endl;

    return 0;
}