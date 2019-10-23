// The program reads the lines and displays the category of each character

#include "../std_lib_facilities.h"

void symbol_category(string& s);

int main()
{
	while (true) {
		cout << "Enter the symbol d to analyze the default line\n"
			<< "(5x+ 6  xy- 23  x  8 3	4		x 2*1+4*x<=y/z*5>8)\n"
			<< " on the category of each character of this line \n"
			<< " or enter your own line for analysis (to exit, enter - quit):\n";
		string str;
		getline(cin, str);
		if (str == "quit")
			break;
		else if (str == "d") {
			str = "5x+ 6  xy- 23  x  8 3	4		x 2*1+4*x<=y/z*5>8";
			symbol_category(str);
		}

		else
			symbol_category(str);
	}
	return 0;
}

void symbol_category(string& s)
{
	istringstream is(s);
	char temp = 'a';
	for (char ch; is.get(ch);)
	{
		if (isspace(ch)) {
			cout << "\'" << ch << "\'" << " - whitespace \n";
			//temp = ch;
		}
		else if (isdigit(ch)) {
			cout << "\'" << ch << "\'" << " - numeric character \n";
			temp = ch;
		}
		else if (isalpha(ch))
		{
			if (ch == 'x')
			{
				vector<string>vs{};
				string str_t = "\'";
				char ch2;
				while (is.get(ch2))
				{
					if (isspace(ch2))
					{
						str_t = str_t + ch2 + "\' - whitespace";
						vs.push_back(str_t);
						str_t = "\'";
					}
					else
						break;
				}
				if (isdigit(temp) && isdigit(ch2))
				{
					cout << "\'" << ch << "\'" << " - arithmetic operations character \n";
					for (string& s : vs)
					{
						cout << s << '\n';
					}
					is.unget();
					temp = ch;
				}
				else
				{
					cout << "\'" << ch << "\'" << " - letter character \n";
					is.unget();
					temp = ch;
				}
			}
			else
			{
				cout << "\'" << ch << "\'" << " - letter character \n";
				temp = ch;
			}

		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
			cout << "\'" << ch << "\'" << " - arithmetic operations character \n";
			temp = ch;
		}
		else if (ch == '<' || ch == '>')
		{
			char ch2;
			is >> ch2;
			if (ch2 == '=')
			{
				cout << "\'" << ch << ch2 << "\'" << " - arithmetic operations character \n";
				temp = ch;
			}
			else
			{
				cout << "\'" << ch << "\'" << " - arithmetic operations character \n";
				is.unget();
				temp = ch;
			}
		}
	}
}
