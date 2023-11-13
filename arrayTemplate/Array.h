#include <iostream>

template<class T>
class Array{
    friend std::ostream& operator <<(std::ostream& os, const Array& t){
        os<<"[";
        for(int i=0; i<t._length; i++){
            if(i==t._length-1){
                os<<*(t.data+i)<<"] ";
            }else{
                os<<*(t.data+i)<<", ";
            }
            
        }
        return os;
    }   
    private:
        T* data;
        T* temp;
        int _size;
        int _length;
    public:
        Array():data{nullptr}, temp{nullptr}, _size{0}, _length{0}{};
        void push(const T& _data){
            if(_length>=_size){
        if(data==nullptr){
            data=new T[2];
            _size=2;
            _length++;
            *(data+_length-1)=_data;
        }else{
            temp=data;
            data= new T[_size*2];
            for (int i = 0; i < _length; i++) {
                *(data + i) = *(temp + i);
            }
            _size=_size*2;
            _length++;
            *(data+_length-1)=_data;
            delete[] temp;
        }
        
    }else{
        _length++;
        *(data+_length-1)=_data;
    }
        };
        int length(){return _length;};
        T& operator[](int n){
            return *(data+n);
        }
        ~Array(){
            if(temp==nullptr){
                delete[] temp;
            }
            if(data==nullptr){
                delete[] data;
            }
        };

};
