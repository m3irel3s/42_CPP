#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) :
	AForm(copy), _target(copy._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	(void)copy;
	return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
	AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

void ShrubberyCreationForm::execute() const
{
	std::string filename = _target + "_shrubbery";

	std::ofstream ofs(filename.c_str());
	if (!ofs)
	{
		std::cerr << "Error: Could not open file " << filename << " for writing.\n";
		return;
	}

	ofs << "      /\\           /\\           /\\\n";
	ofs << "     /**\\         /**\\         /**\\\n";
	ofs << "    /****\\       /****\\       /****\\\n";
	ofs << "   /******\\     /******\\     /******\\\n";
	ofs << "  /********\\   /********\\   /********\\\n";
	ofs << "      |||         |||           |||\n";
	ofs << "      |||         |||           |||\n";

	ofs.close();
}