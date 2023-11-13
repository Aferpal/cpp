#pragma once

class Move{
    private:
        int* data;
    public:
        Move(const Move&);
        Move(int);
        Move(Move&&);
        int getData()const;
        void setData(int);
        ~Move();
};