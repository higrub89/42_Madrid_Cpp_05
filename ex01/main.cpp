#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "=== Form construction tests ===" << std::endl;
    try {
        Form f1("ShrubberyCreation", 145, 137);
        std::cout << f1 << std::endl;

        Form f2("GradeInvalid", 0, 50);
        (void)f2;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        Form f3("TooLow", 200, 50);
        (void)f3;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== signForm tests ===" << std::endl;
    try {
        Bureaucrat lowBureau("Bob", 145);
        Form       f("PresidentialPardon", 25, 5);

        std::cout << lowBureau << std::endl;
        std::cout << f << std::endl;

        lowBureau.signForm(f);  // fail — grade too low
        std::cout << f << std::endl;

        Bureaucrat highBureau("Alice", 1);
        highBureau.signForm(f);  // success
        std::cout << f << std::endl;

        highBureau.signForm(f);  // already signed but still valid
    } catch (std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Copy / assignment ===" << std::endl;
    try {
        Form original("RobotomyRequest", 72, 45);
        Form copy(original);
        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy:     " << copy << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
