#include <iostream>


class OO {

public:
    OO(const char* name, int age): age(age) {
        std::cout << "constructor called!" << '\n';
        //dummy integer count
        unsigned int index(0);
        //get size
        int name_size(this->strlen(const_cast<char *>(name)));
        //get str area on heap
        this->name = new char[name_size+1];
        //rvalue str copies cus it'll be cleared
        for(index=0;index<name_size+1;++index)
            this->name[index] = '\0';
        for(index=0;index<name_size;++index)
            this->name[index] = name[index];
    };
    OO(OO&& ref) {
        this->name = ref.name;
        this->age = ref.age;
        ref.name = nullptr;
        std::cout  << "move constructor" << std::endl;
    };
    ~OO() {
        if (this->name != nullptr) {
            std::cout << "destructor called by end and now delete : " << "[" << this->name << "]" << '\n';
            delete[] this->name;
        } else {
            std::cout << "destructor called by end and [ ~notting ] deletes" << '\n';
        };
    };
private:
    unsigned int strlen(char* txt) {
        unsigned int si(0);
        while(txt[si])
            ++si;
        return si;
    };
private:
    char* name;
    int age;


};

int main() {
    std::cout << "■■■■■■■■■■■■■■■■■■Hello, World! and learn bout pointer copies or refs mechanism!!" << std::endl;

    OO a("hello",12);
    OO b(static_cast<OO&&>(a));

    std::cout << "■■■■■■■■■■■■■■■■■■program is over" << '\n';
    return 0;
}
