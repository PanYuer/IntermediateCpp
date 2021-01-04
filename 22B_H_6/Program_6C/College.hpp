// Specification file for the College class
// Written By: Pan Yue
// IDE: VS Code

#ifndef COLLEGE_H
#define COLLEGE_H

using std::string;

class College
{
private:
    string code;
    string name;
    int rank;
    int cost;

public:
    // Default constructor
    College()
    {
        code = "";
        name = "";
        rank = 0;
        cost = 0;
    }

    // Overloaded Constructor
    College(int r, string c, string n, int m)
    {
        code = c;
        name = n;
        rank = r;
        cost = m;
    }

    // Setters and getters
    void setCode(string c) { code = c; }
    void setName(string n) { name = n; }
    void setRank(int r) { rank = r; }
    void setCost(int m) { cost = m; }
    string getCode() const { return code; }
    string getName() const { return name; }
    int getRank() const { return rank; }
    int getCost() const { return cost; }
    void hDisplay() const;
    void vDisplay() const;
};

#endif
