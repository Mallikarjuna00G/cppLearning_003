/**
 * @file displaySeqContainer.cpp
 * @brief Implementation for overloaded `displaySeqContainer` functions.
 *
 * This file provides the definitions for the `displaySeqContainer` functions
 * declared in `displaySeqContainer.hpp`.
 *
 * @author Mallikarjuna00G
 * @date 2025-06-27
 */

#include "displaySeqContainer.hpp"

void displaySeqContainer(const std::vector<int> &container) {
    for (const auto &item : container) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

void displaySeqContainer(const std::deque<int> &container) {
    for (const auto &item : container) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

void displaySeqContainer(std::deque<std::string>::const_iterator it_container_beg, 
    std::deque<std::string>::const_iterator it_container_end) {
    while (it_container_beg != it_container_end) {
        std::cout << *it_container_beg << " ";
        it_container_beg++;
    }
    std::cout << std::endl;
}

void displaySeqContainer(std::list<std::string>::const_iterator it_container_beg, 
    std::list<std::string>::const_iterator it_container_end) {
    while (it_container_beg != it_container_end) {
        std::cout << *it_container_beg << " ";
        it_container_beg++;
    }
    std::cout << std::endl;
}

void displaySeqContainer(const std::list<int> &container) {
    for (const auto &item : container) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}