// Specification file for the Country class

#ifndef COUNTRY_H
#define COUNTRY_H

using std::string;

class Country
{
private:

    string code,
            name,
            capital;
    long int population;

public:
    Country() {code = ""; name = ""; capital = ""; population = 0;}
    
    // Setters
    void setCode(string co) {code = co;}
    void setName(string n) {name = n;}
    void setCapital(string cp) {capital = cp;}
    void setPopulation(long int p) {population = p;}
    void setAll(string co, string n, string cp, long int p)
        {code = co; name = n; capital = cp; population = p;}
    //getters
    string getCode() const {return code;}
    string getName() const {return name;}
    string getCapital() const {return capital;}
    long int getPopulation() const {return population;}

};

#endif
