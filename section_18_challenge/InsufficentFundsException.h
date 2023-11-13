#include <exception>

class InsufficentFundsException: public std::exception{
    public:
        InsufficentFundsException() {}
        ~InsufficentFundsException() {}
        virtual const char* what() noexcept;
};