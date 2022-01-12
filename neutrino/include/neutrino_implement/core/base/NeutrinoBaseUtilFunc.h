

#ifndef __NEUTRINO_IMPLEMENT_BASE_UTILFUNC_H__
#define __NEUTRINO_IMPLEMENT_BASE_UTILFUNC_H__

#include "neutrino_implement/core/base/PSet.h"

namespace neutrino_implement {

  /// Given a configuration string, format to create neutrino_implement::PSet
  //std::string FormatPSetString(std::string fname);
  /// Given a configuration file (full path), read & parse contents to create neutrino_implement::PSet
  std::string ConfigFile2String(std::string fname);
  /// Given a configuration file (full path), create and return neutrino_implement::PSet
  PSet CreatePSetFromFile(std::string fname,std::string cfg_name="cfg");

  bool mpi_enabled();

}

#endif
/** @} */ // end of doxygen group
