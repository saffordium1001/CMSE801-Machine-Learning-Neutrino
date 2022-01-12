
#ifndef __NEUTRINO_IMPLEMENT_BASE_LOGGER_H__
#define __NEUTRINO_IMPLEMENT_BASE_LOGGER_H__

#include <cstdio>
#include <iostream>
#include <map>
#include "neutrino_implement/core/base/NeutrinoTypes.h"

namespace neutrino_implement {

  /**
     \class logger
     \brief Utility class used to show formatted message on the screen.
     A logger class for neutrino_implement. Simply shows a formatted colored message on a screen. \n
     A static getter method is provided to create a sharable logger instance (see neutrino_base for useage). \n
  */
  class logger{

  public:

    /// Default constructor
    logger(const std::string& name="no_name")
      : _ostrm(&std::cout)
      , _name(name)
    {}

    /// Default destructor
    virtual ~logger(){};

  private:

    /// ostream
    std::ostream *_ostrm;

    /// Level
    msg::Level_t _level;

    /// Name
    std::string _name;

    /// Set of loggers
    static std::map<std::string,neutrino_implement::logger> *_logger_m;

    /// Shared logger
    static neutrino_implement::logger* _shared_logger;

    /// Default logger level
    static msg::Level_t _level_default;

  public:

    /// Logger's name
    const std::string& name() const { return _name; }

    /// Verbosity level setter
    void set(const msg::Level_t level) { _level = level; }

    /// Verbosity level getter
    msg::Level_t level() const { return _level; }

    /// Comparison operator for static collection of loggers
    inline bool operator<(const logger& rhs) const
    {
      if(_name < rhs.name()) return true;
      if(_name > rhs.name()) return false;
      return false;
    }

    /// Getter of a message instance
    static logger& get(const std::string name)
    {
      if(!_logger_m) _logger_m = new std::map<std::string,neutrino_implement::logger>();
      auto iter = _logger_m->find(name);
      if(iter == _logger_m->end()) {
        iter = _logger_m->emplace(name,logger(name)).first;
        iter->second.set(msg::kNORMAL);
      }
      return iter->second;
    };

    static logger& get_shared();

    /// Default logger level getter
    static msg::Level_t default_level() { return _level_default; }
    /// Default logger level setter (only affect future loggers)
    static void default_level(msg::Level_t l) { _level_default = l; }
    /// Force all loggers to change level
    static void force_level(msg::Level_t l)
    {
      default_level(l);
      for(auto& name_logger : *_logger_m) name_logger.second.set(l);
    }

    //
    // Verbosity level checker
    //
    inline bool debug   () const { return _level <= msg::kDEBUG;   }
    inline bool info    () const { return _level <= msg::kINFO;    }
    inline bool normal  () const { return _level <= msg::kNORMAL;  }
    inline bool warning () const { return _level <= msg::kWARNING; }
    inline bool error   () const { return _level <= msg::kERROR;   }
    /// Formatted message (simplest)
    std::ostream& send(const msg::Level_t) const;
    /// Formatted message (function name included)
    std::ostream& send(const msg::Level_t level,
		       const std::string& function ) const;
    /// Formatted message (function name + line number)
    std::ostream& send(const msg::Level_t level,
		       const std::string& function,
		       const unsigned int line_num ) const;
    /// Formatted message (function name + line number + file name)
    std::ostream& send(const msg::Level_t level,
		       const std::string& function,
		       const unsigned int line_num,
		       const std::string& file_name) const;

  };
}
//
// Compiler macro for saving us from text typing
//
/// Compiler macro for DEBUG message
#define NEUTRINO_DEBUG()    if( logger().debug   () ) logger().send(::neutrino_implement::msg::kDEBUG,    __FUNCTION__, __LINE__, __FILE__)
/// Compiler macro for INFO message
#define NEUTRINO_INFO()     if( logger().info    () ) logger().send(::neutrino_implement::msg::kINFO,     __FUNCTION__, __LINE__          )
/// Compiler macro for NORMAL message
#define NEUTRINO_NORMAL()   if( logger().normal  () ) logger().send(::neutrino_implement::msg::kNORMAL,   __FUNCTION__                    )
/// Compiler macro for WARNING message
#define NEUTRINO_WARNING()  if( logger().warning () ) logger().send(::neutrino_implement::msg::kWARNING,  __FUNCTION__                    )
/// Compiler macro for ERROR message
#define NEUTRINO_ERROR()    if( logger().error   () ) logger().send(::neutrino_implement::msg::kERROR,    __FUNCTION__, __LINE__          )
/// Compiler macro for CRITICAL message
#define NEUTRINO_CRITICAL()                           logger().send(::neutrino_implement::msg::kCRITICAL, __FUNCTION__, __LINE__, __FILE__)

#define NEUTRINO_SDEBUG()    if(neutrino_implement::logger::get_shared().debug())    neutrino_implement::logger::get_shared().send(::neutrino_implement::msg::kDEBUG,    __FUNCTION__,__LINE__,__FILE__)
#define NEUTRINO_SINFO()     if(neutrino_implement::logger::get_shared().info())     neutrino_implement::logger::get_shared().send(::neutrino_implement::msg::kINFO,     __FUNCTION__,__LINE__         )
#define NEUTRINO_SNORMAL()   if(neutrino_implement::logger::get_shared().normal())   neutrino_implement::logger::get_shared().send(::neutrino_implement::msg::kNORMAL,   __FUNCTION__                  )
#define NEUTRINO_SWARNING()  if(neutrino_implement::logger::get_shared().warning())  neutrino_implement::logger::get_shared().send(::neutrino_implement::msg::kWARNING,  __FUNCTION__                  )
#define NEUTRINO_SERROR()    if(neutrino_implement::logger::get_shared().error())    neutrino_implement::logger::get_shared().send(::neutrino_implement::msg::kERROR,    __FUNCTION__,__LINE__         )
#define NEUTRINO_SCRITICAL() neutrino_implement::logger::get_shared().send(::neutrino_implement::msg::kCRITICAL, __FUNCTION__,__LINE__,__FILE__)

/** @} */ // end of doxygen group logger
#endif
