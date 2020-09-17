#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'sortRoman' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY names as parameter.
 */

int convertRoman(char r)
{
    switch(r)
    {
        case 'L': return 50;
        case 'X': return 10;
        case 'V': return 5;
        case 'I': return 1;
        default: throw invalid_argument("invalid");
    }
}

string convertBackToRoman (int roman)
{
    string x[] = {"", "X", "XX", "XXX", "XL", "L"};
    string i[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

    string tens = x[(roman%100)/10];
    string ones = i[roman%10];
    string ans = tens + ones;

    return ans;

}

int convertStringToInt(string& roman)
{
    int result = 0;
    int last_added = 0;
    for(auto it = roman.rbegin(); it != roman.rend(); ++it)
    {
        const int val = convertRoman(*it);
        if( val >= last_added)
        {
            result += val;
            last_added = val;
        } 
        else 
        {
            result -= val;
        }
    } 

    return result;
}
vector<string> sortRoman(vector<string> &names) {
    sort(names.begin(), names.end()); //sort names alphabetically
    string delimiter = " ";
    vector<int> to_append;

    for (auto i = names.begin(); i != names.end(); ++i)
    {
        string roman_numeral = (i->substr(i->find(delimiter) + 1));    
        int num = convertStringToInt(roman_numeral);
        i->erase(i->find(delimiter) + 1);
        to_append.push_back(num);        
    }
    vector<int>:: iterator it = to_append.begin();
    sort(to_append.begin(), to_append.end());
    for (auto i = names.begin(); i != names.end(); ++i)
    {
        i->append(to_string(*it));
        it++;
    }

    for (auto i = names.begin(); i != names.end(); ++i)
    {
        string roman_numeral = (i->substr(i->find(delimiter) + 1));    
        int num = stoi(roman_numeral);
        string new_roman = convertBackToRoman(num);
        i->erase(i->find(delimiter) + 1);
        i->append(new_roman);
    }
    return names;
}

int main(){
    vector<string> test = {"Francois VI","Francois XL","Francois XX", "Larry IV", "Larry I", "Alpha II" ,"Alpha L"};

    sortRoman(test);
}