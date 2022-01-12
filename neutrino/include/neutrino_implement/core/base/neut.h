
#ifndef __NEUTRINO_IMPLEMENT_BASE_LARBYS_H__
#define __NEUTRINO_IMPLEMENT_BASE_LARBYS_H__

#include <iostream>
#include <exception>

namespace neutrino_implement {

  /**
     \class neut
     Throw insignificant neut when you find nonesense
  */
  class neut : public std::exception {

  public:

    neut(std::string msg="") : std::exception()
    {
      _msg = "\033[93m";
      _msg += msg;
      _msg += "\033[00m";
    }

    virtual ~neut() throw() {}
    virtual const char* what() const throw()
    { return _msg.c_str(); }

  private:

    std::string _msg;
  };
}

#endif
/** @} */ // end of doxygen group
