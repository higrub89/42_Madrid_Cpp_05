#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {
}

Intern::Intern(const Intern& other) {
    *this = other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {
}

AForm* Intern::_makeShrubbery(const std::string& target) const {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::_makeRobotomy(const std::string& target) const {
    return new RobotomyRequestForm(target);
}

AForm* Intern::_makePresidential(const std::string& target) const {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    std::string names[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (Intern::*funcs[])(const std::string&) const = {
        &Intern::_makeShrubbery,
        &Intern::_makeRobotomy,
        &Intern::_makePresidential
    };

    for (int i = 0; i < 3; i++) {
        if (names[i] == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*funcs[i])(target);
        }
    }

    std::cout << "Intern could not create " << formName << " because it does not exist." << std::endl;
    return NULL;
}
