#include <bits/stdc++.h>

using namespace std;

class Person{
private:
    string name, birth, address;
public:
    Person(string name, string birth, string address){
        this->name = name;
        this->birth = birth;
        this->address = address;
    }

    void convertedInfo(){
        //Converted Name
        string word, tmp = "";
        stringstream ss(this->name);
        while(ss >> word){
            tmp += toupper(word[0]);
            for(int j = 1; j < word.length(); j++){
                tmp += tolower(word[j]);
            }
            tmp += " ";
        }
        tmp.pop_back();
        this->name = tmp;

        //Converted Birth
        if(this->birth[1] == '/')
            this->birth = "0" + this->birth;
        if(this->birth[4] == '/')
            this->birth.insert(3, "0");
    }

    void print(){
        cout << name << " " << birth << " " << address << " "; 
    }
};

class Student : public Person{
private:    
    string ID, class_name;
    double gpa;
public: 
    Student(int stt, string name, string birth, string address, string class_name, double gpa) : Person(name, birth, address){
        ID = string(4 - to_string(stt).length(), '0') + to_string(stt);
        this->class_name = class_name;
        this->gpa = gpa;
    }

    void print(){
        cout << ID << " ";
        Person::print();
        cout << class_name << " " << fixed << setprecision(2) << gpa << endl;
    }
};

int main(){
    int n; cin >> n;
    vector<Student> v;
    for(int i = 0; i < n; i++){
        cin.ignore();
        string name, s, birth, address;
        getline(cin, name);
        getline(cin, s);
        int idx = 0;
        while(!isalpha(s[idx])){
            birth += s[idx];
            idx++;
        }
        while(idx < s.length()){
            address += s[idx];
            idx++;
        }
        string class_name;
        getline(cin, class_name);
        double gpa; cin >> gpa;
        Student x(i + 1, name, birth, address, class_name, gpa);
        x.convertedInfo();
        v.push_back(x);
    }
    for(Student x : v) x.print();
}