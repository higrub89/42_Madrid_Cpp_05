#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), _target("default") {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), _target(other._target) {
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    this->checkExecution(executor);
    
    std::cout << "* BZZZZZ... DRILL NOISES... *" << std::endl;
    
    // We can use a simple rand() approach (requires srand to be called in main)
    if (std::rand() % 2 == 0) {
        std::cout << this->_target << " has been robotomized successfully 50% of the time." << std::endl;
    } else {
        std::cout << "The robotomy on " << this->_target << " failed." << std::endl;
    }
}
