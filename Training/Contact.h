#pragma once

#include "importExport.h"
#include <string>


class impex Contact
{
public:
	Contact();
	Contact(std::string name, std::string number = "");
	Contact(const Contact& other);

	std::string getName() const;
	std::string getNumber() const;
	void setName(std::string name);
	void setNumber(std::string number);
	bool isValid() const;

	bool operator < (const Contact& other) const;

private:
	std::string m_name;
	std::string m_number;
};

