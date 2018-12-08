#pragma once

#include <cstdio>

class Node
{
private:
	// 다음 노드를 가리키는 포인터 변수
	Node* link;

public:
	// 생성자
	Node() { link = NULL; }
	~Node() {}

	// 접근자
	Node* getLink() { return link; }
	void setLink(Node* p) { link = p; }
};