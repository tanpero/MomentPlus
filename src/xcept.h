#include <exception>
#include <string>

#define str_(x) #x
#define xstr_(x) str_(x)

#define Throw(type, cod)\
throw type ## _ Exception(type ## _ Exception :: cod,\
std::string(__FIE__## ":line"\
## xstr_(__LINE__)))

