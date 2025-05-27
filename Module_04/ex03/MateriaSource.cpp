#include "MateriaSource.hpp"

// ========
// Constructor & Destructor
// ========

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MAX_SLOTS; i++)
		delete _source[i];
	std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource::MateriaSource()
{
	for (int i = 0; i < MAX_SLOTS; i++)
		_source[i] = NULL;
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	*this = copy;
	std::cout << "MateriaSource copy constructor called" << std::endl;
}

// ========
// Operator Overload
// ========

MateriaSource &MateriaSource::operator=(const MateriaSource &copy)
{
	if (this != &copy)
	{
		for (int i = 0; i < MAX_SLOTS; i++)
		{
			delete _source[i];
			if (copy._source[i])
				_source[i] = copy._source[i]->clone();
			else
				_source[i] = NULL;
		}
	}
	std::cout << "MateriaSource assign operator called" << std::endl;
	return *this;
}

// ========
// Getters & Setters
// ========

AMateria *MateriaSource::getMateria(std::string const &type)
{
	for (int i = 0; i < MAX_SLOTS; i++)
	{
		if (_source[i] && (_source[i]->getType() == type))
			return _source[i];
	}
	return NULL;
}

// ========
// Public member functions
// ========

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < MAX_SLOTS; i++)
	{
		if (_source[i] && (_source[i]->getType() == type))
		{
			AMateria *newMateria = _source[i]->clone();
			std::cout << "MateriaSource created materia: " << type << " "
			<< newMateria << std::endl;
			return newMateria;
		}
	}
	std::cout << "MateriaSource couldn't create new Materia: " << type << std::endl;
	return NULL;
}

void MateriaSource::learnMateria(AMateria *materia)
{
	if (!materia)
	{
		std::cout << "MateriaSource cannot learn NULL materia" << std::endl;
		return ;
	}
	for (int i = 0; i < MAX_SLOTS; i++)
	{
		if (_source[i] == NULL)
		{
			_source[i] = materia->clone();
			std::cout << "MateriaSource leanerd new materia: " << materia->getType() << std::endl;
			delete materia;
			return ;
			
		}
	}
	std::cout << "MateriaSource cannot learn more materias" << std::endl;
	delete materia;
}

