#include <cassert>
#include <cstddef>
#include <iostream>
#include <functional>
#include <utility>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include "csvstream.hpp"


std::set<std::string> unique_words(const std::string &str) {
  std::istringstream source(str);
  std::set<std::string> words;
  std::string word;
  while (source >> word) {
    words.insert(word);
  }
  return words;
}

class Classifier {

private:
struct DataSet {
int totalPosts;
int totalUniqueWords;
std::set<std::string> UniqueWords;
std::map<std::string, int> numForEachWord;
std::map<std::string, int> numForEachLabel;
std::map<std::string, std::map<std::string, int> > numPairWordLabel;
};



public:

Classifier() {
}
~Classifier(){

}


void training(std::string filename) {
    csvstream csvin(filename);

  // Rows have key = column name, value = cell datum
  std::map<std::string, std::string> row;


  // Extract the "animal" column
  std::vector<std::string> labels;
  std::vector<std::set <std::string> > posts;
  DataSet data;
  data.totalUniqueWords = 0;
  std::set<std::string> words;
  data.totalPosts = 0;
  std::map < std::string, int > postsPerWord;
  std::map < std::string, int > postsPerLabel;
  std::map < std::string, int > wordLabelMap;
  while (csvin >> row) {
    std::set < std::string > words = unique_words(row["content"]);
    for (const auto& element : words) {
        std::string temp = element + "-" + row["tag"];
        std::cout << temp << std::endl;
        if (wordLabelMap.find(temp) == wordLabelMap.end()){
            wordLabelMap[temp] = 1;
        }
        else {
            wordLabelMap[temp]++;
            data.numPairWordLabel["tag"][temp]++;
        }
    }
    std::cout << row["tag"] << " | ";
    std::cout << row["content"] << "\n";
    labels.push_back(row["tag"]);
    posts.push_back(words);
    std::cout << "Posts:\n";
    data.totalPosts ++;
    std::istringstream source(row["content"]);
    std::string word;
    if (postsPerLabel.find(row["tag"]) == postsPerLabel.end()){
            postsPerLabel[row["tag"]] = 1;
        }
    else {
            postsPerLabel[row["tag"]]++;
            data.numForEachLabel["tag"]++;
        }
    while (source >> word) {
        words.insert(word);
        if (postsPerWord.find(word) == postsPerWord.end()){
            postsPerWord[word] = 1;
        }
        else {
            postsPerWord[word]++;
            data.numForEachWord[word]++;
        }
        
    }
  }
  data.totalUniqueWords = sizeof(words);
}
};



int main(int argc, char *argv[]){
std::cout.precision(3);
    if ((argc != 3) && (argc != 4)) {
        std::cout << "Usage: main.exe TRAIN_FILE TEST_FILE [--debug]" << std::endl;
        return 1;
    }
    if ((argc == 4) && strcmp(argv[3], "--debug") != 0){
        std::cout << "Usage: main.exe TRAIN_FILE TEST_FILE [--debug]" << std::endl;
        return 1;
  }

  bool debug = (argc == 4) && (std::string(argv[3]) == "--debug");

Classifier classifier;

classifier.training(argv[1]);
if (debug){

}

}