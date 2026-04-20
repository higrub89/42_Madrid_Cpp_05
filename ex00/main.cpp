/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:44:00 by rhiguita          #+#    #+#             */
/*   Updated: 2026/04/20 17:37:13 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    std::cout << "--- Test 1: Construction with valid grade ---" << std::endl;
    try {
        Bureaucrat b1("Alice", 1);
        std::cout << b1 << std::endl;
        Bureaucrat b2("Bob", 150);
        std::cout << b2 << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 2: Construction with grade too high (0) ---" << std::endl;
    try {
        Bureaucrat b3("High", 0);
        std::cout << b3 << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Caught expected error: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 3: Construction with grade too low (151) ---" << std::endl;
    try {
        Bureaucrat b4("Low", 149);
        std::cout << b4 << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Caught expected error: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 4: Incrementing Alice (1 -> error) ---" << std::endl;
    try {
        Bureaucrat b1("Alice", 1);
        std::cout << b1 << std::endl;
        b1.incrementGrade();
    } catch (std::exception &e) {
        std::cerr << "Caught expected error: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 5: Decrementing Bob (150 -> error) ---" << std::endl;
    try {
        Bureaucrat b2("Bob", 150);
        std::cout << b2 << std::endl;
        b2.decrementGrade();
    } catch (std::exception &e) {
        std::cerr << "Caught expected error: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 6: Normal increment/decrement ---" << std::endl;
    try {
        Bureaucrat b5("Charlie", 42);
        std::cout << b5 << std::endl;
        b5.incrementGrade();
        std::cout << "After increment: " << b5 << std::endl;
        b5.decrementGrade();
        b5.decrementGrade();
        std::cout << "After 2 decrements: " << b5 << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

    return 0;
}
