#include <iostream>     	// for cout, cin
#include <fstream>      	// for ifstream
#include <sstream>      	// for stringstream
#include <filesystem>   	// making inputting files easier
#include <unordered_set>	// containers for the wikiscraper
#include <vector>
#include <queue>
#include <unordered_map>
#include "wikiscraper.h"    // wikiscraper methods

using std::cout;            using std::endl;
using std::ifstream;        using std::stringstream;
using std::string;          using std::vector;
using std::priority_queue;  using std::unordered_map;
using std::unordered_set;   using std::cin;

void split(const string& str, char delim, vector<string>& output) {
    stringstream ss;
    ss << str;
    string item;
    while (getline(ss, item, delim)) {
        output.emplace_back(item);
    }
}

int main() {
    // a quick working directory fix to allow for easier filename inputs
    auto path = std::filesystem::current_path() / "res/";
    std::filesystem::current_path(path);
    std::string filenames = "Available input files: ";
    for (const auto& entry : std::filesystem::directory_iterator(path)) {
        std::string filename = entry.path().string();
        filename = filename.substr(filename.rfind("/") + 1);
        filenames += filename + ", ";
    }
    // omit last ", ".
    cout << filenames.substr(0, filenames.size() - 2) << "." << endl;

    /* Container to store the found ladders in */
    vector<vector<string>> outputLadders;

    cout << "Enter a file name: ";
    string filename;
    getline(cin, filename);

    /* 
        TODO: Create a filestream from the filename.
        For each pair {start_page, end_page} in the input file,
        retrieve the result of findWikiLadder(start_page, end_page)
        and append that vector to outputLadders.
    */
    // Write code here
    ifstream myfile (path.string() + filename);
    int numPairs;
    // parse the first line as the number of tokens
    myfile >> numPairs;

    // loop through each line, parsing out page names and calling findWikiLadder
    string startPage, endPage;
    for (int i = 0; i < numPairs; i++) {
        // parse the start and end page from each line
        myfile >> startPage >> endPage;
        outputLadders.push_back(findWikiLadder(startPage, endPage));
    }
    /*
     * Print out all ladders in outputLadders.
     * We've already implemented this for you!
     */
    // Write code here
    for (auto& ladder : outputLadders) {
        if (ladder.empty()) {
            cout << "No ladder found!" << endl;                
        } else {
                        /*
             * The above is an alternate way to print to cout using the
             * STL algorithms library and iterators. This is equivalent to:
             */
            for (size_t i = 0; i < ladder.size() - 1; ++i) {
                cout << ladder[i] << ", ";
            }
            cout << ladder.back() << "}" << endl;
        }
    }
    return 0;
}




