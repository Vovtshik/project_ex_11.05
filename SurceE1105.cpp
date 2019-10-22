#include "../std_lib_facilities.h"

void tolower_s(string& s);
void symbol_category(string& s);

int main()
{

    return 0;
}

void tolower_s(string& s)
{
    for(char& x: s) x = tolower(x);
}

void symbol_category(string& s)
{
    istringstream is(s);
    char temp;
    for(char ch; is.get(ch);)
    {
        if(isspace(ch)) {
            cout << "\'"<< ch << "\'" << " - whitespace \n";
            temp = ch;
        }
        else if(isdigit(ch)) {
            cout << "\'"<< ch << "\'" << " - numeric character \n";
            temp = ch;
        }
        else if(isalpha(ch)) 
        {
            if(ch == 'x') 
            {
                char ch2;
                is >> ch2;
                if(isdigit(temp) && isdigit(ch2)) 
                {
                    cout << "\'"<< ch << "\'" << " - arithmetic operations character \n";
                    is.unget();
                    temp = ch;
                }
            }
            else
            {
                cout << "\'"<< ch << "\'" << " - letter character \n";
                temp = ch;
            }
            
        }
        else if( ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            cout << "\'"<< ch << "\'" << " - arithmetic operations character \n";
            temp = ch;
        }
    }
}