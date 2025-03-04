#include <iostream>
#include <string>
using namespace std;
char vowel[] = {'a', 'e', 'i', 'o', 'u'};

bool solve(const string& word)
{
    bool hasVowel = false;
    bool continued[2] = {false, false}; // 자음 모음
    bool type[21] = {false, }; //자음 모음
    for(int i=0; i<word.size(); ++i)
    {
        for(int j=0; j<5; ++j)
        {
            if(word[i] == vowel[j])
            {
                type[i] = true;
                hasVowel = true;
                break;
            }
        }

        if(i > 0 && word[i] != 'e' && word[i] != 'o')
        {
            if(word[i-1] == word[i])
                return false;
        }

        if(i > 1 && (type[i-2] == type[i-1]))
        {
            if(type[i-1] == type[i])
                return false;
        }
    }

    return (hasVowel);
}

int main()
{
    string word;
    while(1)
    {
        cin >> word;
        if(word == "end")
            break;

        bool bAnswer = solve(word);
        cout << "<" << word << "> is " << (bAnswer ? "" : "not ") << "acceptable.\n";
    }

    return 0;
}
