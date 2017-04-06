#include "KJHNode.h"
#include<iostream>

CKJHNode::CKJHNode(int data)
{
	m_parent=NULL;
	m_left=NULL;
	m_right=NULL;
	m_data=data;
}


CKJHNode::~CKJHNode(void)
{
}
