#ifndef __NEUTRINO_IMPLEMENT_THREADIO_THREADIOTYPES_H
#define __NEUTRINO_IMPLEMENT_THREADIO_THREADIOTYPES_H

#include <string>

namespace neutrino_implement {

  enum ThreadFillerState_t : int{
    kThreadStateIdle,
    kThreadStateStarting,
    kThreadStateRunning,
    kThreadStateUnknown
  };

  enum class BatchDataType_t : int {
    kBatchDataUnknown,
    kBatchDataChar,
    kBatchDataShort,
    kBatchDataInt,
    kBatchDataFloat,
    kBatchDataDouble,
    kBatchDataString
  };

  std::string BatchDataTypeName(BatchDataType_t type);

  enum class BatchDataState_t :int  {
    kBatchStateUnknown,
    kBatchStateEmpty,
    kBatchStateFilling,
    kBatchStateFilled,
    kBatchStateReleased
  };
}

#endif
