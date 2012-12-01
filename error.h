#ifndef ERROR_H_
#define ERROR_H_

#include <stdexcept>
#include <string>



class error : public std::runtime_error{

public:
	error ( const string &err ) : runtime_error (err){};
};

#endif