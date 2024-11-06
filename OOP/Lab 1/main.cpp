#include <iostream>
#include <string>

using namespace std;

class Company {
    private:
        string name;
        string address;
        string directorName;
        int numberOfEmployee;
    
    public:
        Company(){
            name = "";
            address = "";
            directorName = "";
            numberOfEmployee = 0;
        }

    Company (string name, string address, string directorName, int numberOfEmployee){
        this->name = name;
        this->address = address;
        this->directorName = directorName;
        this->numberOfEmployee = numberOfEmployee; 
    }

    ~Company(){

    }
};

int main(){

    

}