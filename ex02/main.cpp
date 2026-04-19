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
    
    // Try to execute without sign
    boss.executeForm(shrub);
    
    // Intern signs, but try to execute with intern (too low)
    intern.signForm(shrub);
    intern.executeForm(shrub);

    // Mid executes
    mid.executeForm(shrub);

    std::cout << "\n=== RobotomyRequestForm Tests ===" << std::endl;
    RobotomyRequestForm robot("Bender");
    std::cout << robot << std::endl;

    // Intern tries to sign (too low: 145 > 72)
    intern.signForm(robot);
    
    // Mid signs (50 <= 72)
    mid.signForm(robot);

    // Mid tries to execute (too low: 50 > 45)
    mid.executeForm(robot);
    
    // Boss executes (1 <= 45)
    boss.executeForm(robot);
    boss.executeForm(robot); // test randomness 50%
    boss.executeForm(robot);
    boss.executeForm(robot);

    std::cout << "\n=== PresidentialPardonForm Tests ===" << std::endl;
    PresidentialPardonForm pardon("Ford Prefect");
    std::cout << pardon << std::endl;

    // Boss signs and executes
    boss.signForm(pardon);
    boss.executeForm(pardon);

    return 0;
}
