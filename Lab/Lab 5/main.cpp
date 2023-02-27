/*
 * Name: Grayson Whitaker
 * Date Submitted: 3/6/2023
 * Lab Section: 002
 * Assignment Name: Lab 5: Spell Checker Using a Hash Table
 */
 
 #include "stringset.h"
 #include <iostream>
 #include <fstream>
 
 void testStringset(Stringset& words);
 void loadStringset(Stringset& words, string filename);
 vector<string> spellcheck(const Stringset& words, string word);

//  int main()
//  {
//     Stringset wordlist;
//     loadStringset(wordlist, "wordlist.txt");
//     // testStringset(wordlist);
//     string input;
//     cout << "Enter word to spellcheck: ";
//     cin >> input;
//     cout << input;
//     if(wordlist.find(input)){
//         cout << " found" << endl;
//     }
//     else{
//         cout << " not found" << endl;
//     }
//     vector<string> alt = spellcheck(wordlist, input);
//     cout << "Alternatives(" << alt.size() << "): " << endl;
//     for(auto i : alt){
//         cout << i << endl;
//     }
//     return 0;
//  }
 
 void testStringset(Stringset& words)
 {
     string choice;
     string word;
     do
     {
         cout << "I: insert word" << endl;
         cout << "F: find word" << endl;
         cout << "R: remove word" << endl;
         cout << "P: print words in stringset" << endl;
         cout << "Q: quit" << endl;
         cin >> choice;
         switch (choice[0])
         {
             case 'I':
             case 'i':
                cout << "Enter word to insert: ";
                cin >> word;
                words.insert(word);
                break;
             case 'F':
             case 'f':
                cout << "Enter word to find: ";
                cin >> word;
                if (words.find(word))
                {
                    cout << word << " in stringset" << endl;
                }
                else
                {
                    cout << word << " not in stringset" << endl;
                }
                break;
             case 'R':
             case 'r':
                cout << "Enter word to remove: ";
                cin >> word;
                words.remove(word);
                break;
             case 'P':
             case 'p':
                vector<list<string>> t = words.getTable();
                int numWords = words.getNumElems();
                int tSize = words.getSize();
                for(int i=0; i<tSize; ++i)
                {
                    list<string>::iterator pos;
                    for (pos = t[i].begin(); pos != t[i].end(); ++pos)
                    {
                        cout << *pos << endl;
                    }
                }
                cout << "Words: " << numWords << endl;
         }
     } while (choice[0] != 'Q' && choice[0] != 'q');
 }
 
 // Loads words from a file into a stringset
 void loadStringset(Stringset& words, string filename){
    // open file
    ifstream inputFile(filename);
    string word;
    // read words from file and insert into stringset
    while(inputFile >> word){
        words.insert(word);
    }
    // close file
    inputFile.close();
}
 
 // checks for alternative spellings for a certain string
 vector<string> spellcheck(const Stringset& words, string word){
    vector<string> alternatives;
    // increment through string
    for(int i = 0; i < word.length(); i++){
        // set/reset temp and alternateChar
        string temp = word;
        char alternateChar = 'a';
        for(int j = 0; j < 26; j++, alternateChar++){
            // swap out char at index with each letter from alphabet
            temp[i] = alternateChar;
            // if an alternative is found, add to alternative array
            if(words.find(temp) && temp[i] != word[i]){
                alternatives.push_back(temp);
            }
        }
    }
    return alternatives;
}