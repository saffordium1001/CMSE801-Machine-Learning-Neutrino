
#ifndef __NEUTRINO_IMPLEMENT_BASE_NEUTRINO_BASE_H__
#define __NEUTRINO_IMPLEMENT_BASE_NEUTRINO_BASE_H__

#include <vector>
#include "neutrino_implement/core/base/neutrino_logger.h"

namespace neutrino_implement {

  /**
    \class neutrino_base
    Framework base class equipped with a logger class
  */
  class neutrino_base {

  public:

    /// Default constructor
    neutrino_base(const std::string logger_name="neutrino_base")
      : _logger(nullptr)
    { _logger = &(::neutrino_implement::logger::get(logger_name)); }

    /// Default copy constructor
    neutrino_base(const neutrino_base &original) : _logger(original._logger) {}

    /// Default destructor
    virtual ~neutrino_base(){};

    /// Logger getter
    inline const neutrino_implement::logger& logger() const
    { return *_logger; }

    /// Verbosity level
    void set_verbosity(::neutrino_implement::msg::Level_t level)
    { _logger->set(level); }

    /// Name getter, defined in a logger instance attribute
    const std::string& name() const
    { return logger().name(); }

  private:

    neutrino_implement::logger *_logger;   ///< logger

  };
}
#endif

/** @} */ // end of doxygen group
