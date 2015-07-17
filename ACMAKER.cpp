/* 
 * File:   ACMAKER.cpp
 * Author: Rakesh
 * Accepted
 * Created on 28 June, 2015, 9:51 AM
 */

#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
#include<algorithm>
using namespace std;
map<string, bool> insignificant;
string data, abbr, *word;
int abbr_length, num_word;
long long int save[160][160][160];

int main() {
    int insigni, i, word_no, abb_no, j, k;
    string value, temp, temp_abbr;
    cin>>insigni;
    while (insigni > 0) {
        for (i = 0; i < insigni; i++) {
            cin>>value;
            insignificant[value] = true;
        }
        getchar();
        getline(cin, data);
        while (data != "LAST CASE") {
            //cout << data << endl;
            word = new string[150];
            num_word = 0;
            temp = "";
            for (i = 0; i < data.length(); i++) {
                if (data[i] == ' ') {
                    if (insignificant[temp]) {
                        temp = "";
                        continue;
                    }
                    word[num_word] = temp;
                    temp = "";
                    num_word++;
                } else {
                    temp += data[i];
                }
            }
            if (!insignificant[temp]) {
                word[num_word] = temp;
                num_word++;
            }
            abbr = word[0];
            temp_abbr = abbr;
            // for (int m = 0; m < num_word; m++) {
            //    cout << word[m] << " ";
            //}
            transform(abbr.begin(), abbr.end(), abbr.begin(), ::tolower);
            abbr_length = abbr.length();
            if (num_word > abbr_length + 1) {
                cout << temp_abbr << " is not a valid abbreviation" << endl;
            } else {

                for (i = 0; i <= num_word; i++) {
                    for (j = 0; j <= abbr_length; j++) {
                        for (k = 0; k <= data.length(); k++) {
                            save[i][j][k] = 0;
                        }
                    }
                }
                for (word_no = 0; word_no < num_word; word_no++) {
                    for (abb_no = 0; abb_no <= abbr_length; abb_no++) {
                        for (int j = 0; j <= word[word_no].length(); j++) {
                            if (word_no == 0 || abb_no == 0 || j == 0) {
                                save[word_no][abb_no][j] = 0;
                                continue;
                            }
                            save[word_no][abb_no][j] = 0;
                            if (abbr[abb_no - 1] == word[word_no][j - 1] && abb_no >= word_no) {
                                if (abb_no == 1 && word_no == 1) {
                                    save[word_no][abb_no][j] = save[word_no][abb_no][j - 1] + 1;
                                    //continue;
                                } else {//if (save[word_no][abb_no - 1][j - 1] > 0 || save[word_no - 1][abb_no - 1][word[word_no - 1].length()]) {
                                    save[word_no][abb_no][j] = save[word_no][abb_no - 1 ][j - 1] + save[word_no][abb_no][j - 1] + save[word_no - 1][abb_no - 1][word[word_no - 1].length()]; //+ save[word_no - 1][abb_no][word[word_no - 1].length()];
                                }
                                //save[word_no][abb_no][j] += save[word_no][abb_no][j-1] + 1;

                            } else {
                                save[word_no][abb_no][j] = save[word_no][abb_no][j - 1];
                            }
                            //      cout<<save[word_no][abb_no][j]<<" ";
                        }
                        //  cout<<endl;
                    }
                }
                if (save[num_word - 1][abbr_length][word[num_word - 1].length()] > 0) {
                    cout << temp_abbr << " can be formed in " << save[num_word - 1][abbr_length][word[num_word - 1].length()] << " ways" << endl;
                } else {
                    cout << temp_abbr << " is not a valid abbreviation" << endl;
                }
            }
            getline(cin, data);
        }

        insignificant.clear();
        cin>>insigni;
    }
    return 0;
}

