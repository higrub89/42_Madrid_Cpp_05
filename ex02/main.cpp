/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 21:42:49 by rhiguita          #+#    #+#             */
/*   Updated: 2026/04/20 21:42:50 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    std::srand(time(NULL));

    std::cout << "=== Bureaucrats Creation ===" << std::endl;
    Bureaucrat boss("Boss", 1);
    Bureaucrat mid("Mid", 50);
    Bureaucrat intern("Intern", 145);
    
    std::cout << boss << std::endl;
    std::cout << mid << std::endl;
    std::cout << intern << std::endl;

    std::cout << "\n=== ShrubberyCreationForm Tests ===" << std::endl;
    ShrubberyCreationForm shrub("home");
    std::cout << shrub << std::endl;
    
    boss.executeForm(shrub);
    
    intern.signForm(shrub);
    intern.executeForm(shrub);

    mid.executeForm(shrub);

    std::cout << "\n=== RobotomyRequestForm Tests ===" << std::endl;
    RobotomyRequestForm robot("Bender");
    std::cout << robot << std::endl;

    intern.signForm(robot);
    
    mid.signForm(robot);

    mid.executeForm(robot);
    
    boss.executeForm(robot);
    boss.executeForm(robot);
    boss.executeForm(robot);
    boss.executeForm(robot);

    std::cout << "\n=== PresidentialPardonForm Tests ===" << std::endl;
    PresidentialPardonForm pardon("Ford Prefect");
    std::cout << pardon << std::endl;

    boss.signForm(pardon);
    boss.executeForm(pardon);

    return 0;
}
