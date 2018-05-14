#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/lexical_cast.hpp>
using namespace std;

//Single Responsibility principle

struct Journal
{
  string title;
  vector<string> entries;

  explicit Journal(const std::string& title)
    : title{title}
  {
  }

  void add(const std::string& entry);

  // persistence is a separate concern
  void save(const std::string& filename);
};

void Journal::add(const std::string& entry)
{
  static int count = 1;
  entries.push_back(boost::lexical_cast<string>(count++)
    + ": " + entry);
}

void Journal::save(const std::string& filename)
{
  ofstream ofs(filename);
  for (auto& s : entries)
    ofs << s << endl;
}

struct PersistenceManager
{
  static void save(const Journal& j, const std::string& filename)
  {
    ofstream ofs(filename);
    for (auto& s : j.entries)
      ofs << s << endl;
  }
};

int  main_srp()
{
  // Journal journal("Dear Diary");
  Journal journal{"Dear Diary"};
  journal.add("I ate a bug");
  journal.add("I cried today");

  //journal.save("diary.txt");

  PersistenceManager pm;
  pm.save(journal, "diary.txt");
  return 0;
}