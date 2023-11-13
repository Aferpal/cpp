class MyString{
private:
    char* string;
    int length;
public:
    MyString(char*);
    MyString(const MyString&);
    MyString(MyString&&);
    ~MyString();
    int size();

};