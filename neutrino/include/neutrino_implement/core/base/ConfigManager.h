
#ifndef __NEUTRINO_IMPLEMENT_BASE_CONFIGMANAGER_H__
#define __NEUTRINO_IMPLEMENT_BASE_CONFIGMANAGER_H__

#include <iostream>
#include "neutrino_implement/core/base/neutrino_base.h"
#include "neutrino_implement/core/base/neut.h"
#include "neutrino_implement/core/base/PSet.h"
#include <set>

namespace neutrino_implement {
  /**
     \class ConfigManager
     \brief Utility class to register a set of configurations
     Provides also a shared instance through which registered configurations can be shared beyond a single owner.\n
     Using neutrino_implement::PSet, the uniqueness of configuration parameters is guaranteed (no worry to "overwrite")\n
  */
  class ConfigManager : public neutrino_base {

  public:

    /// Default constructor
    ConfigManager() : neutrino_base("ConfigManager")
    {}

    /// Default destructor
    ~ConfigManager(){}
    /// Shared static reference getter
    static const ConfigManager& get()
    {
      if(!_me) _me = new ConfigManager;
      return *_me;
    }
    /// Adder of configuration from a file
    void AddConfigFile(const std::string cfg_file);
    /// Adder of configuration from parsed string
    void AddConfigString(const std::string cfg_str);
    /// Configuration retrieval method
    const PSet& GetConfig(const std::string cfg);

  private:

    static ConfigManager* _me;
    std::set<std::string> _cfg_files;
    PSet _cfg;

  };
}
#endif
/** @} */ // end of doxygen group
