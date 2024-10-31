#ifndef VESSEL_HPP
# define VESSEL_HPP

# include <iostream>

class	Vessel
{
	public:
		Vessel(void);
		~Vessel(void);
		void	complain(std::string level);
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};

#endif