#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

string condense(string &sentence) {

	sentence.erase(remove_if(sentence.begin(), sentence.end(), isspace), sentence.end()); // removes whitespaces from string

	return sentence;

}

string organize(string &condensed) {		// sorts condensed string into alphabetical order
	sort(condensed.begin(), condensed.end());

	return condensed;
}

int main() {

	ifstream sourcefile;
	ofstream histofile;
	string sentence;

	sourcefile.open("sourcefile.txt", ios::in); // opens file storing sentence to be analyzed

	for (int i = 0; !(sourcefile.eof()); i++) { // writes external file contents to 'sentence' variable
		getline(sourcefile, sentence);
	}

	condense(sentence);
	organize(sentence);

	histofile.open("histofile.txt");

	int count = 1;

	for (int i = 0; i < sentence.size(); i++) {
		while (sentence[i] == sentence[i + 1] && i < (sentence.size() - 1)) {

			count++;
			i++;
		}

			histofile << sentence[i] << " ";
			for (int p = 0; p < count; p++) {
				histofile << "*";
			}
			histofile << count << endl;


		count = 1;
	}

	histofile.close();



	return 0;
}
