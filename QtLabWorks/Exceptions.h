#pragma once
#include <exception>
#include <string>

class EdgeHasNoVertexException : public std::exception
{
	std::string _msg;
public:
	EdgeHasNoVertexException(const std::string& msg) : _msg(msg) {}

	virtual const char* what() const noexcept override
	{
		return _msg.c_str();
	}
};