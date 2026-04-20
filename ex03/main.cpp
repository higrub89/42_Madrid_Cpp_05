#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
    std::srand(time(NULL));

    std::cout << "=== Bureaucrats Creation ===" << std::endl;
    Bureaucrat boss("Boss", 1);
    
    std::cout << boss << std::endl;

    std::cout << "\n=== Intern Creation ===" << std::endl;
    Intern someRandomIntern;

    std::cout << "\n=== Test 1: Robotomy Request ===" << std::endl;
    AForm* rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf) {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }

    std::cout << "\n=== Test 2: Shrubbery Creation ===" << std::endl;
    AForm* scf;
    scf = someRandomIntern.makeForm("shrubbery creation", "Home");
    if (scf) {
        boss.signForm(*scf);
        boss.executeForm(*scf);
        delete scf;
    }

    std::cout << "\n=== Test 3: Presidential Pardon ===" << std::endl;
    AForm* ppf;
    ppf = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
    if (ppf) {
        boss.signForm(*ppf);
        boss.executeForm(*ppf);
        delete ppf;
    }

    std::cout << "\n=== Test 4: Unknown Form ===" << std::endl;
    AForm* unknown;
    unknown = someRandomIntern.makeForm("unknown form", "Nobody");
    if (unknown) {
        boss.signForm(*unknown);
        boss.executeForm(*unknown);
        delete unknown;
    }

    return 0;
}
