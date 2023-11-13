class String{
    private:
        char* data;
    public:
        String(const char*);
        String(const String&);
        String(String&&);
        ~String();
        String operator-();
        void printSelf();
        bool operator==(const String&);
        bool operator!=(const String&);
        bool operator>(const String&);
        bool operator<(const String&);
        String operator +(const String&);
        void operator+=(const String&);
        String operator*(int);
        void operator*=(int);
};