#pragma once

#include "importExport.h"

class impexExp A
{
public:
	A();
	A(const A&);

	~A();

	void setVal(double dVal);

	static int m_nCnt;

private:
	double m_dVal;
	
};

