#pragma once

#include <cstdio>

class Node
{
private:
	// ���� ��带 ����Ű�� ������ ����
	Node* link;

public:
	// ������
	Node() { link = NULL; }
	~Node() {}

	// ������
	Node* getLink() { return link; }
	void setLink(Node* p) { link = p; }
};