#ifndef BASE_TYPE_HEADER
#define BASE_TYPE_HEADER

#include <iostream>
#include <memory>
#include "TestBoost.h"

template<typename T> // #TODO: 待把对应的头文件和用例梳理清晰
class Node {
public:
    T m_data;
    std::shared_ptr<Node<T>> m_next;

    Node(T value) : m_data(value), m_next(nullptr) {}
};

template<typename T>
class LinkedList {
protected:
    std::shared_ptr<Node<T>> m_head;

public:
    LinkedList() : m_head(nullptr) {}

    // 在链表末尾添加一个新节点
    void Append(T value)
    {
        std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(value);
        if (!m_head) {
            m_head = newNode;
        } else {
            std::shared_ptr<Node<T>> temp = m_head;
            while (temp->m_next) {
                temp = temp->m_next;
            }
            temp->m_next = newNode;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& self)
    {
        std::shared_ptr<Node<T>> temp = self.m_head;
        while (temp->m_next) {
            os << temp->m_data << "->";
            temp = temp->m_next;
        }
        os << temp->m_data;
        return os;
    }
};

#endif // BASE_TYPE_HEADER