/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 21:48:36 by rhiguita          #+#    #+#             */
/*   Updated: 2026/04/20 21:48:37 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern {
    private:
        AForm*  _makeShrubbery(const std::string& target) const;
        AForm*  _makeRobotomy(const std::string& target) const;
        AForm*  _makePresidential(const std::string& target) const;

    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();

        AForm*  makeForm(const std::string& formName, const std::string& target) const;
};

#endif
