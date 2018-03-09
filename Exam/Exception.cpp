#include "Exception.h"

FileException::FileException(const std::string& message) : message(message)
{
}

const char * FileException::what()
{
	return message.c_str();
}

RepositoryException::RepositoryException() : exception{}, message{ "" }
{
}

RepositoryException::RepositoryException(const std::string & msg) : message(msg)
{
}

const char * RepositoryException::what()
{
	return this->message.c_str();
}

const char * DuplicateException::what()
{
	return "There is another quiz with the same id!";
}
