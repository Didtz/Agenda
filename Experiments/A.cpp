#include "pch.h"
#include "A.h"

int A::m_nCnt = 0;

A::A()
{
	m_dVal = 0;
	m_nCnt++;
}

A::A(const A& other)
{
	m_dVal = other.m_dVal;
	m_nCnt++;
}

A::~A()
{
	m_nCnt--;
}

void A::setVal(double dVal)
{
	m_dVal = dVal;
}