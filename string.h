#ifndef __string__
#define __string__
#include<cstring>
#include<ostream>
#include<iostream>

class String{
    private:
        char* m_data;
    public:
    String(const char* str=nullptr){
        if(str){
            m_data=new char[strlen(str)+1];
            strcpy(m_data,str);
        }else{
            m_data = new char[1];
            *m_data = '\0';
        }
    }
    char* get_c_str() const{return m_data;}
};

inline std::ostream&
operator << (std::ostream& os, const String& str){
    os << str.get_c_str();

    
    return os;
}

#endif