#include "SocketParameterError.h"
#include <string>


SocketParameterError::SocketParameterError(){
	this->t="Error en los parametros de entrada, conexion imposible";
}


std::string SocketParameterError::what(){
	return this->t;
}


SocketParameterError::~SocketParameterError(){}

